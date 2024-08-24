#include "solver.h"

numberOfSolutions solve(double a, double b, double c, double* x1, double* x2) {
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);
    
    if (isZero(a)) {
        return solveLinear(b, c, x1);
    } else {
        return solveQuadratic(a, b, c, x1, x2);
    }
}

numberOfSolutions solveLinear(double p, double q, double* x) {
    assert(x != nullptr);
    if (isZero(p)) {
        return (isZero(q)) ? INFINITE_SOLUTIONS : ZERO_SOLUTIONS;
    } else {
        *x = - q / p;
        return ONE_SOLUTION;
    }
}

numberOfSolutions solveQuadratic(double a, double b, double c, double* x1, double* x2) {
    double d = b * b - 4 * a * c;
    if (isZero(d)) {
        *x1 = -b / (2 * a);
        return ONE_SOLUTION;
    }
    else if (d < 0) return ZERO_SOLUTIONS;
    else {
        d = sqrt(d);
        *x1 = -(b + d) / (2 * a);
        *x2 = (d - b) / (2 * a);
        return TWO_SOLUTIONS;
    }
}