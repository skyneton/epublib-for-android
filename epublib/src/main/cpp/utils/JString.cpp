#include "JString.h"
#include "algorithm"
#include "vector"
#include "utils.h"
#include "JStringBuilder.h"

JString::JString(const unsigned short *str, size_t length): length(std::max(0, static_cast<int>(length))) {
    if(length <= 0) return;
    value = std::shared_ptr<unsigned short>(new unsigned short[length], std::default_delete<unsigned short[]>());
    memcpy(value.get(), str, length * sizeof(short));
}
JString::JString(const char *str) {
    std::vector<unsigned short>result;
    for(int i = 0; str[i]; i++) {
        int utf8 = 0;
        unsigned char byte = str[i];
        int len = 0;
        for(; len < 7 && ((byte >> (7 - len)) & 1); len++);
        utf8 |= ((byte << len) & 0xFF) >> len;
        for(--len, i++; len > 0 && str[i]; len--) {
            utf8 <<= 6;
            utf8 |= str[i++] & 0x3F;
        }
        i--;

        if(utf8 >= 0x10000) {
            result.emplace_back((unsigned short)((utf8 - 0x10000) / 0x400 + 0xD800));
            result.emplace_back((unsigned short)((utf8 - 0x10000) % 0x400 + 0xDC00));
        }else
            result.emplace_back(utf8);
    }

    length = result.size();
    value = std::shared_ptr<unsigned short>(new unsigned short[length], std::default_delete<unsigned short[]>());
    memcpy(value.get(), result.data(), length * sizeof(short));
}

JString::JString(const Array<char>& str) {
    if(str.size() <= 0) return;
    std::vector<unsigned short>result;
    for(int i = 0; i < str.size(); i++) {
        int utf8 = 0;
        unsigned char byte = *str[i];
        int len = 0;
        for(; len < 7 && ((byte >> (7 - len)) & 1); len++);
        utf8 |= ((byte << len) & 0xFF) >> len;
        for(--len, i++; len > 0 && i < str.size(); len--) {
            utf8 <<= 6;
            utf8 |= *str[i++] & 0x3F;
        }
        i--;
        if(utf8 >= 0x10000) {
            result.emplace_back((unsigned short)((utf8 - 0x10000) / 0x400 + 0xD800));
            result.emplace_back((unsigned short)((utf8 - 0x10000) % 0x400 + 0xDC00));
        }else
            result.emplace_back(utf8);
    }

    length = result.size();
    value = std::shared_ptr<unsigned short>(new unsigned short[length], std::default_delete<unsigned short[]>());
    memcpy(value.get(), result.data(), length * sizeof(short));
}

JString::JString(unsigned short c) {
    length = 1;
    value = std::shared_ptr<unsigned short>(new unsigned short[length] { c }, std::default_delete<unsigned short[]>());
}

JString::JString(const Array<unsigned short>& c) {
    length = c.size();
    value = c.ptr();
}

JString::JString(const JString &a, unsigned short b) {
    length = a.length + 1;
    value = std::shared_ptr<unsigned short>(new unsigned short[length], std::default_delete<unsigned short[]>());
    memcpy(value.get(), a.begin(), a.length * sizeof(short));
    value.get()[a.length] = b;
}

JString::JString(const JString &a, const JString &b) {
    length = a.length + b.length;
    value = std::shared_ptr<unsigned short>(new unsigned short[length], std::default_delete<unsigned short[]>());
    memcpy(value.get(), a.begin(), a.length * sizeof(short));
    memcpy(value.get() + a.length, b.begin(), b.length * sizeof(short));
}

JString::JString(unsigned short a, const JString &b) {
    length = 1 + b.length;
    value = std::shared_ptr<unsigned short>(new unsigned short[length] { a }, std::default_delete<unsigned short[]>());
    memcpy(value.get() + 1, b.begin(), b.length * sizeof(short));
}

