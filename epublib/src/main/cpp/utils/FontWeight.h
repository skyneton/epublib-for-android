//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_FONTWEIGHT_H
#define TEXTREADER_FONTWEIGHT_H
#include "JString.h"

class FontWeight {
private:
    int weight;
public:
    FontWeight(): weight(0) {}
    FontWeight(int weight): weight(weight) {}
    int getWeight() const { return weight; }
    bool isSpecified() const { return weight > 0; }
    bool isUnSpecified() const { return weight <= 0; }
    bool operator==(const FontWeight& other) const { return weight == other.weight; }
    bool operator!=(const FontWeight& other) const { return weight != other.weight; }

    static FontWeight toFontWeight(const JString* text);
};

namespace DefaultFontWeight {
    const static FontWeight Bold = FontWeight(700);
    const static FontWeight Normal = FontWeight(400);
    const static FontWeight Light = FontWeight(300);
}
#endif //TEXTREADER_FONTWEIGHT_H
