#include "Epub.h"
#include "vector"
#include "../utils/XMLFromText.h"
#include "../utils/utils.h"

std::tuple<JString, JString, Array<EpubPage>> getPageInfo(std::unordered_map<JString, std::shared_ptr<CssMap>>& cssCacheMap, const JString& rootFilePath, const Epub::FileToStringHandler& fileToStringHandler, const Epub::ImageHandler& imageHandler, bool parseNow) {
    JString text = fileToStringHandler(rootFilePath);
    std::unordered_map<JString, JString>items;
    JString relativePath = utils::getParentPath(rootFilePath);
    JString coverContent, toc;
    bool isManifestSection = 0, isSpineSection = 0;
    std::vector<EpubPage>pages;
    xmlFromText(text, [](const JString& text){},
                [&cssCacheMap, &fileToStringHandler, &imageHandler, &pages, &items, &relativePath, &coverContent, &toc, &isManifestSection, &isSpineSection, &parseNow](const JString& element, bool isOpenClose, bool isClose, std::unordered_map<JString, JString>& attributes){
                    if(element == "manifest") isManifestSection = !isClose;
                    else if(element == "meta") {
                        const JString* content = utils::getOrNull(attributes, {"content"});
                        if(content && !content->empty() && utils::getOrNull(attributes, {"name"})->equals("cover", true))
                            coverContent = *content;
                    } else if(element == "item") {
                        if(!isManifestSection) return;
                        const JString *id = utils::getOrNull(attributes, {"id"}), *href = utils::getOrNull(attributes, {"href"});
                        if(!id || !href || id->empty() || href->empty()) return;
                        items[*id] = utils::getPathCombine(relativePath, *href);
                    } else if(element == "spine") {
                        if((isSpineSection = !isClose)) {
                            const JString *tempToc = utils::getOrNull(attributes, {"toc"});
                            if(tempToc && !tempToc->empty()) toc = utils::getOrDefault(items, *tempToc, *tempToc);
                        }
                    } else if(element == "itemref") {
                        if(!isSpineSection) return;
                        const JString *idRef = utils::getOrNull(attributes, {"idref"});
                        if(idRef && !idRef->empty()) {
                            const JString *href = utils::getOrNull(items, *idRef);
                            if(href && !href->empty())
                                pages.emplace_back(cssCacheMap, *href, *idRef, fileToStringHandler, imageHandler, parseNow);
                        }
                    }
    });
    if(!coverContent.empty())
        coverContent = utils::getOrDefault(items, coverContent, coverContent);
    return {coverContent, toc, Array<EpubPage>(pages.data(), pages.size())};
}

void getNavMap(Array<EpubPage>& pages, const JString& path, const Epub::FileToStringHandler& fileToStringHandler) {
    if(path.empty()) return;
    JString text = fileToStringHandler(path);
    std::unordered_map<JString, JString> navMap;
    bool isNavLabelSection = 0;
    JString lastNavPointId, label;
    xmlFromText(text, [&isNavLabelSection, &label](const JString& text) {
        if(isNavLabelSection) label = text;
        }, [&navMap, &label, &lastNavPointId, &isNavLabelSection](const JString& element, bool isOpenClose, bool isClose, std::unordered_map<JString, JString>& attributes) {
        if(element == "navpoint") {
            if(isClose) {
                if(!label.empty() && !lastNavPointId.empty()) navMap[lastNavPointId] = label;
                label = {};
                lastNavPointId = {};
            }else
                lastNavPointId = utils::getOrDefault(attributes, {"id"}, {});
        }else if(element == "navlabel") isNavLabelSection = !isClose;
    });
    for(EpubPage& page : pages) {
        const JString *name = utils::getOrNull(navMap, page.getIdRef());
        if(name && !name->empty())
            page.setName(*name);
    }
}

Epub::Epub(JString container, const FileToStringHandler& fileToStringHandler, const ImageHandler& imageHandler, bool parseNow) {
    JString rootFilePath;
    xmlFromText(container, [](const JString& text) {},
                [&rootFilePath](const JString& element, bool isOpenClose, bool isClose, std::unordered_map<JString, JString>& attributes) {
                    if(element == "rootfile")
                        rootFilePath = utils::getOrDefault(attributes, {"full-path"}, rootFilePath);
    });
    if(rootFilePath.empty()) return;
    auto [coverContent, toc, parsePages] = getPageInfo(cssCacheMap, rootFilePath, fileToStringHandler, imageHandler, parseNow);
    getNavMap(parsePages, toc, fileToStringHandler);
    pages = parsePages;
    cover = coverContent;
}

const EpubPage *Epub::getPage(int page, const FileToStringHandler &fileToStringHandler,
                              const ImageHandler &imageHandler) {
    if(page < 0 || page >= pages.size()) return nullptr;
    EpubPage* epubPage = pages[page];
    epubPage->parse(cssCacheMap, fileToStringHandler, imageHandler);
    return epubPage;
}

const EpubPage *Epub::getPage(int page) {
    if(page < 0 || page >= pages.size()) return nullptr;
    return pages[page];
}