#ifndef TESTER_H
#define TESTER_H

#include <assert.h>

#include "number.h"
#include "solver.h"
#include "colorPrint.h"

struct Test {
    double a = 0, b = 0, c = 0;
    numberOfSolutions n = ZERO_SOLUTIONS;
    double x1 = 0, x2 = 0;
};

int runTest(const Test* test);

int runDefaultTests();

int runTests(int testCount, Test* tests);

#endif