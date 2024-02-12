//
// Created by skyne on 2023-11-13.
//

#include "CssNode.h"

void CssNode::append(const JString &key, const JString &value) {
    this->styles[key] = value;
}

void CssNode::appendAll(const std::unordered_map<JString, JString>& map) {
    styles.insert(map.begin(), map.end());
}

CssNode* CssNode::getNode(const CssSelector &selector) {
    auto it = children.find(selector.getElementName());
    auto insert = CssNode(selector);
    if(it == children.end()) {
        return const_cast<CssNode *>(&*children[selector.getElementName()].insert(insert).first);
    }
    auto find = it->second.find(insert);
    if(find != it->second.end())
        return const_cast<CssNode *>(&*find);
    return const_cast<CssNode *>(&*it->second.insert(insert).first);
}

CssNode *CssNode::getNode(const Array<CssSelector>& selector) {
    CssNode* target = this;
    for(const CssSelector& select : selector) {
        target = target->getNode(select);
    }
    return target;
}

std::unordered_set<CssNode*> CssNode::filter(const CssSelector &select) const {
    std::unordered_set<CssNode*>v;
    auto it = children.find(select.getElementName());
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(select)) v.insert(const_cast<CssNode *>(&node));
        }
    }
    it = children.find('*');
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(select)) v.insert(const_cast<CssNode *>(&node));
        }
    }
    return v;
}

std::unordered_set<CssNode *>
CssNode::filter(const JString &elementName, const JString &idName, const JString &className) const {
    std::unordered_set<CssNode*>v;
    auto it = children.find(elementName);
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(elementName, idName, className))
                v.insert(const_cast<CssNode *>(&node));
        }
    }
    it = children.find('*');
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(elementName, idName, className))
                v.insert(const_cast<CssNode *>(&node));
        }
    }
    return v;
}

std::unordered_set<CssNode *> &
CssNode::filter(const CssSelector &select, std::unordered_set<CssNode *> &list) const {
    auto it = children.find(select.getElementName());
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(select)) list.insert(const_cast<CssNode *>(&node));
        }
    }
    it = children.find('*');
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(select)) list.insert(const_cast<CssNode *>(&node));
        }
    }
    return list;
}

std::unordered_set<CssNode *> &
CssNode::filter(const JString &elementName, const JString &idName, const JString &className,
                std::unordered_set<CssNode *> &list) const {
    auto it = children.find(elementName);
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(elementName, idName, className))
                list.insert(const_cast<CssNode *>(&node));
        }
    }
    it = children.find('*');
    if(it != children.end()) {
        for (const auto &node: it->second) {
            if (node.contains(elementName, idName, className))
                list.insert(const_cast<CssNode *>(&node));
        }
    }
    return list;
}