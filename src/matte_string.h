#include <cstddef>

/**
   Strings in our world are NOT intended to be the mechanism through which strings
   are built. Although functions exist to do this, it is better to rely on on
   matte::StringBuilder to create Strings without taking massive performance hits.
**/
namespace matte {
    const int SSO_SIZE = 32;

    struct String {
        String();
        String(const char* s);
        String(const String& s);
        ~String(); // Destructor will free this memory when it goes out of scope.
                   // Although I generally dislike RAII, explicitly deleting strings sucks.

        char defaultBuffer[32] = { '\0' };
        char* dynamicBuffer = NULL;

        bool isSso = true;
        int length = 0;
        int capacity = 0;

        String& operator=(const char* other);
        String& operator=(const String& other);
    };

    void set_string(String& str, const char* s);
    void string_print(String& s);
    const char* string_c_value(const String& s);
    int string_indexof(String& s, char c);
    int string_indexof(String& s, char* other);
    int string_indexof(String& s, String& other);
    int string_equals(String& s, char* str);
    void string_clear(String& s);
    void string_free(String& s);
};
