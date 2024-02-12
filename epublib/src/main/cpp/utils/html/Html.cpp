//
// Created by skyne on 2024-02-02.
//
#include "Html.h"
#include "../utils.h"
#include "decode/LowerEntities.h"
#include "decode/UpperEntities.h"
#include "../JStringBuilder.h"

namespace Html {
    int entityHexNumber(const JString& str, int& start, int end) {
        int begin = start;
        int number = 0;
        int right = std::max(end, start + 6);
        const unsigned short* ptr = str.begin();
        for(; start < right; start++) {
            unsigned short c = ptr[start];
            if('0' <= c && c <= '9') number = (number << 4) + (c & 15);
            else if('a' <= c && c <= 'z') number = (number << 4) + (c - 'a' + 10);
            else if('A' <= c && c <= 'Z') number = (number << 4) + (c - 'A' + 10);
            else break;
        }
        if(start <= begin) return -1;
        if(start < end && ptr[start] == ';') start++;
        return number >= 0 ? number : -1;
    }

    int entityNumber(const JString& str, int& start, int end) {
        if(utils::lower(str[start]) == 'x') return entityHexNumber(str, ++start, end);
        int number = 0;
        int begin = start;
        int right = std::min(end, start + 7);
        const unsigned short* ptr = str.begin();
        for(; start < right; start++) {
            if(!('0' <= ptr[start] && ptr[start] <= '9')) break;
            number = number * 10 + (ptr[start] & 15);
        }
        if(start <= begin) return -1;
        if(start < end && ptr[start] == ';') start++;
        return number >= 0 ? number : -1;
    }

    int switchEntityPrefix(const JString& str, int& start, int end) {
        switch(str[start++]) {
            case '#': return entityNumber(str, start, end);
            case 'A': return entityUpperA(str, start, end);
            case 'B': return entityUpperB(str, start, end);
            case 'C': return entityUpperC(str, start, end);
            case 'D': return entityUpperD(str, start, end);
            case 'E': return entityUpperE(str, start, end);
            case 'F': return entityUpperF(str, start, end);
            case 'G': return entityUpperG(str, start, end);
            case 'H': return entityUpperH(str, start, end);
            case 'I': return entityUpperI(str, start, end);
            case 'J': return entityUpperJ(str, start, end);
            case 'K': return entityUpperK(str, start, end);
            case 'L': return entityUpperL(str, start, end);
            case 'M': return entityUpperM(str, start, end);
            case 'N': return entityUpperN(str, start, end);
            case 'O': return entityUpperO(str, start, end);
            case 'P': return entityUpperP(str, start, end);
            case 'Q': return entityUpperQ(str, start, end);
            case 'R': return entityUpperR(str, start, end);
            case 'S': return entityUpperS(str, start, end);
            case 'T': return entityUpperT(str, start, end);
            case 'U': return entityUpperU(str, start, end);
            case 'V': return entityUpperV(str, start, end);
            case 'W': return entityUpperW(str, start, end);
            case 'X': return entityUpperX(str, start, end);
            case 'Y': return entityUpperY(str, start, end);
            case 'Z': return entityUpperZ(str, start, end);

            case 'a': return entityLowerA(str, start, end);
            case 'b': return entityLowerB(str, start, end);
            case 'c': return entityLowerC(str, start, end);
            case 'd': return entityLowerD(str, start, end);
            case 'e': return entityLowerE(str, start, end);
            case 'f': return entityLowerF(str, start, end);
            case 'g': return entityLowerG(str, start, end);
            case 'h': return entityLowerH(str, start, end);
            case 'i': return entityLowerI(str, start, end);
            case 'j': return entityLowerJ(str, start, end);
            case 'k': return entityLowerK(str, start, end);
            case 'l': return entityLowerL(str, start, end);
            case 'm': return entityLowerM(str, start, end);
            case 'n': return entityLowerN(str, start, end);
            case 'o': return entityLowerO(str, start, end);
            case 'p': return entityLowerP(str, start, end);
            case 'q': return entityLowerQ(str, start, end);
            case 'r': return entityLowerR(str, start, end);
            case 's': return entityLowerS(str, start, end);
            case 't': return entityLowerT(str, start, end);
            case 'u': return entityLowerU(str, start, end);
            case 'v': return entityLowerV(str, start, end);
            case 'w': return entityLowerW(str, start, end);
            case 'x': return entityLowerX(str, start, end);
            case 'y': return entityLowerY(str, start, end);
            case 'z': return entityLowerZ(str, start, end);
        }
        return -1;
    }

    JString decodeHtml(const JString& str, int start, int end) {
        JStringBuilder builder;
        start = std::max(0, std::min(str.size(), start));
        end = end < 0 ? str.size() : std::max(start, std::min(str.size(), end));
        if(start >= end) return JString();
        int pos_start = start, pos_end, entity_pos, entity;
        while((pos_end = str.indexOf('&', pos_start, end, false)) >= 0) {
            entity_pos = pos_end + 1;
            if((entity = switchEntityPrefix(str, entity_pos, end)) != -1) {
                if(start < pos_end)
                    builder.append(str.substring(start, pos_end));

                if(entity < 0) {
                    entity = -entity - 0x10000;
                    builder.append((unsigned short)((entity >> 16) & 0xFFFF));
                    builder.append((unsigned short)(entity & 0xFFFF));
                }else if(entity > 0x10000) {
                    builder.append((unsigned short)((entity - 0x10000) / 0x400 + 0xD800));
                    builder.append((unsigned short)((entity - 0x10000) % 0x400 + 0xDC00));
                }else {
                    builder.append((unsigned short)entity);
                }
                pos_start = start = entity_pos;
                continue;
            }
            pos_start = pos_end + 1;
        }
        if(start == 0 && end == str.size()) return str;

        if(start < end) builder.append(str.substring(start, end));

        return builder.toString();
    }
}
