#include "tester.h"

const Test defaultTests[8] = {
    {1, -2, 1, ONE_SOLUTION, 1},
    {0, 0, 0, INFINITE_SOLUTIONS},
    {0, 5.0, -22.5, ONE_SOLUTION, 4.5},
    {1, 0, -4, TWO_SOLUTIONS, 2, -2},
    {0, 0, 28.3, ZERO_SOLUTIONS},
    {5, 0, 34, ZERO_SOLUTIONS},
    {1, -3, -4, TWO_SOLUTIONS, 4, -1},
    {1, 3, 4, ZERO_SOLUTIONS}
};
    
int runTest(const Test *test)
{
    assert(test != nullptr);
    double x1 = 0, x2 = 0;
    numberOfSolutions n = ZERO_SOLUTIONS;
    n = solve(test->a, test->b, test->c, &x1, &x2);
    if (!isEqual(n, test->n) || (n == ONE_SOLUTION && !isEqual(x1, test->x1)) || (n == TWO_SOLUTIONS && (!isEqual(x1, test->x1) || !isEqual(x2, test->x2)) && (!isEqual(x1, test->x2) || !isEqual(x2, test->x1))))
    {
        setRed();
        printf("Error in: a = %lg, b = %lg, c = %lg; result: n = %d", test->a, test->b, test->c, n);
        if (n == ONE_SOLUTION)
            printf(", x = %lg", x1);
        if (n == TWO_SOLUTIONS)
            printf(", x1 = %lg, x2 = %lg", x1, x2);
        printf("\nExpected: n = %d", test->n);
        if (test->n == ONE_SOLUTION)
            printf(", x = %lg", test->x1);
        if (test->n == TWO_SOLUTIONS)
            printf(", x1 = %lg, x2 = %lg", test->x1, test->x2);
        printf("\n");
        resetColor();
        return 1;
    }
    return 0;
}

int runDefaultTests()
{
    for (int i = 0; i < 8; ++i)
    {
        if (runTest(&(defaultTests[i])))
        {
            printfRed("Error at test %d\n", i + 1);
            return i + 1;
        }
    }
    printfGreen("Tests complete succesfully\n");
    return 0;
}

int runTests(int testCount, Test* fileTests) {
    for (int i = 0; i < testCount; ++i)
    {
        if (runTest(&(fileTests[i])))
        {
            printfRed("Error at test %d\n", i + 1);
            return i + 1;
        }
    }
    printfGreen("Tests complete succesfully\n");
    return 0;
}