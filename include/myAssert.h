#ifndef MY_ASSERT_H
#define MY_ASSERT_H

// FIXME: выводил номер строки, имя файла, название функции и тд + завершить программу
#define myAssert(expr, str, a...) \
    {\
        if (!(expr)) { \
        printfRed("Error in file: %s;\nFunction: %s; line: %d\n", __FILE__, __FUNCTION__, __LINE__); \
        printfRed(str, ## a); \
        exit(0);\
        }\
    } \

#endif