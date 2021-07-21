#include "../src/matte_string.h"
#include <cstdio>

void test_set();
void test_set_big();
void test_constructor_1();
void test_constructor_1_big();
void test_constructor_2();

const char* big_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

int main() {
    test_set();
    test_set_big();
    test_constructor_1();
    test_constructor_1_big();
    test_constructor_2();
    return 0;
}

void test_set() {
    printf("\n");
    printf("Running test_set\n");
    matte::String str;

    matte::set_string(str, "Hello World");

    printf("%s\n", matte::string_c_value(str));
    printf("Finished test_set\n");
}

void test_set_big() {
    printf("\n");
    printf("Running test_set_big\n");
    matte::String str;

    matte::set_string(str, big_text);

    printf("%s\n", matte::string_c_value(str));
    printf("Finished test_set_big\n");
}

void test_constructor_1() {
    printf("\n");
    printf("Running test_constructor_1\n");
    matte::String str = "Hello World";

    printf("%s\n", matte::string_c_value(str));
    printf("Finished test_constructor_1\n");
}

void test_constructor_1_big() {
    printf("\n");
    printf("Running test_constructor_1_big\n");
    matte::String str = big_text;

    printf("%s\n", matte::string_c_value(str));
    printf("Finished test_constructor_1_big\n");
}

void test_constructor_2() {
    printf("\n");
    printf("Running test_constructor_2\n");
    matte::String str1 = "Hello World";
    matte::String str2 = str1;

    printf("%s\n", matte::string_c_value(str2));
    printf("Finished test_constructor_2\n");
}
