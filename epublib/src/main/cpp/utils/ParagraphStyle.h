//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_PARAGRAPHSTYLE_H
#define TEXTREADER_PARAGRAPHSTYLE_H
#pragma once
#include "TextUnit.h"

class ParagraphStyle {
private:
    TextUnit lineHeight;
public:
    ParagraphStyle() {}
    ParagraphStyle(const TextUnit& lineHeight): lineHeight(lineHeight) {}
    const TextUnit& getLineHeight() const { return lineHeight; }
};


#endif //TEXTREADER_PARAGRAPHSTYLE_H
