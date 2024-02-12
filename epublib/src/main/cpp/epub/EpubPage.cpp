//
// Created by skyne on 2023-12-26.
//
#include "EpubPage.h"
#include "../utils/utils.h"
#include "../utils/XMLFromText.h"
#include "EpubElement.h"
#include "../css/DefaultStyle.h"

EpubPage::EpubPage(std::unordered_map<JString, std::shared_ptr<CssMap>>& cssCacheMap, const JString &href, const JString &idRef,
                   const FileToStringHandler &fileToStringHandler, const EpubPage::ImageHandler &imageHandler, bool parseNow):
                   href(href), idRef(idRef), name(utils::getFileNameWithoutExtension(href)) {
    if (!parseNow) return;
    parse(cssCacheMap, fileToStringHandler, imageHandler);
}

std::tuple<JString, Array<std::shared_ptr<CssMap>>, EpubPageParseElementBlock>
parseDocument(std::unordered_map<JString, std::shared_ptr<CssMap>> &cssCacheMap, const JString &href,
                 const EpubPage::FileToStringHandler &fileToStringHandler,
                 const EpubPage::ImageHandler &imageHandler) {
    JString text = fileToStringHandler(href);
    JString relativePath = utils::getParentPath(href);
    EpubPageParseElementBlock html = {"", "", ""};
    std::vector<EpubPageParseElementBlock*> elementList = {&html};
    bool isTitleSection = 0;
    int bodyDepth = 0;
    JString title;
    std::unordered_set<std::shared_ptr<CssMap>> cssList;

    xmlFromText(text, [&elementList, &title, &isTitleSection, &bodyDepth](
                        const JString &text) {
                    if (isTitleSection && title.empty())
                        title = text;
                    if (bodyDepth <= 0) return;
                    elementList.back()->getValue().emplace_back(std::shared_ptr<EpubPageParseElement>(new EpubPageParseElementText(text)));
                },
                [&cssCacheMap, &imageHandler, &fileToStringHandler, &relativePath, &elementList, &cssList, &isTitleSection, &bodyDepth](
                        const JString &element, bool isOpenClose, bool isClose,
                        std::unordered_map<JString, JString> &attributes) {
                    if (element == "title") isTitleSection = !isClose;
                    else if (element == "body")
                        bodyDepth = std::max(bodyDepth + (static_cast<int>(isClose) * -2) + 1, 0);
                    else if (element == "link") {
                        const JString *href = utils::getOrNull(attributes, {"href"});
                        if (href) {
                            JString path = utils::getPathCombine(relativePath, *href);
                            auto cacheData = cssCacheMap.find(path);
                            if (cacheData != cssCacheMap.end()) {
                                cssList.insert(cacheData->second);
                            }else {
                                CssMap *map = CssMap::fromText(path, fileToStringHandler(path), 0);
                                if (map) {
                                    auto ptr = std::shared_ptr<CssMap>(map);
                                    cssCacheMap.emplace(path, ptr);
                                    cssList.insert(ptr);
                                }
                            }
                        }
                        return;
                    } else if (element == "br") {
                        if (bodyDepth > 0)
                            elementList.back()->getValue().emplace_back(std::shared_ptr<EpubPageParseElementText>(new EpubPageParseElementText('\n')));
                        return;
                    } else if (element == "hr") {
                        if (bodyDepth > 0) {
                            elementList.back()->getValue().emplace_back(std::shared_ptr<EpubPageParseElementDivider>(
                                    new EpubPageParseElementDivider(
                                            element,
                                            utils::getOrDefault(attributes, {"id"}, {'*'}),
                                            utils::getOrDefault(attributes, {"class"}, {'*'})))
                            );
                        }
                        return;
                    } else if (element == "img") {
                        if (bodyDepth > 0) {
                            const JString *src = utils::getOrNull(attributes, {"src"});
                            if (src && !src->empty()) {
                                JString path = utils::getPathCombine(relativePath, *src);
                                Array<int> imageShape = imageHandler(path);
                                if (imageShape.size() == 2) {
                                    elementList.back()->getValue().emplace_back(
                                            std::shared_ptr<EpubPageParseElementImage>(
                                                    new EpubPageParseElementImage(element,
                                                                                  utils::getOrDefault(attributes, {"id"}, {'*'}),
                                                                                  utils::getOrDefault(attributes, {"class"}, {'*'}),
                                                                                  path,
                                                                                  *imageShape[0],
                                                                                  *imageShape[1])
                                            ));
                                }
                            }
                        }
                        return;
                    }
                    if(!(bodyDepth > 0 || bodyDepth == 0 && isClose && element == "body")) return;
                    if(!(isClose || isOpenClose)) {
                        elementList.back()->getValue().emplace_back(
                                std::shared_ptr<EpubPageParseElementBlock>(
                                        new EpubPageParseElementBlock(
                                                element,
                                                utils::getOrDefault(attributes, {"id"}, {'*'}),
                                                utils::getOrDefault(attributes, {"class"}, {'*'}))));
                        elementList.emplace_back(static_cast<EpubPageParseElementBlock*>(elementList.back()->getValue().back().get()));
                    }else if(isClose && elementList.back()->getElementName() == element)
                        elementList.pop_back();
                });
    auto result = Array<std::shared_ptr<CssMap>>(cssList.size());
    int i = 0;
    for(auto it = cssList.begin(); it != cssList.end(); it++) *result[i++] = *it;
    return {title, result, html};
}

