#include <iostream> 

#include "Message.hpp"
#include "MessageBase.hpp"


namespace msg {
    /* Нарисовать точку. Принимает указатель на буфер, где будет
     * сформировано сообщение, координаты x и y, возвращает размер сообщения.
     */
    size_t drawPoint(char *buffer, const int x, const int y) {
        char code = 'A'; // код сообщения Нарисовать точку
        
        size_t lengthText = msgbase::makeText(buffer + sizeof(msgbase::Header),
                x, y);
        msgbase::makeHeader(buffer, code, lengthText);
        msgbase::makeFooter(buffer, buffer + sizeof(msgbase::Header) + 
                lengthText);

        return sizeof(msgbase::Header) + lengthText + sizeof(msgbase::Footer);
    }


    /* Нарисовать линию. Принимает указатель на буфер, где будет сформировано 
     * сообщение, координаты x и y первой точки и координаты x и y второй точки,
     * возвращает размер сообщения.
     */
    size_t drawLine(char *buffer, const int x1, const int y1, const int x2, 
            const int y2) {

        char code = 'B'; // код сообщения Нарисовать линию

        size_t lengthText = msgbase::makeText(buffer + sizeof(msgbase::Header),
                x1, y1, x2, y2);

        msgbase::makeHeader(buffer, code, lengthText);
        msgbase::makeFooter(buffer, buffer + sizeof(msgbase::Header) + 
                lengthText);

        return sizeof(msgbase::Header) + lengthText + sizeof(msgbase::Footer);
    }
}
