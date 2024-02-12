#pragma once
#include "EpubPage.h"
#include "../utils/Array.h"
#include "../utils/JString.h"
#include "functional"
class Epub {
private:
    std::unordered_map<JString, std::shared_ptr<CssMap>> cssCacheMap;
    Array<EpubPage> pages;
    JString cover;
public:
    typedef std::function<void* (const JString&, JString)> LoadFontHandler;
    typedef std::function<JString (const JString&)> FileToStringHandler;
    typedef std::function<Array<int> (const JString&)> ImageHandler;
    Epub(JString root, const FileToStringHandler& fileToStringHandler, const ImageHandler& imageHandler, bool parseNow);

    int totalPages() { return pages.size(); }
    const EpubPage* getPage(int page, const FileToStringHandler &fileToStringHandler, const ImageHandler &imageHandler);
    const EpubPage* getPage(int page);
    const Array<EpubPage>& getPages() const { return pages; }

    const JString& getCover() const { return cover; }
};