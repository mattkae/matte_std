#include "matte_string.h"
#include <cstring>

namespace matte {
    String::String() { }

    String::String(const char* s) {
        int len = strlen(s);
        if (len >= SSO_SIZE) {
            dynamicBuffer = new char[len + 1];
            memcpy(dynamicBuffer, s, len);
            dynamicBuffer[len] = '\0';
            isSso = false;
        } else {
            memcpy(defaultBuffer, s, len);
            isSso = true;
        }
    }

    char* String::getValue() {
        if (isSso) {
            return defaultBuffer;
        } else {
            return dynamicBuffer;
        }
    }

    void string_print(String& s) {
        
    }
    
    char* string_c_value(String& s) {

    }

    int string_indexof(String& s, char c) {

    }

    int string_indexof(String& s, char* other) {
        
    }

    int string_indexof(String& s, String& other) {

    }

    int string_equals(String& s, char* str) {

    }
    
    void string_clear(String& s) {
        
    }
    
    void string_free(String& s) {

    }
};
