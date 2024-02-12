//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_TEXTUNIT_H
#define TEXTREADER_TEXTUNIT_H
#pragma once

#include "ByteBuf.h"
#include "JString.h"

class TextUnit {
private:
    float value;
    bool isEm;
    bool specified;
    const static int DefaultPx = 16;
    constexpr const static float LineHeightDifferFontSize = 1.33F;
public:
    TextUnit(int value, bool isEm): value(*(float*)&value), isEm(isEm), specified(true) {}
    TextUnit(): specified(false), value(-128), isEm(false) {}
    TextUnit(float value, bool isEm): specified(true), value(value), isEm(isEm) {}
    bool isSpecified() const { return specified; }
    bool isUnSpecified() const { return !specified; }
    bool isEmValue() const { return isEm; }
    bool isSpValue() const { return !isEm; }
    float getValue() const { return value; }
    int getIntValue() const { return *(int*)&value; }

    bool operator==(const TextUnit& other) const { return isUnSpecified() && other.isUnSpecified() || value == other.value && isEm == other.isEm; }
    bool operator!=(const TextUnit& other) const { return !(*this == other); }

    void save(ByteBuf &buf) const;
    TextUnit& load(ByteBuf &buf);

    static TextUnit toTextUnit(const JString* text);

    float toPx(float textSize, float fontScale, float density, bool unspecifiedZero = false) const;
    TextUnit apply(TextUnit fontSize) const;
};

TextUnit operator*(const TextUnit& a, float b);
TextUnit operator*(float a, const TextUnit& b);

namespace DefaultTextUnit {
    const static TextUnit Unspecified = TextUnit();
    const static TextUnit Zero = TextUnit(0, true);
}
#endif //TEXTREADER_TEXTUNIT_H