bool getIsItalic(const JString* text) {
    if(!text || text->empty()) return 0;
    return text->startsWith("italic", true) || text->startsWith("oblique", true);
}

AnnotatedString importCss(const AnnotatedString& text, const std::unordered_map<JString, JString>& styles) {
    Color color = Color::convertToColor(utils::getOrNull(styles, {"color"}));
    TextUnit fontSize = TextUnit::toTextUnit(utils::getOrNull(styles, {"font-size"}));
    TextUnit lineHeight = TextUnit::toTextUnit(utils::getOrNull(styles, {"line-height"}));
    FontWeight fontWeight = FontWeight::toFontWeight(utils::getOrNull(styles, {"font-weight"}));
    bool isItalic = getIsItalic(utils::getOrNull(styles, {"font-style"}));
    JString fontFamily = utils::getOrDefault(styles, {"font-family"}, {});
    TextUnit letterSpacing = TextUnit::toTextUnit(utils::getOrNull(styles, {"letter-spacing"}));
    TextDecoration textDecoration = TextDecoration::toTextDecoration(utils::getOrNull(styles, {"text-decoration"}));

    AnnotatedStringBuilder builder = AnnotatedStringBuilder(text.text());
    if(color.isSpecified() || fontSize.isSpecified() || fontWeight.isSpecified() || isItalic || !fontFamily.empty()) {
        SpanStyle spanStyle = SpanStyle(fontFamily, color, fontSize, fontWeight, letterSpacing, textDecoration, isItalic);
        int start = 0;
        for(const Range<SpanStyle>& data : text.getSpanStyles()) {
            if(data.getItem() == spanStyle) continue;
            if(start != data.getStart())
                builder.addStyle(spanStyle, start, data.getStart());

            start = data.getEnd();
            builder.addStyle(data);
        }
        if(start < text.length())
            builder.addStyle(spanStyle, start, text.length());

        if(fontSize.isSpecified() && fontSize.getValue() > 0)
            lineHeight = lineHeight.apply(fontSize);
    }else builder.addStyleAll(text.getSpanStyles());

    if(lineHeight.isSpecified()) {
        ParagraphStyle paragraphStyle = ParagraphStyle(lineHeight);
        int start = 0;
        for(const Range<ParagraphStyle>& data : text.getParagraphStyles()) {
            if(data.getItem().getLineHeight() == lineHeight) continue;
            if(start != data.getStart())
                builder.addStyle(paragraphStyle, start, data.getStart());
            start = data.getEnd();
            builder.addStyle(data);
        }
        if(start < text.length())
            builder.addStyle(paragraphStyle, start, text.length());
    }
    return builder.toAnnotatedString();
}

std::unordered_map<JString, JString>& getStyles(const Array<std::shared_ptr<CssMap>>& cssList,
                                                std::unordered_map<CssMap*, std::unordered_set<CssNode*>>& selectorAll,
                                                const std::unordered_map<CssMap*, std::unordered_map<JString, JString>>& fontAnnotations,
                                                std::unordered_map<JString, JString>& styles,
                                                const JString& elementName,
                                                const JString& idName,
                                                const JString& className) {
    auto defaultStyles = DefaultStyle::getDefaultStyle(elementName);
    if(defaultStyles) {
        for(const auto &[k, v] : *defaultStyles)
            styles[k] = v;
//        styles.insert(defaultStyles->begin(), defaultStyles->end());
    }

    for(std::shared_ptr<CssMap> cssMap : cssList) {
        std::unordered_set<CssNode*> list = cssMap->filter(elementName, idName, className);
        std::unordered_set<CssNode*>& cache = selectorAll[cssMap.get()];
        for(CssNode* node : cache)
            node->filter(elementName, idName, className, list);
        cache.insert(list.begin(), list.end());
        for(CssNode* node : list) {
            std::unordered_map<JString, JString>& nodeStyles = const_cast<std::unordered_map<JString, JString>&>(node->getStyles());
            const JString *fontFamilyPtr = utils::getOrNull(nodeStyles, {"font-family"});
            if(fontFamilyPtr) {
                JString fontFamily = fontFamilyPtr->splitFirst(' ');
                if(!fontFamily.empty()) {
                    auto fontAnnotation = fontAnnotations.find(cssMap.get());
                    if (fontAnnotation != fontAnnotations.end()) {
                        const JString *path = utils::getOrNull(fontAnnotation->second, fontFamily);
                        if (path && !path->empty())
                            nodeStyles["font-family"] = *path;
                    }
                }
            }
            styles.insert(nodeStyles.begin(), nodeStyles.end());
        }
    }

    return styles;
}

