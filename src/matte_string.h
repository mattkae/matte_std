namespace matte {
    const SSO_SIZE = 32;

    struct String {
        String();
        String(const char* s);
        String(const String&& s);
        ~String(); // Destructor will free this memory when it goes out of scope.
                   // Although I hate RAII, explicitly delting strings sucks.
        operator=();

        char defaultBuffer[32] = { '\0' }'
        char* dynamicBuffer = NULL;

        bool isSso = true;
        int length = 0;
        int capacity = 0;

        char* getValue();
    };

    void string_print(String& s);
    char* string_c_value(String& s);
    int string_indexof(String& s, char c);
    int string_indexof(String& s, char* other);
    int string_indexof(String& s, String& other);
    int string_equals(String& s, char* str);
    void string_clear(String& s);
    void string_free(String& s);
};
