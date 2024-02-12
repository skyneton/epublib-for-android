//
// Created by skyne on 2023-12-24.
//

#ifndef TEXTREADER_ARRAY_H
#define TEXTREADER_ARRAY_H

#pragma once
#include "memory"
#include "initializer_list"
#include "algorithm"

template <typename T>
class Array {
private:
    std::shared_ptr<T> value;
    int length;
public:
    Array(): length(0) {}
    Array(int size): length(std::max(0, size)) {
        if(length <= 0) return;
        value = std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
    }
    Array(const T* source, int size, bool is_memcpy = false): length(std::max(0, size)) {
        if(length <= 0) return;
        value = std::shared_ptr<T>(new T[size], std::default_delete<T[]>());

        if(source) {
            if (is_memcpy)
                memcpy(value.get(), source, size * sizeof(T));
            else {
                for (int i = 0; i < size; i++) value.get()[i] = source[i];
            }
        }
    }
    Array(const T** source, int size): length(std::max(0, size)) {
        if(length <= 0) return;
        value = std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
        if(source) {
            for (int i = 0; i < size; i++) value.get()[i] = *source[i];
        }
    }

    Array(const std::initializer_list<T>& list): Array(list.begin(), list.size()) {}
    Array(std::__wrap_iter<T *> begin, int size): length(std::max(0, size)) {
        if(length <= 0) return;
        value = std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
        for(int i = 0; i < size; i++) value.get()[i] = begin[i];
    }

    int size() const { return length; }
    bool empty() const { return length <= 0; }
    T* begin() { return value.get(); }
    T* end() { return value.get() + length; }
    const T* begin() const { return value.get(); }
    const T* end() const { return value.get() + length; }
    Array<T> subList(int start, int end) const {
        start = std::max(0, std::min(length, start));
        end = std::max(start, std::min(length, end));
        return Array<T>(begin() + start, end - start);
    }
    const std::shared_ptr<T>& ptr() const { return value; }

    T* operator[](int index) const { return index >= 0 && index < length ? value.get() + index : nullptr; }
};


#endif //TEXTREADER_ARRAY_H
