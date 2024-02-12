#pragma once
#include "vector"
#include "JString.h"
class ByteBuf {
private:
    std::vector<char> writeBuffer;
    int position = 0;
    const char* readBuffer;
    int readBufferLength;
public:
    ByteBuf(): readBuffer(nullptr), readBufferLength(0) {}
    ByteBuf(const char* array, int length): readBuffer(array), readBufferLength(length) {}
    int readableLength() const { return readBufferLength - position; }
    char readByte() { return readBuffer[position++]; }

    int readVarInt();
    long long int readVarLong();
    short readShort() { return (((unsigned char)readByte()) << 8) | ((unsigned char)readByte()); }
    int readInt() { return (((unsigned char)readByte()) << 24) | (((unsigned char)readByte()) << 16) | (((unsigned char)readByte()) << 8) | ((unsigned char)readByte()); }
    unsigned short readUtf8Char();
    JString readString();
    bool readBool();
    Array<char> readByteArray() {
        int size = readVarInt();
        Array<char> arr(readBuffer + position, size, true);
        position += size;
        return arr;
    }

    ByteBuf& writeByte(char byte) { writeBuffer.emplace_back(byte); return *this; }
    ByteBuf& writeVarInt(int integer);
    ByteBuf& writeVarLong(long integer);
    ByteBuf& writeUtf8Char(unsigned short c);
    ByteBuf& writeString(const JString& str);
    ByteBuf& writeBool(bool b);
    ByteBuf& writeByteBuf(const ByteBuf& buf) {
        writeVarInt(buf.writeBuffer.size());
        writeBuffer.insert(writeBuffer.end(), buf.writeBuffer.begin(), buf.writeBuffer.end());
        return *this;
    }
    ByteBuf& writeByteArray(const char* array, int size) {
        writeVarInt(size);
        writeBuffer.insert(writeBuffer.end(), array, array + size);
        return *this;
    }
    ByteBuf& writeByteArray(const Array<char>& array) {
        writeVarInt(array.size());
        writeBuffer.insert(writeBuffer.end(), array.begin(), array.begin() + array.size());
        return *this;
    }
    ByteBuf& writeShort(short value) {
        writeByte((unsigned char) (value >> 8));
        return writeByte((unsigned char) (value & 0xFF));
    }
    ByteBuf& writeInt(int integer) {
        writeByte((unsigned char) ((integer >> 24) & 0xFF));
        writeByte((unsigned char) ((integer >> 16) & 0xFF));
        writeByte((unsigned char) ((integer >> 8) & 0xFF));
        return writeByte((unsigned char) (integer & 0xFF));
    }
    const std::vector<char>& getWriteBuffer() { return writeBuffer; }
};