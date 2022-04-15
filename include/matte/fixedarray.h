#ifndef FIXED_ARRAY_H
#define FIXED_ARRAY_H

#include "types.h"
#include <cstring>
template <typename T, i32 SIZE>
struct FixedArray {
    T elements[SIZE];
    i32 size = SIZE;

    FixedArray() { }

    FixedArray(const T (&inElements)[SIZE]) {
        memcpy(elements, inElements, SIZE * sizeof(T));
    }

    T& operator[](i32 i) {
        if (i < SIZE) return elements[i];
        else return elements[SIZE - 1];
    }
};

#endif