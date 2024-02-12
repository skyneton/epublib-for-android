#pragma once

#include "memory"
#include "Array.h"
class JString {
private:
    std::shared_ptr<unsigned short> value;
    int length = 0;
    size_t hash = 0;
public:
    JString() {}
    JString(const unsigned short *str, size_t length);
    JString(const char* str);
    JString(const Array<char>& str);
    JString(const Array<unsigned short>& str);
    JString(unsigned short c);
    JString(const JString& a, unsigned short b);
    JString(const JString& a, const JString& b);
    JString(unsigned short a, const JString& b);

    int size() const { return length; }
    bool operator==(const JString& str) const;
    bool operator==(const char* str) const;
    bool operator==(const unsigned short c) const { return length == 1 && value.get()[0] == c; }
    bool operator!=(const JString& str) const { return !(*this == str); }

    bool equals(const char* str, bool ignoreCase = false) const;
    bool startsIdx(const char* str, int start, int end, bool ignoreCase = false) const;
    bool equals(const JString& str, bool ignoreCase = false) const;
    bool equals(unsigned short, bool ignoreCase = false) const;


    unsigned short operator[](int index) const { return index >= 0 && index < length ? value.get()[index] : 0; }
    bool empty() const { return length <= 0; }

    bool startsWith(unsigned short c) const;
    bool startsWith(const JString& str, bool ignoreCase = false) const;
    bool startsWith(const char* str, bool ignoreCase = false) const;
    bool endsWith(unsigned short c) const;
    bool endsWith(const JString& str, bool ignoreCase = false) const;
    bool endsWith(const char* str, bool ignoreCase = false) const;
    JString substr(int pos = 0, int len = -1) const;
    JString substring(int pos = 0, int end = -1) const;
    Array<JString> split(unsigned short c) const;
    JString splitFirst(unsigned short c) const;
    JString ltrim() const;
    JString rtrim() const;
    JString trim() const;
    JString lower() const;
    Array<char> c_str() const;
    Array<char> c_str_null() const;
    int lastIndexOf(unsigned short c, int start = -1) const;
    int indexOf(unsigned short c, int start = 0, bool ignoreCase = false) const;
    int indexOf(unsigned short c, int start = 0, int end = -1, bool ignoreCase = false) const;
    int ignoreCaseIndexOf(const JString& other, int start) const;
    int ignoreCaseIndexOf(const char* other, int start) const;
    int ignoreCaseIndexOf(const unsigned short* other, int start) const;
    int caseIndexOf(const JString& other, int start) const;
    int caseIndexOf(const char* other, int start) const;
    int caseIndexOf(const unsigned short* other, int start) const;
    int indexOf(const JString& other, int start = 0, bool ignoreCase = false) const;
    int indexOf(const char* other, int start = 0, bool ignoreCase = false) const;
    int indexOf(const unsigned short* other, int start = 0, bool ignoreCase = false) const;

    JString replace(const JString& oldValue, const JString& newValue) const;
    JString replace(const char* oldValue, const char* newValue) const;
    JString replace(const char* oldValue, const unsigned short newValue) const;
    JString replace(const char* oldValue, const unsigned short* newValue) const;
    JString replace(const unsigned short* oldValue, const unsigned short* newValue) const;

    const JString& getOrDefault(const JString& base) const;
    double toDouble() const;
    int hexToInt() const;

    bool isDigitOnly() const;

    const unsigned short * begin() const { return value.get(); }
    const unsigned short * end() const { return value.get() + length; }

    JString operator+=(unsigned short a);
    JString operator+=(const JString& a);

    size_t hashCode() const {
        size_t h = hash;
        if(h == 0 && length > 0) {
            for(int i = 0; i < length; i++)
                h = h * 31 + value.get()[i];

            const_cast<JString*>(this)->hash = h;
        }
        return h;
    }
};

JString operator+(unsigned short a, const JString& b);
JString operator+(const JString& a, unsigned short b);
JString operator+(const JString& a, const JString& b);

template<>
class std::hash<JString> {
public:
    size_t operator()(const JString& o) const { return o.hashCode(); }
};