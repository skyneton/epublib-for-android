#pragma once
#include "../utils/JString.h"
#include "functional"
#include "../css/CssMap.h"
#include "EpubElement.h"

class EpubPage {
private:
    JString name;
    JString href;
    JString idRef;
    bool parsed = 0;
    Array<std::shared_ptr<EpubElement>> document;
public:
    typedef std::function<JString (const JString&)> FileToStringHandler;
    typedef std::function<Array<int> (const JString&)> ImageHandler;
    EpubPage() {}
    EpubPage(std::unordered_map<JString, std::shared_ptr<CssMap>>& cssCacheMap, const JString& href, const JString& idRef, const FileToStringHandler& fileToStringHandler, const ImageHandler& imageHandler, bool parseNow);

    void parse(std::unordered_map<JString, std::shared_ptr<CssMap>>& cssCacheMap, const FileToStringHandler &fileToStringHandler, const ImageHandler& imageHandler);

    JString& getName() { return name; }
    JString& setName(const JString& newName) { return name = newName; }

    JString& getIdRef() { return idRef; }
    JString& getHref() { return href; }

    const Array<std::shared_ptr<EpubElement>>& getDocument() const { return document; }
    void setDocument(Array<std::shared_ptr<EpubElement>>& loadDocument);
    const bool parse() const { return parsed; }
};