bool JString::operator==(const JString& str) const {
    if(str.length != length) return 0;
    for(int i = 0; i < length; i++) {
        if(str.value.get()[i] != value.get()[i]) return 0;
    }
    return 1;
}
bool JString::operator==(const char* str) const {
    int i = 0;
    for(; i < length && str[i]; i++) {
        if(str[i] != value.get()[i]) return 0;
    }
    return !str[i] && i >= length;
}

bool JString::equals(unsigned short c, bool ignoreCase) const {
    return length == 1 && (ignoreCase ? utils::lower(value.get()[0]) : value.get()[0]) == (ignoreCase ? utils::lower(c) : c);
}

bool JString::equals(const char *str, bool ignoreCase) const {
    int i = 0;
    if(ignoreCase) {
        for(; i < length && str[i]; i++) {
            if(utils::lower(value.get()[i]) != utils::lower(str[i])) return 0;
        }
    }else {
        for(; i < length && str[i]; i++) {
            if(value.get()[i] != str[i]) return 0;
        }
    }
    return !str[i] && i >= length;
}

bool JString::startsIdx(const char *str, int start, int end, bool ignoreCase) const {
    int i = 0;
    end = std::min(length, end);
    if(ignoreCase) {
        for(; start < end && str[i]; start++, i++) {
            if(utils::lower(value.get()[start]) != utils::lower(str[i])) return 0;
        }
    }else {
        for(; start < end && str[i]; start++, i++) {
            if(value.get()[start] != str[i]) return 0;
        }
    }
    return !str[i];
}

bool JString::equals(const JString &str, bool ignoreCase) const {
    if(str.length != length) return 0;
    if(ignoreCase) {
        for(int i = 0; i < length; i++) {
            if(utils::lower(value.get()[i]) != utils::lower(str.value.get()[i])) return 0;
        }
    }else {
        for(int i = 0; i < length; i++) {
            if(value.get()[i] != str.value.get()[i]) return 0;
        }
    }
    return 1;
}

bool JString::startsWith(unsigned short c) const {
    return length > 0 && value.get()[0] == c;
}
bool JString::startsWith(const JString& str, bool ignoreCase) const {
    if(length < str.length) return 0;
    if(ignoreCase) {
        for(int i = 0; i < str.length; i++) {
            if(utils::lower(value.get()[i]) != utils::lower(str.value.get()[i]))
                return 0;
        }
    }else {
        for(int i = 0; i < str.length; i++) {
            if(value.get()[i] != str.value.get()[i])
                return 0;
        }
    }
    return 1;
}
bool JString::startsWith(const char* str, bool ignoreCase) const {
    int i = 0;
    if(ignoreCase) {
        while(i < length && str[i]) {
            if(utils::lower(value.get()[i]) != utils::lower(str[i]))
                return 0;
            i++;
        }
    }else {
        while(i < length && str[i]) {
            if(value.get()[i] != utils::lower(str[i]))
                return 0;
            i++;
        }
    }
    return !str[i];
}

bool JString::endsWith(unsigned short c) const {
    return length > 0 && value.get()[length - 1] == c;
}
bool JString::endsWith(const JString& str, bool ignoreCase) const {
    if(length < str.length) return 0;
    if(ignoreCase) {
        for(int i = 1; i <= str.length; i++) {
            if(utils::lower(value.get()[length - i]) != utils::lower(str.value.get()[str.length - i]))
                return 0;
        }
    }else {
        for(int i = 1; i <= str.length; i++) {
            if(value.get()[length - i] != str.value.get()[str.length - i])
                return 0;
        }
    }
    return 1;
}
bool JString::endsWith(const char* str, bool ignoreCase) const {
    int strLength = 0;
    while(str[strLength]) strLength++;
    if(length < strLength) return 0;
    if(ignoreCase) {
        for(int i = 1; i <= strLength; i++) {
            if(utils::lower(value.get()[length - i]) != utils::lower(str[strLength - i]))
                return 0;
        }
    }else {
        for(int i = 1; i <= strLength; i++) {
            if(value.get()[length - i] != str[strLength - i]) return 0;
        }
    }
    return 1;
}

