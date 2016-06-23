#include <exception>

namespace msgbase {

    // Структура заголовка сообщения
    struct Header {
        const char soh  = 0x01;
        char code = 'x'; 
        char textLength[2] = {'x', 'x'};
        const char stx = 0x02;
    };

    // Структура окончания сообщения
    struct Footer {
        const char etx = 0x03;
        char bcc[2] = {'x', 'x'};
        const char eot = 0x04;
    };
    
    // Структура текста сообщения для команды Нарисовать точку.
    // Эта структура не обязательна, но указав её, мы можем быстрее и нагляднее
    // менять размеры текста сообщения. 
    struct TextPoint {
        char coordX[4] = {'x', 'x', 'x', 'x'};
        char coordY[4] = {'x', 'x', 'x', 'x'};
    };

    // Структура текста сообщения для команды Нарисовать линию.
    struct TextLine {
        char coordX1[4] = {'x', 'x', 'x', 'x'};
        char coordY1[4] = {'x', 'x', 'x', 'x'};
        char coordX2[4] = {'x', 'x', 'x', 'x'};
        char coordY2[4] = {'x', 'x', 'x', 'x'};
    };

    size_t makeText(char *, const int, const int);

    size_t makeText(char *, const int, const int, const int, const int);

    void makeHeader(char *, const char, const int);

    void makeFooter(char *, char *);

    class ExceptionCoordTooLong : public std::exception {
    public:
        virtual const char* what() const throw();
    };

}
