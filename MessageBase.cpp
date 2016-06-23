#include <iostream> // for test
#include <iomanip>
#include <sstream>

#include <cstring>
#include <cassert>

#include "MessageBase.hpp"

namespace msgbase {
    ExceptionCoordTooLong exceptionCoordTooLong; // исключение

    // Метод исключения
    const char* ExceptionCoordTooLong::what() const throw() {
            return "Coordinate too long";
    }

    /* Локальная функция. Форматирует число value как шестнадцатиричное и 
     * записывает в строковый поток.
     * size - количество символов в которое должно отформатироваться число.
     */
    void formatNumber(std::stringstream &strbuffer, const int value, 
            const int size) {
        strbuffer << std::hex << std::uppercase << std::setfill('0') << 
            std::setw(size)  << value ;
    }


    /* Сформировать текст сообщения и положить его в buffer. На входе указатель 
     * на буфер, координаты. Возвращаем размер сообщения в символах.
     */
    size_t makeText(char *buffer, const int x, const int y) {
        std::stringstream strbuffer;

        formatNumber(strbuffer, x, sizeof(TextPoint::coordX));
        formatNumber(strbuffer, y, sizeof(TextPoint::coordY));

        if ((sizeof(TextPoint::coordX) + sizeof(TextPoint::coordY)) != 
                strbuffer.str().length()) {
            throw exceptionCoordTooLong;
        }         
        
        std::strcpy(buffer, strbuffer.str().c_str());

        return strbuffer.str().length();
    }


    /* Перегруженная версия предыдущей функции, принимает четыре координаты.
     */
    size_t makeText(char *buffer, const int x1, const int y1, const int x2, 
            const int y2) {
        std::stringstream strbuffer;

        formatNumber(strbuffer, x1, sizeof(TextLine::coordX1));
        formatNumber(strbuffer, y1, sizeof(TextLine::coordY1));
        formatNumber(strbuffer, x2, sizeof(TextLine::coordX2));
        formatNumber(strbuffer, y2, sizeof(TextLine::coordY2));

        if ((sizeof(TextLine::coordX1) + sizeof(TextLine::coordY1) + 
                    sizeof(TextLine::coordX2) + sizeof(TextLine::coordY2)) != 
                strbuffer.str().length()) {
            throw exceptionCoordTooLong;
        }

        std::strcpy(buffer, strbuffer.str().c_str());

        return strbuffer.str().length();
    }


    /* Сформировать заголовок сообщения и положить его в buffer.
     * code - код сообщения. lengthText - длина текста сообщения.
     */
    void makeHeader(char *buffer, const char code, const int lengthText) {
        Header header;

        std::stringstream strbuffer;
        formatNumber(strbuffer, lengthText, sizeof(Header::textLength));

        // assert сработает только при неверной реализации протокола.
        // Пользователь на это повлиять никак не может.
        assert(strbuffer.str().length() == sizeof(Header::textLength));

        header.code = code;
        std::memcpy(&header.textLength, strbuffer.str().c_str(), 
                sizeof(header.textLength));

        std::memcpy(buffer, &header, sizeof(Header));

        return;
    }

  
    /* Сформировать окончание сообщения. bufferStart - начало сообщения.
     * bufferEnd - указатель на буфер, куда нужно положить окончание 
     * сообщения. 
     */
    void makeFooter(char *bufferStart, char *bufferEnd) {
        assert(bufferEnd > bufferStart);

        Footer footer;
        char bcc = *bufferStart;  

        for(char *iterator = bufferStart+1; iterator != bufferEnd; ++iterator) {
            bcc = *iterator ^ bcc;
        }

        bcc = bcc ^ footer.etx; // не забудем одно значение в footer

        std::stringstream strbuffer;
        formatNumber(strbuffer, (int) bcc, sizeof(Footer::bcc));

        // assert сработает только при неверной реализации протокола
        assert(strbuffer.str().length() == sizeof(Footer::bcc));

        std::memcpy(&footer.bcc, strbuffer.str().c_str(), sizeof(footer.bcc));

        std::memcpy(bufferEnd, &footer, sizeof(Footer));
            
        return;
    }
}
