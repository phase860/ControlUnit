#include <iostream>
#include <ctime>

#include "Message.hpp"

// Случайное число от 1 до 1000
int findRandom() {
    return std::rand() % 1000 + 1; 
}

int main() {
    char buffer[100]; // буфер для сообщений
    size_t length;

    std::srand(std::time(0)); // инициализируем генератор случайных чисел

    for (int i=0; i<10; ++i) {
        length = msg::drawPoint(buffer, findRandom(), findRandom());
        buffer[length] = '\0'; // теперь buffer - это строка в стиле Си
        std::cout << buffer << std::endl;
    }

    for (int i=0; i<10; ++i) {
        length = msg::drawLine(buffer, findRandom(), findRandom(), findRandom(), 
                findRandom());
        buffer[length] = '\0';
        std::cout << buffer << std::endl;
    }

    return 0;
}
