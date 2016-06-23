#include <iostream>
#include <cstring>
#include <cassert>

#include "Message.hpp"

void test1() {
    char buffer[100];
    std::memset(buffer, 0, sizeof(buffer));

    const char teststr1[] = {0x01, 'A', '0', '8', 0x02, '0', '3', '8', 'C', '0', 
        '2', 'D', 'F', 0x03, '3', '1', 0x04, 0x00};

    msg::drawPoint(buffer, 908, 735);
    
    std::cout << "Test 1: ";
    if (0 == std::strcmp(buffer, teststr1)) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "FALED" << std::endl;
        std::cout << "buffer: " << buffer << ", you need: " << teststr1 << std::endl;
        assert(1 == 0);
    }
}


void test2() {
    char buffer[100];
    std::memset(buffer, 0, sizeof(buffer));

    const char teststr1[] = {0x01, 'B', '1', '0', 0x02, '0', '3', '3', '4', '0', 
        '2', 'D', '0', '0', '3', '5', '0', '0', '0', '1', '2', 0x03, '3', '4',
        0x04, 0x00};

    msg::drawLine(buffer, 820, 720, 848, 18);
    
    std::cout << "Test 2: ";
    if (0 == std::strcmp(buffer, teststr1)) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "FALED" << std::endl;
        std::cout << "buffer: " << buffer << ", you need: " << teststr1 << std::endl;
        assert(1 == 0);
    }
}


int main() {
    test1();
    test2();

    return 0;
}

