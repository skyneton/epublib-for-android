//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_SPANSTYLE_H
#define TEXTREADER_SPANSTYLE_H
#pragma once
#include "TextUnit.h"
#include "JString.h"
#include "Color.h"
#include "FontWeight.h"
#include "TextDecoration.h"

class SpanStyle {
private:
    JString fontFamily;
    Color color;
    TextUnit fontSize;
    FontWeight fontWeight;
    TextUnit letterSpacing;
    /*TextUnit wordSpacing;*/ //api ver >= 29
    TextDecoration textDecoration;
    bool italic;
public:
    SpanStyle() {}
    SpanStyle(const JString& fontFamily, const Color& color, const TextUnit& fontSize, const FontWeight& fontWeight, const TextUnit& letterSpacing, const TextDecoration& textDecoration, const bool isItalic):
    fontFamily(fontFamily), color(color), fontSize(fontSize), fontWeight(fontWeight), letterSpacing(letterSpacing), textDecoration(textDecoration), italic(isItalic) {}

    const JString& getFontFamily() const { return fontFamily; }
    const Color& getColor() const { return color; }
    const TextUnit& getFontSize() const { return fontSize; }
    const FontWeight& getFontWeight() const { return fontWeight; }
    const TextUnit& getLetterSpacing() const { return letterSpacing; }
    const TextDecoration& getTextDecoration() const { return textDecoration; }
    bool isItalic() const { return italic; }

    bool operator==(const SpanStyle& other) const;
    bool operator!=(const SpanStyle& other) const { return !(*this == other); }
};


#endif //TEXTREADER_SPANSTYLE_H