JString JString::substr(int pos, int len) const {
    return JString(value.get() + pos, std::max(0, std::min(length - pos, len < 0 ? length - pos : len)));
}

JString JString::substring(int pos, int end) const {
    return JString(value.get() + pos, std::max(0, std::min(length - pos, end < 0 ? length - pos : (end - pos))));
}

JString JString::ltrim() const {
    for(int i = 0; i < length; i++) {
        if(!isspace(value.get()[i])) return JString(value.get() + i, length - i);
    }
    return {};
}

JString JString::rtrim() const {
    for(int i = length - 1; i >= 0; i--) {
        if(!isspace(value.get()[i])) return JString(value.get(), i + 1);
    }
    return {};
}

JString JString::trim() const {
    int left = 0, right = length - 1;
    for(; left < length && isspace(value.get()[left]); left++);
    if(left == length) return {};
    for(; right >= 0 && isspace(value.get()[right]); right--);
    if(right < left) return {};
    return JString(value.get() + left, right - left + 1);
}

JString JString::lower() const {
//    Array<unsigned short>arr(length);
//    for(int i = 0; i < length; i++) {
//        *arr[i] = utils::lower(value.get()[i]);
//    }
//    return arr;
    JString result(begin(), length);
    for(int i = 0; i < length; i++) {
        if(result.value.get()[i] >= 'A' && result.value.get()[i] <= 'Z')
            result.value.get()[i] += 'a' - 'A';
    }
    return result;
}

Array<char> JString::c_str() const {
    std::vector<char> result;
    for(int i = 0; i < length; i++) {
        int c = value.get()[i];
        if(0xD800 <= c && c <= 0xD8FF && i + 1 < length && 0xDC00 <= value.get()[i + 1] && value.get()[i + 1] <= 0xDFFF) {
            c = (c - 0xD800) * 0x400 + (value.get()[i + 1] - 0xDC00) + 0x10000;
            i++;
        }
        int len = 0;
        for(;c >> (6 * len + 7 - len); len++);
        if(len == 0)
            result.emplace_back((unsigned char) (c >> (6 * len)));
        else
            result.emplace_back((unsigned char) ((c >> (6 * len)) | (0xFF << (7 - len)) & 0xFF));

        while(--len >= 0) {
            result.emplace_back((unsigned char) (((c >> (6 * len)) & 0x3F) | 128));
        }
    }
    return { result.data(), static_cast<int>(result.size()) };
}

Array<char> JString::c_str_null() const {
    std::vector<char> result;
    for(int i = 0; i < length; i++) {
        int c = value.get()[i];
        if(0xD800 <= c && c <= 0xD8FF && i + 1 < length && 0xDC00 <= value.get()[i + 1] && value.get()[i + 1] <= 0xDFFF) {
            c = (c - 0xD800) * 0x400 + (value.get()[i + 1] - 0xDC00) + 0x10000;
            i++;
        }
        int len = 0;
        for(;c >> (6 * len + 7 - len); len++);
        if(len == 0)
            result.emplace_back((unsigned char) (c >> (6 * len)));
        else
            result.emplace_back((unsigned char) ((c >> (6 * len)) | (0xFF << (7 - len)) & 0xFF));

        while(--len >= 0) {
            result.emplace_back((unsigned char) (((c >> (6 * len)) & 0x3F) | 128));
        }
    }
    result.emplace_back(0);
    return { result.data(), static_cast<int>(result.size()) };
}

int JString::lastIndexOf(unsigned short c, int start) const {
    start = start < 0 ? length - 1 : std::min(length - 1, start);
    for(int i = start; i >= 0; i--) {
        if(value.get()[i] == c) return i;
    }
    return -1;
}

int JString::indexOf(unsigned short c, int start, bool ignoreCase) const {
    start = std::max(0, start);
    if(ignoreCase) {
        c = utils::lower(c);
        for (int i = start; i < length; i++) {
            if (utils::lower(value.get()[i]) == c) return i;
        }
    }else {
        for (int i = start; i < length; i++) {
            if (value.get()[i] == c) return i;
        }
    }
    return -1;
}

