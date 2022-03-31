#include "hashmap.h"

// https://research.cs.vt.edu/AVresearch/hashing/strings.php
i64 strHashFunc(const char* str) {
    i32 len = strlen(str);
    i32 intLength = len / 4;
    i64 sum = 0;
    for (i32 j = 0; j < intLength; j++) {
        i32 substrLen = (j * 4) + 4;
        const char* ptr = &str[j * 4];
        long mult = 1;
        for (int k = 0; k < substrLen; k++) {
            sum += ptr[k] * mult;
            mult *= 256;
        }
    }

    const char* ptr = &str[intLength * 4];
    i32 endOfStringLen = strlen(ptr);
    
    long mult = 1;
    for (int k = 0; k < endOfStringLen; k++) {
        sum += ptr[k] * mult;
        mult *= 256;
    }

    return labs(sum);
}