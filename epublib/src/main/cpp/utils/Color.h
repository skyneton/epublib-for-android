//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_COLOR_H
#define TEXTREADER_COLOR_H
#pragma once

#include "ByteBuf.h"

class Color {
private:
    unsigned int value;
    bool specified;
public:
    Color(unsigned int value): value(value), specified(true) {}
    Color(): value(0), specified(false) {}
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255): value(((unsigned int) a << 24) | ((unsigned int) r << 16) | ((unsigned int) g << 8) | ((unsigned int) b)), specified(true) {}
    bool operator==(const Color& other) const { return value == other.value && specified == other.specified; }
    bool operator!=(const Color& other) const { return value != other.value || specified != other.specified; }
    unsigned int getValue() const { return value; }
    bool isSpecified() const { return specified; }

    void save(ByteBuf &buf) const;
    Color& load(ByteBuf &buf);

    static Color convertToColor(const JString* value);
};
#endif //TEXTREADER_COLOR_H
