//
// Created by skyne on 2024-02-03.
//
#include "LowerEntities.h"

namespace Html {
    int entityLowerA(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("cute", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 225;
                }
                break;
            case 'b': if(str.startsIdx("reve;", start, end)) { start += 5; return 259; } break;
            case 'c':
                if(start < end && str[start] == ';') { start++; return 8766; }
                if(str.startsIdx("E;", start, end)) { start += 2; return -574554931; }
                if(str.startsIdx("d;", start, end)) { start += 2; return 8767; }
                if(str.startsIdx("irc", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 226;
                }
                if(str.startsIdx("ute", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 180;
                }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1072; }
                break;
            case 'e':
                if(str.startsIdx("lig", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 230;
                }
                break;
            case 'f':
                if(start < end && str[start] == ';') { start++; return 8289; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120094; }
                break;
            case 'g':
                if(str.startsIdx("rave", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 224;
                }
                break;
            case 'l':
                if(str.startsIdx("efsym;", start, end)) { start += 6; return 8501; }
                if(str.startsIdx("eph;", start, end)) { start += 4; return 8501; }
                if(str.startsIdx("pha;", start, end)) { start += 4; return 945; }
                break;
            case 'm':
                if(str.startsIdx("acr;", start, end)) { start += 4; return 257; }
                if(str.startsIdx("alg;", start, end)) { start += 4; return 10815; }
                if(start < end && str[start] == 'p') {
                    start += 1 + (start + 1 < end && str[start + 1] == ';');
                    return 38;
                }
                break;
            case 'n':
                if(start < end && str[start] == 'd') {
                    start++;
                    if(start < end && str[start] == ';') { start++; return 8743; }
                    if(str.startsIdx("and;", start, end)) { start += 4; return 10837; }
                    if(str.startsIdx("d;", start, end)) { start += 2; return 10844; }
                    if(str.startsIdx("slope;", start, end)) { start += 6; return 10840; }
                    if(str.startsIdx("v;", start, end)) { start += 2; return 10842; }
                    break;
                }
                if(start < end && str[start] == 'g') {
                    start++;
                    if(start < end && str[start] == ';') { start++; return 8736; }
                    if(str.startsIdx("e;", start, end)) { start += 2; return 10660; }
                    if(str.startsIdx("le;", start, end)) { start += 3; return 8736; }
                    if(str.startsIdx("msd", start, end)) {
                        start += 3;
                        if(start < end && str[start] == ';') { start++; return 8737; }
                        if(start < end && str[start] == 'a') {
                            start++;
                            if(str.startsIdx("a;", start, end)) { start += 2; return 10664; }
                            if(str.startsIdx("b;", start, end)) { start += 2; return 10665; }
                            if(str.startsIdx("c;", start, end)) { start += 2; return 10666; }
                            if(str.startsIdx("d;", start, end)) { start += 2; return 10667; }
                            if(str.startsIdx("e;", start, end)) { start += 2; return 10668; }
                            if(str.startsIdx("f;", start, end)) { start += 2; return 10669; }
                            if(str.startsIdx("g;", start, end)) { start += 2; return 10670; }
                            if(str.startsIdx("h;", start, end)) { start += 2; return 10671; }
                        }
                        break;
                    }
                    if(str.startsIdx("rt;", start, end)) { start += 3; return 8735; }
                    if(str.startsIdx("rtvb;", start, end)) { start += 5; return 8894; }
                    if(str.startsIdx("rtvbd;", start, end)) { start += 6; return 10653; }
                    if(str.startsIdx("sph;", start, end)) { start += 4; return 8738; }
                    if(str.startsIdx("st;", start, end)) { start += 3; return 197; }
                    if(str.startsIdx("zarr;", start, end)) { start += 5; return 9084; }
                }
                break;
            case 'o':
                if(str.startsIdx("gon;", start, end)) { start += 4; return 261; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120146; }
                break;
            case 'p':
                if(start < end && str[start] == ';') { start++; return 8776; }
                if(str.startsIdx("E;", start, end)) { start += 2; return 10864; }
                if(str.startsIdx("acir;", start, end)) { start += 5; return 10863; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 8778; }
                if(str.startsIdx("id;", start, end)) { start += 3; return 8779; }
                if(str.startsIdx("os;", start, end)) { start += 3; return 39; }
                if(str.startsIdx("prox;", start, end)) { start += 5; return 8776; }
                if(str.startsIdx("proxeq;", start, end)) { start += 7; return 8778; }
                break;
            case 'r':
                if(str.startsIdx("ing", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 229;
                }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119990; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 42; }
                if(str.startsIdx("ymp;", start, end)) { start += 4; return 8776; }
                if(str.startsIdx("ympeq;", start, end)) { start += 6; return 8781; }
                break;
            case 't':
                if(str.startsIdx("ilde", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 227;
                }
                break;
            case 'u':
                if(str.startsIdx("ml", start, end)) {
                    start += 2 + (start + 2 < end && str[start + 2] == ';');
                    return 228;
                }
                break;
            case 'w':
                if(str.startsIdx("conint;", start, end)) { start += 7; return 8755; }
                if(str.startsIdx("int;", start, end)) { start += 4; return 10769; }
                break;
        }
        return -1;
    }

    int entityLowerB(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'N': if(str.startsIdx("ot;", start, end)) { start += 3; return 10989; } break;
            case 'a':
                if(str.startsIdx("ck", start, end)) {
                    start += 2;
                    if(str.startsIdx("cong;", start, end)) { start += 5; return 8780; }
                    if(str.startsIdx("epsilon;", start, end)) { start += 8; return 1014; }
                    if(str.startsIdx("prime;", start, end)) { start += 6; return 8245; }
                    if(str.startsIdx("sim;", start, end)) { start += 4; return 8765; }
                    if(str.startsIdx("simeq;", start, end)) { start += 6; return 8909; }
                    break;
                }
                if(start < end && str[start] == 'r') {
                    start++;
                    if(str.startsIdx("vee;", start, end)) { start += 4; return 8893; }
                    if(str.startsIdx("wed;", start, end)) { start += 4; return 8965; }
                    if(str.startsIdx("wedge;", start, end)) { start += 6; return 8965; }
                }
                break;
            case 'b':
                if(str.startsIdx("rk", start, end)) {
                    start += 2;
                    if(start < end && str[start] == ';') { start++; return 9141; }
                    if(str.startsIdx("tbrk;", start, end)) { start += 5; return 9142; }
                    break;
                }
                break;
            case 'c':
                if(str.startsIdx("ong;", start, end)) { start += 4; return 8780; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1073; }
                break;
            case 'd': if(str.startsIdx("quo;", start, end)) { start += 4; return 8222; } break;
            case 'e':
                if(str.startsIdx("caus", start, end)) {
                    start += 4;
                    if(start < end && str[start] == ';') { start++; return 8757; }
                    if(str.startsIdx("e;", start, end)) { start += 2; return 8757; }
                    break;
                }
                if(str.startsIdx("mptyv;", start, end)) { start += 6; return 10672; }
                if(str.startsIdx("psi;", start, end)) { start += 4; return 1014; }
                if(str.startsIdx("rnou;", start, end)) { start += 5; return 8492; }
                if(start < end && str[start] == 't') {
                    start++;
                    if(str.startsIdx("a;", start, end)) { start += 2; return 946; }
                    if(str.startsIdx("h;", start, end)) { start += 2; return 8502; }
                    if(str.startsIdx("ween;", start, end)) { start += 5; return 8812; }
                }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120095; } break;
            case 'i':
                if(start < end && str[start] == 'g') {
                    start++;
                    if(start < end && str[start] == 'c') {
                        start++;
                        if(str.startsIdx("ap;", start, end)) { start += 3; return 8898; }
                        if(str.startsIdx("irc;", start, end)) { start += 4; return 9711; }
                        if(str.startsIdx("up;", start, end)) { start += 3; return 8899; }
                        break;
                    }
                    if(start < end && str[start] == 'o') {
                        start++;
                        if(str.startsIdx("dot;", start, end)) { start += 4; return 10752; }
                        if(str.startsIdx("plus;", start, end)) { start += 5; return 10753; }
                        if(str.startsIdx("times;", start, end)) { start += 6; return 10754; }
                        break;
                    }
                    if(str.startsIdx("sqcup;", start, end)) { start += 6; return 10758; }
                    if(str.startsIdx("star;", start, end)) { start += 5; return 9733; }
                    if(str.startsIdx("triangle", start, end)) {
                        start += 8;
                        if(str.startsIdx("down;", start, end)) { start += 5; return 9661; }
                        if(str.startsIdx("up;", start, end)) { start += 3; return 9651; }
                        break;
                    }
                    if(str.startsIdx("uplus;", start, end)) { start += 6; return 10756; }
                    if(str.startsIdx("vee;", start, end)) { start += 4; return 8897; }
                    if(str.startsIdx("wedge;", start, end)) { start += 6; return 8896; }
                }
                break;
            case 'k': if(str.startsIdx("arow;", start, end)) { start += 5; return 10509; } break;
            case 'l':
                if(str.startsIdx("ack", start, end)) {
                    start += 3;
                    if(str.startsIdx("lozenge;", start, end)) { start += 8; return 10731; }
                    if(str.startsIdx("square;", start, end)) { start += 7; return 9642; }
                    if(str.startsIdx("triangle", start, end)) {
                        start += 8;
                        if(start < end && str[start] == ';') { start++; return 9652; }
                        if(str.startsIdx("down;", start, end)) { start += 5; return 9662; }
                        if(str.startsIdx("left;", start, end)) { start += 5; return 9666; }
                        if(str.startsIdx("right;", start, end)) { start += 6; return 9656; }
                    }
                    break;
                }
                if(str.startsIdx("ank;", start, end)) { start += 4; return 9251; }
                if(str.startsIdx("k12;", start, end)) { start += 4; return 9618; }
                if(str.startsIdx("k14;", start, end)) { start += 4; return 9617; }
                if(str.startsIdx("k34;", start, end)) { start += 4; return 9619; }
                if(str.startsIdx("ock;", start, end)) { start += 4; return 9608; }
                break;
            case 'n':
                if(str.startsIdx("e;", start, end)) { start += 2; return -4071653; }
                if(str.startsIdx("equiv;", start, end)) { start += 6; return -576856293; }
                if(str.startsIdx("ot;", start, end)) { start += 3; return 8976; }
                break;
            case 'o':
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120147; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 8869; }
                if(str.startsIdx("ttom;", start, end)) { start += 5; return 8869; }
                if(str.startsIdx("wtie;", start, end)) { start += 5; return 8904; }
                if(start < end && str[start] == 'x') {
                    start++;
                    if(start + 1 >= end) break;
                    if(str[start] == 'D') {
                        start++;
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'L') { start += 2; return 9559; }
                        if(str[start] == 'R') { start += 2; return 9556; }
                        if(str[start] == 'l') { start += 2; return 9558; }
                        if(str[start] == 'r') { start += 2; return 9555; }
                        break;
                    }
                    if(str[start] == 'H') {
                        start++;
                        if(str[start] == ';') { start++; return 9552; }
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'D') { start += 2; return 9574; }
                        if(str[start] == 'U') { start += 2; return 9577; }
                        if(str[start] == 'd') { start += 2; return 9572; }
                        if(str[start] == 'u') { start += 2; return 9575; }
                        break;
                    }
                    if(str[start] == 'U') {
                        start++;
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'L') { start += 2; return 9565; }
                        if(str[start] == 'R') { start += 2; return 9562; }
                        if(str[start] == 'l') { start += 2; return 9564; }
                        if(str[start] == 'r') { start += 2; return 9561; }
                        break;
                    }
                    if(str[start] == 'V') {
                        start++;
                        if(str[start] == ';') { start++; return 9553; }
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'H') { start += 2; return 9580; }
                        if(str[start] == 'L') { start += 2; return 9571; }
                        if(str[start] == 'R') { start += 2; return 9568; }
                        if(str[start] == 'h') { start += 2; return 9579; }
                        if(str[start] == 'l') { start += 2; return 9570; }
                        if(str[start] == 'r') { start += 2; return 9567; }
                        break;
                    }
                    if(str.startsIdx("box;", start, end)) { start += 4; return 10697; }
                    if(str[start] == 'd') {
                        start++;
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'L') { start += 2; return 9557; }
                        if(str[start] == 'R') { start += 2; return 9554; }
                        if(str[start] == 'l') { start += 2; return 9488; }
                        if(str[start] == 'r') { start += 2; return 9484; }
                        break;
                    }
                    if(str[start] == 'h') {
                        start++;
                        if(str[start] == ';') { start++; return 9472; }
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'D') { start += 2; return 9573; }
                        if(str[start] == 'U') { start += 2; return 9576; }
                        if(str[start] == 'd') { start += 2; return 9516; }
                        if(str[start] == 'u') { start += 2; return 9524; }
                        break;
                    }
                    if(str.startsIdx("minus;", start, end)) { start += 6; return 8863; }
                    if(str.startsIdx("plus;", start, end)) { start += 5; return 8862; }
                    if(str.startsIdx("times;", start, end)) { start += 6; return 8864; }
                    if(str[start] == 'u') {
                        start++;
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'L') { start += 2; return 9563; }
                        if(str[start] == 'R') { start += 2; return 9560; }
                        if(str[start] == 'l') { start += 2; return 9496; }
                        if(str[start] == 'r') { start += 2; return 9492; }
                        break;
                    }
                    if(str[start] == 'v') {
                        start++;
                        if(str[start] == ';') { start++; return 9474; }
                        if(start + 1 >= end || str[start + 1] != ';') break;
                        if(str[start] == 'H') { start += 2; return 9578; }
                        if(str[start] == 'L') { start += 2; return 9569; }
                        if(str[start] == 'R') { start += 2; return 9566; }
                        if(str[start] == 'h') { start += 2; return 9532; }
                        if(str[start] == 'l') { start += 2; return 9508; }
                        if(str[start] == 'r') { start += 2; return 9500; }
                        break;
                    }
                }
                break;
            case 'p': if(str.startsIdx("rime;", start, end)) { start += 5; return 8245; } break;
            case 'r':
                if(str.startsIdx("eve;", start, end)) { start += 4; return 728; }
                if(str.startsIdx("vbar", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 166;
                }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119991; }
                if(str.startsIdx("emi;", start, end)) { start += 4; return 8271; }
                if(str.startsIdx("im;", start, end)) { start += 3; return 8765; }
                if(str.startsIdx("ime;", start, end)) { start += 4; return 8909; }
                if(str.startsIdx("ol;", start, end)) { start += 3; return 92; }
                if(str.startsIdx("olb;", start, end)) { start += 4; return 10693; }
                if(str.startsIdx("olhsub;", start, end)) { start += 7; return 10184; }
                break;
            case 'u':
                if(str.startsIdx("ll;", start, end)) { start += 3; return 8226; }
                if(str.startsIdx("llet;", start, end)) { start += 5; return 8226; }
                if(str.startsIdx("mp;", start, end)) { start += 3; return 8782; }
                if(str.startsIdx("mpE;", start, end)) { start += 4; return 10926; }
                if(str.startsIdx("mpe;", start, end)) { start += 4; return 8783; }
                if(str.startsIdx("mpeq;", start, end)) { start += 5; return 8783; }
                break;
        }
        return -1;
    }

    int entityLowerC(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("cute;", start, end)) { start += 5; return 263; }
                if(start < end && str[start] == 'p') {
                    start++;
                    if(start < end && str[start] == ';') { start++; return 8745; }
                    if(str.startsIdx("and;", start, end)) { start += 4; return 10820; }
                    if(str.startsIdx("brcup;", start, end)) { start += 6; return 10825; }
                    if(str.startsIdx("cap;", start, end)) { start += 4; return 10827; }
                    if(str.startsIdx("cup;", start, end)) { start += 4; return 10823; }
                    if(str.startsIdx("dot;", start, end)) { start += 4; return 10816; }
                    if(str.startsIdx("s;", start, end)) { start += 2; return -573242880; }
                    break;
                }
                if(str.startsIdx("ret;", start, end)) { start += 4; return 8257; }
                if(str.startsIdx("ron;", start, end)) { start += 4; return 711; }
                break;
            case 'c':
                if(str.startsIdx("aps;", start, end)) { start += 4; return 10829; }
                if(str.startsIdx("aron;", start, end)) { start += 5; return 269; }
                if(str.startsIdx("edil", start, end)) {
                    start += 4 + (start + 4 < end && str[start + 4] == ';');
                    return 231;
                }
                if(str.startsIdx("irc;", start, end)) { start += 4; return 265; }
                if(str.startsIdx("ups;", start, end)) { start += 4; return 10828; }
                if(str.startsIdx("upssm;", start, end)) { start += 6; return 10832; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 267; } break;
            case 'e':
                if(str.startsIdx("dil", start, end)) {
                    start += 3 + (start + 3 < end && str[start + 3] == ';');
                    return 184;
                }
                if(str.startsIdx("mptyv;", start, end)) { start += 6; return 10674; }
                if(str.startsIdx("nt", start, end)) {
                    start += 2;
                    if(str.startsIdx("erdot;", start, end)) { start += 6; return 183; }
                    if(start < end && str[start] == ';') start++;
                    return 162;
                }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120096; } break;
            case 'h':
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1095; }
                if(str.startsIdx("eck;", start, end)) { start += 4; return 10003; }
                if(str.startsIdx("eckmark;", start, end)) { start += 8; return 10003; }
                if(str.startsIdx("i;", start, end)) { start += 2; return 967; }
                break;
            case 'i':
                if(str.startsIdx("r;", start, end)) { start += 2; return 9675; }
                if(str.startsIdx("rE;", start, end)) { start += 3; return 10691; }
                if(str.startsIdx("rc;", start, end)) { start += 3; return 710; }
                if(str.startsIdx("rceq;", start, end)) { start += 5; return 8791; }
                if(str.startsIdx("rclearrowleft;", start, end)) { start += 14; return 8634; }
                if(str.startsIdx("rclearrowright;", start, end)) { start += 15; return 8635; }
                if(str.startsIdx("rcledR;", start, end)) { start += 7; return 174; }
                if(str.startsIdx("rcledS;", start, end)) { start += 7; return 9416; }
                if(str.startsIdx("rcledast;", start, end)) { start += 9; return 8859; }
                if(str.startsIdx("rcledcirc;", start, end)) { start += 10; return 8858; }
                if(str.startsIdx("rcleddash;", start, end)) { start += 10; return 8861; }
                if(str.startsIdx("re;", start, end)) { start += 3; return 8791; }
                if(str.startsIdx("rfnint;", start, end)) { start += 7; return 10768; }
                if(str.startsIdx("rmid;", start, end)) { start += 5; return 10991; }
                if(str.startsIdx("rscir;", start, end)) { start += 6; return 10690; }
                break;
            case 'l':
                if(str.startsIdx("ubs;", start, end)) { start += 4; return 9827; }
                if(str.startsIdx("ubsuit;", start, end)) { start += 7; return 9827; }
                break;
            case 'o':
                if(str.startsIdx("lon;", start, end)) { start += 4; return 58; }
                if(str.startsIdx("lone;", start, end)) { start += 5; return 8788; }
                if(str.startsIdx("loneq;", start, end)) { start += 6; return 8788; }
                if(str.startsIdx("mma;", start, end)) { start += 4; return 44; }
                if(str.startsIdx("mmat;", start, end)) { start += 5; return 64; }
                if(str.startsIdx("mp;", start, end)) { start += 3; return 8705; }
                if(str.startsIdx("mpfn;", start, end)) { start += 5; return 8728; }
                if(str.startsIdx("mplement;", start, end)) { start += 9; return 8705; }
                if(str.startsIdx("mplexes;", start, end)) { start += 8; return 8450; }
                if(str.startsIdx("ng;", start, end)) { start += 3; return 8773; }
                if(str.startsIdx("ngdot;", start, end)) { start += 6; return 10861; }
                if(str.startsIdx("nint;", start, end)) { start += 5; return 8750; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120148; }
                if(str.startsIdx("prod;", start, end)) { start += 5; return 8720; }
                if(str.startsIdx("py", start, end)) {
                    start += 2;
                    if(str.startsIdx("sr;", start, end)) { start += 3; return 8471; }
                    if(start < end && str[start] == ';') start++;
                    return 169;
                }
                break;
            case 'r':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8629; }
                if(str.startsIdx("oss;", start, end)) { start += 4; return 10007; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119992; }
                if(str.startsIdx("ub;", start, end)) { start += 3; return 10959; }
                if(str.startsIdx("ube;", start, end)) { start += 4; return 10961; }
                if(str.startsIdx("up;", start, end)) { start += 3; return 10960; }
                if(str.startsIdx("upe;", start, end)) { start += 4; return 10962; }
                break;
            case 't': if(str.startsIdx("dot;", start, end)) { start += 4; return 8943; } break;
            case 'u':
                if(start < end) {
                    switch(str[start++]) {
                        case 'd':
                            if(str.startsIdx("arrl;", start, end)) { start += 5; return 10552; }
                            if(str.startsIdx("arrr;", start, end)) { start += 5; return 10549; }
                            break;
                        case 'e':
                            if(str.startsIdx("pr;", start, end)) { start += 3; return 8926; }
                            if(str.startsIdx("sc;", start, end)) { start += 3; return 8927; }
                            break;
                        case 'l':
                            if(str.startsIdx("arr;", start, end)) { start += 4; return 8630; }
                            if(str.startsIdx("arrp;", start, end)) { start += 5; return 10557; }
                            break;
                        case 'p':
                            if(start < end && str[start] == ';') { start++; return 8746; }
                            if(str.startsIdx("brcap;", start, end)) { start += 6; return 10824; }
                            if(str.startsIdx("cap;", start, end)) { start += 4; return 10822; }
                            if(str.startsIdx("cup;", start, end)) { start += 4; return 10826; }
                            if(str.startsIdx("dot;", start, end)) { start += 4; return 8845; }
                            if(str.startsIdx("or;", start, end)) { start += 3; return 10821; }
                            if(str.startsIdx("s;", start, end)) { start += 2; return -573308416; }
                            break;
                        case 'r':
                            if(str.startsIdx("arr;", start, end)) { start += 4; return 8631; }
                            if(str.startsIdx("arrm;", start, end)) { start += 5; return 10556; }
                            if(str.startsIdx("lyeqprec;", start, end)) { start += 9; return 8926; }
                            if(str.startsIdx("lyeqsucc;", start, end)) { start += 9; return 8927; }
                            if(str.startsIdx("lyvee;", start, end)) { start += 6; return 8910; }
                            if(str.startsIdx("lywedge;", start, end)) { start += 8; return 8911; }
                            if(str.startsIdx("ren", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 164; }
                            if(str.startsIdx("vearrowleft;", start, end)) { start += 12; return 8630; }
                            if(str.startsIdx("vearrowright;", start, end)) { start += 13; return 8631; }
                            break;
                        case 'v': if(str.startsIdx("ee;", start, end)) { start += 3; return 8910; } break;
                        case 'w': if(str.startsIdx("ed;", start, end)) { start += 3; return 8911; } break;
                    }
                    break;
                }
                break;
            case 'w':
                if(str.startsIdx("conint;", start, end)) { start += 7; return 8754; }
                if(str.startsIdx("int;", start, end)) { start += 4; return 8753; }
                break;
            case 'y': if(str.startsIdx("lcty;", start, end)) { start += 5; return 9005; } break;
        }
        return -1;
    }

    int entityLowerD(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A': if(str.startsIdx("rr;", start, end)) { start += 3; return 8659; } break;
            case 'H': if(str.startsIdx("ar;", start, end)) { start += 3; return 10597; } break;
            case 'a':
                if(str.startsIdx("gger;", start, end)) { start += 5; return 8224; }
                if(str.startsIdx("leth;", start, end)) { start += 5; return 8504; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8595; }
                if(str.startsIdx("sh;", start, end)) { start += 3; return 8208; }
                if(str.startsIdx("shv;", start, end)) { start += 4; return 8867; }
                break;
            case 'b':
                if(str.startsIdx("karow;", start, end)) { start += 6; return 10511; }
                if(str.startsIdx("lac;", start, end)) { start += 4; return 733; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 271; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1076; }
                break;
            case 'd':
                if(start < end && str[start] == ';') { start++; return 8518; }
                if(str.startsIdx("agger;", start, end)) { start += 6; return 8225; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8650; }
                if(str.startsIdx("otseq;", start, end)) { start += 6; return 10871; }
                break;
            case 'e':
                if(start < end && str[start] == 'g') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 176; }
                if(str.startsIdx("lta;", start, end)) { start += 4; return 948; }
                if(str.startsIdx("mptyv;", start, end)) { start += 6; return 10673; }
                break;
            case 'f':
                if(str.startsIdx("isht;", start, end)) { start += 5; return 10623; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120097; }
                break;
            case 'h':
                if(str.startsIdx("arl;", start, end)) { start += 4; return 8643; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8642; }
                break;
            case 'i':
                if(str.startsIdx("am;", start, end)) { start += 3; return 8900; }
                if(str.startsIdx("amond;", start, end)) { start += 6; return 8900; }
                if(str.startsIdx("amondsuit;", start, end)) { start += 10; return 9830; }
                if(str.startsIdx("ams;", start, end)) { start += 4; return 9830; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 168; }
                if(str.startsIdx("gamma;", start, end)) { start += 6; return 989; }
                if(str.startsIdx("sin;", start, end)) { start += 4; return 8946; }
                if(str.startsIdx("v;", start, end)) { start += 2; return 247; }
                if(str.startsIdx("vide", start, end)) {
                    start += 4;
                    if(start < end && str[start] == ';') { start++; return 247; }
                    if(str.startsIdx("ontimes;", start, end)) { start += 8; return 8903; }
                    return 247;
                }
                if(str.startsIdx("vonx;", start, end)) { start += 5; return 8903; }
                break;
            case 'j': if(str.startsIdx("cy;", start, end)) { start += 3; return 1106; } break;
            case 'l':
                if(str.startsIdx("corn;", start, end)) { start += 5; return 8990; }
                if(str.startsIdx("crop;", start, end)) { start += 5; return 8973; }
                break;
            case 'o':
                if(str.startsIdx("llar;", start, end)) { start += 5; return 36; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120149; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 729; }
                if(str.startsIdx("teq;", start, end)) { start += 4; return 8784; }
                if(str.startsIdx("teqdot;", start, end)) { start += 7; return 8785; }
                if(str.startsIdx("tminus;", start, end)) { start += 7; return 8760; }
                if(str.startsIdx("tplus;", start, end)) { start += 6; return 8724; }
                if(str.startsIdx("tsquare;", start, end)) { start += 8; return 8865; }
                if(str.startsIdx("ublebarwedge;", start, end)) { start += 13; return 8966; }
                if(str.startsIdx("wnarrow;", start, end)) { start += 8; return 8595; }
                if(str.startsIdx("wndownarrows;", start, end)) { start += 13; return 8650; }
                if(str.startsIdx("wnharpoonleft;", start, end)) { start += 14; return 8643; }
                if(str.startsIdx("wnharpoonright;", start, end)) { start += 15; return 8642; }
                break;
            case 'r':
                if(str.startsIdx("bkarow;", start, end)) { start += 7; return 10512; }
                if(str.startsIdx("corn;", start, end)) { start += 5; return 8991; }
                if(str.startsIdx("crop;", start, end)) { start += 5; return 8972; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119993; }
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1109; }
                if(str.startsIdx("ol;", start, end)) { start += 3; return 10742; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 273; }
                break;
            case 't':
                if(str.startsIdx("dot;", start, end)) { start += 4; return 8945; }
                if(str.startsIdx("ri;", start, end)) { start += 3; return 9663; }
                if(str.startsIdx("rif;", start, end)) { start += 4; return 9662; }
                break;
            case 'u':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8693; }
                if(str.startsIdx("har;", start, end)) { start += 4; return 10607; }
                break;
            case 'w': if(str.startsIdx("angle;", start, end)) { start += 6; return 10662; } break;
            case 'z':
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1119; }
                if(str.startsIdx("igrarr;", start, end)) { start += 7; return 10239; }
                break;
        }
        return -1;
    }

    int entityLowerE(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'D':
                if(str.startsIdx("Dot;", start, end)) { start += 4; return 10871; }
                if(str.startsIdx("ot;", start, end)) { start += 3; return 8785; }
                break;
            case 'a':
                if(str.startsIdx("cute", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 233; }
                if(str.startsIdx("ster;", start, end)) { start += 5; return 10862; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 283; }
                if(str.startsIdx("ir;", start, end)) { start += 3; return 8790; }
                if(str.startsIdx("irc", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 234; }
                if(str.startsIdx("olon;", start, end)) { start += 5; return 8789; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1101; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 279; } break;
            case 'e': if(start < end && str[start] == ';') { start++; return 8519; } break;
            case 'f':
                if(str.startsIdx("Dot;", start, end)) { start += 4; return 8786; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120098; }
                break;
            case 'g':
                if(start < end && str[start] == ';') { start++; return 10906; }
                if(str.startsIdx("rave", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 232; }
                if(str.startsIdx("s;", start, end)) { start += 2; return 10902; }
                if(str.startsIdx("sdot;", start, end)) { start += 5; return 10904; }
                break;
            case 'l':
                if(start < end && str[start] == ';') { start++; return 10905; }
                if(str.startsIdx("inters;", start, end)) { start += 7; return 9191; }
                if(str.startsIdx("l;", start, end)) { start += 2; return 8467; }
                if(str.startsIdx("s;", start, end)) { start += 2; return 10901; }
                if(str.startsIdx("sdot;", start, end)) { start += 5; return 10903; }
                break;
            case 'm':
                if(str.startsIdx("acr;", start, end)) { start += 4; return 275; }
                if(str.startsIdx("pty;", start, end)) { start += 4; return 8709; }
                if(str.startsIdx("ptyset;", start, end)) { start += 7; return 8709; }
                if(str.startsIdx("ptyv;", start, end)) { start += 5; return 8709; }
                if(str.startsIdx("sp13;", start, end)) { start += 5; return 8196; }
                if(str.startsIdx("sp14;", start, end)) { start += 5; return 8197; }
                if(str.startsIdx("sp;", start, end)) { start += 3; return 8195; }
                break;
            case 'n':
                if(str.startsIdx("g;", start, end)) { start += 2; return 331; }
                if(str.startsIdx("sp;", start, end)) { start += 3; return 8194; }
                break;
            case 'o':
                if(str.startsIdx("gon;", start, end)) { start += 4; return 281; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120150; }
                break;
            case 'p':
                if(str.startsIdx("ar;", start, end)) { start += 3; return 8917; }
                if(str.startsIdx("arsl;", start, end)) { start += 5; return 10723; }
                if(str.startsIdx("lus;", start, end)) { start += 4; return 10865; }
                if(str.startsIdx("si;", start, end)) { start += 3; return 949; }
                if(str.startsIdx("silon;", start, end)) { start += 6; return 949; }
                if(str.startsIdx("siv;", start, end)) { start += 4; return 1013; }
                break;
            case 'q':
                if(str.startsIdx("circ;", start, end)) { start += 5; return 8790; }
                if(str.startsIdx("colon;", start, end)) { start += 6; return 8789; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return 8770; }
                if(str.startsIdx("slantgtr;", start, end)) { start += 9; return 10902; }
                if(str.startsIdx("slantless;", start, end)) { start += 10; return 10901; }
                if(str.startsIdx("uals;", start, end)) { start += 5; return 61; }
                if(str.startsIdx("uest;", start, end)) { start += 5; return 8799; }
                if(str.startsIdx("uiv;", start, end)) { start += 4; return 8801; }
                if(str.startsIdx("uivDD;", start, end)) { start += 6; return 10872; }
                if(str.startsIdx("vparsl;", start, end)) { start += 7; return 10725; }
                break;
            case 'r':
                if(str.startsIdx("Dot;", start, end)) { start += 4; return 8787; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 10609; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 8495; }
                if(str.startsIdx("dot;", start, end)) { start += 4; return 8784; }
                if(str.startsIdx("im;", start, end)) { start += 3; return 8770; }
                break;
            case 't':
                if(str.startsIdx("a;", start, end)) { start += 2; return 951; }
                if(start < end && str[start] == 'h') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 240; }
                break;
            case 'u':
                if(str.startsIdx("ml", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 235; }
                if(str.startsIdx("ro;", start, end)) { start += 3; return 8364; }
                break;
            case 'x':
                if(str.startsIdx("cl;", start, end)) { start += 3; return 33; }
                if(str.startsIdx("ist;", start, end)) { start += 4; return 8707; }
                if(str.startsIdx("pectation;", start, end)) { start += 10; return 8496; }
                if(str.startsIdx("ponentiale;", start, end)) { start += 11; return 8519; }
                break;
        }
        return -1;
    }

    int entityLowerF(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a': if(str.startsIdx("llingdotseq;", start, end)) { start += 12; return 8786; } break;
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1092; } break;
            case 'e': if(str.startsIdx("male;", start, end)) { start += 5; return 9792; } break;
            case 'f':
                if(str.startsIdx("ilig;", start, end)) { start += 5; return 64259; }
                if(str.startsIdx("lig;", start, end)) { start += 4; return 64256; }
                if(str.startsIdx("llig;", start, end)) { start += 5; return 64260; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120099; }
                break;
            case 'i': if(str.startsIdx("lig;", start, end)) { start += 4; return 64257; } break;
            case 'j': if(str.startsIdx("lig;", start, end)) { start += 4; return -6750314; } break;
            case 'l':
                if(str.startsIdx("at;", start, end)) { start += 3; return 9837; }
                if(str.startsIdx("lig;", start, end)) { start += 4; return 64258; }
                if(str.startsIdx("tns;", start, end)) { start += 4; return 9649; }
                break;
            case 'n': if(str.startsIdx("of;", start, end)) { start += 3; return 402; } break;
            case 'o':
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120151; }
                if(str.startsIdx("rall;", start, end)) { start += 5; return 8704; }
                if(str.startsIdx("rk;", start, end)) { start += 3; return 8916; }
                if(str.startsIdx("rkv;", start, end)) { start += 4; return 10969; }
                break;
            case 'p': if(str.startsIdx("artint;", start, end)) { start += 7; return 10765; } break;
            case 'r':
                if(str.startsIdx("ac", start, end)) {
                    start += 2;
                    if(str.startsIdx("12", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 189; }
                    if(str.startsIdx("13;", start, end)) { start += 3; return 8531; }
                    if(str.startsIdx("14", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 188; }
                    if(str.startsIdx("15;", start, end)) { start += 3; return 8533; }
                    if(str.startsIdx("16;", start, end)) { start += 3; return 8537; }
                    if(str.startsIdx("18;", start, end)) { start += 3; return 8539; }
                    if(str.startsIdx("23;", start, end)) { start += 3; return 8532; }
                    if(str.startsIdx("25;", start, end)) { start += 3; return 8534; }
                    if(str.startsIdx("34", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 190; }
                    if(str.startsIdx("35;", start, end)) { start += 3; return 8535; }
                    if(str.startsIdx("38;", start, end)) { start += 3; return 8540; }
                    if(str.startsIdx("45;", start, end)) { start += 3; return 8536; }
                    if(str.startsIdx("56;", start, end)) { start += 3; return 8538; }
                    if(str.startsIdx("58;", start, end)) { start += 3; return 8541; }
                    if(str.startsIdx("78;", start, end)) { start += 3; return 8542; }
                    break;
                }
                if(str.startsIdx("asl;", start, end)) { start += 4; return 8260; }
                if(str.startsIdx("own;", start, end)) { start += 4; return 8994; }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 119995; } break;
        }
        return -1;
    }

    int entityLowerG(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'E':
                if(start < end && str[start] == ';') { start++; return 8807; }
                if(str.startsIdx("l;", start, end)) { start += 2; return 10892; }
                break;
            case 'a':
                if(str.startsIdx("cute;", start, end)) { start += 5; return 501; }
                if(str.startsIdx("mma;", start, end)) { start += 4; return 947; }
                if(str.startsIdx("mmad;", start, end)) { start += 5; return 989; }
                if(str.startsIdx("p;", start, end)) { start += 2; return 10886; }
                break;
            case 'b': if(str.startsIdx("reve;", start, end)) { start += 5; return 287; } break;
            case 'c':
                if(str.startsIdx("irc;", start, end)) { start += 4; return 285; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1075; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 289; } break;
            case 'e':
                if(start < end && str[start] == ';') { start++; return 8805; }
                if(str.startsIdx("l;", start, end)) { start += 2; return 8923; }
                if(str.startsIdx("q;", start, end)) { start += 2; return 8805; }
                if(str.startsIdx("qq;", start, end)) { start += 3; return 8807; }
                if(str.startsIdx("qslant;", start, end)) { start += 7; return 10878; }
                if(str.startsIdx("s;", start, end)) { start += 2; return 10878; }
                if(str.startsIdx("scc;", start, end)) { start += 4; return 10921; }
                if(str.startsIdx("sdot;", start, end)) { start += 5; return 10880; }
                if(str.startsIdx("sdoto;", start, end)) { start += 6; return 10882; }
                if(str.startsIdx("sdotol;", start, end)) { start += 7; return 10884; }
                if(str.startsIdx("sl;", start, end)) { start += 3; return -584908288; }
                if(str.startsIdx("sles;", start, end)) { start += 5; return 10900; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120100; } break;
            case 'g':
                if(start < end && str[start] == ';') { start++; return 8811; }
                if(str.startsIdx("g;", start, end)) { start += 2; return 8921; }
                break;
            case 'i': if(str.startsIdx("mel;", start, end)) { start += 4; return 8503; } break;
            case 'j': if(str.startsIdx("cy;", start, end)) { start += 3; return 1107; } break;
            case 'l':
                if(start < end && str[start] == ';') { start++; return 8823; }
                if(str.startsIdx("E;", start, end)) { start += 2; return 10898; }
                if(str.startsIdx("a;", start, end)) { start += 2; return 10917; }
                if(str.startsIdx("j;", start, end)) { start += 2; return 10916; }
                break;
            case 'n':
                if(str.startsIdx("E;", start, end)) { start += 2; return 8809; }
                if(str.startsIdx("ap;", start, end)) { start += 3; return 10890; }
                if(str.startsIdx("approx;", start, end)) { start += 7; return 10890; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 10888; }
                if(str.startsIdx("eq;", start, end)) { start += 3; return 10888; }
                if(str.startsIdx("eqq;", start, end)) { start += 4; return 8809; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return 8935; }
                break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120152; } break;
            case 'r': if(str.startsIdx("ave;", start, end)) { start += 4; return 96; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 8458; }
                if(str.startsIdx("im;", start, end)) { start += 3; return 8819; }
                if(str.startsIdx("ime;", start, end)) { start += 4; return 10894; }
                if(str.startsIdx("iml;", start, end)) { start += 4; return 10896; }
                break;
            case 't':
                if(str.startsIdx("cc;", start, end)) { start += 3; return 10919; }
                if(str.startsIdx("cir;", start, end)) { start += 4; return 10874; }
                if(str.startsIdx("dot;", start, end)) { start += 4; return 8919; }
                if(str.startsIdx("lPar;", start, end)) { start += 5; return 10645; }
                if(str.startsIdx("quest;", start, end)) { start += 6; return 10876; }
                if(str.startsIdx("rapprox;", start, end)) { start += 8; return 10886; }
                if(str.startsIdx("rarr;", start, end)) { start += 5; return 10616; }
                if(str.startsIdx("rdot;", start, end)) { start += 5; return 8919; }
                if(str.startsIdx("reqless;", start, end)) { start += 8; return 8923; }
                if(str.startsIdx("reqqless;", start, end)) { start += 9; return 10892; }
                if(str.startsIdx("rless;", start, end)) { start += 6; return 8823; }
                if(str.startsIdx("rsim;", start, end)) { start += 5; return 8819; }
                if(start < end && str[start] == ';') start++;
                return 62;
            case 'v':
                if(str.startsIdx("ertneqq;", start, end)) { start += 8; return -577437184; }
                if(str.startsIdx("nE;", start, end)) { start += 3; return -577437184; }
                break;
        }
        return -1;
    }
    int entityLowerH(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A': if(str.startsIdx("rr;", start, end)) { start += 3; return 8660; } break;
            case 'a':
                if(str.startsIdx("irsp;", start, end)) { start += 5; return 8202; }
                if(str.startsIdx("lf;", start, end)) { start += 3; return 189; }
                if(str.startsIdx("milt;", start, end)) { start += 5; return 8459; }
                if(str.startsIdx("rdcy;", start, end)) { start += 5; return 1098; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8596; }
                if(str.startsIdx("rrcir;", start, end)) { start += 6; return 10568; }
                if(str.startsIdx("rrw;", start, end)) { start += 4; return 8621; }
                break;
            case 'b': if(str.startsIdx("ar;", start, end)) { start += 3; return 8463; } break;
            case 'c': if(str.startsIdx("irc;", start, end)) { start += 4; return 293; } break;
            case 'e':
                if(str.startsIdx("arts;", start, end)) { start += 5; return 9829; }
                if(str.startsIdx("artsuit;", start, end)) { start += 8; return 9829; }
                if(str.startsIdx("llip;", start, end)) { start += 5; return 8230; }
                if(str.startsIdx("rcon;", start, end)) { start += 5; return 8889; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120101; } break;
            case 'k':
                if(str.startsIdx("searow;", start, end)) { start += 7; return 10533; }
                if(str.startsIdx("swarow;", start, end)) { start += 7; return 10534; }
                break;
            case 'o':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8703; }
                if(str.startsIdx("mtht;", start, end)) { start += 5; return 8763; }
                if(str.startsIdx("okleftarrow;", start, end)) { start += 12; return 8617; }
                if(str.startsIdx("okrightarrow;", start, end)) { start += 13; return 8618; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120153; }
                if(str.startsIdx("rbar;", start, end)) { start += 5; return 8213; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119997; }
                if(str.startsIdx("lash;", start, end)) { start += 5; return 8463; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 295; }
                break;
            case 'y':
                if(str.startsIdx("bull;", start, end)) { start += 5; return 8259; }
                if(str.startsIdx("phen;", start, end)) { start += 5; return 8208; }
                break;
        }
        return -1;
    }

    int entityLowerI(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("cute", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 237; }
                break;
            case 'c':
                if(start < end && str[start] == ';') { start++; return 8291; }
                if(str.startsIdx("irc", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 238; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1080; }
                break;
            case 'e':
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1077; }
                if(str.startsIdx("xcl", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 161; }
                break;
            case 'f':
                if(str.startsIdx("f;", start, end)) { start += 2; return 8660; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120102; }
                break;
            case 'g':
                if(str.startsIdx("rave", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 236; }
                break;
            case 'i':
                if(start < end && str[start] == ';') { start++; return 8520; }
                if(str.startsIdx("iint;", start, end)) { start += 5; return 10764; }
                if(str.startsIdx("int;", start, end)) { start += 4; return 8749; }
                if(str.startsIdx("nfin;", start, end)) { start += 5; return 10716; }
                if(str.startsIdx("ota;", start, end)) { start += 4; return 8489; }
                break;
            case 'j': if(str.startsIdx("lig;", start, end)) { start += 4; return 307; } break;
            case 'm':
                if(str.startsIdx("acr;", start, end)) { start += 4; return 299; }
                if(str.startsIdx("age;", start, end)) { start += 4; return 8465; }
                if(str.startsIdx("agline;", start, end)) { start += 7; return 8464; }
                if(str.startsIdx("agpart;", start, end)) { start += 7; return 8465; }
                if(str.startsIdx("ath;", start, end)) { start += 4; return 305; }
                if(str.startsIdx("of;", start, end)) { start += 3; return 8887; }
                if(str.startsIdx("ped;", start, end)) { start += 4; return 437; }
                break;
            case 'n':
                if(start < end && str[start] == ';') { start++; return 8712; }
                if(str.startsIdx("care;", start, end)) { start += 5; return 8453; }
                if(str.startsIdx("fin;", start, end)) { start += 4; return 8734; }
                if(str.startsIdx("fintie;", start, end)) { start += 7; return 10717; }
                if(str.startsIdx("odot;", start, end)) { start += 5; return 305; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 8747; }
                if(str.startsIdx("tcal;", start, end)) { start += 5; return 8890; }
                if(str.startsIdx("tegers;", start, end)) { start += 7; return 8484; }
                if(str.startsIdx("tercal;", start, end)) { start += 7; return 8890; }
                if(str.startsIdx("tlarhk;", start, end)) { start += 7; return 10775; }
                if(str.startsIdx("tprod;", start, end)) { start += 6; return 10812; }
                break;
            case 'o':
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1105; }
                if(str.startsIdx("gon;", start, end)) { start += 4; return 303; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120154; }
                if(str.startsIdx("ta;", start, end)) { start += 3; return 953; }
                break;
            case 'p': if(str.startsIdx("rod;", start, end)) { start += 4; return 10812; } break;
            case 'q':
                if(str.startsIdx("uest", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 191; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119998; }
                if(str.startsIdx("in;", start, end)) { start += 3; return 8712; }
                if(str.startsIdx("inE;", start, end)) { start += 4; return 8953; }
                if(str.startsIdx("indot;", start, end)) { start += 6; return 8949; }
                if(str.startsIdx("ins;", start, end)) { start += 4; return 8948; }
                if(str.startsIdx("insv;", start, end)) { start += 5; return 8947; }
                if(str.startsIdx("inv;", start, end)) { start += 4; return 8712; }
                break;
            case 't':
                if(start < end && str[start] == ';') { start++; return 8290; }
                if(str.startsIdx("ilde;", start, end)) { start += 5; return 297; }
                break;
            case 'u':
                if(str.startsIdx("kcy;", start, end)) { start += 4; return 1110; }
                if(str.startsIdx("ml", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 239; }
                break;
        }
        return -1;
    }

    int entityLowerJ(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'c':
                if(str.startsIdx("irc;", start, end)) { start += 4; return 309; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1081; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120103; } break;
            case 'm': if(str.startsIdx("ath;", start, end)) { start += 4; return 567; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120155; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 119999; }
                if(str.startsIdx("ercy;", start, end)) { start += 5; return 1112; }
                break;
            case 'u': if(str.startsIdx("kcy;", start, end)) { start += 4; return 1108; } break;
        }
        return -1;
    }

    int entityLowerK(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("ppa;", start, end)) { start += 4; return 954; }
                if(str.startsIdx("ppav;", start, end)) { start += 5; return 1008; }
                break;
            case 'c':
                if(str.startsIdx("edil;", start, end)) { start += 5; return 311; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1082; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120104; } break;
            case 'g': if(str.startsIdx("reen;", start, end)) { start += 5; return 312; } break;
            case 'h': if(str.startsIdx("cy;", start, end)) { start += 3; return 1093; } break;
            case 'j': if(str.startsIdx("cy;", start, end)) { start += 3; return 1116; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120156; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 120000; } break;
        }
        return -1;
    }

    int entityLowerL(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8666; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8656; }
                if(str.startsIdx("tail;", start, end)) { start += 5; return 10523; }
                break;
            case 'B': if(str.startsIdx("arr;", start, end)) { start += 4; return 10510; } break;
            case 'E':
                if(start < end && str[start] == ';') { start++; return 8806; }
                if(str.startsIdx("g;", start, end)) { start += 2; return 10891; }
                break;
            case 'H': if(str.startsIdx("ar;", start, end)) { start += 3; return 10594; } break;
            case 'a':
                if(str.startsIdx("cute;", start, end)) { start += 5; return 314; }
                if(str.startsIdx("emptyv;", start, end)) { start += 7; return 10676; }
                if(str.startsIdx("gran;", start, end)) { start += 5; return 8466; }
                if(str.startsIdx("mbda;", start, end)) { start += 5; return 955; }
                if(str.startsIdx("ng;", start, end)) { start += 3; return 10216; }
                if(str.startsIdx("ngd;", start, end)) { start += 4; return 10641; }
                if(str.startsIdx("ngle;", start, end)) { start += 5; return 10216; }
                if(str.startsIdx("p;", start, end)) { start += 2; return 10885; }
                if(str.startsIdx("quo", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 171; }
                if(str.startsIdx("rr", start, end)) {
                    start += 2;
                    if(start < end && str[start] == ';') { start++; return 8592; }
                    if(str.startsIdx("b;", start, end)) { start += 2; return 8676; }
                    if(str.startsIdx("bfs;", start, end)) { start += 4; return 10527; }
                    if(str.startsIdx("fs;", start, end)) { start += 3; return 10525; }
                    if(str.startsIdx("hk;", start, end)) { start += 3; return 8617; }
                    if(str.startsIdx("lp;", start, end)) { start += 3; return 8619; }
                    if(str.startsIdx("pl;", start, end)) { start += 3; return 10553; }
                    if(str.startsIdx("sim;", start, end)) { start += 4; return 10611; }
                    if(str.startsIdx("tl;", start, end)) { start += 3; return 8610; }
                    break;
                }
                if(str.startsIdx("t;", start, end)) { start += 2; return 10923; }
                if(str.startsIdx("tail;", start, end)) { start += 5; return 10521; }
                if(str.startsIdx("te;", start, end)) { start += 3; return 10925; }
                if(str.startsIdx("tes;", start, end)) { start += 4; return -716111360; }
                break;
            case 'b':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 10508; }
                if(str.startsIdx("brk;", start, end)) { start += 4; return 10098; }
                if(str.startsIdx("race;", start, end)) { start += 5; return 123; }
                if(str.startsIdx("rack;", start, end)) { start += 5; return 91; }
                if(str.startsIdx("rke;", start, end)) { start += 4; return 10635; }
                if(str.startsIdx("rksld;", start, end)) { start += 6; return 10639; }
                if(str.startsIdx("rkslu;", start, end)) { start += 6; return 10637; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 318; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 316; }
                if(str.startsIdx("eil;", start, end)) { start += 4; return 8968; }
                if(str.startsIdx("ub;", start, end)) { start += 3; return 123; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1083; }
                break;
            case 'd':
                if(str.startsIdx("ca;", start, end)) { start += 3; return 10550; }
                if(str.startsIdx("quo;", start, end)) { start += 4; return 8220; }
                if(str.startsIdx("quor;", start, end)) { start += 5; return 8222; }
                if(str.startsIdx("rdhar;", start, end)) { start += 6; return 10599; }
                if(str.startsIdx("rushar;", start, end)) { start += 7; return 10571; }
                if(str.startsIdx("sh;", start, end)) { start += 3; return 8626; }
                break;
            case 'e':
                if(start < end && str[start] == ';') { start++; return 8804; }
                if(str.startsIdx("ft", start, end)) {
                    start += 2;
                    if(str.startsIdx("arrow;", start, end)) { start += 6; return 8592; }
                    if(str.startsIdx("arrowtail;", start, end)) { start += 10; return 8610; }
                    if(str.startsIdx("harpoondown;", start, end)) { start += 12; return 8637; }
                    if(str.startsIdx("harpoonup;", start, end)) { start += 10; return 8636; }
                    if(str.startsIdx("leftarrows;", start, end)) { start += 11; return 8647; }
                    if(str.startsIdx("rightarrow;", start, end)) { start += 11; return 8596; }
                    if(str.startsIdx("rightarrows;", start, end)) { start += 12; return 8646; }
                    if(str.startsIdx("rightharpoons;", start, end)) { start += 14; return 8651; }
                    if(str.startsIdx("rightsquigarrow;", start, end)) { start += 16; return 8621; }
                    if(str.startsIdx("threetimes;", start, end)) { start += 11; return 8907; }
                    break;
                }
                if(str.startsIdx("g;", start, end)) { start += 2; return 8922; }
                if(start < end && str[start] == 'q') {
                    start += 1;
                    if(start < end && str[start] == ';') { start++; return 8804; }
                    if(str.startsIdx("q;", start, end)) { start += 2; return 8806; }
                    if(str.startsIdx("slant;", start, end)) { start += 6; return 10877; }
                    break;
                }
                if(start < end && str[start] == 's') {
                    start++;
                    if(start < end && str[start] == ';') { start++; return 10877; }
                    if(str.startsIdx("cc;", start, end)) { start += 3; return 10920; }
                    if(str.startsIdx("dot;", start, end)) { start += 4; return 10879; }
                    if(str.startsIdx("doto;", start, end)) { start += 5; return 10881; }
                    if(str.startsIdx("dotor;", start, end)) { start += 6; return 10883; }
                    if(str.startsIdx("g;", start, end)) { start += 2; return -584842752; }
                    if(str.startsIdx("ges;", start, end)) { start += 4; return 10899; }
                    if(str.startsIdx("sapprox;", start, end)) { start += 8; return 10885; }
                    if(str.startsIdx("sdot;", start, end)) { start += 5; return 8918; }
                    if(str.startsIdx("seqgtr;", start, end)) { start += 7; return 8922; }
                    if(str.startsIdx("seqqgtr;", start, end)) { start += 8; return 10891; }
                    if(str.startsIdx("sgtr;", start, end)) { start += 5; return 8822; }
                    if(str.startsIdx("ssim;", start, end)) { start += 5; return 8818; }
                    break;
                }
            case 'f':
                if(str.startsIdx("isht;", start, end)) { start += 5; return 10620; }
                if(str.startsIdx("loor;", start, end)) { start += 5; return 8970; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120105; }
                break;
            case 'g':
                if(start < end && str[start] == ';') { start++; return 8822; }
                if(str.startsIdx("E;", start, end)) { start += 2; return 10897; }
                break;
            case 'h':
                if(str.startsIdx("ard;", start, end)) { start += 4; return 8637; }
                if(str.startsIdx("aru;", start, end)) { start += 4; return 8636; }
                if(str.startsIdx("arul;", start, end)) { start += 5; return 10602; }
                if(str.startsIdx("blk;", start, end)) { start += 4; return 9604; }
                break;
            case 'j': if(str.startsIdx("cy;", start, end)) { start += 3; return 1113; } break;
            case 'l':
                if(start < end && str[start] == ';') { start++; return 8810; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8647; }
                if(str.startsIdx("corner;", start, end)) { start += 7; return 8990; }
                if(str.startsIdx("hard;", start, end)) { start += 5; return 10603; }
                if(str.startsIdx("tri;", start, end)) { start += 4; return 9722; }
                break;
            case 'm':
                if(str.startsIdx("idot;", start, end)) { start += 5; return 320; }
                if(str.startsIdx("oust;", start, end)) { start += 5; return 9136; }
                if(str.startsIdx("oustache;", start, end)) { start += 9; return 9136; }
                break;
            case 'n':
                if(str.startsIdx("E;", start, end)) { start += 2; return 8808; }
                if(str.startsIdx("ap;", start, end)) { start += 3; return 10889; }
                if(str.startsIdx("approx;", start, end)) { start += 7; return 10889; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 10887; }
                if(str.startsIdx("eq;", start, end)) { start += 3; return 10887; }
                if(str.startsIdx("eqq;", start, end)) { start += 4; return 8808; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return 8934; }
                break;
            case 'o':
                if(str.startsIdx("ang;", start, end)) { start += 4; return 10220; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8701; }
                if(str.startsIdx("brk;", start, end)) { start += 4; return 10214; }
                if(str.startsIdx("ngleftarrow;", start, end)) { start += 12; return 10229; }
                if(str.startsIdx("ngleftrightarrow;", start, end)) { start += 17; return 10231; }
                if(str.startsIdx("ngmapsto;", start, end)) { start += 9; return 10236; }
                if(str.startsIdx("ngrightarrow;", start, end)) { start += 13; return 10230; }
                if(str.startsIdx("oparrowleft;", start, end)) { start += 12; return 8619; }
                if(str.startsIdx("oparrowright;", start, end)) { start += 13; return 8620; }
                if(str.startsIdx("par;", start, end)) { start += 4; return 10629; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120157; }
                if(str.startsIdx("plus;", start, end)) { start += 5; return 10797; }
                if(str.startsIdx("times;", start, end)) { start += 6; return 10804; }
                if(str.startsIdx("wast;", start, end)) { start += 5; return 8727; }
                if(str.startsIdx("wbar;", start, end)) { start += 5; return 95; }
                if(str.startsIdx("z;", start, end)) { start += 2; return 9674; }
                if(str.startsIdx("zenge;", start, end)) { start += 6; return 9674; }
                if(str.startsIdx("zf;", start, end)) { start += 3; return 10731; }
                break;
            case 'p':
                if(str.startsIdx("ar;", start, end)) { start += 3; return 40; }
                if(str.startsIdx("arlt;", start, end)) { start += 5; return 10643; }
                break;
            case 'r':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8646; }
                if(str.startsIdx("corner;", start, end)) { start += 7; return 8991; }
                if(str.startsIdx("har;", start, end)) { start += 4; return 8651; }
                if(str.startsIdx("hard;", start, end)) { start += 5; return 10605; }
                if(str.startsIdx("m;", start, end)) { start += 2; return 8206; }
                if(str.startsIdx("tri;", start, end)) { start += 4; return 8895; }
                break;
            case 's':
                if(str.startsIdx("aquo;", start, end)) { start += 5; return 8249; }
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120001; }
                if(str.startsIdx("h;", start, end)) { start += 2; return 8624; }
                if(str.startsIdx("im;", start, end)) { start += 3; return 8818; }
                if(str.startsIdx("ime;", start, end)) { start += 4; return 10893; }
                if(str.startsIdx("img;", start, end)) { start += 4; return 10895; }
                if(str.startsIdx("qb;", start, end)) { start += 3; return 91; }
                if(str.startsIdx("quo;", start, end)) { start += 4; return 8216; }
                if(str.startsIdx("quor;", start, end)) { start += 5; return 8218; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 322; }
                break;
            case 't':
                if(str.startsIdx("cc;", start, end)) { start += 3; return 10918; }
                if(str.startsIdx("cir;", start, end)) { start += 4; return 10873; }
                if(str.startsIdx("dot;", start, end)) { start += 4; return 8918; }
                if(str.startsIdx("hree;", start, end)) { start += 5; return 8907; }
                if(str.startsIdx("imes;", start, end)) { start += 5; return 8905; }
                if(str.startsIdx("larr;", start, end)) { start += 5; return 10614; }
                if(str.startsIdx("quest;", start, end)) { start += 6; return 10875; }
                if(str.startsIdx("rPar;", start, end)) { start += 5; return 10646; }
                if(str.startsIdx("ri;", start, end)) { start += 3; return 9667; }
                if(str.startsIdx("rie;", start, end)) { start += 4; return 8884; }
                if(str.startsIdx("rif;", start, end)) { start += 4; return 9666; }
                if(start < end && str[start] == ';') start++;
                return 60;
            case 'u':
                if(str.startsIdx("rdshar;", start, end)) { start += 7; return 10570; }
                if(str.startsIdx("ruhar;", start, end)) { start += 6; return 10598; }
                break;
            case 'v':
                if(str.startsIdx("ertneqq;", start, end)) { start += 8; return -577371648; }
                if(str.startsIdx("nE;", start, end)) { start += 3; return -577371648; }
                break;
        }
        return -1;
    }

    int entityLowerM(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'D': if(str.startsIdx("Dot;", start, end)) { start += 4; return 8762; } break;
            case 'a':
                if(str.startsIdx("cr", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 175; }
                if(str.startsIdx("le;", start, end)) { start += 3; return 9794; }
                if(str.startsIdx("lt;", start, end)) { start += 3; return 10016; }
                if(str.startsIdx("ltese;", start, end)) { start += 6; return 10016; }
                if(str.startsIdx("p;", start, end)) { start += 2; return 8614; }
                if(str.startsIdx("psto;", start, end)) { start += 5; return 8614; }
                if(str.startsIdx("pstodown;", start, end)) { start += 9; return 8615; }
                if(str.startsIdx("pstoleft;", start, end)) { start += 9; return 8612; }
                if(str.startsIdx("pstoup;", start, end)) { start += 7; return 8613; }
                if(str.startsIdx("rker;", start, end)) { start += 5; return 9646; }
                break;
            case 'c':
                if(str.startsIdx("omma;", start, end)) { start += 5; return 10793; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1084; }
                break;
            case 'd':
                if(str.startsIdx("ash;", start, end)) { start += 4; return 8212; }
                break;
            case 'e': if(str.startsIdx("asuredangle;", start, end)) { start += 12; return 8737; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120106; } break;
            case 'h': if(str.startsIdx("o;", start, end)) { start += 2; return 8487; } break;
            case 'i':
                if(str.startsIdx("cro", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 181; }
                if(str.startsIdx("d;", start, end)) { start += 2; return 8739; }
                if(str.startsIdx("dast;", start, end)) { start += 5; return 42; }
                if(str.startsIdx("dcir;", start, end)) { start += 5; return 10992; }
                if(str.startsIdx("ddot", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 183; }
                if(str.startsIdx("nus;", start, end)) { start += 4; return 8722; }
                if(str.startsIdx("nusb;", start, end)) { start += 5; return 8863; }
                if(str.startsIdx("nusd;", start, end)) { start += 5; return 8760; }
                if(str.startsIdx("nusdu;", start, end)) { start += 6; return 10794; }
                break;
            case 'l':
                if(str.startsIdx("cp;", start, end)) { start += 3; return 10971; }
                if(str.startsIdx("dr;", start, end)) { start += 3; return 8230; }
                break;
            case 'n': if(str.startsIdx("plus;", start, end)) { start += 5; return 8723; } break;
            case 'o':
                if(str.startsIdx("dels;", start, end)) { start += 5; return 8871; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120158; }
                break;
            case 'p': if(start < end && str[start] == ';') { start++; return 8723; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120002; }
                if(str.startsIdx("tpos;", start, end)) { start += 5; return 8766; }
                break;
            case 'u':
                if(start < end && str[start] == ';') { start++; return 956; }
                if(str.startsIdx("ltimap;", start, end)) { start += 7; return 8888; }
                if(str.startsIdx("map;", start, end)) { start += 4; return 8888; }
                break;
        }
        return -1;
    }

    int entityLowerN(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'G':
                if(str.startsIdx("g;", start, end)) { start += 2; return -584713016; }
                if(str.startsIdx("t;", start, end)) { start += 2; return -577511634; }
                if(str.startsIdx("tv;", start, end)) { start += 3; return -577504056; }
                break;
            case 'L':
                if(str.startsIdx("eftarrow;", start, end)) { start += 9; return 8653; }
                if(str.startsIdx("eftrightarrow;", start, end)) { start += 14; return 8654; }
                if(str.startsIdx("l;", start, end)) { start += 2; return -584647480; }
                if(str.startsIdx("t;", start, end)) { start += 2; return -577446098; }
                if(str.startsIdx("tv;", start, end)) { start += 3; return -577438520; }
                break;
            case 'R': if(str.startsIdx("ightarrow;", start, end)) { start += 10; return 8655; } break;
            case 'V':
                if(str.startsIdx("Dash;", start, end)) { start += 5; return 8879; }
                if(str.startsIdx("dash;", start, end)) { start += 5; return 8878; }
                break;
            case 'a':
                if(str.startsIdx("bla;", start, end)) { start += 4; return 8711; }
                if(str.startsIdx("cute;", start, end)) { start += 5; return 324; }
                if(str.startsIdx("ng;", start, end)) { start += 3; return -572596434; }
                if(str.startsIdx("p;", start, end)) { start += 2; return 8777; }
                if(str.startsIdx("pE;", start, end)) { start += 3; return -712049464; }
                if(str.startsIdx("pid;", start, end)) { start += 4; return -575406904; }
                if(str.startsIdx("pos;", start, end)) { start += 4; return 329; }
                if(str.startsIdx("pprox;", start, end)) { start += 6; return 8777; }
                if(str.startsIdx("tur;", start, end)) { start += 4; return 9838; }
                if(str.startsIdx("tural;", start, end)) { start += 6; return 9838; }
                if(str.startsIdx("turals;", start, end)) { start += 7; return 8469; }
                break;
            case 'b':
                if(str.startsIdx("sp", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 160; }
                if(str.startsIdx("ump;", start, end)) { start += 4; return -575603512; }
                if(str.startsIdx("umpe;", start, end)) { start += 5; return -575669048; }
                break;
            case 'c':
                if(str.startsIdx("ap;", start, end)) { start += 3; return 10819; }
                if(str.startsIdx("aron;", start, end)) { start += 5; return 328; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 326; }
                if(str.startsIdx("ong;", start, end)) { start += 4; return 8775; }
                if(str.startsIdx("ongdot;", start, end)) { start += 7; return -711852856; }
                if(str.startsIdx("up;", start, end)) { start += 3; return 10818; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1085; }
                break;
            case 'd': if(str.startsIdx("ash;", start, end)) { start += 4; return 8211; } break;
            case 'e':
                if(start < end && str[start] == ';') { start++; return 8800; }
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 8663; }
                if(str.startsIdx("arhk;", start, end)) { start += 5; return 10532; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8599; }
                if(str.startsIdx("arrow;", start, end)) { start += 6; return 8599; }
                if(str.startsIdx("dot;", start, end)) { start += 4; return -575734584; }
                if(str.startsIdx("quiv;", start, end)) { start += 5; return 8802; }
                if(str.startsIdx("sear;", start, end)) { start += 5; return 10536; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return -574817080; }
                if(str.startsIdx("xist;", start, end)) { start += 5; return 8708; }
                if(str.startsIdx("xists;", start, end)) { start += 6; return 8708; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120107; } break;
            case 'g':
                if(str.startsIdx("E;", start, end)) { start += 2; return -577241912; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 8817; }
                if(str.startsIdx("eq;", start, end)) { start += 3; return 8817; }
                if(str.startsIdx("eqq;", start, end)) { start += 4; return -577241912; }
                if(str.startsIdx("eqslant;", start, end)) { start += 8; return -712966968; }
                if(str.startsIdx("es;", start, end)) { start += 3; return -712966968; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return 8821; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 8815; }
                if(str.startsIdx("tr;", start, end)) { start += 3; return 8815; }
                break;
            case 'h':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 8654; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8622; }
                if(str.startsIdx("par;", start, end)) { start += 4; return 10994; }
                break;
            case 'i':
                if(start < end && str[start] == ';') { start++; return 8715; }
                if(str.startsIdx("s;", start, end)) { start += 2; return 8956; }
                if(str.startsIdx("sd;", start, end)) { start += 3; return 8954; }
                if(str.startsIdx("v;", start, end)) { start += 2; return 8715; }
                break;
            case 'j': if(str.startsIdx("cy;", start, end)) { start += 3; return 1114; } break;
            case 'l':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 8653; }
                if(str.startsIdx("E;", start, end)) { start += 2; return -577176376; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8602; }
                if(str.startsIdx("dr;", start, end)) { start += 3; return 8229; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 8816; }
                if(str.startsIdx("eftarrow;", start, end)) { start += 9; return 8602; }
                if(str.startsIdx("eftrightarrow;", start, end)) { start += 14; return 8622; }
                if(str.startsIdx("eq;", start, end)) { start += 3; return 8816; }
                if(str.startsIdx("eqq;", start, end)) { start += 4; return -577176376; }
                if(str.startsIdx("eqslant;", start, end)) { start += 8; return -712901432; }
                if(str.startsIdx("es;", start, end)) { start += 3; return -712901432; }
                if(str.startsIdx("ess;", start, end)) { start += 4; return 8814; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return 8820; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 8814; }
                if(str.startsIdx("tri;", start, end)) { start += 4; return 8938; }
                if(str.startsIdx("trie;", start, end)) { start += 5; return 8940; }
                break;
            case 'm': if(str.startsIdx("id;", start, end)) { start += 3; return 8740; } break;
            case 'o':
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120159; }
                if(str.startsIdx("t", start, end)) {
                    start += 1;
                    if(start < end && str[start] == ';') { start++; return 172; }
                    if(str.startsIdx("in;", start, end)) { start += 3; return 8713; }
                    if(str.startsIdx("inE;", start, end)) { start += 4; return -586810168; }
                    if(str.startsIdx("indot;", start, end)) { start += 6; return -586548024; }
                    if(str.startsIdx("inva;", start, end)) { start += 5; return 8713; }
                    if(str.startsIdx("invb;", start, end)) { start += 5; return 8951; }
                    if(str.startsIdx("invc;", start, end)) { start += 5; return 8950; }
                    if(str.startsIdx("ni;", start, end)) { start += 3; return 8716; }
                    if(str.startsIdx("niva;", start, end)) { start += 5; return 8716; }
                    if(str.startsIdx("nivb;", start, end)) { start += 5; return 8958; }
                    if(str.startsIdx("nivc;", start, end)) { start += 5; return 8957; }
                    return 172;
                }
                break;
            case 'p':
                if(str.startsIdx("ar;", start, end)) { start += 3; return 8742; }
                if(str.startsIdx("arallel;", start, end)) { start += 8; return 8742; }
                if(str.startsIdx("arsl;", start, end)) { start += 5; return -721297637; }
                if(str.startsIdx("art;", start, end)) { start += 4; return -570622776; }
                if(str.startsIdx("olint;", start, end)) { start += 6; return 10772; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 8832; }
                if(str.startsIdx("rcue;", start, end)) { start += 5; return 8928; }
                if(str.startsIdx("re;", start, end)) { start += 3; return -716178232; }
                if(str.startsIdx("rec;", start, end)) { start += 4; return 8832; }
                if(str.startsIdx("receq;", start, end)) { start += 6; return -716178232; }
                break;
            case 'r':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 8655; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8603; }
                if(str.startsIdx("arrc;", start, end)) { start += 5; return -691274552; }
                if(str.startsIdx("arrw;", start, end)) { start += 5; return -564003640; }
                if(str.startsIdx("ightarrow;", start, end)) { start += 10; return 8603; }
                if(str.startsIdx("tri;", start, end)) { start += 4; return 8939; }
                if(str.startsIdx("trie;", start, end)) { start += 5; return 8941; }
                break;
            case 's':
                if(str.startsIdx("c;", start, end)) { start += 2; return 8833; }
                if(str.startsIdx("ccue;", start, end)) { start += 5; return 8929; }
                if(str.startsIdx("ce;", start, end)) { start += 3; return -716243768; }
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120003; }
                if(str.startsIdx("hortmid;", start, end)) { start += 8; return 8740; }
                if(str.startsIdx("hortparallel;", start, end)) { start += 13; return 8742; }
                if(str.startsIdx("im;", start, end)) { start += 3; return 8769; }
                if(str.startsIdx("ime;", start, end)) { start += 4; return 8772; }
                if(str.startsIdx("imeq;", start, end)) { start += 5; return 8772; }
                if(str.startsIdx("mid;", start, end)) { start += 4; return 8740; }
                if(str.startsIdx("par;", start, end)) { start += 4; return 8742; }
                if(str.startsIdx("qsube;", start, end)) { start += 6; return 8930; }
                if(str.startsIdx("qsupe;", start, end)) { start += 6; return 8931; }
                if(str.startsIdx("ub;", start, end)) { start += 3; return 8836; }
                if(str.startsIdx("ubE;", start, end)) { start += 4; return -717620024; }
                if(str.startsIdx("ube;", start, end)) { start += 4; return 8840; }
                if(str.startsIdx("ubset;", start, end)) { start += 6; return -579018962; }
                if(str.startsIdx("ubseteq;", start, end)) { start += 8; return 8840; }
                if(str.startsIdx("ubseteqq;", start, end)) { start += 9; return -717620024; }
                if(str.startsIdx("ucc;", start, end)) { start += 4; return 8833; }
                if(str.startsIdx("ucceq;", start, end)) { start += 6; return -716243768; }
                if(str.startsIdx("up;", start, end)) { start += 3; return 8837; }
                if(str.startsIdx("upE;", start, end)) { start += 4; return -717685560; }
                if(str.startsIdx("upe;", start, end)) { start += 4; return 8841; }
                if(str.startsIdx("upset;", start, end)) { start += 6; return -579084498; }
                if(str.startsIdx("upseteq;", start, end)) { start += 8; return 8841; }
                if(str.startsIdx("upseteqq;", start, end)) { start += 9; return -717685560; }
                break;
            case 't':
                if(str.startsIdx("gl;", start, end)) { start += 3; return 8825; }
                if(str.startsIdx("ilde", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 241; }
                if(str.startsIdx("lg;", start, end)) { start += 3; return 8824; }
                if(str.startsIdx("riangleleft;", start, end)) { start += 12; return 8938; }
                if(str.startsIdx("rianglelefteq;", start, end)) { start += 14; return 8940; }
                if(str.startsIdx("riangleright;", start, end)) { start += 13; return 8939; }
                if(str.startsIdx("rianglerighteq;", start, end)) { start += 15; return 8941; }
                break;
            case 'u':
                if(start < end && str[start] == ';') { start++; return 957; }
                if(str.startsIdx("m;", start, end)) { start += 2; return 35; }
                if(str.startsIdx("mero;", start, end)) { start += 5; return 8470; }
                if(str.startsIdx("msp;", start, end)) { start += 4; return 8199; }
                break;
            case 'v':
                if(str.startsIdx("Dash;", start, end)) { start += 5; return 8877; }
                if(str.startsIdx("Harr;", start, end)) { start += 5; return 10500; }
                if(str.startsIdx("ap;", start, end)) { start += 3; return -575545554; }
                if(str.startsIdx("dash;", start, end)) { start += 5; return 8876; }
                if(str.startsIdx("ge;", start, end)) { start += 3; return -577118418; }
                if(str.startsIdx("gt;", start, end)) { start += 3; return -4137170; }
                if(str.startsIdx("infin;", start, end)) { start += 6; return 10718; }
                if(str.startsIdx("lArr;", start, end)) { start += 5; return 10498; }
                if(str.startsIdx("le;", start, end)) { start += 3; return -577052882; }
                if(str.startsIdx("lt;", start, end)) { start += 3; return -4006098; }
                if(str.startsIdx("ltrie;", start, end)) { start += 6; return -582295762; }
                if(str.startsIdx("rArr;", start, end)) { start += 5; return 10499; }
                if(str.startsIdx("rtrie;", start, end)) { start += 6; return -582361298; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return -574431442; }
                break;
            case 'w':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 8662; }
                if(str.startsIdx("arhk;", start, end)) { start += 5; return 10531; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8598; }
                if(str.startsIdx("arrow;", start, end)) { start += 6; return 8598; }
                if(str.startsIdx("near;", start, end)) { start += 5; return 10535; }
                break;
        }
        return -1;
    }

    int entityLowerO(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'S': if(start < end && str[start] == ';') { start++; return 9416; } break;
            case 'a':
                if(str.startsIdx("cute", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 243; }
                if(str.startsIdx("st;", start, end)) { start += 3; return 8859; }
                break;
            case 'c':
                if(str.startsIdx("ir;", start, end)) { start += 3; return 8858; }
                if(str.startsIdx("irc", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 244; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1086; }
                break;
            case 'd':
                if(str.startsIdx("ash;", start, end)) { start += 4; return 8861; }
                if(str.startsIdx("blac;", start, end)) { start += 5; return 337; }
                if(str.startsIdx("iv;", start, end)) { start += 3; return 10808; }
                if(str.startsIdx("ot;", start, end)) { start += 3; return 8857; }
                if(str.startsIdx("sold;", start, end)) { start += 5; return 10684; }
                break;
            case 'e': if(str.startsIdx("lig;", start, end)) { start += 4; return 339; } break;
            case 'f':
                if(str.startsIdx("cir;", start, end)) { start += 4; return 10687; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120108; }
                break;
            case 'g':
                if(str.startsIdx("on;", start, end)) { start += 3; return 731; }
                if(str.startsIdx("rave", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 242; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 10689; }
                break;
            case 'h':
                if(str.startsIdx("bar;", start, end)) { start += 4; return 10677; }
                if(str.startsIdx("m;", start, end)) { start += 2; return 937; }
                break;
            case 'i': if(str.startsIdx("nt;", start, end)) { start += 3; return 8750; } break;
            case 'l':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8634; }
                if(str.startsIdx("cir;", start, end)) { start += 4; return 10686; }
                if(str.startsIdx("cross;", start, end)) { start += 6; return 10683; }
                if(str.startsIdx("ine;", start, end)) { start += 4; return 8254; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 10688; }
                break;
            case 'm':
                if(str.startsIdx("acr;", start, end)) { start += 4; return 333; }
                if(str.startsIdx("ega;", start, end)) { start += 4; return 969; }
                if(str.startsIdx("icron;", start, end)) { start += 6; return 959; }
                if(str.startsIdx("id;", start, end)) { start += 3; return 10678; }
                if(str.startsIdx("inus;", start, end)) { start += 5; return 8854; }
                break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120160; } break;
            case 'p':
                if(str.startsIdx("ar;", start, end)) { start += 3; return 10679; }
                if(str.startsIdx("erp;", start, end)) { start += 4; return 10681; }
                if(str.startsIdx("lus;", start, end)) { start += 4; return 8853; }
                break;
            case 'r':
                if(start < end && str[start] == ';') { start++; return 8744; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8635; }
                if(str.startsIdx("d;", start, end)) { start += 2; return 10845; }
                if(str.startsIdx("der;", start, end)) { start += 4; return 8500; }
                if(str.startsIdx("derof;", start, end)) { start += 6; return 8500; }
                if(str.startsIdx("df", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 170; }
                if(str.startsIdx("dm", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 186; }
                if(str.startsIdx("igof;", start, end)) { start += 5; return 8886; }
                if(str.startsIdx("or;", start, end)) { start += 3; return 10838; }
                if(str.startsIdx("slope;", start, end)) { start += 6; return 10839; }
                if(str.startsIdx("v;", start, end)) { start += 2; return 10843; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 8500; }
                if(str.startsIdx("lash", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 248; }
                if(str.startsIdx("ol;", start, end)) { start += 3; return 8856; }
                break;
            case 't':
                if(str.startsIdx("ilde", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 245; }
                if(str.startsIdx("imes;", start, end)) { start += 5; return 8855; }
                if(str.startsIdx("imesas;", start, end)) { start += 7; return 10806; }
                break;
            case 'u': if(str.startsIdx("ml", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 246; } break;
            case 'v': if(str.startsIdx("bar;", start, end)) { start += 4; return 9021; } break;
        }
        return -1;
    }
    int entityLowerP(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("r;", start, end)) { start += 2; return 8741; }
                if(str.startsIdx("ra", start, end)) {
                    start += 2;
                    if(start < end && str[start] == ';') { start++; return 182; }
                    if(str.startsIdx("llel;", start, end)) { start += 5; return 8741; }
                    return 182;
                }
                if(str.startsIdx("rsim;", start, end)) { start += 5; return 10995; }
                if(str.startsIdx("rsl;", start, end)) { start += 4; return 11005; }
                if(str.startsIdx("rt;", start, end)) { start += 3; return 8706; }
                break;
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1087; } break;
            case 'e':
                if(str.startsIdx("rcnt;", start, end)) { start += 5; return 37; }
                if(str.startsIdx("riod;", start, end)) { start += 5; return 46; }
                if(str.startsIdx("rmil;", start, end)) { start += 5; return 8240; }
                if(str.startsIdx("rp;", start, end)) { start += 3; return 8869; }
                if(str.startsIdx("rtenk;", start, end)) { start += 6; return 8241; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120109; } break;
            case 'h':
                if(str.startsIdx("i;", start, end)) { start += 2; return 966; }
                if(str.startsIdx("iv;", start, end)) { start += 3; return 981; }
                if(str.startsIdx("mmat;", start, end)) { start += 5; return 8499; }
                if(str.startsIdx("one;", start, end)) { start += 4; return 9742; }
                break;
            case 'i':
                if(start < end && str[start] == ';') { start++; return 960; }
                if(str.startsIdx("tchfork;", start, end)) { start += 8; return 8916; }
                if(str.startsIdx("v;", start, end)) { start += 2; return 982; }
                break;
            case 'l':
                if(str.startsIdx("anck;", start, end)) { start += 5; return 8463; }
                if(str.startsIdx("anckh;", start, end)) { start += 6; return 8462; }
                if(str.startsIdx("ankv;", start, end)) { start += 5; return 8463; }
                if(str.startsIdx("us;", start, end)) { start += 3; return 43; }
                if(str.startsIdx("usacir;", start, end)) { start += 7; return 10787; }
                if(str.startsIdx("usb;", start, end)) { start += 4; return 8862; }
                if(str.startsIdx("uscir;", start, end)) { start += 6; return 10786; }
                if(str.startsIdx("usdo;", start, end)) { start += 5; return 8724; }
                if(str.startsIdx("usdu;", start, end)) { start += 5; return 10789; }
                if(str.startsIdx("use;", start, end)) { start += 4; return 10866; }
                if(str.startsIdx("usmn", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 177; }
                if(str.startsIdx("ussim;", start, end)) { start += 6; return 10790; }
                if(str.startsIdx("ustwo;", start, end)) { start += 6; return 10791; }
                break;
            case 'm': if(start < end && str[start] == ';') { start++; return 177; } break;
            case 'o':
                if(str.startsIdx("intint;", start, end)) { start += 7; return 10773; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120161; }
                if(str.startsIdx("und", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 163; }
                break;
            case 'r':
                if(start < end && str[start] == ';') { start++; return 8826; }
                if(str.startsIdx("E;", start, end)) { start += 2; return 10931; }
                if(str.startsIdx("ap;", start, end)) { start += 3; return 10935; }
                if(str.startsIdx("cue;", start, end)) { start += 4; return 8828; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 10927; }
                if(str.startsIdx("ec;", start, end)) { start += 3; return 8826; }
                if(str.startsIdx("ecapprox;", start, end)) { start += 9; return 10935; }
                if(str.startsIdx("eccurlyeq;", start, end)) { start += 10; return 8828; }
                if(str.startsIdx("eceq;", start, end)) { start += 5; return 10927; }
                if(str.startsIdx("ecnapprox;", start, end)) { start += 10; return 10937; }
                if(str.startsIdx("ecneqq;", start, end)) { start += 7; return 10933; }
                if(str.startsIdx("ecnsim;", start, end)) { start += 7; return 8936; }
                if(str.startsIdx("ecsim;", start, end)) { start += 6; return 8830; }
                if(str.startsIdx("ime;", start, end)) { start += 4; return 8242; }
                if(str.startsIdx("imes;", start, end)) { start += 5; return 8473; }
                if(str.startsIdx("nE;", start, end)) { start += 3; return 10933; }
                if(str.startsIdx("nap;", start, end)) { start += 4; return 10937; }
                if(str.startsIdx("nsim;", start, end)) { start += 5; return 8936; }
                if(str.startsIdx("od;", start, end)) { start += 3; return 8719; }
                if(str.startsIdx("ofalar;", start, end)) { start += 7; return 9006; }
                if(str.startsIdx("ofline;", start, end)) { start += 7; return 8978; }
                if(str.startsIdx("ofsurf;", start, end)) { start += 7; return 8979; }
                if(str.startsIdx("op;", start, end)) { start += 3; return 8733; }
                if(str.startsIdx("opto;", start, end)) { start += 5; return 8733; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return 8830; }
                if(str.startsIdx("urel;", start, end)) { start += 5; return 8880; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120005; }
                if(str.startsIdx("i;", start, end)) { start += 2; return 968; }
                break;
            case 'u': if(str.startsIdx("ncsp;", start, end)) { start += 5; return 8200; } break;
        }
        return -1;
    }

    int entityLowerQ(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120110; } break;
            case 'i': if(str.startsIdx("nt;", start, end)) { start += 3; return 10764; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120162; } break;
            case 'p': if(str.startsIdx("rime;", start, end)) { start += 5; return 8279; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 120006; } break;
            case 'u':
                if(str.startsIdx("aternions;", start, end)) { start += 10; return 8461; }
                if(str.startsIdx("atint;", start, end)) { start += 6; return 10774; }
                if(str.startsIdx("est;", start, end)) { start += 4; return 63; }
                if(str.startsIdx("esteq;", start, end)) { start += 6; return 8799; }
                if(str.startsIdx("ot", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 34; }
                break;
        }
        return -1;
    }

    int entityLowerR(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8667; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8658; }
                if(str.startsIdx("tail;", start, end)) { start += 5; return 10524; }
                break;
            case 'B': if(str.startsIdx("arr;", start, end)) { start += 4; return 10511; } break;
            case 'H': if(str.startsIdx("ar;", start, end)) { start += 3; return 10596; } break;
            case 'a':
                if(str.startsIdx("ce;", start, end)) { start += 3; return -574489393; }
                if(str.startsIdx("cute;", start, end)) { start += 5; return 341; }
                if(str.startsIdx("dic;", start, end)) { start += 4; return 8730; }
                if(str.startsIdx("emptyv;", start, end)) { start += 7; return 10675; }
                if(str.startsIdx("ng;", start, end)) { start += 3; return 10217; }
                if(str.startsIdx("ngd;", start, end)) { start += 4; return 10642; }
                if(str.startsIdx("nge;", start, end)) { start += 4; return 10661; }
                if(str.startsIdx("ngle;", start, end)) { start += 5; return 10217; }
                if(str.startsIdx("quo", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 187; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8594; }
                if(str.startsIdx("rrap;", start, end)) { start += 5; return 10613; }
                if(str.startsIdx("rrb;", start, end)) { start += 4; return 8677; }
                if(str.startsIdx("rrbfs;", start, end)) { start += 6; return 10528; }
                if(str.startsIdx("rrc;", start, end)) { start += 4; return 10547; }
                if(str.startsIdx("rrfs;", start, end)) { start += 5; return 10526; }
                if(str.startsIdx("rrhk;", start, end)) { start += 5; return 8618; }
                if(str.startsIdx("rrlp;", start, end)) { start += 5; return 8620; }
                if(str.startsIdx("rrpl;", start, end)) { start += 5; return 10565; }
                if(str.startsIdx("rrsim;", start, end)) { start += 6; return 10612; }
                if(str.startsIdx("rrtl;", start, end)) { start += 5; return 8611; }
                if(str.startsIdx("rrw;", start, end)) { start += 4; return 8605; }
                if(str.startsIdx("tail;", start, end)) { start += 5; return 10522; }
                if(str.startsIdx("tio;", start, end)) { start += 4; return 8758; }
                if(str.startsIdx("tionals;", start, end)) { start += 8; return 8474; }
                break;
            case 'b':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 10509; }
                if(str.startsIdx("brk;", start, end)) { start += 4; return 10099; }
                if(str.startsIdx("race;", start, end)) { start += 5; return 125; }
                if(str.startsIdx("rack;", start, end)) { start += 5; return 93; }
                if(str.startsIdx("rke;", start, end)) { start += 4; return 10636; }
                if(str.startsIdx("rksld;", start, end)) { start += 6; return 10638; }
                if(str.startsIdx("rkslu;", start, end)) { start += 6; return 10640; }
                break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 345; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 343; }
                if(str.startsIdx("eil;", start, end)) { start += 4; return 8969; }
                if(str.startsIdx("ub;", start, end)) { start += 3; return 125; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1088; }
                break;
            case 'd':
                if(str.startsIdx("ca;", start, end)) { start += 3; return 10551; }
                if(str.startsIdx("ldhar;", start, end)) { start += 6; return 10601; }
                if(str.startsIdx("quo;", start, end)) { start += 4; return 8221; }
                if(str.startsIdx("quor;", start, end)) { start += 5; return 8221; }
                if(str.startsIdx("sh;", start, end)) { start += 3; return 8627; }
                break;
            case 'e':
                if(str.startsIdx("al;", start, end)) { start += 3; return 8476; }
                if(str.startsIdx("aline;", start, end)) { start += 6; return 8475; }
                if(str.startsIdx("alpart;", start, end)) { start += 7; return 8476; }
                if(str.startsIdx("als;", start, end)) { start += 4; return 8477; }
                if(str.startsIdx("ct;", start, end)) { start += 3; return 9645; }
                if(start < end && str[start] == 'g') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 174; }
                break;
            case 'f':
                if(str.startsIdx("isht;", start, end)) { start += 5; return 10621; }
                if(str.startsIdx("loor;", start, end)) { start += 5; return 8971; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120111; }
                break;
            case 'h':
                if(str.startsIdx("ard;", start, end)) { start += 4; return 8641; }
                if(str.startsIdx("aru;", start, end)) { start += 4; return 8640; }
                if(str.startsIdx("arul;", start, end)) { start += 5; return 10604; }
                if(str.startsIdx("o;", start, end)) { start += 2; return 961; }
                if(str.startsIdx("ov;", start, end)) { start += 3; return 1009; }
                break;
            case 'i':
                if(str.startsIdx("ght", start, end)) {
                    start += 3;
                    if(str.startsIdx("arrow;", start, end)) { start += 6; return 8594; }
                    if(str.startsIdx("arrowtail;", start, end)) { start += 10; return 8611; }
                    if(str.startsIdx("harpoondown;", start, end)) { start += 12; return 8641; }
                    if(str.startsIdx("harpoonup;", start, end)) { start += 10; return 8640; }
                    if(str.startsIdx("leftarrows;", start, end)) { start += 11; return 8644; }
                    if(str.startsIdx("leftharpoons;", start, end)) { start += 13; return 8652; }
                    if(str.startsIdx("rightarrows;", start, end)) { start += 12; return 8649; }
                    if(str.startsIdx("squigarrow;", start, end)) { start += 11; return 8605; }
                    if(str.startsIdx("threetimes;", start, end)) { start += 11; return 8908; }
                    break;
                }
                if(str.startsIdx("ng;", start, end)) { start += 3; return 730; }
                if(str.startsIdx("singdotseq;", start, end)) { start += 11; return 8787; }
                break;
            case 'l':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8644; }
                if(str.startsIdx("har;", start, end)) { start += 4; return 8652; }
                if(str.startsIdx("m;", start, end)) { start += 2; return 8207; }
                break;
            case 'm':
                if(str.startsIdx("oust;", start, end)) { start += 5; return 9137; }
                if(str.startsIdx("oustache;", start, end)) { start += 9; return 9137; }
                break;
            case 'n':
                if(str.startsIdx("mid;", start, end)) { start += 4; return 10990; }
                break;
            case 'o':
                if(str.startsIdx("ang;", start, end)) { start += 4; return 10221; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8702; }
                if(str.startsIdx("brk;", start, end)) { start += 4; return 10215; }
                if(str.startsIdx("par;", start, end)) { start += 4; return 10630; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120163; }
                if(str.startsIdx("plus;", start, end)) { start += 5; return 10798; }
                if(str.startsIdx("times;", start, end)) { start += 6; return 10805; }
                break;
            case 'p':
                if(str.startsIdx("ar;", start, end)) { start += 3; return 41; }
                if(str.startsIdx("argt;", start, end)) { start += 5; return 10644; }
                if(str.startsIdx("polint;", start, end)) { start += 7; return 10770; }
                break;
            case 'r': if(str.startsIdx("arr;", start, end)) { start += 4; return 8649; } break;
            case 's':
                if(str.startsIdx("aquo;", start, end)) { start += 5; return 8250; }
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120007; }
                if(str.startsIdx("h;", start, end)) { start += 2; return 8625; }
                if(str.startsIdx("qb;", start, end)) { start += 3; return 93; }
                if(str.startsIdx("quo;", start, end)) { start += 4; return 8217; }
                if(str.startsIdx("quor;", start, end)) { start += 5; return 8217; }
                break;
            case 't':
                if(str.startsIdx("hree;", start, end)) { start += 5; return 8908; }
                if(str.startsIdx("imes;", start, end)) { start += 5; return 8906; }
                if(str.startsIdx("ri;", start, end)) { start += 3; return 9657; }
                if(str.startsIdx("rie;", start, end)) { start += 4; return 8885; }
                if(str.startsIdx("rif;", start, end)) { start += 4; return 9656; }
                if(str.startsIdx("riltri;", start, end)) { start += 7; return 10702; }
                break;
            case 'u': if(str.startsIdx("luhar;", start, end)) { start += 6; return 10600; } break;
            case 'x': if(start < end && str[start] == ';') { start++; return 8478; } break;
        }
        return -1;
    }

    int entityLowerS(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a': if(str.startsIdx("cute;", start, end)) { start += 5; return 347; } break;
            case 'b': if(str.startsIdx("quo;", start, end)) { start += 4; return 8218; } break;
            case 'c':
                if(start < end && str[start] == ';') { start++; return 8827; }
                if(str.startsIdx("E;", start, end)) { start += 2; return 10932; }
                if(str.startsIdx("ap;", start, end)) { start += 3; return 10936; }
                if(str.startsIdx("aron;", start, end)) { start += 5; return 353; }
                if(str.startsIdx("cue;", start, end)) { start += 4; return 8829; }
                if(str.startsIdx("e;", start, end)) { start += 2; return 10928; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 351; }
                if(str.startsIdx("irc;", start, end)) { start += 4; return 349; }
                if(str.startsIdx("nE;", start, end)) { start += 3; return 10934; }
                if(str.startsIdx("nap;", start, end)) { start += 4; return 10938; }
                if(str.startsIdx("nsim;", start, end)) { start += 5; return 8937; }
                if(str.startsIdx("polint;", start, end)) { start += 7; return 10771; }
                if(str.startsIdx("sim;", start, end)) { start += 4; return 8831; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1089; }
                break;
            case 'd':
                if(str.startsIdx("ot;", start, end)) { start += 3; return 8901; }
                if(str.startsIdx("otb;", start, end)) { start += 4; return 8865; }
                if(str.startsIdx("ote;", start, end)) { start += 4; return 10854; }
                break;
            case 'e':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 8664; }
                if(str.startsIdx("arhk;", start, end)) { start += 5; return 10533; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8600; }
                if(str.startsIdx("arrow;", start, end)) { start += 6; return 8600; }
                if(str.startsIdx("ct", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 167; }
                if(str.startsIdx("mi;", start, end)) { start += 3; return 59; }
                if(str.startsIdx("swar;", start, end)) { start += 5; return 10537; }
                if(str.startsIdx("tminus;", start, end)) { start += 7; return 8726; }
                if(str.startsIdx("tmn;", start, end)) { start += 4; return 8726; }
                if(str.startsIdx("xt;", start, end)) { start += 3; return 10038; }
                break;
            case 'f':
                if(str.startsIdx("r;", start, end)) { start += 2; return 120112; }
                if(str.startsIdx("rown;", start, end)) { start += 5; return 8994; }
                break;
            case 'h':
                if(str.startsIdx("arp;", start, end)) { start += 4; return 9839; }
                if(str.startsIdx("chcy;", start, end)) { start += 5; return 1097; }
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1096; }
                if(str.startsIdx("ortmid;", start, end)) { start += 7; return 8739; }
                if(str.startsIdx("ortparallel;", start, end)) { start += 12; return 8741; }
                if(start < end && str[start] == 'y') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 173; }
                break;
            case 'i':
                if(str.startsIdx("gma;", start, end)) { start += 4; return 963; }
                if(str.startsIdx("gmaf;", start, end)) { start += 5; return 962; }
                if(str.startsIdx("gmav;", start, end)) { start += 5; return 962; }
                if(str.startsIdx("m;", start, end)) { start += 2; return 8764; }
                if(str.startsIdx("mdot;", start, end)) { start += 5; return 10858; }
                if(str.startsIdx("me;", start, end)) { start += 3; return 8771; }
                if(str.startsIdx("meq;", start, end)) { start += 4; return 8771; }
                if(str.startsIdx("mg;", start, end)) { start += 3; return 10910; }
                if(str.startsIdx("mgE;", start, end)) { start += 4; return 10912; }
                if(str.startsIdx("ml;", start, end)) { start += 3; return 10909; }
                if(str.startsIdx("mlE;", start, end)) { start += 4; return 10911; }
                if(str.startsIdx("mne;", start, end)) { start += 4; return 8774; }
                if(str.startsIdx("mplus;", start, end)) { start += 6; return 10788; }
                if(str.startsIdx("mrarr;", start, end)) { start += 6; return 10610; }
                break;
            case 'l': if(str.startsIdx("arr;", start, end)) { start += 4; return 8592; } break;
            case 'm':
                if(str.startsIdx("allsetminus;", start, end)) { start += 12; return 8726; }
                if(str.startsIdx("ashp;", start, end)) { start += 5; return 10803; }
                if(str.startsIdx("eparsl;", start, end)) { start += 7; return 10724; }
                if(str.startsIdx("id;", start, end)) { start += 3; return 8739; }
                if(str.startsIdx("ile;", start, end)) { start += 4; return 8995; }
                if(str.startsIdx("t;", start, end)) { start += 2; return 10922; }
                if(str.startsIdx("te;", start, end)) { start += 3; return 10924; }
                if(str.startsIdx("tes;", start, end)) { start += 4; return -716045824; }
                break;
            case 'o':
                if(str.startsIdx("ftcy;", start, end)) { start += 5; return 1100; }
                if(str.startsIdx("l;", start, end)) { start += 2; return 47; }
                if(str.startsIdx("lb;", start, end)) { start += 3; return 10692; }
                if(str.startsIdx("lbar;", start, end)) { start += 5; return 9023; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120164; }
                break;
            case 'p':
                if(str.startsIdx("ades;", start, end)) { start += 5; return 9824; }
                if(str.startsIdx("adesuit;", start, end)) { start += 8; return 9824; }
                if(str.startsIdx("ar;", start, end)) { start += 3; return 8741; }
                break;
            case 'q':
                if(str.startsIdx("cap;", start, end)) { start += 4; return 8851; }
                if(str.startsIdx("caps;", start, end)) { start += 5; return -580189696; }
                if(str.startsIdx("cup;", start, end)) { start += 4; return 8852; }
                if(str.startsIdx("cups;", start, end)) { start += 5; return -580255232; }
                if(str.startsIdx("sub;", start, end)) { start += 4; return 8847; }
                if(str.startsIdx("sube;", start, end)) { start += 5; return 8849; }
                if(str.startsIdx("subset;", start, end)) { start += 7; return 8847; }
                if(str.startsIdx("subseteq;", start, end)) { start += 9; return 8849; }
                if(str.startsIdx("sup;", start, end)) { start += 4; return 8848; }
                if(str.startsIdx("supe;", start, end)) { start += 5; return 8850; }
                if(str.startsIdx("supset;", start, end)) { start += 7; return 8848; }
                if(str.startsIdx("supseteq;", start, end)) { start += 9; return 8850; }
                if(str.startsIdx("u;", start, end)) { start += 2; return 9633; }
                if(str.startsIdx("uare;", start, end)) { start += 5; return 9633; }
                if(str.startsIdx("uarf;", start, end)) { start += 5; return 9642; }
                if(str.startsIdx("uf;", start, end)) { start += 3; return 9642; }
                break;
            case 'r': if(str.startsIdx("arr;", start, end)) { start += 4; return 8594; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120008; }
                if(str.startsIdx("etmn;", start, end)) { start += 5; return 8726; }
                if(str.startsIdx("mile;", start, end)) { start += 5; return 8995; }
                if(str.startsIdx("tarf;", start, end)) { start += 5; return 8902; }
                break;
            case 't':
                if(str.startsIdx("ar;", start, end)) { start += 3; return 9734; }
                if(str.startsIdx("arf;", start, end)) { start += 4; return 9733; }
                if(str.startsIdx("raightepsilon;", start, end)) { start += 14; return 1013; }
                if(str.startsIdx("raightphi;", start, end)) { start += 10; return 981; }
                if(str.startsIdx("rns;", start, end)) { start += 4; return 175; }
                break;
            case 'u':
                if(start < end && str[start] == 'b') {
                    start++;
                    if(start < end && str[start] == ';') { start++; return 8834; }
                    if(str.startsIdx("E;", start, end)) { start += 2; return 10949; }
                    if(str.startsIdx("dot;", start, end)) { start += 4; return 10941; }
                    if(str.startsIdx("e;", start, end)) { start += 2; return 8838; }
                    if(str.startsIdx("edot;", start, end)) { start += 5; return 10947; }
                    if(str.startsIdx("mult;", start, end)) { start += 5; return 10945; }
                    if(str.startsIdx("nE;", start, end)) { start += 3; return 10955; }
                    if(str.startsIdx("ne;", start, end)) { start += 3; return 8842; }
                    if(str.startsIdx("plus;", start, end)) { start += 5; return 10943; }
                    if(str.startsIdx("rarr;", start, end)) { start += 5; return 10617; }
                    if(str.startsIdx("set", start, end)) {
                        start += 3;
                        if(start < end && str[start] == ';') { start++; return 8834; }
                        if(str.startsIdx("eq;", start, end)) { start += 3; return 8838; }
                        if(str.startsIdx("eqq;", start, end)) { start += 4; return 10949; }
                        if(str.startsIdx("neq;", start, end)) { start += 4; return 8842; }
                        if(str.startsIdx("neqq;", start, end)) { start += 5; return 10955; }
                        break;
                    }
                    if(str.startsIdx("sim;", start, end)) { start += 4; return 10951; }
                    if(str.startsIdx("sub;", start, end)) { start += 4; return 10965; }
                    if(str.startsIdx("sup;", start, end)) { start += 4; return 10963; }
                    break;
                }
                if(str.startsIdx("cc", start, end)) {
                    start += 2;
                    if(start < end && str[start] == ';') { start++; return 8827; }
                    if(str.startsIdx("approx;", start, end)) { start += 7; return 10936; }
                    if(str.startsIdx("curlyeq;", start, end)) { start += 8; return 8829; }
                    if(str.startsIdx("eq;", start, end)) { start += 3; return 10928; }
                    if(str.startsIdx("napprox;", start, end)) { start += 8; return 10938; }
                    if(str.startsIdx("neqq;", start, end)) { start += 5; return 10934; }
                    if(str.startsIdx("nsim;", start, end)) { start += 5; return 8937; }
                    if(str.startsIdx("sim;", start, end)) { start += 4; return 8831; }
                    break;
                }
                if(str.startsIdx("m;", start, end)) { start += 2; return 8721; }
                if(str.startsIdx("ng;", start, end)) { start += 3; return 9834; }
                if(start < end && str[start] == 'p') {
                    start++;
                    if(start < end && str[start] == '1') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 185; }
                    if(start < end && str[start] == '2') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 178; }
                    if(start < end && str[start] == '3') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 179; }
                    if(start < end && str[start] == ';') { start++; return 8835; }
                    if(str.startsIdx("E;", start, end)) { start += 2; return 10950; }
                    if(str.startsIdx("dot;", start, end)) { start += 4; return 10942; }
                    if(str.startsIdx("dsub;", start, end)) { start += 5; return 10968; }
                    if(str.startsIdx("e;", start, end)) { start += 2; return 8839; }
                    if(str.startsIdx("edot;", start, end)) { start += 5; return 10948; }
                    if(str.startsIdx("hsol;", start, end)) { start += 5; return 10185; }
                    if(str.startsIdx("hsub;", start, end)) { start += 5; return 10967; }
                    if(str.startsIdx("larr;", start, end)) { start += 5; return 10619; }
                    if(str.startsIdx("mult;", start, end)) { start += 5; return 10946; }
                    if(str.startsIdx("nE;", start, end)) { start += 3; return 10956; }
                    if(str.startsIdx("ne;", start, end)) { start += 3; return 8843; }
                    if(str.startsIdx("plus;", start, end)) { start += 5; return 10944; }
                    if(str.startsIdx("set", start, end)) {
                        start += 3;
                        if(start < end && str[start] == ';') { start++; return 8835; }
                        if(str.startsIdx("eq;", start, end)) { start += 3; return 8839; }
                        if(str.startsIdx("eqq;", start, end)) { start += 4; return 10950; }
                        if(str.startsIdx("neq;", start, end)) { start += 4; return 8843; }
                        if(str.startsIdx("neqq;", start, end)) { start += 5; return 10956; }
                        break;
                    }
                    if(str.startsIdx("sim;", start, end)) { start += 4; return 10952; }
                    if(str.startsIdx("sub;", start, end)) { start += 4; return 10964; }
                    if(str.startsIdx("sup;", start, end)) { start += 4; return 10966; }
                    break;
                }
                break;
            case 'w':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 8665; }
                if(str.startsIdx("arhk;", start, end)) { start += 5; return 10534; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8601; }
                if(str.startsIdx("arrow;", start, end)) { start += 6; return 8601; }
                if(str.startsIdx("nwar;", start, end)) { start += 5; return 10538; }
                break;
            case 'z':
                if(str.startsIdx("lig", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 223; }
                break;
        }
        return -1;
    }

    int entityLowerT(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("rget;", start, end)) { start += 5; return 8982; }
                if(str.startsIdx("u;", start, end)) { start += 2; return 964; }
                break;
            case 'b': if(str.startsIdx("rk;", start, end)) { start += 3; return 9140; } break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 357; }
                if(str.startsIdx("edil;", start, end)) { start += 5; return 355; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1090; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 8411; } break;
            case 'e': if(str.startsIdx("lrec;", start, end)) { start += 5; return 8981; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120113; } break;
            case 'h':
                if(str.startsIdx("ere4;", start, end)) { start += 5; return 8756; }
                if(str.startsIdx("erefore;", start, end)) { start += 8; return 8756; }
                if(str.startsIdx("eta;", start, end)) { start += 4; return 952; }
                if(str.startsIdx("etasym;", start, end)) { start += 7; return 977; }
                if(str.startsIdx("etav;", start, end)) { start += 5; return 977; }
                if(str.startsIdx("ickapprox;", start, end)) { start += 10; return 8776; }
                if(str.startsIdx("icksim;", start, end)) { start += 7; return 8764; }
                if(str.startsIdx("insp;", start, end)) { start += 5; return 8201; }
                if(str.startsIdx("kap;", start, end)) { start += 4; return 8776; }
                if(str.startsIdx("ksim;", start, end)) { start += 5; return 8764; }
                if(str.startsIdx("orn", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 254; }
                break;
            case 'i':
                if(str.startsIdx("lde;", start, end)) { start += 4; return 732; }
                if(str.startsIdx("mes", start, end)) {
                    start += 3;
                    if(start < end && str[start] == ';') { start++; return 215; }
                    if(str.startsIdx("b;", start, end)) { start += 2; return 8864; }
                    if(str.startsIdx("bar;", start, end)) { start += 4; return 10801; }
                    if(str.startsIdx("d;", start, end)) { start += 2; return 10800; }
                    return 215;
                }
                if(str.startsIdx("nt;", start, end)) { start += 3; return 8749; }
                break;
            case 'o':
                if(str.startsIdx("ea;", start, end)) { start += 3; return 10536; }
                if(str.startsIdx("p;", start, end)) { start += 2; return 8868; }
                if(str.startsIdx("pbot;", start, end)) { start += 5; return 9014; }
                if(str.startsIdx("pcir;", start, end)) { start += 5; return 10993; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120165; }
                if(str.startsIdx("pfork;", start, end)) { start += 6; return 10970; }
                if(str.startsIdx("sa;", start, end)) { start += 3; return 10537; }
                break;
            case 'p': if(str.startsIdx("rime;", start, end)) { start += 5; return 8244; } break;
            case 'r':
                if(str.startsIdx("ade;", start, end)) { start += 4; return 8482; }
                if(str.startsIdx("iangle", start, end)) {
                    start += 6;
                    if(start < end && str[start] == ';') { start++; return 9653; }
                    if(str.startsIdx("down;", start, end)) { start += 5; return 9663; }
                    if(str.startsIdx("left;", start, end)) { start += 5; return 9667; }
                    if(str.startsIdx("lefteq;", start, end)) { start += 7; return 8884; }
                    if(str.startsIdx("q;", start, end)) { start += 2; return 8796; }
                    if(str.startsIdx("right;", start, end)) { start += 6; return 9657; }
                    if(str.startsIdx("righteq;", start, end)) { start += 8; return 8885; }
                    break;
                }
                if(start < end && str[start] == 'i') {
                    start++;
                    if(str.startsIdx("dot;", start, end)) { start += 4; return 9708; }
                    if(str.startsIdx("e;", start, end)) { start += 2; return 8796; }
                    if(str.startsIdx("minus;", start, end)) { start += 6; return 10810; }
                    if(str.startsIdx("plus;", start, end)) { start += 5; return 10809; }
                    if(str.startsIdx("sb;", start, end)) { start += 3; return 10701; }
                    if(str.startsIdx("time;", start, end)) { start += 5; return 10811; }
                    break;
                }
                if(str.startsIdx("pezium;", start, end)) { start += 7; return 9186; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120009; }
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1094; }
                if(str.startsIdx("hcy;", start, end)) { start += 4; return 1115; }
                if(str.startsIdx("trok;", start, end)) { start += 5; return 359; }
                break;
            case 'w':
                if(str.startsIdx("ixt;", start, end)) { start += 4; return 8812; }
                if(str.startsIdx("oheadleftarrow;", start, end)) { start += 15; return 8606; }
                if(str.startsIdx("oheadrightarrow;", start, end)) { start += 16; return 8608; }
                break;
        }
        return -1;
    }

    int entityLowerU(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A': if(str.startsIdx("rr;", start, end)) { start += 3; return 8657; } break;
            case 'H': if(str.startsIdx("ar;", start, end)) { start += 3; return 10595; } break;
            case 'a':
                if(str.startsIdx("cute", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 250; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8593; }
                break;
            case 'b':
                if(str.startsIdx("rcy;", start, end)) { start += 4; return 1118; }
                if(str.startsIdx("reve;", start, end)) { start += 5; return 365; }
                break;
            case 'c':
                if(str.startsIdx("irc", start, end)) { start += 3 + (start + 3 < end && str[start + 3] == ';'); return 251; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1091; }
                break;
            case 'd':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8645; }
                if(str.startsIdx("blac;", start, end)) { start += 5; return 369; }
                if(str.startsIdx("har;", start, end)) { start += 4; return 10606; }
                break;
            case 'f':
                if(str.startsIdx("isht;", start, end)) { start += 5; return 10622; }
                if(str.startsIdx("r;", start, end)) { start += 2; return 120114; }
                break;
            case 'g':
                if(str.startsIdx("rave", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 249; }
                break;
            case 'h':
                if(str.startsIdx("arl;", start, end)) { start += 4; return 8639; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8638; }
                if(str.startsIdx("blk;", start, end)) { start += 4; return 9600; }
                break;
            case 'l':
                if(str.startsIdx("corn;", start, end)) { start += 5; return 8988; }
                if(str.startsIdx("corner;", start, end)) { start += 7; return 8988; }
                if(str.startsIdx("crop;", start, end)) { start += 5; return 8975; }
                if(str.startsIdx("tri;", start, end)) { start += 4; return 9720; }
                break;
            case 'm':
                if(str.startsIdx("acr;", start, end)) { start += 4; return 363; }
                if(start < end && str[start] == 'l') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 168; }
                break;
            case 'o':
                if(str.startsIdx("gon;", start, end)) { start += 4; return 371; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120166; }
                break;
            case 'p':
                if(str.startsIdx("arrow;", start, end)) { start += 6; return 8593; }
                if(str.startsIdx("downarrow;", start, end)) { start += 10; return 8597; }
                if(str.startsIdx("harpoonleft;", start, end)) { start += 12; return 8639; }
                if(str.startsIdx("harpoonright;", start, end)) { start += 13; return 8638; }
                if(str.startsIdx("lus;", start, end)) { start += 4; return 8846; }
                if(str.startsIdx("si;", start, end)) { start += 3; return 965; }
                if(str.startsIdx("sih;", start, end)) { start += 4; return 978; }
                if(str.startsIdx("silon;", start, end)) { start += 6; return 965; }
                if(str.startsIdx("uparrows;", start, end)) { start += 9; return 8648; }
                break;
            case 'r':
                if(str.startsIdx("corn;", start, end)) { start += 5; return 8989; }
                if(str.startsIdx("corner;", start, end)) { start += 7; return 8989; }
                if(str.startsIdx("crop;", start, end)) { start += 5; return 8974; }
                if(str.startsIdx("ing;", start, end)) { start += 4; return 367; }
                if(str.startsIdx("tri;", start, end)) { start += 4; return 9721; }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 120010; } break;
            case 't':
                if(str.startsIdx("dot;", start, end)) { start += 4; return 8944; }
                if(str.startsIdx("ilde;", start, end)) { start += 5; return 361; }
                if(str.startsIdx("ri;", start, end)) { start += 3; return 9653; }
                if(str.startsIdx("rif;", start, end)) { start += 4; return 9652; }
                break;
            case 'u':
                if(str.startsIdx("arr;", start, end)) { start += 4; return 8648; }
                if(str.startsIdx("ml", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 252; }
                break;
            case 'w': if(str.startsIdx("angle;", start, end)) { start += 6; return 10663; } break;
        }
        return -1;
    }

    int entityLowerV(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'A': if(str.startsIdx("rr;", start, end)) { start += 3; return 8661; } break;
            case 'B':
                if(str.startsIdx("ar;", start, end)) { start += 3; return 10984; }
                if(str.startsIdx("arv;", start, end)) { start += 4; return 10985; }
                break;
            case 'D': if(str.startsIdx("ash;", start, end)) { start += 4; return 8872; } break;
            case 'a':
                if(str.startsIdx("ngrt;", start, end)) { start += 5; return 10652; }
                if(str.startsIdx("repsilon;", start, end)) { start += 9; return 1013; }
                if(str.startsIdx("rkappa;", start, end)) { start += 7; return 1008; }
                if(str.startsIdx("rnothing;", start, end)) { start += 9; return 8709; }
                if(str.startsIdx("rphi;", start, end)) { start += 5; return 981; }
                if(str.startsIdx("rpi;", start, end)) { start += 4; return 982; }
                if(str.startsIdx("rpropto;", start, end)) { start += 8; return 8733; }
                if(str.startsIdx("rr;", start, end)) { start += 3; return 8597; }
                if(str.startsIdx("rrho;", start, end)) { start += 5; return 1009; }
                if(str.startsIdx("rsigma;", start, end)) { start += 7; return 962; }
                if(str.startsIdx("rsubsetneq;", start, end)) { start += 11; return -579599872; }
                if(str.startsIdx("rsubsetneqq;", start, end)) { start += 12; return -718077440; }
                if(str.startsIdx("rsupsetneq;", start, end)) { start += 11; return -579665408; }
                if(str.startsIdx("rsupsetneqq;", start, end)) { start += 12; return -718142976; }
                if(str.startsIdx("rtheta;", start, end)) { start += 7; return 977; }
                if(str.startsIdx("rtriangleleft;", start, end)) { start += 14; return 8882; }
                if(str.startsIdx("rtriangleright;", start, end)) { start += 15; return 8883; }
                break;
            case 'c': if(str.startsIdx("y;", start, end)) { start += 2; return 1074; } break;
            case 'd': if(str.startsIdx("ash;", start, end)) { start += 4; return 8866; } break;
            case 'e':
                if(str.startsIdx("e;", start, end)) { start += 2; return 8744; }
                if(str.startsIdx("ebar;", start, end)) { start += 5; return 8891; }
                if(str.startsIdx("eeq;", start, end)) { start += 4; return 8794; }
                if(str.startsIdx("llip;", start, end)) { start += 5; return 8942; }
                if(str.startsIdx("rbar;", start, end)) { start += 5; return 124; }
                if(str.startsIdx("rt;", start, end)) { start += 3; return 124; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120115; } break;
            case 'l': if(str.startsIdx("tri;", start, end)) { start += 4; return 8882; } break;
            case 'n':
                if(str.startsIdx("sub;", start, end)) { start += 4; return -579018962; }
                if(str.startsIdx("sup;", start, end)) { start += 4; return -579084498; }
                break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120167; } break;
            case 'p': if(str.startsIdx("rop;", start, end)) { start += 4; return 8733; } break;
            case 'r': if(str.startsIdx("tri;", start, end)) { start += 4; return 8883; } break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120011; }
                if(str.startsIdx("ubnE;", start, end)) { start += 5; return -718077440; }
                if(str.startsIdx("ubne;", start, end)) { start += 5; return -579599872; }
                if(str.startsIdx("upnE;", start, end)) { start += 5; return -718142976; }
                if(str.startsIdx("upne;", start, end)) { start += 5; return -579665408; }
                break;
            case 'z': if(str.startsIdx("igzag;", start, end)) { start += 6; return 10650; } break;
        }
        return -1;
    }

    int entityLowerW(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'c': if(str.startsIdx("irc;", start, end)) { start += 4; return 373; } break;
            case 'e':
                if(str.startsIdx("dbar;", start, end)) { start += 5; return 10847; }
                if(str.startsIdx("dge;", start, end)) { start += 4; return 8743; }
                if(str.startsIdx("dgeq;", start, end)) { start += 5; return 8793; }
                if(str.startsIdx("ierp;", start, end)) { start += 5; return 8472; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120116; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120168; } break;
            case 'p': if(start < end && str[start] == ';') { start++; return 8472; } break;
            case 'r':
                if(start < end && str[start] == ';') { start++; return 8768; }
                if(str.startsIdx("eath;", start, end)) { start += 5; return 8768; }
                break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 120012; } break;
        }
        return -1;
    }

    int entityLowerX(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'c':
                if(str.startsIdx("ap;", start, end)) { start += 3; return 8898; }
                if(str.startsIdx("irc;", start, end)) { start += 4; return 9711; }
                if(str.startsIdx("up;", start, end)) { start += 3; return 8899; }
                break;
            case 'd': if(str.startsIdx("tri;", start, end)) { start += 4; return 9661; } break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120117; } break;
            case 'h':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 10234; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 10231; }
                break;
            case 'i': if(start < end && str[start] == ';') { start++; return 958; } break;
            case 'l':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 10232; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 10229; }
                break;
            case 'm': if(str.startsIdx("ap;", start, end)) { start += 3; return 10236; } break;
            case 'n': if(str.startsIdx("is;", start, end)) { start += 3; return 8955; } break;
            case 'o':
                if(str.startsIdx("dot;", start, end)) { start += 4; return 10752; }
                if(str.startsIdx("pf;", start, end)) { start += 3; return 120169; }
                if(str.startsIdx("plus;", start, end)) { start += 5; return 10753; }
                if(str.startsIdx("time;", start, end)) { start += 5; return 10754; }
                break;
            case 'r':
                if(str.startsIdx("Arr;", start, end)) { start += 4; return 10233; }
                if(str.startsIdx("arr;", start, end)) { start += 4; return 10230; }
                break;
            case 's':
                if(str.startsIdx("cr;", start, end)) { start += 3; return 120013; }
                if(str.startsIdx("qcup;", start, end)) { start += 5; return 10758; }
                break;
            case 'u':
                if(str.startsIdx("plus;", start, end)) { start += 5; return 10756; }
                if(str.startsIdx("tri;", start, end)) { start += 4; return 9651; }
                break;
            case 'v': if(str.startsIdx("ee;", start, end)) { start += 3; return 8897; } break;
            case 'w': if(str.startsIdx("edge;", start, end)) { start += 5; return 8896; } break;
        }
        return -1;
    }

    int entityLowerY(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a':
                if(str.startsIdx("cute", start, end)) { start += 4 + (start + 4 < end && str[start + 4] == ';'); return 253; }
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1103; }
                break;
            case 'c':
                if(str.startsIdx("irc;", start, end)) { start += 4; return 375; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1099; }
                break;
            case 'e':
                if(start < end && str[start] == 'n') { start += 1 + (start + 1 < end && str[start + 1] == ';'); return 165; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120118; } break;
            case 'i': if(str.startsIdx("cy;", start, end)) { start += 3; return 1111; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120170; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 120014; } break;
            case 'u':
                if(str.startsIdx("cy;", start, end)) { start += 3; return 1102; }
                if(str.startsIdx("ml", start, end)) { start += 2 + (start + 2 < end && str[start + 2] == ';'); return 255; }
                break;
        }
        return -1;
    }

    int entityLowerZ(const JString& str, int& start, int end) {
        if(start >= end) return -1;
        switch(str[start++]) {
            case 'a': if(str.startsIdx("cute;", start, end)) { start += 5; return 378; } break;
            case 'c':
                if(str.startsIdx("aron;", start, end)) { start += 5; return 382; }
                if(str.startsIdx("y;", start, end)) { start += 2; return 1079; }
                break;
            case 'd': if(str.startsIdx("ot;", start, end)) { start += 3; return 380; } break;
            case 'e':
                if(str.startsIdx("etrf;", start, end)) { start += 5; return 8488; }
                if(str.startsIdx("ta;", start, end)) { start += 3; return 950; }
                break;
            case 'f': if(str.startsIdx("r;", start, end)) { start += 2; return 120119; } break;
            case 'h': if(str.startsIdx("cy;", start, end)) { start += 3; return 1078; } break;
            case 'i': if(str.startsIdx("grarr;", start, end)) { start += 6; return 8669; } break;
            case 'o': if(str.startsIdx("pf;", start, end)) { start += 3; return 120171; } break;
            case 's': if(str.startsIdx("cr;", start, end)) { start += 3; return 120015; } break;
            case 'w':
                if(str.startsIdx("j;", start, end)) { start += 2; return 8205; }
                if(str.startsIdx("nj;", start, end)) { start += 3; return 8204; }
                break;
        }
        return -1;
    }
}