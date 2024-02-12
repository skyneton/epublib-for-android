//
// Created by skyne on 2023-11-13.
//

#ifndef TEXTREADER_CSSMAP_H
#define TEXTREADER_CSSMAP_H

#include "unordered_map"
#include "vector"
#include "CssNode.h"

class CssMap {
private:
    CssNode node;
    std::unordered_map<JString, std::vector<CssNode>> annotations;
    JString href;
public:
    CssMap(const JString& href): href(href) {}
    void append(const JString& annotation, const CssNode& x);
    CssNode* getNode(const Array<CssSelector>& selector);
    std::unordered_set<CssNode*> filter(const CssSelector& selector) const;
    std::unordered_set<CssNode*> filter(const JString& elementName, const JString& id, const JString& className) const;
    const std::unordered_map<JString, std::vector<CssNode>>& getAnnotations() const { return annotations; }
    const std::unordered_map<JString, JString>& getStyles() const { return node.getStyles(); }
    const std::unordered_map<JString, std::unordered_set<CssNode>>& getChildren() const { return node.getChildren(); }
    const JString& getHref() const { return href; }
    static CssMap* fromText(const JString& href, const JString& text, int start);
    static CssMap* fromText(const JString& href, const unsigned short* text, int start, int length);
    static std::unordered_map<JString, JString>& getInheritanceStyles(std::unordered_map<JString, JString>& dest, const std::unordered_map<JString, JString> &src);
};

#endif //TEXTREADER_CSSMAP_H