Array<JString> cssSplitValue(const std::unordered_map<JString, JString>& styles,
                             const JString& a, const JString& b, const JString& c, const JString& d,
                             const JString& multi) {
    JString aValue = utils::getOrDefault(styles, a, {});
    JString bValue = utils::getOrDefault(styles, b, {});
    JString cValue = utils::getOrDefault(styles, c, {});
    JString dValue = utils::getOrDefault(styles, d, {});
    Array<JString> multiValue = utils::getOrDefault(styles, multi, {}).split(' ');
    bool isFind = 0;
    for(int i = multiValue.size() - 1; i >= 0; i--) {
        JString& v = *multiValue[i];
        if(!(v.endsWith("px", true) || v.endsWith("em") || v.endsWith('%') || v.isDigitOnly())) continue;
        multiValue = multiValue.subList(0, i + 1);
        isFind = 1;
        break;
    }
    if(!isFind && !multiValue.empty())
        multiValue = Array<JString>();
    switch(multiValue.size()) {
        case 1:
            dValue = cValue = bValue = aValue = *multiValue[0];
            break;
        case 2:
            cValue = aValue = *multiValue[0];
            dValue = bValue = *multiValue[1];
            break;
        case 3:
            aValue = *multiValue[0];
            dValue = bValue = *multiValue[1];
            cValue = *multiValue[2];
            break;
        case 4:
            aValue = *multiValue[0];
            bValue = *multiValue[1];
            cValue = *multiValue[2];
            dValue = *multiValue[3];
    }

    return {aValue, bValue, cValue, dValue};
}