int JString::indexOf(unsigned short c, int start, int end, bool ignoreCase) const {
    start = std::max(0, start);
    end = end < 0 ? length : std::min(length, end);
    if(ignoreCase) {
        c = utils::lower(c);
        for (int i = start; i < end; i++) {
            if (utils::lower(value.get()[i]) == c) return i;
        }
    }else {
        for (int i = start; i < end; i++) {
            if (value.get()[i] == c) return i;
        }
    }
    return -1;
}

int JString::ignoreCaseIndexOf(const JString& other, int start) const {
    if(other.empty()) return 0;
    unsigned short* a = value.get(), * b = other.value.get();
    int patternLastIdx = other.length - 1;
    unsigned short patternStart = utils::lower(b[0]);
    unsigned short patternEnd = utils::lower(b[patternLastIdx]);
    int end = length - other.length;
    for (int i = start; i <= end; i++) {
        while (i <= end && (utils::lower(a[i]) != patternStart || utils::lower(a[i + patternLastIdx]) != patternEnd)) i++;
        if (i > end) break;

        int j = i + patternLastIdx - 1, k = patternLastIdx - 1;
        while(k > 0 && utils::lower(a[j]) == utils::lower(b[k])) j--, k--;
        if (k == 0) return i;
        unsigned short c = utils::lower(a[j]);
        while (k >= 0 && c != utils::lower(b[k])) k--;
        i += patternLastIdx - k - 1;
    }
    return -1;
}

int JString::ignoreCaseIndexOf(const char* other, int start) const {
    unsigned short* a = value.get();
    int otherLength = 0;
    while(other[otherLength]) otherLength++;
    if(otherLength <= 0) return 0;
    int patternLastIdx = otherLength - 1;
    unsigned short patternStart = utils::lower(other[0]);
    unsigned short patternEnd = utils::lower(other[patternLastIdx]);
    int end = length - otherLength;
    for (int i = start; i <= end; i++) {
        while (i <= end && (utils::lower(a[i]) != patternStart || utils::lower(a[i + patternLastIdx]) != patternEnd)) i++;
        if (i > end) break;

        int j = i + patternLastIdx - 1, k = patternLastIdx - 1;
        while(k > 0 && utils::lower(a[j]) == utils::lower(other[k])) j--, k--;
        if (k == 0) return i;
        unsigned short c = utils::lower(a[j]);
        while (k >= 0 && c != utils::lower(other[k])) k--;
        i += patternLastIdx - k - 1;
    }
    return -1;
}

int JString::ignoreCaseIndexOf(const unsigned short* other, int start) const {
    unsigned short* a = value.get();
    int otherLength = 0;
    while(other[otherLength]) otherLength++;
    if(otherLength <= 0) return 0;
    int patternLastIdx = otherLength - 1;
    unsigned short patternStart = utils::lower(other[0]);
    unsigned short patternEnd = utils::lower(other[patternLastIdx]);
    int end = length - otherLength;
    for (int i = start; i <= end; i++) {
        while (i <= end && (utils::lower(a[i]) != patternStart || utils::lower(a[i + patternLastIdx]) != patternEnd)) i++;
        if (i > end) break;

        int j = i + patternLastIdx - 1, k = patternLastIdx - 1;
        while(k > 0 && utils::lower(a[j]) == utils::lower(other[k])) j--, k--;
        if (k == 0) return i;
        unsigned short c = utils::lower(a[j]);
        while (k >= 0 && c != utils::lower(other[k])) k--;
        i += patternLastIdx - k - 1;
    }
    return -1;
}

int JString::caseIndexOf(const JString& other, int start) const {
    unsigned short *a = value.get(), *b = other.value.get();
    unsigned short patternStart = b[0];
    unsigned short patternEnd = b[other.length - 1];
    int end = length - other.length;
    int patternLastIdx = other.length - 1;
    for (int i = start; i <= end; i++) {
        while (i <= end && (a[i] != patternStart || a[i + patternLastIdx] != patternEnd)) i++;
        if (i > end) break;

        int j = i + patternLastIdx - 1, k = patternLastIdx - 1;
        while (k > 0 && a[j] == b[k]) j--, k--;
        if (k == 0) return i;
        unsigned short c = a[j];
        while (k >= 0 && c != b[k]) k--;
        i += patternLastIdx - k - 1;
    }
    return -1;
}

