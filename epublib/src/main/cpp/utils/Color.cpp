//
// Created by skyne on 2023-12-26.
//

#include "Color.h"
#include "DefaultColor.h"
#include "utils.h"

void Color::save(ByteBuf &buf) const {
    buf.writeBool(specified);
    if(specified)
        buf.writeVarInt(getValue());
}

Color& Color::load(ByteBuf &buf) {
    specified = buf.readBool();
    if(specified)
        value = buf.readVarInt();
    return *this;
}

Color Color::convertToColor(const JString* value) {
    if(!value || value->empty()) return DefaultColor::Unspecified;
    if(value->startsWith("rgba(", true)) {
        Array<JString> data = value->substring(5, value->size() - 1).split(',');
        if(data.size() != 4) return DefaultColor::Unspecified;
        return Color(utils::clamp(static_cast<int>(data[0]->toDouble()), 0, 255),
                     utils::clamp(static_cast<int>(data[1]->toDouble()), 0, 255),
                     utils::clamp(static_cast<int>(data[2]->toDouble()), 0, 255),
                     utils::clamp(static_cast<int>(data[3]->toDouble()), 0, 255));
    }
    if(value->startsWith("rgb(", true)) {
        Array<JString> data = value->substring(4, value->size() - 1).split(',');
        if(data.size() != 3) return DefaultColor::Unspecified;
        return Color(utils::clamp(static_cast<int>(data[0]->toDouble()), 0, 255),
                     utils::clamp(static_cast<int>(data[1]->toDouble()), 0, 255),
                     utils::clamp(static_cast<int>(data[2]->toDouble()), 0, 255));
    }
    if(value->startsWith('#')) {
        if(!(value->size() == 7 || value->size() == 9)) return DefaultColor::Unspecified;
        return Color(value->substring(1, 3).hexToInt(),
                     value->substring(3, 5).hexToInt(),
                     value->substring(5, 7).hexToInt(),
                     value->size() == 9 ? value->substring(7, 9).hexToInt() : 0xFF);
    }
    JString color = value->lower();
    if(color == "white") return DefaultColor::White;
    if(color == "silver") return DefaultColor::Silver;
    if(color == "lightgray" || color == "lightgrey") return DefaultColor::LightGray;
    if(color == "gray" || color == "grey") return DefaultColor::Gray;
    if(color == "black") return DefaultColor::Black;
    if(color == "red") return DefaultColor::Red;
    if(color == "maroon") return DefaultColor::Maroon;
    if(color == "yellow") return DefaultColor::Yellow;
    if(color == "olive") return DefaultColor::Olive;
    if(color == "lime") return DefaultColor::Lime;
    if(color == "green") return DefaultColor::Green;
    if(color == "aqua") return DefaultColor::Aqua;
    if(color == "teal") return DefaultColor::Teal;
    if(color == "blue") return DefaultColor::Blue;
    if(color == "navy") return DefaultColor::Navy;
    if(color == "fuchsia") return DefaultColor::Fuchsia;
    if(color == "purple") return DefaultColor::Purple;
    if(color == "aliceblue") return DefaultColor::AliceBlue;
    if(color == "antiquewhite") return DefaultColor::AntiqueWhite;
    if(color == "aquamarine") return DefaultColor::Aquamarine;
    if(color == "azure") return DefaultColor::Azure;
    if(color == "beige") return DefaultColor::Beige;
    if(color == "bisque") return DefaultColor::Bisque;
    if(color == "blanchedalmond") return DefaultColor::BlanchedAlmond;
    if(color == "blueviolet") return DefaultColor::BlueViolet;
    if(color == "brown") return DefaultColor::Brown;
    if(color == "burlywood") return DefaultColor::BurlyWood;
    if(color == "cadetblue") return DefaultColor::CadetBlue;
    if(color == "chartreuse") return DefaultColor::ChartReuse;
    if(color == "chocolate") return DefaultColor::Chocolate;
    if(color == "coral") return DefaultColor::Coral;
    if(color == "cornflowerblue") return DefaultColor::CornflowerBlue;
    if(color == "cornsilk") return DefaultColor::CornSilk;
    if(color == "crimson") return DefaultColor::Crimson;
    if(color == "cyan") return DefaultColor::Cyan;
    if(color == "darkblue") return DefaultColor::DarkBlue;
    if(color == "darkcyan") return DefaultColor::DarkCyan;
    if(color == "darkgoldenrod") return DefaultColor::DarkGoldenrod;
    if(color == "darkgray" || color == "darkgrey") return DefaultColor::DarkGray;
    if(color == "darkgreen") return DefaultColor::DarkGreen;
    if(color == "darkkhaki") return DefaultColor::DarkKhaki;
    if(color == "darkmagenta") return DefaultColor::DarkMagenta;
    if(color == "darkolivegreen") return DefaultColor::DarkOliveGreen;
    if(color == "darkorange") return DefaultColor::DarkOrange;
    if(color == "darkorchid") return DefaultColor::DarkOrchid;
    if(color == "darkred") return DefaultColor::DarkRed;
    if(color == "darksalmon") return DefaultColor::DarkSalmon;
    if(color == "darkseagreen") return DefaultColor::DarkSeaGreen;
    if(color == "darkslategray" || color == "darkslategrey") return DefaultColor::DarkSlateGray;
    if(color == "darkturquoise") return DefaultColor::DarkTurquoise;
    if(color == "darkviolet") return DefaultColor::DarkViolet;
    if(color == "deeppink") return DefaultColor::DeepPink;
    if(color == "deepskyblue") return DefaultColor::DeepSkyBlue;
    if(color == "dimgray" || color == "dimgray") return DefaultColor::DimGray;
    if(color == "dodgerblue") return DefaultColor::DodgerBlue;
    if(color == "firebrick") return DefaultColor::Firebrick;
    if(color == "floralwhite") return DefaultColor::FloralWhite;
    if(color == "forestgreen") return DefaultColor::ForestGreen;
    if(color == "gainsboro") return DefaultColor::GainsBoro;
    if(color == "ghostwhite") return DefaultColor::GhostWhite;
    if(color == "gold") return DefaultColor::Gold;
    if(color == "goldenrod") return DefaultColor::Goldenrod;
    if(color == "greenyellow") return DefaultColor::GreenYellow;
    if(color == "honeydew") return DefaultColor::Honeydew;
    if(color == "hotpink") return DefaultColor::HotPink;
    if(color == "indianred") return DefaultColor::IndianRed;
    if(color == "indigo") return DefaultColor::Indigo;
    if(color == "ivory") return DefaultColor::Ivory;
    if(color == "khaki") return DefaultColor::Khaki;
    if(color == "lavender") return DefaultColor::Lavender;
    if(color == "lavenderblush") return DefaultColor::LavenderBlush;
    if(color == "lawngreen") return DefaultColor::LawnGreen;
    if(color == "lemonchiffon") return DefaultColor::LemonChiffon;
    if(color == "lightblue") return DefaultColor::LightBlue;
    if(color == "lightcoral") return DefaultColor::LightCoral;
    if(color == "lightcyan") return DefaultColor::LightCyan;
    if(color == "lightgoldenrodyellow") return DefaultColor::LightGoldenrodYellow;
    if(color == "lightgreen") return DefaultColor::LightGreen;
    if(color == "lightpink") return DefaultColor::LightPink;
    if(color == "lightsalmon") return DefaultColor::LightSalmon;
    if(color == "lightseagreen") return DefaultColor::LightSeaGreen;
    if(color == "lightskyblue") return DefaultColor::LightSkyBlue;
    if(color == "lightslategray" || color == "lightslategrey") return DefaultColor::LightSlateGray;
    if(color == "lightsteelblue") return DefaultColor::LightSteelBlue;
    if(color == "lightyellow") return DefaultColor::LightYellow;
    if(color == "limegreen") return DefaultColor::LimeGreen;
    if(color == "linen") return DefaultColor::Linen;
    if(color == "magenta") return DefaultColor::Magenta;
    if(color == "mediumaquamarine") return DefaultColor::MediumAquamarine;
    if(color == "mediumblue") return DefaultColor::MediumBlue;
    if(color == "mediumorchid") return DefaultColor::MediumOrchid;
    if(color == "mediumpurple") return DefaultColor::MediumPurple;
    if(color == "mediumseagreen") return DefaultColor::MediumSeaGreen;
    if(color == "mediumslateblue") return DefaultColor::MediumSlateBlue;
    if(color == "mediumspringgreen") return DefaultColor::MediumSpringGreen;
    if(color == "mediumturquoise") return DefaultColor::MediumTurquoise;
    if(color == "mediumvioletred") return DefaultColor::MediumVioletRed;
    if(color == "midnightblue") return DefaultColor::MidnightBlue;
    if(color == "mintcream") return DefaultColor::MintCream;
    if(color == "mistyrose") return DefaultColor::MistyRose;
    if(color == "moccasin") return DefaultColor::Moccasin;
    if(color == "navajowhite") return DefaultColor::NavajoWhite;
    if(color == "oldlace") return DefaultColor::OldLace;
    if(color == "olivedrab") return DefaultColor::OliveDrab;
    if(color == "orange") return DefaultColor::Orange;
    if(color == "orangered") return DefaultColor::OrangeRed;
    if(color == "orchid") return DefaultColor::Orchid;
    if(color == "palegoldenrod") return DefaultColor::PaleGoldenrod;
    if(color == "palegreen") return DefaultColor::PaleGreen;
    if(color == "paleturquoise") return DefaultColor::PaleTurquoise;
    if(color == "palevioletred") return DefaultColor::PaleVioletRed;
    if(color == "papayawhip") return DefaultColor::PapayaWhip;
    if(color == "peachpuff") return DefaultColor::PeachPuff;
    if(color == "peru") return DefaultColor::Peru;
    if(color == "pink") return DefaultColor::Pink;
    if(color == "plum") return DefaultColor::Plum;
    if(color == "powderblue") return DefaultColor::PowderBlue;
    if(color == "rebeccapurple") return DefaultColor::RebeccaPurple;
    if(color == "rosybrown") return DefaultColor::RosyBrown;
    if(color == "royalblue") return DefaultColor::RoyalBlue;
    if(color == "saddlebrown") return DefaultColor::SaddleBrown;
    if(color == "salmon") return DefaultColor::Salmon;
    if(color == "sandybrown") return DefaultColor::SandyBrown;
    if(color == "seagreen") return DefaultColor::SeaGreen;
    if(color == "seashell") return DefaultColor::Seashell;
    if(color == "sienna") return DefaultColor::Sienna;
    if(color == "skyblue") return DefaultColor::SkyBlue;
    if(color == "slateblue") return DefaultColor::SlateBlue;
    if(color == "slategray" || color == "slategrey") return DefaultColor::SlateGray;
    if(color == "snow") return DefaultColor::Snow;
    if(color == "springgreen") return DefaultColor::SpringGreen;
    if(color == "steelblue") return DefaultColor::SteelBlue;
    if(color == "tan") return DefaultColor::Tan;
    if(color == "thistle") return DefaultColor::Thistle;
    if(color == "tomato") return DefaultColor::Tomato;
    if(color == "turquoise") return DefaultColor::Turquoise;
    if(color == "violet") return DefaultColor::Violet;
    if(color == "wheat") return DefaultColor::Wheat;
    if(color == "whitesmoke") return DefaultColor::WhiteSmoke;
    if(color == "yellowgreen") return DefaultColor::YellowGreen;

    return DefaultColor::Unspecified;
}
