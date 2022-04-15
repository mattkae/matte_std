#pragma once
#include "matte_string.h"

namespace matte {
    struct SbBuffer {
        int bufferPosition = 0;
        char buffer[32] = { '\0' };
    };

    struct SbBufferAddResult {
        int amountAdded = 0;
        int amountLeft = 0;
    };

    SbBufferAddResult sb_buffer_add(const char* s);

    struct StringBuilder {
        int length = 0;
        int bufferPointer = 0;
        int numBuffers = 0;
        
        ~StringBuilder();

        
    };

    void stringbuilder_add_str(const char* s);
    void stringbuilder_add_str(const String& s);
    void stringbuilder_add_format(const char* format, ...);
    void stringbuilder_add_char();
    void stringbuilder_clear();
    void stringbuilder_free();
};
