#include "fileTests.h"

void runFileTests(const char* filename) {
    FILE* filePtr;
    filePtr = fopen(filename, "r");
    if (filePtr == NULL) {
        printfRed("Unable to open file: %s\n", filename);
        exit(0);
    }
    double a = 0, b = 0, c = 0;
    int nRoots = 0;
    double x1 = 0, x2 = 0;
    int testCount = 0, readElems = 0;
    while ((readElems = fscanf(filePtr, "%lg %lg %lg %d", &a, &b, &c, &nRoots)) != EOF) {
        if (readElems == 4 && isfinite(a) && isfinite(b) && isfinite(c)) {
            switch (nRoots) {
                case 0:
                case -1:
                    ++testCount;
                    //printf("%lg %lg %lg %d\n", a, b, c, nRoots);
                    break;
                case 1:
                    if ((readElems = fscanf(filePtr, "%lg", &x1)) != EOF) {
                        if (readElems == 1 && isfinite(x1)) {
                            ++testCount;
                            //printf("%lg %lg %lg %d %lg\n", a, b, c, nRoots, x1);
                        }
                    }
                    break;
                case 2:
                    if ((readElems = fscanf(filePtr, "%lg %lg", &x1, &x2)) != EOF) {
                        if (readElems == 2 && isfinite(x1) && isfinite(x2)) {
                            ++testCount;
                            //printf("%lg %lg %lg %d %lg %lg\n", a, b, c, nRoots, x1, x2);
                        }
                    }
                    break;
            }
        }
        flushStream(filePtr);
    }
    printf("Valid tests found: %d\n", testCount);
    Test* tests = (Test*)malloc(testCount * sizeof(Test));
    fseek(filePtr, 0, SEEK_SET);
    int testIndex = 0;
    while ((readElems = fscanf(filePtr, "%lg %lg %lg %d", &a, &b, &c, &nRoots)) != EOF) {
        if (readElems == 4 && isfinite(a) && isfinite(b) && isfinite(c)) {
            switch (nRoots) {
                case 0:
                case -1:
                    tests[testIndex++] = {a, b, c, (numberOfSolutions)nRoots};
                    break;
                case 1:
                    if ((readElems = fscanf(filePtr, "%lg", &x1)) != EOF) {
                        if (readElems == 1 && isfinite(x1)) {
                            tests[testIndex++] = {a, b, c, (numberOfSolutions)nRoots, x1};
                        }
                    }
                    break;
                case 2:
                    if ((readElems = fscanf(filePtr, "%lg %lg", &x1, &x2)) != EOF) {
                        if (readElems == 2 && isfinite(x1) && isfinite(x2)) {
                            tests[testIndex++] = {a, b, c, (numberOfSolutions)nRoots, x1, x2};
                        }
                    }
                    break;
            }
        }
        flushStream(filePtr);
    }
    runTests(testCount, tests);

    fclose(filePtr);
}