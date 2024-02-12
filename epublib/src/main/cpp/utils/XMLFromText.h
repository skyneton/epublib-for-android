//
// Created by skyne on 2023-12-25.
//

#pragma once

#include "JString.h"
#include "unordered_map"
#include "functional"

#ifndef TEXTREADER_XMLFROMTEXT_H
#define TEXTREADER_XMLFROMTEXT_H

#endif //TEXTREADER_XMLFROMTEXT_H

typedef std::function<void (const JString&)> StringHandler;
typedef std::function<void (const JString&, bool, bool, std::unordered_map<JString, JString>&)> TagHandler;

void xmlFromText(const JString& text, const StringHandler stringHandler, const TagHandler tagHandler);
void xmlFromText(const unsigned short* text, int length, const StringHandler stringHandler, const TagHandler tagHandler);