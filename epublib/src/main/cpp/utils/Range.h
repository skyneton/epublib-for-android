//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_RANGE_H
#define TEXTREADER_RANGE_H
#pragma once

template<class T>
class Range {
private:
    T item;
    int start, end;
public:
    Range() {}
    Range(const T& item, int start, int end): item(item), start(start), end(end) {}
    T& getItem() { return item; }
    const T& getItem() const { return item; }
    int getStart() const { return start; }
    int getEnd() const { return end; }
};


#endif //TEXTREADER_RANGE_H