int JString::caseIndexOf(const char* other, int start) const {
    unsigned short *a = value.get();
    int otherLength = 0;
    while(other[otherLength]) otherLength++;
    int patternLastIdx = otherLength - 1;

    unsigned short patternStart = other[0];
    unsigned short patternEnd = other[patternLastIdx];

    int end = length - otherLength;
    for (int i = start; i <= end; i++) {
        while (i <= end && (a[i] != patternStart || a[i + patternLastIdx] != patternEnd)) i++;
        if (i > end) break;

        int j = i + patternLastIdx - 1, k = patternLastIdx - 1;
        while (k > 0 && a[j] == other[k]) j--, k--;
        if (k == 0) return i;
        unsigned short c = a[j];
        while (k >= 0 && c != other[k]) k--;
        i += patternLastIdx - k - 1;
    }
    return -1;
}

int JString::caseIndexOf(const unsigned short * other, int start) const {
    unsigned short *a = value.get();
    int otherLength = 0;
    while(other[otherLength]) otherLength++;
    int patternLastIdx = otherLength - 1;

    unsigned short patternStart = other[0];
    unsigned short patternEnd = other[patternLastIdx];

    int end = length - otherLength;
    for (int i = start; i <= end; i++) {
        while (i <= end && (a[i] != patternStart || a[i + patternLastIdx] != patternEnd)) i++;
        if (i > end) break;

        int j = i + patternLastIdx - 1, k = patternLastIdx - 1;
        while (k > 0 && a[j] == other[k]) j--, k--;
        if (k == 0) return i;
        unsigned short c = a[j];
        while (k >= 0 && c != other[k]) k--;
        i += patternLastIdx - k - 1;
    }
    return -1;
}

int JString::indexOf(const JString& other, int start, bool ignoreCase) const {
    return ignoreCase ? ignoreCaseIndexOf(other, start) : caseIndexOf(other, start);
}

int JString::indexOf(const char* other, int start, bool ignoreCase) const {
    return ignoreCase ? ignoreCaseIndexOf(other, start) : caseIndexOf(other, start);
}

int JString::indexOf(const unsigned short * other, int start, bool ignoreCase) const {
    return ignoreCase ? ignoreCaseIndexOf(other, start) : caseIndexOf(other, start);
}

JString JString::replace(const JString &oldValue, const JString &newValue) const {
    int pos_start = 0, pos_end;
    JStringBuilder builder;
    while((pos_end = indexOf(oldValue, pos_start)) >= 0) {
        builder += substring(pos_start, pos_end);
        builder += newValue;
        pos_start = pos_end + oldValue.length;
    }
    if(pos_start == 0) return *this;

    if(pos_start < length)
        builder += substring(pos_start, length);
    return builder.toString();
}
JString JString::replace(const char* oldValue, const char* newValue) const {
    int pos_start = 0, pos_end;
    JStringBuilder builder;
    int oldLength = 0;
    while(oldValue[oldLength]) oldLength++;
    while((pos_end = indexOf(oldValue, pos_start)) >= 0) {
        builder += substring(pos_start, pos_end);
        builder.append(newValue);
        pos_start = pos_end + oldLength;
    }
    if(pos_start == 0) return *this;

    if(pos_start < length)
        builder += substring(pos_start, length);
    return builder.toString();
}
JString JString::replace(const char* oldValue, const unsigned short* newValue) const {
    int pos_start = 0, pos_end;
    JStringBuilder builder;
    int oldLength = 0;
    while(oldValue[oldLength]) oldLength++;
    while((pos_end = indexOf(oldValue, pos_start)) >= 0) {
        builder += substring(pos_start, pos_end);
        builder.append(newValue);
        pos_start = pos_end + oldLength;
    }
    if(pos_start == 0) return *this;

    if(pos_start < length)
        builder += substring(pos_start, length);
    return builder.toString();
}
JString JString::replace(const char* oldValue, const unsigned short newValue) const {
    int pos_start = 0, pos_end;
    JStringBuilder builder;
    int oldLength = 0;
    while(oldValue[oldLength]) oldLength++;
    while((pos_end = indexOf(oldValue, pos_start)) >= 0) {
        builder += substring(pos_start, pos_end);
        builder.append(newValue);
        pos_start = pos_end + oldLength;
    }
    if(pos_start == 0) return *this;

    if(pos_start < length)
        builder += substring(pos_start, length);
    return builder.toString();
}
JString JString::replace(const unsigned short* oldValue, const unsigned short* newValue) const {
    int pos_start = 0, pos_end;
    JStringBuilder builder;
    int oldLength = 0;
    while(oldValue[oldLength]) oldLength++;
    while((pos_end = indexOf(oldValue, pos_start)) >= 0) {
        builder += substring(pos_start, pos_end);
        builder.append(newValue);
        pos_start = pos_end + oldLength;
    }
    if(pos_start == 0) return *this;

    if(pos_start < length)
        builder += substring(pos_start, length);
    return builder.toString();
}

