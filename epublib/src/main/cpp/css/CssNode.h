//
// Created by skyne on 2023-11-13.
//

#ifndef TEXTREADER_CSSNODE_H
#define TEXTREADER_CSSNODE_H

#include "unordered_map"
#include "unordered_set"
#include "vector"
#include "CssSelector.h"

class CssNode {
private:
    CssSelector selector;
    std::unordered_map<JString, std::unordered_set<CssNode>>children;
    std::unordered_map<JString, JString>styles;
public:
    CssNode() {}
    CssNode(const CssSelector selector): selector(selector) {}
    const CssSelector& getSelector() const { return selector; }
    const std::unordered_map<JString, JString>& getStyles() const { return styles; }
    const std::unordered_map<JString, std::unordered_set<CssNode>>& getChildren() const { return children; }

    void append(const JString& key, const JString& value);
    void appendAll(const std::unordered_map<JString, JString>& map);
    CssNode* getNode(const CssSelector& selector);
    CssNode* getNode(const Array<CssSelector>& selector);
    std::unordered_set<CssNode*> filter(const CssSelector& select) const;
    std::unordered_set<CssNode*> filter(const JString& elementName, const JString& idName, const JString& className) const;
    std::unordered_set<CssNode*>& filter(const CssSelector& select, std::unordered_set<CssNode*>& list) const;
    std::unordered_set<CssNode*>& filter(const JString& elementName, const JString& idName, const JString& className, std::unordered_set<CssNode*>& list) const;

    size_t hashCode() const {
        return selector.hashCode();
    }

    bool operator<(const CssNode& other) const {
        return this->hashCode() < other.hashCode();
    }
    bool operator>(const CssNode& other) const {
        return this->hashCode() > other.hashCode();
    }
    bool operator==(const CssNode& other) const {
        return selector == other.selector;
    }
    bool contains(const CssNode& other) const {
        return selector.contains(other.selector);
    }
    bool contains(const CssSelector& select) const {
        return selector.contains(select);
    }
    bool contains(const JString& elementName, const JString& id, const JString& className) const {
        return selector.contains(elementName, id, className);
    }
};

template<>
class std::hash<CssNode> {
public:
    size_t operator()(const CssNode& o) const {
        return o.hashCode();
    }
};

#endif //TEXTREADER_CSSNODE_H
