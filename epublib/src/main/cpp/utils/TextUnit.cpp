//
// Created by skyne on 2023-12-26.
//

#include "TextUnit.h"

void TextUnit::save(ByteBuf &buf) const {
    if(isSpecified())
        buf.writeByte(static_cast<char>(isEm) + 1).writeVarInt(getIntValue());
    else
        buf.writeByte(0);
}

TextUnit& TextUnit::load(ByteBuf &buf) {
    char flag = buf.readByte();
    if(!flag) {
        value = -128;
        specified = false;
        return *this;
    }
    int intValue = buf.readVarInt();
    value = *(float*)&intValue;
    specified = true;
    isEm = flag - 1;
    return *this;
}

TextUnit TextUnit::toTextUnit(const JString *text) {
    if(!text || text->empty()) return DefaultTextUnit::Unspecified;
    if(text->endsWith("px", true))
        return {(float)(text->substring(0, text->size() - 2).toDouble() / DefaultPx), true};
    if(text->endsWith("em", true))
        return {(float)text->substring(0, text->size() - 2).toDouble(), true};
    if(text->endsWith('%'))
        return {(float)(text->substring(0, text->size() - 1).toDouble() / 100), true};
    return {(float)text->toDouble(), true};
}

float TextUnit::toPx(float textSize, float fontScale, float density, bool unspecifiedZero) const {
    if(isUnSpecified()) return unspecifiedZero ? 0 : textSize;
    return isEm ? (value * textSize) : (value * fontScale * density);
}

TextUnit TextUnit::apply(TextUnit fontSize) const {
    if(isUnSpecified()) return fontSize * LineHeightDifferFontSize;
    if(fontSize.isEm) return *this * (fontSize.value > 1 ? (fontSize.value - 1) * 0.7F + 1 : (fontSize.value * 1.03F));
    return *this * (fontSize.value / DefaultPx);
}

TextUnit operator*(const TextUnit& a, float b) {
    return { a.getValue() * b, a.isEmValue() };
}
TextUnit operator*(float a, const TextUnit& b) {
    return { a * b.getValue(), b.isEmValue() };
}