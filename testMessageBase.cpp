#include <iostream>
#include <cstring>
#include <cassert>

#include "MessageBase.hpp"

void testExceptionCoordTooLong() {
    char buffer[100];
    try {
        msgbase::makeText(buffer, 66000, 10);
    } catch (msgbase::ExceptionCoordTooLong& e) {
        auto test = new msgbase::ExceptionCoordTooLong;

        // Проверим, что выброшенное исключение - то, что нужно.
        if (0 == std::strcmp(test->what(), e.what())) {
            std::cout << "Test ExceptionCoordTooLong OK" << std::endl;
            delete test;
            return;
        }
        delete test;
    }

    std::cout << "Test ExceptionCoordTooLong FAILED" << std::endl;
    assert(1 == 0);
}


int main() {
    testExceptionCoordTooLong(); 

    return 0;
}

