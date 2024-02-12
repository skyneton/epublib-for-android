//
// Created by skyne on 2024-02-03.
//
#include "UpperEntities.h"

namespace Html {
    int entityUpperA(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch (str[start++]) {
            case 'E':
                if(str.startsIdx("lig", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 198;
                }
                break;
            case 'M':
                if(start < end && str[start] == 'P') {
                    start += 1 + (start + 1 < end && str[start + 1] == ';');
                    return 38;
                }
                break;
            case 'a':
                if(str.startsIdx("cute", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 193;
                }
                break;
            case 'b': if(str.startsIdx("reve;", start, end)) { start += 5; return 258; } break;
            case 'c':
                if(str.startsIdx("irc", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 194;
                }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1040; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120068; } break;
            case 'g':
                if(str.startsIdx("rave", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 192;
                }
                break;
            case 'l': if(str.startsIdx("pha;", start, end)) { start += 4; return 913; } break;
            case 'm': if(str.startsIdx("acr;", start, end)) { start += 4; return 256; } break;
            case 'n': if(str.startsIdx("d;", start, end)) { start += 2; return 10835; } break;
            case 'o':
                if(str.startsIdx("gon;", start, end)) { start += 4; return 260; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120120; }
                break;
            case 'p': if(str.startsIdx("plyFunction;", start, end)) { start += 12; return 8289; } break;
            case 'r':
                if(str.startsIdx("ing", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 197;
                }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119964; }
                if(str.startsIdx("sign;", start, end)) { start += 5; return 8788; }
                break;
            case 't':
                if(str.startsIdx("ilde", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 195;
                }
                break;
            case 'u':
                if(str.startsIdx("ml", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 196;
                }
                break;
        }
        return -1;
    }

    int entityUpperB(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("ckslash;", start, end)) { start += 8; return 8726; }
                if(str.startsIdx("rv;", start, end)) { start += 3; return 10983; }
                if(str.startsIdx("rwed;", start, end)) { start += 5; return 8966; }
                break;
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1041; } break;
            case 'e':
                if(str.startsIdx("cause;", start, end)) { start += 6; return 8757; }
                if(str.startsIdx("rnoullis;", start, end)) { start += 9; return 8492; }
                if(str.startsIdx("ta;", start, end)) { start += 3; return 914; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120069; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120121; } break;
            case 'r': if(str.startsIdx("eve;", start, end)) { start += 4; return 728; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 8492; } break;
            case 'u': if(str.startsIdx("mpeq;", start, end)) { start += 5; return 8782; } break;
        }
        return -1;
    }

    int entityUpperC(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'H': if(str.startsIdx("cy;", start, end)) { start += 3; return 1063; } break;
            case 'O':
                if(str.startsIdx("PY", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 169;
                }
                break;
            case 'a':
                if(str.startsIdx("cute;", start, end)) { start += 5; return 262; }
                if(str.startsIdx("p;", start, end)) { start += 2; return 8914; }
                if(str.startsIdx("pitalDifferentialD;", start, end)) { start += 19; return 8517; }
                if(str.startsIdx("yleys;", start, end)) { start += 6; return 8493; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 268; }
                if(str.startsIdx("edil", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 199; }
                if(str.startsIdx("irc;", start, end)) { start += 4; return 264; }
                if(str.startsIdx("onint;", start, end)) { start += 6; return 8752; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 266; } break;
            case 'e':
                if(str.startsIdx("dilla;", start, end)) { start += 6; return 184; }
                if(str.startsIdx("nterDot;", start, end)) { start += 8; return 183; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 8493; } break;
            case 'h': if(str.startsIdx("i;", start, end)) { start += 2; return 935; } break;
            case 'i':
                if(str.startsIdx("rcle", start, end)) {
                    start += 4;
                    if(str.startsIdx("Dot;", start, end)) { start += 4; return 8857; }
                    if(str.startsIdx("Minus;", start, end)) { start += 6; return 8854; }
                    if(str.startsIdx("Plus;", start, end)) { start += 5; return 8853; }
                    if(str.startsIdx("Times;", start, end)) { start += 6; return 8855; }
                }
                break;
            case 'l':
                if(start < end && str[start] == 'o') {
                    start++;
                    if(str.startsIdx("ckwiseContourIntegral;", start, end)) { start += 22; return 8754; }
                    if(str.startsIdx("seCurlyDoubleQuote;", start, end)) { start += 19; return 8221; }
                    if(str.startsIdx("seCurlyQuote;", start, end)) { start += 13; return 8217; }
                }
                break;
            case 'o':
                if(start >= end) break;
                switch(str[start++]) {
                    case 'l':
                        if(str.startsIdx("on", start, end)) {
                            start += 2;
                            if(start < end && str[start] == ';') { start++; return 8759; }
                            if(str.startsIdx("e;", start, end)) { start += 2; return 10868; }
                        }
                        break;
                    case 'n':
                        if(str.startsIdx("gruent;", start, end)) { start += 7; return 8801; }
                        if(str.startsIdx("int;", start, end)) { start += 4; return 8751; }
                        if(str.startsIdx("tourIntegral;", start, end)) { start += 13; return 8750; }
                        break;
                    case 'p':
                        if(str.startsIdx("f;", start, end)) { start += 2; return 8450; }
                        if(str.startsIdx("roduct;", start, end)) { start += 7; return 8720; }
                        break;
                    case 'u':
                        if(str.startsIdx("nterClockwiseContourIntegral;", start, end)) { start += 29; return 8755; }
                }
                break;
            case 'r': if(str.startsIdx("oss;", start, end)) { start += 4; return 10799; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119966; } break;
            case 'u':
                if(str.startsIdx("p;", start, end)) { start += 2; return 8915; }
                if(str.startsIdx("pCap;", start, end)) { start += 5; return 8781; }
                break;
        }
        return -1;
    }

    int entityUpperD(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'D':
                if(start < end && str[start] == ';') { start++; return 8517; }
                if(str.startsIdx("otrahd;", start, end)) { start += 7; return 10513; }
                break;
            case 'J': if(str.startsIdx("cy;", start, end)) { start += 3; return 1026; } break;
            case 'S': if(str.startsIdx("cy;", start, end)) { start += 3; return 1029; } break;
            case 'Z': if(str.startsIdx("cy;", start, end)) { start += 3; return 1039; } break;
            case 'a':
                if(str.startsIdx("gger;", start, end)) { start += 5; return 8225; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8609; }
                if(str.startsIdx("shv;", start, end)) { start += 4; return 10980; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 270; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1044; }
                break;
            case 'e':
                if(start < end && str[start] == 'l') {
                    start++;
                    if(start < end && str[start] == ';') { start++; return 8711; }
                    if(str.startsIdx("ta;", start, end)) { start += 3; return 916; }
                    break;
                }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120071; } break;
            case 'i':
                if(str.startsIdx("acritical", start, end)) {
                    start += 9;
                    if(str.startsIdx("Acute;", start, end)) { start += 6; return 180; }
                    if(str.startsIdx("Dot;", start, end)) { start += 4; return 729; }
                    if(str.startsIdx("DoubleAcute;", start, end)) { start += 12; return 733; }
                    if(str.startsIdx("Grave;", start, end)) { start += 6; return 96; }
                    if(str.startsIdx("Tilde;", start, end)) { start += 6; return 732; }
                    break;
                }
                if(str.startsIdx("amond;", start, end)) { start += 6; return 8900; }
                if(str.startsIdx("fferentialD;", start, end)) { start += 12; return 8518; }
                break;
            case 'o':
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120123; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 168; }
                if(str.startsIdx("tDot;", start, end)) { start += 5; return 8412; }
                if(str.startsIdx("tEqual;", start, end)) { start += 7; return 8784; }
                if(str.startsIdx("uble", start, end)) {
                    start += 4;
                    if(str.startsIdx("ContourIntegral;", start, end)) { start += 16; return 8751; }
                    if(str.startsIdx("Dot;", start, end)) { start += 4; return 168; }
                    if(str.startsIdx("DownArrow;", start, end)) { start += 10; return 8659; }
                    if(str.startsIdx("LeftArrow;", start, end)) { start += 10; return 8656; }
                    if(str.startsIdx("LeftRightArrow;", start, end)) { start += 15; return 8660; }
                    if(str.startsIdx("LeftTee;", start, end)) { start += 8; return 10980; }
                    if(str.startsIdx("LongLeftArrow;", start, end)) { start += 14; return 10232; }
                    if(str.startsIdx("LongLeftRightArrow;", start, end)) { start += 19; return 10234; }
                    if(str.startsIdx("LongRightArrow;", start, end)) { start += 15; return 10233; }
                    if(str.startsIdx("RightArrow;", start, end)) { start += 11; return 8658; }
                    if(str.startsIdx("RightTee;", start, end)) { start += 9; return 8872; }
                    if(str.startsIdx("UpArrow;", start, end)) { start += 8; return 8657; }
                    if(str.startsIdx("UpDownArrow;", start, end)) { start += 12; return 8661; }
                    if(str.startsIdx("VerticalBar;", start, end)) { start += 12; return 8741; }
                    break;
                }
                if(str.startsIdx("wn", start, end)) {
                    start += 2;
                    if(str.startsIdx("Arrow;", start, end)) { start += 6; return 8595; }
                    if(str.startsIdx("ArrowBar;", start, end)) { start += 9; return 10515; }
                    if(str.startsIdx("ArrowUpArrow;", start, end)) { start += 13; return 8693; }
                    if(str.startsIdx("Breve;", start, end)) { start += 6; return 785; }
                    if(str.startsIdx("LeftRightVector;", start, end)) { start += 16; return 10576; }
                    if(str.startsIdx("LeftTeeVector;", start, end)) { start += 14; return 10590; }
                    if(str.startsIdx("LeftVector;", start, end)) { start += 11; return 8637; }
                    if(str.startsIdx("LeftVectorBar;", start, end)) { start += 14; return 10582; }
                    if(str.startsIdx("RightTeeVector;", start, end)) { start += 15; return 10591; }
                    if(str.startsIdx("RightVector;", start, end)) { start += 12; return 8641; }
                    if(str.startsIdx("RightVectorBar;", start, end)) { start += 15; return 10583; }
                    if(str.startsIdx("Tee;", start, end)) { start += 4; return 8868; }
                    if(str.startsIdx("TeeArrow;", start, end)) { start += 9; return 8615; }
                    if(str.startsIdx("arrow;", start, end)) { start += 6; return 8659; }
                }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119967; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 272; }
                break;
        }
        return -1;
    }

    int entityUpperE(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'N': if(str.startsIdx("G;", start, end)) { start += 2; return 330; } break;
            case 'T':
                if(start < end && str[start] == 'H') {
                    start += 1 + (start + 1 < end && str[start + 1] == ';');
                    return 208;
                }
                break;
            case 'a':
                if(str.startsIdx("cute", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 201;
                }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 282; }
                if(str.startsIdx("irc", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 202;
                }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1069; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 278; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120072; } break;
            case 'g':
                if(str.startsIdx("rave", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 200;
                }
                break;
            case 'l': if(str.startsIdx("ement;", start, end)) { start += 6; return 8712; } break;
            case 'm':
                if(str.startsIdx("acr;", start, end)) { start += 4; return 274; }
                if(str.startsIdx("ptySmallSquare;", start, end)) { start += 15; return 9723; }
                if(str.startsIdx("ptyVerySmallSquare;", start, end)) { start += 19; return 9643; }
                break;
            case 'o':
                if(str.startsIdx("gon;", start, end)) { start += 4; return 280; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120124; }
                break;
            case 'p': if(str.startsIdx("silon;", start, end)) { start += 6; return 917; } break;
            case 'q':
                if(str.startsIdx("ual", start, end)) {
                    start += 3;
                    if(start < end && str[start] == ';') { start++; return 10869; }
                    if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8770; }
                    break;
                }
                if(str.startsIdx("uilibrium;", start, end)) { start += 10; return 8652; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 8496; }
                if(str.startsIdx("im;", start, end)) { start += 3; return 10867; }
                break;
            case 't': if(str.startsIdx("a;", start, end)) { start += 2; return 919; } break;
            case 'u':
                if(str.startsIdx("ml", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 203;
                }
                break;
            case 'x':
                if(str.startsIdx("ists;", start, end)) { start += 5; return 8707; }
                if(str.startsIdx("ponentialE;", start, end)) { start += 11; return 8519; }
                break;
        }
        return -1;
    }

    int entityUpperF(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1060; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120073; } break;
            case 'i':
                if(str.startsIdx("lled", start, end)) {
                    start += 4;
                    if(str.startsIdx("SmallSquare;", start, end)) { start += 12; return 9724; }
                    if(str.startsIdx("VerySmallSquare;", start, end)) { start += 16; return 9642; }
                }
                break;
            case 'o':
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120125; }
                if(str.startsIdx("rAll;", start, end)) { start += 5; return 8704; }
                if(str.startsIdx("uriertrf;", start, end)) { start += 9; return 8497; }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 8497; } break;
        }
        return -1;
    }

    int entityUpperG(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'J': if(str.startsIdx("cy;", start, end)) { start += 3; return 1027; } break;
            case 'T':
                if(start < end && str[start] == ';') start++;
                return 62;
            case 'a':
                if(str.startsIdx("mma", start, end)) {
                    start += 3;
                    if(start < end && str[start] == ';') { start++; return 915; }
                    if(str.startsIdx("d;", start, end)) { start += 2; return 988; }
                }
                break;
            case 'b': if(str.startsIdx("reve;", start, end)) { start += 5; return 286; } break;
            case 'c':
                if(str.startsIdx("edil;", start, end)) { start += 5; return 290; }
                if(str.startsIdx("irc;", start, end)) { start += 4; return 284; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1043; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 288; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120074; } break;
            case 'g':
                if(start < end && str[start] == ';') { start++; return 8921; }
                break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120126; } break;
            case 'r':
                if(str.startsIdx("eater", start, end)) {
                    start += 5;
                    if(str.startsIdx("Equal;", start, end)) { start += 6; return 8805; }
                    if(str.startsIdx("EqualLess;", start, end)) { start += 10; return 8923; }
                    if(str.startsIdx("FullEqual;", start, end)) { start += 10; return 8807; }
                    if(str.startsIdx("Greater;", start, end)) { start += 8; return 10914; }
                    if(str.startsIdx("Less;", start, end)) { start += 5; return 8823; }
                    if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return 10878; }
                    if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8819; }
                    break;
                }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119970; } break;
            case 't':
                if(start < end && str[start] == ';') { start++; return 8811; }
                break;
        }
        return -1;
    }

    int entityUpperH(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A': if(str.startsIdx("RDcy;", start, end)) { start += 5; return 1066; } break;
            case 'a':
                if(str.startsIdx("cek;", start, end)) { start += 4; return 711; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 94; }
                break;
            case 'c': if(str.startsIdx("irc;", start, end)) { start += 4; return 292; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 8460; } break;
            case 'i': if(str.startsIdx("lbertSpace;", start, end)) { start += 11; return 8459; } break;
            case 'o':
                if(str.startsIdx("pf;", start, end)) { start += 3; return 8461; }
                if(str.startsIdx("rizontalLine;", start, end)) { start += 13; return 9472; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 8459; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 294; }
                break;
            case 'u':
                if(str.startsIdx("mp", start, end)) {
                    start += 2;
                    if(str.startsIdx("DownHump;", start, end)) { start += 9; return 8782; }
                    if(str.startsIdx("Equal;", start, end)) { start += 6; return 8783; }
                }
                break;
        }
        return -1;
    }

    int entityUpperI(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'E': if(str.startsIdx("cy;", start, end)) { start += 3; return 1045; } break;
            case 'J': if(str.startsIdx("lig;", start, end)) { start += 4; return 306; } break;
            case 'O': if(str.startsIdx("cy;", start, end)) { start += 3; return 1025; } break;
            case 'a':
                if(str.startsIdx("cute", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 205;
                }
                break;
            case 'c':
                if(str.startsIdx("irc", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 206;
                }
                else if(str.startsIdx("y;", start, end)) { start += 2; return 1048; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 304; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 8465; } break;
            case 'g':
                if(str.startsIdx("rave", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 204;
                }
                break;
            case 'm':
                if(start < end && str[start] == ';') { start++; return 8465; }
                if(str.startsIdx("acr;", start, end)) { start += 4; return 298; }
                if(str.startsIdx("aginaryI;", start, end)) { start += 9; return 8520; }
                if(str.startsIdx("plies;", start, end)) { start += 6; return 8658; }
                break;
            case 'n':
                if(str.startsIdx("t;", start, end)) { start += 2; return 8748; }
                if(str.startsIdx("tegral;", start, end)) { start += 7; return 8747; }
                if(str.startsIdx("tersection;", start, end)) { start += 11; return 8898; }
                if(str.startsIdx("visible", start, end)) {
                    start += 7;
                    if(str.startsIdx("Comma;", start, end)) { start += 6; return 8291; }
                    if(str.startsIdx("Times;", start, end)) { start += 6; return 8290; }
                }
                break;
            case 'o':
                if(str.startsIdx("gon;", start, end)) { start += 4; return 302; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120128; }
                if(str.startsIdx("ta;", start, end)) { start += 3; return 921; }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 8464; } break;
            case 't': if(str.startsIdx("ilde;", start, end)) { start += 5; return 296; } break;
            case 'u':
                if(str.startsIdx("kcy;", start, end)) { start += 4; return 1030; }
                if(str.startsIdx("ml", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 207;
                }
                break;
        }
        return -1;
    }

    int entityUpperJ(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'c':
                if(str.startsIdx("irc;", start, end)) { start += 4; return 308; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1049; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120077; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120129; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119973; }
                if(str.startsIdx("ercy;", start, end)) { start += 5; return 1032; }
                break;
            case 'u': if(str.startsIdx("kcy;", start, end)) { start += 4; return 1028; } break;
        }
        return -1;
    }

    int entityUpperK(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'H': if(str.startsIdx("cy;", start, end)) { start += 3; return 1061; } break;
            case 'J': if(str.startsIdx("cy;", start, end)) { start += 3; return 1036; } break;
            case 'a': if(str.startsIdx("ppa;", start, end)) { start += 4; return 922; } break;
            case 'c':
                if(str.startsIdx("edil;", start, end)) { start += 5; return 310; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1050; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120078; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120130; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119974; } break;
        }
        return -1;
    }

    int entityUpperL(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'J': if(str.startsIdx("cy;", start, end)) { start += 3; return 1033; } break;
            case 'T':
                if(start < end && str[start] == ';') start++;
                return 60;
            case 'a':
                if(str.startsIdx("cute;", start, end)) { start += 5; return 313; }
                if(str.startsIdx("mbda;", start, end)) { start += 5; return 923; }
                if(str.startsIdx("ng;", start, end)) { start += 3; return 10218; }
                if(str.startsIdx("placetrf;", start, end)) { start += 9; return 8466; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8606; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 317; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 315; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1051; }
                break;
            case 'e':
                if(str.startsIdx("ft", start, end)) {
                    start += 2;
                    if(str.startsIdx("AngleBracket;", start, end)) { start += 13; return 10216; }
                    if(str.startsIdx("Arrow", start, end)) {
                        start += 5;
                        if(start < end && str[start] == ';') { start++; return 8592; }
                        if(str.startsIdx("Bar;", start, end)) { start += 4; return 8676; }
                        if(str.startsIdx("RightArrow;", start, end)) { start += 11; return 8646; }
                        break;
                    }
                    if(str.startsIdx("Ceiling;", start, end)) { start += 8; return 8968; }
                    if(str.startsIdx("DoubleBracket;", start, end)) { start += 14; return 10214; }
                    if(str.startsIdx("Down", start, end)) {
                        start += 4;
                        if(str.startsIdx("TeeVector;", start, end)) { start += 10; return 10593; }
                        if(str.startsIdx("Vector;", start, end)) { start += 7; return 8643; }
                        if(str.startsIdx("VectorBar;", start, end)) { start += 10; return 10585; }
                        break;
                    }
                    if(str.startsIdx("Floor;", start, end)) { start += 6; return 8970; }
                    if(str.startsIdx("Right", start, end)) {
                        start += 5;
                        if(str.startsIdx("Arrow;", start, end)) { start += 6; return 8596; }
                        if(str.startsIdx("Vector;", start, end)) { start += 7; return 10574; }
                        break;
                    }
                    if(str.startsIdx("Tee", start, end)) {
                        start += 3;
                        if(start < end && str[start] == ';') { start++; return 8867; }
                        if(str.startsIdx("Arrow;", start, end)) { start += 6; return 8612; }
                        if(str.startsIdx("Vector;", start, end)) { start += 7; return 10586; }
                        break;
                    }
                    if(str.startsIdx("Triangle", start, end)) {
                        start += 8;
                        if(start < end && str[start] == ';') { start++; return 8882; }
                        if(str.startsIdx("Bar;", start, end)) { start += 4; return 10703; }
                        if(str.startsIdx("Equal;", start, end)) { start += 6; return 8884; }
                        break;
                    }
                    if(str.startsIdx("Up", start, end)) {
                        start += 2;
                        if(str.startsIdx("DownVector;", start, end)) { start += 11; return 10577; }
                        if(str.startsIdx("TeeVector;", start, end)) { start += 10; return 10592; }
                        if(str.startsIdx("Vector;", start, end)) { start += 7; return 8639; }
                        if(str.startsIdx("VectorBar;", start, end)) { start += 10; return 10584; }
                        break;
                    }
                    if(str.startsIdx("Vector", start, end)) {
                        start += 6;
                        if(start < end && str[start] == ';') { start++; return 8636; }
                        if(str.startsIdx("Bar;", start, end)) { start += 4; return 10578; }
                        break;
                    }
                    if(str.startsIdx("arrow;", start, end)) { start += 6; return 8656; }
                    if(str.startsIdx("rightarrow;", start, end)) { start += 11; return 8660; }
                    break;
                }
                if(str.startsIdx("ss", start, end)) {
                    start += 2;
                    if(str.startsIdx("EqualGreater;", start, end)) { start += 13; return 8922; }
                    if(str.startsIdx("FullEqual;", start, end)) { start += 10; return 8806; }
                    if(str.startsIdx("Greater;", start, end)) { start += 8; return 8822; }
                    if(str.startsIdx("Less;", start, end)) { start += 5; return 10913; }
                    if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return 10877; }
                    if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8818; }
                }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120079; } break;
            case 'l':
                if(start < end && str[start] == ';') { start++; return 8920; }
                if(str.startsIdx("eftarrow;", start, end)) { start += 9; return 8666; }
                break;
            case 'm': if(str.startsIdx("idot;", start, end)) { start += 5; return 319; } break;
            case 'o':
                if(str.startsIdx("ng", start, end)) {
                    start += 2;
                    if(str.startsIdx("LeftArrow;", start, end)) { start += 10; return 10229; }
                    if(str.startsIdx("LeftRightArrow;", start, end)) { start += 15; return 10231; }
                    if(str.startsIdx("RightArrow;", start, end)) { start += 11; return 10230; }
                    if(str.startsIdx("leftarrow;", start, end)) { start += 10; return 10232; }
                    if(str.startsIdx("leftrightarrow;", start, end)) { start += 15; return 10234; }
                    if(str.startsIdx("rightarrow;", start, end)) { start += 11; return 10233; }
                    break;
                }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120131; }
                if(str.startsIdx("werLeftArrow;", start, end)) { start += 13; return 8601; }
                if(str.startsIdx("werRightArrow;", start, end)) { start += 14; return 8600; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 8466; }
                if(str.startsIdx("h;", start, end)) { start += 2; return 8624; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 321; }
                break;
            case 't': if(start < end && str[start] == ';') { start++; return 8810; }
        }
        return -1;
    }

    int entityUpperM(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a': if(str.startsIdx("p;", start, end)) { start += 2; return 10501; } break;
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1052; } break;
            case 'e':
                if(str.startsIdx("diumSpace;", start, end)) { start += 10; return 8287; }
                if(str.startsIdx("llintrf;", start, end)) { start += 8; return 8499; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120080; } break;
            case 'i': if(str.startsIdx("nusPlus;", start, end)) { start += 8; return 8723; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120132; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 8499; } break;
            case 'u': if(start < end && str[start] == ';') { start++; return 924; } break;
        }
        return -1;
    }

    int entityUpperN(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'J': if(str.startsIdx("cy;", start, end)) { start += 3; return 1034; } break;
            case 'a': if(str.startsIdx("cute;", start, end)) { start += 5; return 323; } break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 327; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 325; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1053; }
                break;
            case 'e':
                if(str.startsIdx("gative", start, end)) {
                    start += 6;
                    if(str.startsIdx("MediumSpace;", start, end)) { start += 12; return 8203; }
                    if(str.startsIdx("ThickSpace;", start, end)) { start += 11; return 8203; }
                    if(str.startsIdx("ThinSpace;", start, end)) { start += 10; return 8203; }
                    if(str.startsIdx("VeryThinSpace;", start, end)) { start += 14; return 8203; }
                    break;
                }
                if(str.startsIdx("stedGreaterGreater;", start, end)) { start += 19; return 8811; }
                if(str.startsIdx("stedLessLess;", start, end)) { start += 13; return 8810; }
                if(str.startsIdx("wLine;", start, end)) { start += 6; return 10; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120081; } break;
            case 'o':
                if(str.startsIdx("Break;", start, end)) { start += 6; return 8288; }
                if(str.startsIdx("nBreakingSpace;", start, end)) { start += 15; return 160; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 8469; }
                if(start < end && str[start] == 't') {
                    start++;
                    if(start < end && str[start] == ';') { start++; return 10988; }
                    if(start >= end) break;
                    switch(str[start++]) {
                        case 'C':
                            if(str.startsIdx("ongruent;", start, end)) { start += 9; return 8802; }
                            if(str.startsIdx("upCap;", start, end)) { start += 6; return 8813; }
                            break;
                        case 'D': if(str.startsIdx("oubleVerticalBar;", start, end)) { start += 17; return 8742; } break;
                        case 'E':
                            if(str.startsIdx("lement;", start, end)) { start += 7; return 8713; }
                            if(str.startsIdx("qual", start, end)) {
                                start += 4;
                                if(start < end && str[start] == ';') { start++; return 8800; }
                                if(str.startsIdx("Tilde;", start, end)) { start += 6; return -574817080; }
                                break;
                            }
                            if(str.startsIdx("xists;", start, end)) { start += 6; return 8708; }
                            break;
                        case 'G':
                            if(str.startsIdx("reater", start, end)) {
                                start += 6;
                                if(start < end && str[start] == ';') { start++; return 8815; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return 8817; }
                                if(str.startsIdx("FullEqual;", start, end)) { start += 10; return -577241912; }
                                if(str.startsIdx("Greater;", start, end)) { start += 8; return -577504056; }
                                if(str.startsIdx("Less;", start, end)) { start += 5; return 8825; }
                                if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return -712966968; }
                                if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8821; }
                            }
                            break;
                        case 'H':
                            if(str.startsIdx("ump", start, end)) {
                                start += 3;
                                if(str.startsIdx("DownHump;", start, end)) { start += 9; return -575603512; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return -575669048; }
                            }
                            break;
                        case 'L':
                            if(str.startsIdx("eftTriangle", start, end)) {
                                start += 11;
                                if(start < end && str[start] == ';') { start++; return 8938; }
                                if(str.startsIdx("Bar;", start, end)) { start += 4; return -701498168; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return 8940; }
                                break;
                            }
                            if(str.startsIdx("ess", start, end)) {
                                start += 3;
                                if(start < end && str[start] == ';') { start++; return 8814; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return 8816; }
                                if(str.startsIdx("Greater;", start, end)) { start += 8; return 8824; }
                                if(str.startsIdx("Less;", start, end)) { start += 5; return -577438520; }
                                if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return -712901432; }
                                if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8820; }
                            }
                            break;
                        case 'N':
                            if(str.startsIdx("ested", start, end)) {
                                start += 5;
                                if(str.startsIdx("GreaterGreater;", start, end)) { start += 15; return -715326264; }
                                if(str.startsIdx("LessLess;", start, end)) { start += 9; return -715260728; }
                            }
                            break;
                        case 'P':
                            if(str.startsIdx("recedes", start, end)) {
                                start += 7;
                                if(start < end && str[start] == ';') { start++; return 8832; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return -716178232; }
                                if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return 8928; }
                            }
                            break;
                        case 'R':
                            if(str.startsIdx("everseElement;", start, end)) { start += 14; return 8716; }
                            if(str.startsIdx("ightTriangle", start, end)) {
                                start += 12;
                                if(start < end && str[start] == ';') { start++; return 8939; }
                                if(str.startsIdx("Bar;", start, end)) { start += 4; return -701563704; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return 8941; }
                            }
                            break;
                        case 'S':
                            if(str.startsIdx("quareSu", start, end)) {
                                start += 7;
                                if(str.startsIdx("bset;", start, end)) { start += 5; return -579863352; }
                                if(str.startsIdx("bsetEqual;", start, end)) { start += 10; return 8930; }
                                if(str.startsIdx("perset;", start, end)) { start += 7; return -579928888; }
                                if(str.startsIdx("persetEqual;", start, end)) { start += 12; return 8931; }
                                break;
                            }
                            if(str.startsIdx("ubset", start, end)) {
                                start += 5;
                                if(start < end && str[start] == ';') { start++; return -579018962; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return 8840; }
                                break;
                            }
                            if(str.startsIdx("ucceeds", start, end)) {
                                start += 7;
                                if(start < end && str[start] == ';') { start++; return 8833; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return -716243768; }
                                if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return 8929; }
                                if(str.startsIdx("Tilde;", start, end)) { start += 6; return -578814776; }
                                break;
                            }
                            if(str.startsIdx("uperset", start, end)) {
                                start += 7;
                                if(start < end && str[start] == ';') { start++; return -579084498; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return 8841; }
                            }
                            break;
                        case 'T':
                            if(str.startsIdx("ilde", start, end)) {
                                start += 4;
                                if(start < end && str[start] == ';') { start++; return 8769; }
                                if(str.startsIdx("Equal;", start, end)) { start += 6; return 8772; }
                                if(str.startsIdx("FullEqual;", start, end)) { start += 10; return 8775; }
                                if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8777; }
                            }
                            break;
                        case 'V': if(str.startsIdx("erticalBar;", start, end)) { start += 11; return 8740; } break;
                    }
                }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119977; } break;
            case 't':
                if(str.startsIdx("ilde", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 209;
                }
                break;
            case 'u': if(start < end && str[start] == ';') { start++; return 925; } break;
        }
        return -1;
    }

    int entityUpperO(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'E': if(str.startsIdx("lig;", start, end)) { start += 4; return 338; } break;
            case 'a':
                if(str.startsIdx("cute", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 211;
                }
                break;
            case 'c':
                if(str.startsIdx("irc", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 212;
                }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1054; }
                break;
            case 'd': if(str.startsIdx("blac;", start, end)) { start += 5; return 336; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120082; } break;
            case 'g':
                if(str.startsIdx("rave", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 210;
                }
                break;
            case 'm':
                if(str.startsIdx("acr;", start, end)) { start += 4; return 332; }
                if(str.startsIdx("ega;", start, end)) { start += 4; return 937; }
                if(str.startsIdx("icron;", start, end)) { start += 6; return 927; }
                break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120134; } break;
            case 'p':
                if(str.startsIdx("enCurly", start, end)) {
                    start += 7;
                    if(str.startsIdx("DoubleQuote;", start, end)) { start += 12; return 8220; }
                    if(str.startsIdx("Quote;", start, end)) { start += 6; return 8216; }
                }
                break;
            case 'r': if(start < end && str[start] == ';') { start++; return 10836; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119978; }
                if(str.startsIdx("lash", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 216;
                }
                break;
            case 't':
                if(str.startsIdx("ilde", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 213;
                }
                if(str.startsIdx("imes;", start, end)) { start += 5; return 10807; }
                break;
            case 'u':
                if(str.startsIdx("ml", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 214;
                }
                break;
            case 'v':
                if(str.startsIdx("er", start, end)) {
                    start += 2;
                    if(start < end && str[start] == 'B') {
                        start++;
                        if(str.startsIdx("ar;", start, end)) { start += 3; return 8254; }
                        if(str.startsIdx("race;", start, end)) { start += 5; return 9182; }
                        if(str.startsIdx("racket;", start, end)) { start += 7; return 9140; }
                        break;
                    }
                    if(str.startsIdx("Parenthesis;", start, end)) { start += 12; return 9180; }
                }
                break;
        }
        return -1;
    }

    int entityUpperP(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a': if(str.startsIdx("rtialD;", start, end)) { start += 7; return 8706; } break;
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1055; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120083; } break;
            case 'h': if(str.startsIdx("i;", start, end)) { start += 2; return 934; } break;
            case 'i': if(start < end && str[start] == ';') { start++; return 928; } break;
            case 'l': if(str.startsIdx("usMinus;", start, end)) { start += 8; return 177; } break;
            case 'o':
                if(str.startsIdx("incareplane;", start, end)) { start += 12; return 8460; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 8473; }
                break;
            case 'r':
                if(start < end && str[start] == ';') { start++; return 10939; }
                if(str.startsIdx("ecedes", start, end)) {
                    start += 6;
                    if(start < end && str[start] == ';') { start++; return 8826; }
                    if(str.startsIdx("Equal;", start, end)) { start += 6; return 10927; }
                    if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return 8828; }
                    if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8830; }
                    break;
                }
                if(str.startsIdx("ime;", start, end)) { start += 4; return 8243; }
                if(str.startsIdx("oduct;", start, end)) { start += 6; return 8719; }
                if(str.startsIdx("oportion", start, end)) {
                    start += 8;
                    if(start < end && str[start] == ';') { start++; return 8759; }
                    if(str.startsIdx("al;", start, end)) { start += 3; return 8733; }
                    return 8759;
                }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119979; }
                if(str.startsIdx("i;", start, end)) { start += 2; return 936; }
                break;
        }
        return -1;
    }

    int entityUpperQ(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'U':
                if(str.startsIdx("OT", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 34;
                }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120084; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 8474; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119980; } break;
        }
        return -1;
    }

    int entityUpperR(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'B': if(str.startsIdx("arr;", start, end)) { start += 4; return 10512; } break;
            case 'E':
                if(start < end && str[start] == 'G') {
                    start += 1 + (start + 1 < end && str[start + 1] == ';');
                    return 174;
                }
                break;
            case 'a':
                if(str.startsIdx("cute;", start, end)) { start += 5; return 340; }
                if(str.startsIdx("ng;", start, end)) { start += 3; return 10219; }
                if(str.startsIdx("rr", start, end)) {
                    start += 2;
                    if(start < end && str[start] == ';') { start++; return 8608; }
                    if(str.startsIdx("tl;", start, end)) { start += 3; return 10518; }
                }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 344; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 342; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1056; }
                break;
            case 'e':
                if(start < end && str[start] == ';') { start++; return 8476; }
                if(str.startsIdx("verse", start, end)) {
                    start += 5;
                    if(str.startsIdx("Element;", start, end)) { start += 8; return 8715; }
                    if(str.startsIdx("Equilibrium;", start, end)) { start += 12; return 8651; }
                    if(str.startsIdx("UpEquilibrium;", start, end)) { start += 14; return 10607; }
                }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 8476; } break;
            case 'h': if(str.startsIdx("o;", start, end)) { start += 2; return 929; } break;
            case 'i':
                if(str.startsIdx("ght", start, end)) {
                    start += 3;
                    if(str.startsIdx("AngleBracket;", start, end)) { start += 13; return 10217; }
                    if(str.startsIdx("Arrow", start, end)) {
                        start += 5;
                        if(start < end && str[start] == ';') { start++; return 8594; }
                        if(str.startsIdx("Bar;", start, end)) { start += 4; return 8677; }
                        if(str.startsIdx("LeftArrow;", start, end)) { start += 10; return 8644; }
                        break;
                    }
                    if(str.startsIdx("Ceiling;", start, end)) { start += 8; return 8969; }
                    if(str.startsIdx("DoubleBracket;", start, end)) { start += 14; return 10215; }
                    if(str.startsIdx("Down", start, end)) {
                        start += 4;
                        if(str.startsIdx("TeeVector;", start, end)) { start += 10; return 10589; }
                        if(str.startsIdx("Vector", start, end)) {
                            start += 6;
                            if(start < end && str[start] == ';') { start++; return 8642; }
                            if(str.startsIdx("Bar;", start, end)) { start += 4; return 10581; }
                            break;
                        }
                        break;
                    }
                    if(str.startsIdx("Floor;", start, end)) { start += 6; return 8971; }
                    if(str.startsIdx("Tee", start, end)) {
                        start += 3;
                        if(start < end && str[start] == ';') { start++; return 8866; }
                        if(str.startsIdx("Arrow;", start, end)) { start += 6; return 8614; }
                        if(str.startsIdx("Vector;", start, end)) { start += 7; return 10587; }
                        break;
                    }
                    if(str.startsIdx("Triangle", start, end)) {
                        start += 8;
                        if(start < end && str[start] == ';') { start++; return 8883; }
                        if(str.startsIdx("Bar;", start, end)) { start += 4; return 10704; }
                        if(str.startsIdx("Equal;", start, end)) { start += 6; return 8885; }
                        break;
                    }
                    if(str.startsIdx("Up", start, end)) {
                        start += 2;
                        if(str.startsIdx("DownVector;", start, end)) { start += 11; return 10575; }
                        if(str.startsIdx("TeeVector;", start, end)) { start += 10; return 10588; }
                        if(str.startsIdx("Vector;", start, end)) { start += 7; return 8638; }
                        if(str.startsIdx("VectorBar;", start, end)) { start += 10; return 10580; }
                        break;
                    }
                    if(str.startsIdx("Vector;", start, end)) { start += 7; return 8640; }
                    if(str.startsIdx("VectorBar;", start, end)) { start += 10; return 10579; }
                    if(str.startsIdx("arrow;", start, end)) { start += 6; return 8658; }
                }
                break;
            case 'o':
                if(str.startsIdx("pf;", start, end)) { start += 3; return 8477; }
                if(str.startsIdx("undImplies;", start, end)) { start += 11; return 10608; }
                break;
            case 'r': if(str.startsIdx("ightarrow;", start, end)) { start += 10; return 8667; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 8475; }
                if(str.startsIdx("h;", start, end)) { start += 2; return 8625; }
                break;
            case 'u': if(str.startsIdx("leDelayed;", start, end)) { start += 10; return 10740; } break;
        }
        return -1;
    }

    int entityUpperS(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'H':
                if(str.startsIdx("CHcy;", start, end)) { start += 5; return 1065; }
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1064; }
                break;
            case 'O': if(str.startsIdx("FTcy;", start, end)) { start += 5; return 1068; } break;
            case 'a': if(str.startsIdx("cute;", start, end)) { start += 5; return 346; } break;
            case 'c':
                if(start < end && str[start] == ';') { start++; return 10940; }
                if(str.startsIdx("aron;", start, end)) { start += 5; return 352; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 350; }
                if(str.startsIdx("irc;", start, end)) { start += 4; return 348; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1057; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120086; } break;
            case 'h':
                if(str.startsIdx("ort", start, end)) {
                    start += 3;
                    if(str.startsIdx("DownArrow;", start, end)) { start += 10; return 8595; }
                    if(str.startsIdx("LeftArrow;", start, end)) { start += 10; return 8592; }
                    if(str.startsIdx("RightArrow;", start, end)) { start += 11; return 8594; }
                    if(str.startsIdx("UpArrow;", start, end)) { start += 8; return 8593; }
                }
                break;
            case 'i': if(str.startsIdx("gma;", start, end)) { start += 4; return 931; } break;
            case 'm': if(str.startsIdx("allCircle;", start, end)) { start += 10; return 8728; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120138; } break;
            case 'q':
                if(str.startsIdx("rt;", start, end)) { start += 3; return 8730; }
                if(str.startsIdx("uare", start, end)) {
                    start += 4;
                    if(start < end && str[start] == ';') { start++; return 9633; }
                    if(str.startsIdx("Intersection;", start, end)) { start += 13; return 8851; }
                    if(str.startsIdx("Subset", start, end)) {
                        start += 6;
                        if(start < end && str[start] == ';') { start++; return 8847; }
                        if(str.startsIdx("Equal;", start, end)) { start += 6; return 8849; }
                        break;
                    }
                    if(str.startsIdx("Superset", start, end)) {
                        start += 8;
                        if(start < end && str[start] == ';') { start++; return 8848; }
                        if(str.startsIdx("Equal;", start, end)) { start += 6; return 8850; }
                        break;
                    }
                    if(str.startsIdx("Union;", start, end)) { start += 6; return 8852; }
                }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119982; } break;
            case 't': if(str.startsIdx("ar;", start, end)) { start += 3; return 8902; } break;
            case 'u':
                if(str.startsIdx("b;", start, end)) { start += 2; return 8912; }
                if(str.startsIdx("bset", start, end)) {
                    start += 4;
                    if(start < end && str[start] == ';') { start++; return 8912; }
                    if(str.startsIdx("Equal;", start, end)) { start += 6; return 8838; }
                    break;
                }
                if(str.startsIdx("cceeds", start, end)) {
                    start += 6;
                    if(start < end && str[start] == ';') { start++; return 8827; }
                    if(str.startsIdx("Equal;", start, end)) { start += 6; return 10928; }
                    if(str.startsIdx("SlantEqual;", start, end)) { start += 11; return 8829; }
                    if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8831; }
                    break;
                }
                if(str.startsIdx("chThat;", start, end)) { start += 7; return 8715; }
                if(str.startsIdx("m;", start, end)) { start += 2; return 8721; }
                if(str.startsIdx("p;", start, end)) { start += 2; return 8913; }
                if(str.startsIdx("perset;", start, end)) { start += 7; return 8835; }
                if(str.startsIdx("persetEqual;", start, end)) { start += 12; return 8839; }
                if(str.startsIdx("pset;", start, end)) { start += 5; return 8913; }
                break;
        }
        return -1;
    }

    int entityUpperT(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'H':
                if(str.startsIdx("ORN", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 222;
                }
                break;
            case 'R': if(str.startsIdx("ADE;", start, end)) { start += 4; return 8482; } break;
            case 'S':
                if(str.startsIdx("Hcy;", start, end)) { start += 4; return 1035; }
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1062; }
                break;
            case 'a':
                if(str.startsIdx("b;", start, end)) { start += 2; return 9; }
                if(str.startsIdx("u;", start, end)) { start += 2; return 932; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 356; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 354; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1058; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120087; } break;
            case 'h':
                if(str.startsIdx("erefore;", start, end)) { start += 8; return 8756; }
                if(str.startsIdx("eta;", start, end)) { start += 4; return 920; }
                if(str.startsIdx("ickSpace;", start, end)) { start += 9; return -543170570; }
                if(str.startsIdx("inSpace;", start, end)) { start += 8; return 8201; }
                break;
            case 'i':
                if(str.startsIdx("lde", start, end)) {
                    start += 3;
                    if(start < end && str[start] == ';') { start++; return 8764; }
                    if(str.startsIdx("Equal;", start, end)) { start += 6; return 8771; }
                    if(str.startsIdx("FullEqual;", start, end)) { start += 10; return 8773; }
                    if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8776; }
                }
                break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120139; } break;
            case 'r': if(str.startsIdx("ipleDot;", start, end)) { start += 8; return 8411; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119983; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 358; }
                break;
        }
        return -1;
    }

    int entityUpperU(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("cute", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 218;
                }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8607; }
                if(str.startsIdx("rrocir;", start, end)) { start += 7; return 10569; }
                break;
            case 'b':
                if(str.startsIdx("rcy;", start, end)) { start += 4; return 1038; }
                if(str.startsIdx("reve;", start, end)) { start += 5; return 364; }
                break;
            case 'c':
                if(str.startsIdx("irc", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 219;
                }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1059; }
                break;
            case 'd': if(str.startsIdx("blac;", start, end)) { start += 5; return 368; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120088; } break;
            case 'g':
                if(str.startsIdx("rave", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 217;
                }
                break;
            case 'm': if(str.startsIdx("acr;", start, end)) { start += 4; return 362; } break;
            case 'n':
                if(str.startsIdx("der", start, end)) {
                    start += 3;
                    if(str.startsIdx("Bar;", start, end)) { start += 4; return 95; }
                    if(str.startsIdx("Brace;", start, end)) { start += 6; return 9183; }
                    if(str.startsIdx("Bracket;", start, end)) { start += 8; return 9141; }
                    if(str.startsIdx("Parenthesis;", start, end)) { start += 12; return 9181; }
                    break;
                }
                if(str.startsIdx("ion", start, end)) {
                    start += 3;
                    if(start < end && str[start] == ';') { start++; return 8899; }
                    if(str.startsIdx("Plus;", start, end)) { start += 5; return 8846; }
                }
                break;
            case 'o':
                if(str.startsIdx("gon;", start, end)) { start += 4; return 370; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120140; }
                break;
            case 'p':
                if(str.startsIdx("Arrow", start, end)) {
                    start += 5;
                    if(start < end && str[start] == ';') { start++; return 8593; }
                    if(str.startsIdx("Bar;", start, end)) { start += 4; return 10514; }
                    if(str.startsIdx("DownArrow;", start, end)) { start += 10; return 8645; }
                    break;
                }
                if(str.startsIdx("DownArrow;", start, end)) { start += 10; return 8597; }
                if(str.startsIdx("Equilibrium;", start, end)) { start += 12; return 10606; }
                if(str.startsIdx("Tee", start, end)) {
                    start += 3;
                    if(start < end && str[start] == ';') { start++; return 8869; }
                    if(str.startsIdx("Arrow;", start, end)) { start += 6; return 8613; }
                    break;
                }
                if(str.startsIdx("arrow;", start, end)) { start += 6; return 8657; }
                if(str.startsIdx("downarrow;", start, end)) { start += 10; return 8661; }
                if(str.startsIdx("perLeftArrow;", start, end)) { start += 13; return 8598; }
                if(str.startsIdx("perRightArrow;", start, end)) { start += 14; return 8599; }
                if(str.startsIdx("si;", start, end)) { start += 3; return 978; }
                if(str.startsIdx("silon;", start, end)) { start += 6; return 933; }
                break;
            case 'r': if(str.startsIdx("ing;", start, end)) { start += 4; return 366; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119984; } break;
            case 't': if(str.startsIdx("ilde;", start, end)) { start += 5; return 360; } break;
            case 'u':
                if(str.startsIdx("ml", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 220;
                }
                break;
        }
        return -1;
    }

    int entityUpperV(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'D': if(str.startsIdx("ash;", start, end)) { start += 4; return 8875; } break;
            case 'b': if(str.startsIdx("ar;", start, end)) { start += 3; return 10987; } break;
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1042; } break;
            case 'd':
                if(str.startsIdx("ash", start, end)) {
                    start += 3;
                    if(start < end && str[start] == ';') { start++; return 8873; }
                    if(str.startsIdx("l;", start, end)) { start += 2; return 10982; }
                }
                break;
            case 'e':
                if(str.startsIdx("e;", start, end)) { start += 2; return 8897; }
                if(start < end && str[start] == 'r') {
                    start++;
                    if(str.startsIdx("bar;", start, end)) { start += 4; return 8214; }
                    if(str.startsIdx("t;", start, end)) { start += 2; return 8214; }
                    if(str.startsIdx("tical", start, end)) {
                        start += 5;
                        if(str.startsIdx("Bar;", start, end)) { start += 4; return 8739; }
                        if(str.startsIdx("Line;", start, end)) { start += 5; return 124; }
                        if(str.startsIdx("Separator;", start, end)) { start += 10; return 10072; }
                        if(str.startsIdx("Tilde;", start, end)) { start += 6; return 8768; }
                        break;
                    }
                    if(str.startsIdx("yThinSpace;", start, end)) { start += 11; return 8202; }
                }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120089; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120141; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119985; } break;
            case 'v': if(str.startsIdx("dash;", start, end)) { start += 5; return 8874; } break;
        }
        return -1;
    }

    int entityUpperW(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'c': if(str.startsIdx("irc;", start, end)) { start += 4; return 372; } break;
            case 'e': if(str.startsIdx("dge;", start, end)) { start += 4; return 8896; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120090; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120142; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119986; } break;
        }
        return -1;
    }

    int entityUpperX(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120091; } break;
            case 'i': if(start < end && str[start] == ';') { start++; return 926; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120143; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119987; } break;
        }
        return -1;
    }

    int entityUpperY(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A': if(str.startsIdx("cy;", start, end)) { start += 3; return 1071; } break;
            case 'I': if(str.startsIdx("cy;", start, end)) { start += 3; return 1031; } break;
            case 'U': if(str.startsIdx("cy;", start, end)) { start += 3; return 1070; } break;
            case 'a':
                if(str.startsIdx("cute", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 221;
                }
                break;
            case 'c':
                if(str.startsIdx("irc;", start, end)) { start += 4; return 374; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1067; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120092; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120144; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119988; } break;
            case 'u': if(str.startsIdx("ml;", start, end)) { start += 3; return 376; } break;
        }
        return -1;
    }

    int entityUpperZ(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'H': if(str.startsIdx("cy;", start, end)) { start += 3; return 1046; } break;
            case 'a': if(str.startsIdx("cute;", start, end)) { start += 5; return 377; } break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 381; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1047; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 379; } break;
            case 'e':
                if(str.startsIdx("roWidthSpace;", start, end)) { start += 13; return 8203; }
                if(str.startsIdx("ta;", start, end)) { start += 3; return 918; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 8488; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 8484; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119989; } break;
        }
        return -1;
    }
}