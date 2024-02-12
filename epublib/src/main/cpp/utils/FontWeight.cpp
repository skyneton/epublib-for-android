//
// Created by skyne on 2023-12-26.
//

#include "FontWeight.h"

FontWeight FontWeight::toFontWeight(const JString *text) {
    if(!text || text->empty()) return DefaultFontWeight::Normal;
    if(text->equals("bold", true) || text->equals("bolder", true))
        return DefaultFontWeight::Bold;
    if(text->equals("normal", true)) return DefaultFontWeight::Normal;
    if(text->equals("lighter", true)) return DefaultFontWeight::Light;
    return FontWeight(static_cast<int>(text->toDouble()));
}