Array<JString> JString::split(unsigned short c) const {
    int start = 0, end;
    std::vector<JString>splits;
    while((end = indexOf(c, start, false)) >= 0) {
        splits.emplace_back(substring(start, end));
        start = end + 1;
    }
    if(start < length) {
        splits.emplace_back(substring(start, length));
    }
    return Array<JString>(splits.data(), splits.size());
}

JString JString::splitFirst(unsigned short c) const {
    int start = 0, end;
    std::vector<JString>splits;
    while((end = indexOf(c, start, false)) >= 0) {
        return substring(start, end);
    }
    return substring(start, length);
}

const JString &JString::getOrDefault(const JString &base) const {
    return length <= 0 ? base : *this;
}

double JString::toDouble() const {
    unsigned short* ptr = value.get();
    while (ptr < end() && utils::isspace(*ptr)) ++ptr;
    if(ptr >= end()) return 0;
    int sign = 1;
    if (*ptr == '-' || *ptr == '+')
        sign = (*ptr++ == '-') ? -1 : 1;

    int integer = 0;
    double decimal = 0;
    while (ptr < end() && *ptr >= '0' && *ptr <= '9')
        integer = integer * 10 + (*ptr++ & 15);

    if (ptr < end() && *ptr == '.') {
        double decimalMul = 0.1;
        ptr++;
        while (ptr < end() && *ptr >= '0' && *ptr <= '9') {
            decimal += decimalMul * (*ptr++ & 15);
            decimalMul *= 0.1;
        }
    }
    return sign * (integer + decimal);
}

int JString::hexToInt() const {
    int result = 0;
    for(int i = 0; i < length; i++) {
        unsigned short c = value.get()[i];
        if(c >= '0' && c <= '9')
            result = (result << 4) | (result & 15);
        else if(c >= 'a' && c <= 'z')
            result = (result << 4) | (result - 'a' + 10);
        else if(c >= 'A' && c <= 'Z')
            result = (result << 4) | (result - 'A' + 10);
        else return 0;
    }
    return result;
}

bool JString::isDigitOnly() const {
    for(int i = 0; i < length; i++) {
        unsigned short c = value.get()[i];
        if(!(c >= '0' && c <= '9')) return 0;
    }
    return 1;
}

JString JString::operator+=(unsigned short a) {
    return *this = JString(*this, a);
}

JString JString::operator+=(const JString &a) {
    return *this = JString(*this, a);
}

JString operator+(unsigned short a, const JString& b) {
    return JString(a, b);
}
JString operator+(const JString& a, unsigned short b) {
    return JString(a, b);
}
JString operator+(const JString& a, const JString& b) {
    return JString(a, b);
}