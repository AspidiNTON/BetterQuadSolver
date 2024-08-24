#ifndef SOLVER_H
#define SOLVER_H

#include <math.h>
#include <assert.h>
#include <iostream>

#include "number.h"

numberOfSolutions solve(double a, double b, double c, double* x1, double* x2);

numberOfSolutions solveLinear(double p, double q, double* x);

numberOfSolutions solveQuadratic(double a, double b, double c, double* x1, double* x2);

#endif