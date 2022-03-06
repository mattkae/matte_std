#ifndef TEST_HELPER_H
#define TEST_HELPER_H
#include <cstring>
#include <assert.h>
#include "../src/logger.h"
#include "../src/logger.cpp"


namespace Test {
    LoggerOptions options;
    void init() {
        Logger::initialize(options);
    }

    template <typename T>
    void assertEqual(const char* testName, T first, T second) {
        if (first != second) {
            logger_error("Test failed: %s", testName);
        }
    }

    void assertEqual(const char *testName, const char* first, const char* second) {
        if (strcmp(first, second) != 0) {
            logger_error("Test failed: %s", testName);
        }
        else {
            logger_info("Test passed: %s", testName);
        }
    }
};

#endif