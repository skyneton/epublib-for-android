//
// Created by skyne on 2023-12-25.
//
#include "XMLFromText.h"
#include "utils.h"
#include "JStringBuilder.h"
#include "algorithm"
#include "html/Html.h"

std::tuple<JString, bool, bool> parseElement(const unsigned short* text, int &index, int end, std::unordered_map<JString, JString>& attributes) {
    index = utils::skipWhiteSpace(text, index + 1, end) - 1;
    unsigned short openTextChar = 0;
    JString tagName, key;
    JStringBuilder builder;
    bool isValuePart = 0, isOpenClose = 0, isClose = 0;
    while(++index < end) {
        unsigned short c = text[index];
        switch (c) {
            case '<':
                if(openTextChar) break;
                --index;
                return {{}, 0, 0};
            case '>':
                if(openTextChar) break;
                goto finish;
            case ' ':
                if(openTextChar) break;
                if(tagName.empty()) {
                    if(builder.empty()) return {{}, 0, 0};
                    tagName = builder.lower().toString();
                }
                else if(!isValuePart) {
                    if(!key.empty()) {
                        attributes[key] = {};
                    }
                    key = builder.lower().toString();
                }
                else if(!key.empty()) {
                    attributes[key] = builder.toString();
                }
                builder.clear();
                index = std::max(index, utils::skipWhiteSpace(text, index + 1, end) - 1);
                continue;
            case '"': case '\'':
                if(tagName.empty() || !isValuePart) return {{}, 0, 0};
                if(builder.empty() && !openTextChar) {
                    openTextChar = c;
                    continue;
                }
                if(openTextChar == c) {
                    openTextChar = 0;
                    if(!key.empty()) {
                        attributes[key] = builder.toString();
                    }
                    isValuePart = false;
                    key = {};
                    builder.clear();
                    index = std::max(index, utils::skipWhiteSpace(text, index + 1, end) - 1);
                    continue;
                }
                break;
            case '=':
                if(tagName.empty()) return {{}, 0, 0};
                if(!isValuePart) {
                    isValuePart = true;
                    key = builder.lower().toString();
                    builder.clear();
                    continue;
                }
            case '/':
                if(!openTextChar) {
                    if(tagName.empty() && builder.empty()) isClose = true;
                    else isOpenClose = true;
                    index = std::max(index, utils::skipWhiteSpace(text, index + 1, end) - 1);
                    continue;
                }
                break;
        }
        builder += c;
    }
    finish:
    if(!builder.empty()) {
        if(tagName.empty()) tagName = builder.lower().toString();
        else if(!isValuePart) attributes[builder.lower().toString()] = {};
        else if(!key.empty()) attributes[key] = builder.lower().toString();
    }
    if(!tagName.empty()) tagName = tagName.trim();
    return { tagName, isOpenClose, isClose };
}

void xmlFromText(const unsigned short* text, int length, const StringHandler stringHandler, const TagHandler tagHandler) {
    int stringStartIdx = 0;
    int index = utils::skipWhiteSpace(text, 0, length);
    bool isPreBody = 0;
    if(text[index] == '<') {
        int xmlTagCheckIdx = utils::skipWhiteSpace(text, index + 1, length);
        if(text[xmlTagCheckIdx] == '?'
        || utils::lower(text[xmlTagCheckIdx]) == 'x' && utils::lower(text[xmlTagCheckIdx + 1]) == 'm' && utils::lower(text[xmlTagCheckIdx + 2]) == 'l') {
            index = std::max(index, utils::skipWhiteSpace(text, utils::indexOf(text, '>', 0, length) + 1, length));
            stringStartIdx = index;
        }
    }

    index--;
    while(++index < length) {
        switch (text[index]) {
            case '<':
                std::unordered_map<JString, JString> attributes;
                int stringLast = index;
                const auto [elementName, isOpenClose, isClose] = parseElement(text, index, length, attributes);
                if(elementName.empty()) continue;
                if(stringStartIdx < stringLast) {
                    JString string;
                    if (!isPreBody) {
                        JString s = Html::decodeHtml(JString(text + stringStartIdx, stringLast - stringStartIdx));
//                                .replace("&lt", '<')
//                                .replace("&gt;", '>')
//                                .replace("&nbsp;", 0x00A0)
//                                .replace("&#160;", 0x00A0)
//                                .replace("&#13;", '\r');

                        JStringBuilder normString;
                        int pos_start = 0;
                        int pos_end;
                        while((pos_end = s.indexOf('\n', pos_start, false)) >= 0) {
                            normString += ' ';
                            normString += s.substring(pos_start, pos_end).ltrim();
                            pos_start = pos_end + 1;
                        }
                        if(pos_start > 0 && pos_start < s.size()) {
                            normString += ' ';
                            normString += s.substr(pos_start).ltrim();
                        }
                        string = pos_start > 0 ? normString.ltrim().toString() : s;
                    }else string = Html::decodeHtml(JString(text + stringStartIdx, stringLast - stringStartIdx));
//                                .replace("&lt", '<')
//                                .replace("&gt;", '>')
//                                .replace("&nbsp;", 0x00A0)
//                                .replace("&#160;", 0x00A0)
//                                .replace("&#13;", '\r');
                    if(!string.empty())
                        stringHandler(string);
                }

                if(elementName == "pre")
                    isPreBody = !(isOpenClose || isClose);

                tagHandler(elementName, isOpenClose, isClose, attributes);
                stringStartIdx = index + 1;
                break;
        }
    }
    if(stringStartIdx < length) {
        JString string;
        if (!isPreBody) {
            JString s = Html::decodeHtml(JString(text + stringStartIdx, length - stringStartIdx));
//                    .replace("&lt", '<')
//                    .replace("&gt;", '>')
//                    .replace("&nbsp;", 0x00A0)
//                    .replace("&#160;", 0x00A0)
//                    .replace("&#13;", '\r');
            JStringBuilder normString;
            int pos_start = 0;
            int pos_end;
            while((pos_end = s.indexOf('\n', pos_start, false)) >= 0) {
                normString += ' ';
                normString += s.substr(pos_start, pos_end - pos_start).ltrim();
                pos_start = pos_end + 1;
            }
            if(pos_start > 0 && pos_start < s.size()) {
                normString += ' ';
                normString += s.substr(pos_start).ltrim();
            }
            string = pos_start > 0 ? normString.ltrim().toString() : s;
        }else string = Html::decodeHtml(JString(text + stringStartIdx, length - stringStartIdx));
//                    .replace("&lt", '<')
//                    .replace("&gt;", '>')
//                    .replace("&nbsp;", 0x00A0)
//                    .replace("&#160;", 0x00A0)
//                    .replace("&#13;", '\r');
        if(!string.empty())
            stringHandler(string);
    }
}

void xmlFromText(const JString& text, const StringHandler stringHandler, const TagHandler tagHandler) {
    xmlFromText(text.begin(), text.size(), stringHandler, tagHandler);
}