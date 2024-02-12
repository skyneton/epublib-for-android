//
// Created by skyne on 2023-11-13.
//

#include <android/log.h>
#include "CssMap.h"
#include "../utils/utils.h"
#include "../utils/Array.h"
#include "../utils/JStringBuilder.h"

void CssMap::append(const JString& annotation, const CssNode& x) {
    annotations[annotation].emplace_back(x);
}

CssNode* CssMap::getNode(const Array<CssSelector> &selector) {
    return node.getNode(selector);
}

std::unordered_set<CssNode*> CssMap::filter(const CssSelector &selector) const {
    return node.filter(selector);
}

std::unordered_set<CssNode*>
CssMap::filter(const JString &elementName, const JString &id, const JString &className) const {
    return node.filter(elementName, id, className);
}

std::vector<Array<CssSelector>> parseTagSelector(const unsigned short* text, int& idx, int end) {
    std::vector<Array<CssSelector>> result;
    std::vector<CssSelector>list;
    JString elementName, idName, className;
    int partInfo = 0;
    JStringBuilder builder;
    bool commentSection = 0;
    idx = utils::skipWhiteSpace(text, idx, end) - 1;
    while(++idx < end) {
        unsigned short c = text[idx];
        if(commentSection && c != '/') continue;
        switch(c) {
            case '/':
                if(!commentSection && idx + 1 < end && text[idx + 1] == '*' || commentSection && idx > 0 && text[idx - 1] == '*') {
                    commentSection = !commentSection;
                    if(!commentSection) idx = std::max(idx, utils::skipWhiteSpace(text, idx + 1, end) - 1);
                    continue;
                }
                break;
            case '.':
                if(!builder.empty()) {
                    if(partInfo == 0) elementName = builder.toString();
                    else if(partInfo == 1) idName = builder.toString();
                }
                partInfo = 2;
                builder.clear();
                continue;
            case '#':
                if(!builder.empty()) {
                    if(partInfo == 0) elementName = builder.toString();
                    else if(partInfo == 2) className = builder.toString();
                }
                partInfo = 1;
                builder.clear();
                continue;
            case ' ':
                if(!builder.empty()) {
                    if(partInfo == 0) elementName = builder.toString();
                    else if(partInfo == 1) idName = builder.toString();
                    else className = builder.toString();
                }
                if(!elementName.empty() || !idName.empty() || !className.empty()) {
                    list.emplace_back(elementName.empty() ? '*' : elementName,
                                      idName.empty() ? '*' : idName,
                                      className.empty() ? '*' : className);
                }
                partInfo = 0;
                elementName = {};
                idName = {};
                className = {};
                builder.clear();
                continue;
            case ',':
                if(!builder.empty()) {
                    if(partInfo == 0) elementName = builder.toString();
                    else if(partInfo == 1) idName = builder.toString();
                    else className = builder.toString();
                }
                if(!elementName.empty() || !idName.empty() || !className.empty()) {
                    list.emplace_back(elementName.empty() ? '*' : elementName,
                                      idName.empty() ? '*' : idName,
                                      className.empty() ? '*' : className);
                }
                partInfo = 0;
                elementName = {};
                idName = {};
                className = {};
                builder.clear();
                result.emplace_back(list.data(), list.size());
                list.clear();
                idx = std::max(idx, utils::skipWhiteSpace(text, idx + 1, end) - 1);
                continue;
                case '{': case ';': goto finish;
        }
        builder += c;
    }
    finish:
    if(!builder.empty()) {
        if(partInfo == 0) elementName = builder.toString();
        else if(partInfo == 1) idName = builder.toString();
        else className = builder.toString();
    }
    if(!elementName.empty() || !idName.empty() || !className.empty()) {
        list.emplace_back(elementName.empty() ? '*' : elementName,
                          idName.empty() ? '*' : idName,
                          className.empty() ? '*' : className);
    }
    if(!list.empty())
        result.emplace_back(list.data(), list.size());
    return result;
}

