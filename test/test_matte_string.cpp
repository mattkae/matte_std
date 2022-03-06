#include "../src/matte_string.h"
#include <cstdio>
#include "test.h"

void test_set();
void test_set_big();
void test_constructor_1();
void test_constructor_1_big();
void test_constructor_2();

const char* big_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

int main() {
    Test::init();
    test_set();
    test_set_big();
    test_constructor_1();
    test_constructor_1_big();
    test_constructor_2();
    return 0;
}

void test_set() {
    matte::String str;
    matte::set_string(str, "Hello World");
    Test::assertEqual("test_set()", string_c_value(str), (const char*)"Hello World");
}

void test_set_big() {
    matte::String str;
    matte::set_string(str, big_text);
    Test::assertEqual("test_set_big()", string_c_value(str), big_text);
}

void test_constructor_1() {
    matte::String str = "Hello World";
    Test::assertEqual("test_constructor_1()", string_c_value(str), (const char*)"Hello World");
}

void test_constructor_1_big() {
    matte::String str = big_text;
    Test::assertEqual("test_constructor_1_big()", string_c_value(str), big_text);

}

void test_constructor_2() {
    matte::String str1 = "Hello World";
    matte::String str2 = str1;
    Test::assertEqual("test_constructor_2()", string_c_value(str1), matte::string_c_value(str2));
}
