//
// Created by skyne on 2024-01-05.
//

#include "TextDecoration.h"

void TextDecoration::save(ByteBuf &buf) const {
    buf.writeVarInt(mask);
}

TextDecoration &TextDecoration::load(ByteBuf &buf) {
    mask = buf.readVarInt();
    return *this;
}

TextDecoration TextDecoration::toTextDecoration(const JString *text) {
    if(!text || text->empty()) return DefaultTextDecoration::None;
    int mask = 0;
    if(text->indexOf("underline", 0, true) >= 0)
        mask |= DefaultTextDecoration::Underline.getMask();
    if(text->indexOf("line-through", 0, true) >= 0)
        mask |= DefaultTextDecoration::LineThrough.getMask();
    return TextDecoration(mask);
}