bool parseBody(const unsigned short* text, int& idx, int end, std::unordered_map<JString, JString>& body) {
    unsigned short openTextChar = 0;
    JStringBuilder builder;
    JString key;
    bool isValuePart = 0, commentSection = 0;
    idx = utils::skipWhiteSpace(text, idx, end) - 1;
    while(++idx < end) {
        unsigned short c = text[idx];
        if(commentSection && c != '/') continue;
        switch (c) {
            case '/':
                if(!commentSection && idx + 1 < end && text[idx + 1] == '*' || commentSection && idx > 0 && text[idx - 1] == '*') {
                    commentSection = !commentSection;
                    continue;
                }
                break;
            case '"': case '\'':
                if(!openTextChar) {
                    openTextChar = c;
                    continue;
                }
                if(openTextChar == c) {
                    openTextChar = 0;
                    continue;
                }
                break;
            case ':':
                if(openTextChar) break;
                if(isValuePart) {
                    __android_log_write(ANDROID_LOG_ERROR, "NATIVE_CSS_BODY", utils::format("ERROR 1 %d", idx).c_str());
                    return false;
                }
                key = builder.lower().toString();
                isValuePart = true;
                idx = std::max(idx, utils::skipWhiteSpace(text, idx + 1, end) - 1);
                builder.clear();
                continue;
            case ';':
                if(openTextChar) break;
                if(!isValuePart) {
                    __android_log_write(ANDROID_LOG_ERROR, "NATIVE_CSS_BODY", utils::format("ERROR 2 %d", idx).c_str());
                    return false;
                }
                if(!key.empty())
                    body[key] = builder.toString();
                builder.clear();
                isValuePart = false;
                idx = std::max(idx, utils::skipWhiteSpace(text, idx + 1, end) - 1);
                key = {};
                continue;
            case '}':
                goto finish;
        }
        builder += c;
    }
    finish:
    if(!key.empty() && !builder.empty() && isValuePart)
        body[key] = builder.toString();

    return true;
}

CssMap* CssMap::fromText(const JString& href, const unsigned short* text, int start, int length) {
    int idx = utils::skipWhiteSpace(text, start, length) - 1;
    CssMap* cssMap = new CssMap(href);
    while(++idx < length) {
        auto selectorList = parseTagSelector(text, idx, length);
        if(selectorList.size() == 1 && !selectorList[0].empty() && selectorList[0][0]->getElementName().startsWith('@')) {
            JString annotation = selectorList[0][0]->getElementName().substr(1).lower();
            CssNode node;
            if(selectorList[0].size() > 1) {
                if(annotation != "font-face" && annotation != "charset") {
                    while(1) {
                        idx = std::max(idx + 1, utils::skipWhiteSpace(text, idx + 1, length) - 1);
                        if(idx + 1 >= length || text[idx + 1] == '}') break;

                        auto annoSelectorList = parseTagSelector(text, ++idx, length);
                        std::unordered_map<JString, JString>body;
                        if(!parseBody(text, ++idx, length, body)) {
                            delete cssMap;
                            return nullptr;
                        }
                        for(const Array<CssSelector> &selector : annoSelectorList) {
                            node.getNode(selector)->appendAll(body);
                        }
                    }
                    idx++;
                }else node.append(annotation, selectorList[0][1]->getElementName());
            }else {
                std::unordered_map<JString, JString>body;
                if(!parseBody(text, ++idx, length, body)) {
                    delete cssMap;
                    return nullptr;
                }
                node.appendAll(body);
            }
            cssMap->append(annotation, node);
            idx = std::max(idx + 1, utils::skipWhiteSpace(text, idx + 1, length) - 1);
            continue;
        }
        std::unordered_map<JString, JString>body;
        if(!parseBody(text, ++idx, length, body)) {
            delete cssMap;
            return nullptr;
        }
        for(const Array<CssSelector>& selector : selectorList) {
            cssMap->getNode(selector)->appendAll(body);
        }
        idx = std::max(idx + 1, utils::skipWhiteSpace(text, idx + 1, length) - 1);
    }
    return cssMap;
}

CssMap* CssMap::fromText(const JString& href, const JString& text, int start) { return fromText(href, text.begin(), start, text.size()); }

std::unordered_map<JString, JString>& CssMap::getInheritanceStyles(std::unordered_map<JString, JString>& dest,
                                  const std::unordered_map<JString, JString>& src) {
    static const Array<JString> inheritanceStyles = { "font-family", "font-size", "font-style", "font-weight", "font", "letter-spacing", "line-height", "color" };
    for(const JString& inheritance : inheritanceStyles) {
        auto it = src.find(inheritance);
        if(it == src.end()) continue;
        dest[it->first] = it->second;
    }
    return dest;
}