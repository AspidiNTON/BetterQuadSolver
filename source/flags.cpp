#include "flags.h"


void checkFlags(int argc, const char *argv[], int flagsSize, const flag* flags){
    int filenameIndex = -1;
    bool testMode = false;
    while (--argc) {
        //--help -h
        if (strcmp(argv[argc], flags[0].fullName) == 0 || strcmp(argv[argc], flags[0].shortName) == 0) {
            for (int i = 0; i < flagsSize; ++i) {
                printf("%s %s: %s\n", flags[i].shortName, flags[i].fullName, flags[i].description);
            }
            return;
        }
        //--test -t
        if (strcmp(argv[argc], flags[1].fullName) == 0 || strcmp(argv[argc], flags[1].shortName) == 0) {
            testMode = true;
            continue;
        }
        filenameIndex = argc;
    }
    if (testMode) {
        if (filenameIndex != -1) {
            runFileTests(argv[filenameIndex]);
        } else {
            runDefaultTests();
        }
    } else {
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        readQuadratic(&a, &b, &c);
        numberOfSolutions n = solve(a, b, c, &x1, &x2);
        printQuadraticSolutions(n, x1, x2);
    }
}