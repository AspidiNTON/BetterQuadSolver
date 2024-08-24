#ifndef NUMBER_H
#define NUMBER_H

#include <math.h>

enum numberOfSolutions {
    ZERO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INFINITE_SOLUTIONS = -1
};

bool isEqual(double a, double b);

bool isZero(double a);


#endif