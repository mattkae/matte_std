#include "matte_string.h"
#include <cstring>

namespace matte {
    String::String() { }

    String::String(const char* s) {
        set_string(*this, s);
    }

    String::String(const String& s) {
        set_string(*this, string_c_value(s));
    }

    String::~String() {
        string_free(*this);
    }

    void set_string(String& str, const char* s) {
        string_free(str); // Always free a string before setting it. If you intended to build the string, use StringBuilder instead.

        int len = strlen(s);
        if (len >= SSO_SIZE) {
            str.dynamicBuffer = new char[len + 1];
            memcpy(str.dynamicBuffer, s, len);
            str.dynamicBuffer[len] = '\0';
            str.isSso = false;
        } else {
            memcpy(str.defaultBuffer, s, len);
            str.isSso = true;
        }
    }

    void string_print(String& s) {
        
    }
    
    const char* string_c_value(const String& s) {
        return s.isSso ? s.defaultBuffer : s.dynamicBuffer;
    }

    int string_indexof(String& s, char c) {
        return -1;
    }

    int string_indexof(String& s, char* other) {
        return -1;
    }

    int string_indexof(String& s, String& other) {
        return -1;
    }

    int string_equals(String& s, const char* str) {
        return -1;
    }
    
    void string_clear(String& s) {
        if (s.isSso) {
            s.defaultBuffer[0] = '\0';
        } else if (s.dynamicBuffer != NULL) {
            s.dynamicBuffer[0] = '\0';
        }
    }
    
    void string_free(String& s) {
        if (s.dynamicBuffer != NULL) {
            delete s.dynamicBuffer;
            s.dynamicBuffer = NULL;
            s.isSso = true;
        }

        string_clear(s);
    }

    String& String::operator=(const char* other) {
        set_string(*this, other);
        return *this;
    }

    String& String::operator=(const String& other) {
        set_string(*this, string_c_value(other));
        return *this;
    }
};
