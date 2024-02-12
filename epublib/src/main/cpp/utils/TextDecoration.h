//
// Created by skyne on 2024-01-05.
//

#ifndef TEXTREADER_TEXTDECORATION_H
#define TEXTREADER_TEXTDECORATION_H


#include "ByteBuf.h"

class TextDecoration {
private:
    int mask;
public:
    TextDecoration(): mask(0) {}
    TextDecoration(int mask): mask(mask) {}
    int getMask() const { return mask; }

    bool operator==(const TextDecoration& other) const { return mask == other.mask; }
    bool operator!=(const TextDecoration& other) const { return !(*this == other); }

    void save(ByteBuf &buf) const;
    TextDecoration& load(ByteBuf &buf);
    static TextDecoration toTextDecoration(const JString* text);
};

namespace DefaultTextDecoration {
    const static TextDecoration None = TextDecoration(0);
    const static TextDecoration Underline = TextDecoration(0x1);
    const static TextDecoration LineThrough = TextDecoration(0x2);
}


#endif //TEXTREADER_TEXTDECORATION_H
