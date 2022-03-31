#include "../src/hashmap.h"
#include <cstdio>
#include "test.h"

void test_set();
void test_set_big();
void test_constructor_1();
void test_constructor_1_big();
void test_constructor_2();

int main() {
    Test::init();
    
    HashMap<const char*, int, strHashFunc> map;
    
    // Simple 
    map.insert("Hello world", 2);

    int v1;
    map.lookup("Hello world", &v1);
    Test::assertEqual("HashMap::insert1", v1, 2);

    map.insert("Another one", 10);
    int v2;
    map.lookup("Another one", &v2);
    Test::assertEqual("HashMap::insert2", v2, 10);

    int v3;
    bool b1 = map.lookup("Another two", &v3);
    Test::assertEqual("HashMap::insert3", b1, false);

    // Medium
    map.replace("Hello world", 32);
    map.lookup("Hello world", &v1);
    Test::assertEqual("HashMap::replace", v1, 32);

    map.remove("Hello world");
    bool b2 = map.lookup("Hello world", &v3);
    Test::assertEqual("HashMap::remove", b2, false);

    map.freeMap();

    return 0;
}