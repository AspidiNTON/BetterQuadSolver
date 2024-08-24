#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

#include <stdio.h>

#define printfRed(s, a...) printf("\033[0;31m" s "\033[1;0m", ## a)

#define printfGreen(s, a...) printf("\033[0;32m" s "\033[1;0m", ## a)

#define printfPurple(s, a...) printf("\033[2;35m" s "\033[1;0m", ## a)

void setRed();

void setGreen();

void resetColor();

#endif