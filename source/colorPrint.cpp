#include "colorPrint.h"


void setRed(){
    printf("\033[0;31m");
}

void setGreen(){
    printf("\033[0;32m");
}

void resetColor(){
    printf("\033[1;0m");
}