Array<std::shared_ptr<EpubElement>> getImportElement(
        const Array<std::shared_ptr<CssMap>>& cssList,
        const std::unordered_map<JString, JString>& styles,
        const std::unordered_map<CssMap*, std::unordered_set<CssNode*>>& selectorAll,
        const std::unordered_map<CssMap*, std::unordered_map<JString, JString>>& fontAnnotations,
        const EpubPageParseElementBlock& block) {
    const JString *display = utils::getOrNull(styles, {"display"});
    if(display && display->equals("none", true)) return Array<std::shared_ptr<EpubElement>>();
    std::vector<std::shared_ptr<EpubElement>>list;
    AnnotatedStringBuilder builder;

    for(const std::shared_ptr<EpubPageParseElement>& e : block.getValue()) {
        const auto element = e.get();
        if(element->getType() == EpubElementData::EpubElementText) {
            builder.append(static_cast<const EpubPageParseElementText*>(element)->text());
            continue;
        }
        if(builder.length() > 0) {
            list.emplace_back(std::shared_ptr<EpubElementText>(new EpubElementText(importCss(builder.toAnnotatedString(), styles))));
            builder.clear();
        }
        switch (element->getType()) {
            case EpubElementData::EpubElementImage: {
                const EpubPageParseElementImage* image = static_cast<const EpubPageParseElementImage*>(element);
                list.emplace_back(std::shared_ptr<EpubElementImage>(new EpubElementImage(image->getSrc(), image->getWidth(), image->getHeight())));
                break;
            }
            case EpubElementData::EpubElementDivider:
                list.emplace_back(std::shared_ptr<EpubElementDivider>(new EpubElementDivider()));
                break;
            case EpubElementData::EpubElementBox: {
                std::unordered_map<JString, JString> childStyles;
                std::unordered_map<CssMap*, std::unordered_set<CssNode*>> childSelectorAll = selectorAll;
                auto child = getImportElement(cssList,
                                              getStyles(cssList,
                                                        childSelectorAll,
                                                        fontAnnotations,
                                                        CssMap::getInheritanceStyles(childStyles, styles),
                                                        element->getElementName(),
                                                        element->getIdName(),
                                                        element->getClassName()),
                                              childSelectorAll,
                                              fontAnnotations,
                                              *static_cast<const EpubPageParseElementBlock*>(element));

                int i = 0;
                if(!list.empty() && !child.empty()) {
                    auto *parentLastBlock = list.back().get();
                    auto *newFirstBlock = child.begin()->get();
                    if(parentLastBlock->getType() == EpubElementData::EpubElementText && newFirstBlock->getType() == EpubElementData::EpubElementText) {
                        i = 1;
                        AnnotatedStringBuilder concatBuilder = static_cast<const EpubElementText&>(*parentLastBlock).text();
                        concatBuilder.append(static_cast<const EpubElementText&>(*newFirstBlock).text());
                        list.pop_back();
                        list.emplace_back(std::shared_ptr<EpubElementText>(new EpubElementText(concatBuilder.toAnnotatedString())));
                    }
                }

                list.insert(list.end(), child.begin() + i, child.end());
                if(!list.empty() && list.back().get()->getType() == EpubElementData::EpubElementText) {
                    builder = static_cast<const EpubElementText*>(list.back().get())->text();
                    list.pop_back();
                }
                break;
            }
            default: break;
        }
    }
    if(!builder.empty()) {
        list.emplace_back(std::shared_ptr<EpubElementText>(new EpubElementText(importCss(builder.toAnnotatedString(), styles))));
    }
    if(display && display->equals("block", true)) {
        return {
            std::shared_ptr<EpubElement>(
                    new EpubElementBox(Array<std::shared_ptr<EpubElement>>(list.data(), list.size()),
                           RectTextUnit(cssSplitValue(styles,
                                                      "margin-top", "margin-right", "margin-bottom", "margin-left",
                                                      "margin")),
                           RectTextUnit(cssSplitValue(styles,
                                                      "padding-top", "padding-right", "padding-bottom", "padding-left",
                                                      "padding")),
                           RectTextUnit(cssSplitValue(styles,
                                                      "border-top", "border-right", "border-bottom", "border-left",
                                                      "border")),
                           RectTextUnit(cssSplitValue(styles,
                                                      "_", "_", "_", "_",
                                                      "border-radius")))
            )
        };
    }
    return Array<std::shared_ptr<EpubElement>>(list.data(), list.size());
}

Array<std::shared_ptr<EpubElement>> getImportDocument(const Array<std::shared_ptr<CssMap>>& cssList, const EpubPageParseElementBlock& html) {
    std::unordered_map<CssMap*, std::unordered_set<CssNode*>>selectorAll;
    std::unordered_map<CssMap*, std::unordered_map<JString, JString>>fontAnnotations;
    std::unordered_map<JString, JString>styles;
    for(std::shared_ptr<CssMap> cssMap : cssList) {
        JString relativePath = utils::getParentPath(cssMap->getHref());
        auto annotations = cssMap->getAnnotations().find("font-face");
        if(annotations != cssMap->getAnnotations().end()) {
            for (const CssNode &node: annotations->second) {
                const auto &fontFace = node.getStyles();
                const JString *namePtr = utils::getOrNull(fontFace, {"font-family"});
                const JString *srcPtr = utils::getOrNull(fontFace, {"src"});
                if(namePtr && srcPtr) {
                    JString name = namePtr->splitFirst(' ');
                    JString src = srcPtr->splitFirst(' ').trim();
                    if (src.startsWith("url", true))
                        src = src.substring(4, src.size() - 1).trim();
                    if (src.startsWith('"') || src.startsWith('\''))
                        src = src.substring(1, src.size() - 1);
                    if (name.empty() || src.empty()) continue;
                    src = utils::getPathCombine(relativePath, src);
                    fontAnnotations[cssMap.get()][name] = src;
                }
            }
        }
    }
    return getImportElement(cssList, styles, selectorAll, fontAnnotations, html);
}

void EpubPage::parse(std::unordered_map<JString, std::shared_ptr<CssMap>> &cssCacheMap,
                     const EpubPage::FileToStringHandler &fileToStringHandler,
                     const ImageHandler &imageHandler) {
    if(parsed) return;
    const auto [title, cssList, html] = parseDocument(cssCacheMap, href, fileToStringHandler, imageHandler);
    if(name.empty() && !title.empty()) name = title;
    document = getImportDocument(cssList, html);
    parsed = true;
}

void EpubPage::setDocument(Array<std::shared_ptr<EpubElement>> &loadDocument) {
    document = loadDocument;
    parsed = 1;
}
