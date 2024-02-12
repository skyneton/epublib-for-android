#include "ByteBuf.h"

int ByteBuf::readVarInt() {
    int value = 0;
    int byteLength = 0;
    unsigned char byte;
    while((byte = readByte()) & 0x80) {
        value |= (byte & 0x7F) << (byteLength++ * 7);
        if(byteLength > 5) throw "VarInt too long.";
    }
    return value | ((byte & 0x7F) << (byteLength * 7));
}

long long ByteBuf::readVarLong() {
    long value = 0;
    int byteLength = 0;
    unsigned char byte;
    while((byte = readByte()) & 0x80) {
        value |= (byte & 0x7F) << (byteLength++ * 7);
        if(byteLength > 10) throw "VarLong too long.";
    }
    return value | ((byte & 0x7F) << (byteLength * 7));
}

unsigned short ByteBuf::readUtf8Char() {
    unsigned short value = 0;
    unsigned char byte = readByte();
    int len = 0;
    for(; len < 7 && ((byte >> (7 - len)) & 1); len++);
    value |= ((byte << len) & 0xFF) >> len;
    while(--len > 0) {
        value <<= 6;
        value |= readByte() & 0x3F;
    }
    return value;
}

JString ByteBuf::readString() {
    return JString(readByteArray());
}

bool ByteBuf::readBool() {
    return readByte() != 0;
}

ByteBuf &ByteBuf::writeVarInt(int integer) {
    unsigned int value = integer;
    while(value & -128) {
        writeByte((unsigned char) (value & 127) | 128);
        value >>= 7;
    }
    return writeByte(value);
}

ByteBuf &ByteBuf::writeVarLong(long integer) {
    unsigned long value = integer;
    while(value & -128) {
        writeByte((unsigned char) (value & 127) | 128);
        value >>= 7;
    }
    return writeByte(value);
}

ByteBuf &ByteBuf::writeUtf8Char(unsigned short c) {
    int len = 0;
    while(c & -64) {
        writeByte((unsigned char) (c & 0x3F));
        c >>= 6;
        len++;
    }
    return writeByte((unsigned char)(((0xFF << (7 - len)) & 0xFF) | c));
}

ByteBuf &ByteBuf::writeString(const JString& str) {
    return writeByteArray(str.c_str());
}

ByteBuf &ByteBuf::writeBool(bool b) {
    writeBuffer.emplace_back(b);
    return *this;
}