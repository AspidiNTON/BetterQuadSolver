#include "quadConsole.h"

void flush() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') break;
    }
}

void flushStream(FILE* ptr) {
    int c;
    while ((c = getc(ptr)) != EOF) {
        if (c == '\n') break;
    }
}

void readQuadratic(double* a, double* b, double* c) {
    myAssert(a != nullptr, "Nullpointer recieved\n");
    myAssert(b != nullptr, "Nullpointer recieved\n");
    myAssert(c != nullptr, "Nullpointer recieved\n");
    myAssert(a != b && b != c && a != c, "Same pointer recieved\n");

    printf("Enter 3 multipliers of the quadratic equation:\n");
    while (scanf("%lf %lf %lf", a, b, c) != 3 || !isfinite(*a) || !isfinite(*b) || !isfinite(*c)) {
        flush();
        printfRed("Please enter three real numbers:\n");
    }
}

void printQuadraticSolutions(numberOfSolutions n, double x1, double x2) {
    switch (n) {
        case ZERO_SOLUTIONS:
            printf("The equation has no solutions\n");
            break;
        case ONE_SOLUTION:
            printf("The only root of the equation is: %lg\n", x1);
            break;
        case TWO_SOLUTIONS:
            printf("The equation has 2 solutions: %lg and %lg\n", x1, x2);
            break;
        case INFINITE_SOLUTIONS:
            printf("The equation has an infinite number of solutions\n");
            break;
        default:
            printf("wtf was that damage my guy?!\n");
    }
}