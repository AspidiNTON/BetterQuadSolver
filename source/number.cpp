#include "number.h"

const double DOUBLE_EPSILON = 0.000001;

bool isEqual(double a, double b) {
    return fabs(a - b) <= DOUBLE_EPSILON;
}

bool isZero(double a) {
    return fabs(a) <= DOUBLE_EPSILON;
}