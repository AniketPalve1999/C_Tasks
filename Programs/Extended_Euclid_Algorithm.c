// Program to perform the implementation of Extended Euclid's algorithm.

#include <stdio.h>
#include <assert.h>

int do_Extended_Euclid_Computation(int n1, int n2, int *x, int *y)
{
    if (n1 == 0)
    {
        *x = 0;
        *y = 1;
        return n2;
    }
    else if (n2 == 0)
    {
        *x = 1;
        *y = 0;
        return n1;
    }

    int x1, y1;

    int GCD_Result = do_Extended_Euclid_Computation(n2 % n1, n1, &x1, &y1);

    *x = y1 - (n2 / n1) * x1;
    *y = x1;

    return GCD_Result;
}

int main(int argc, char *argv[])
{
    printf("***** Extended Euclid's Algorithm *****\n\n");

    int num1, num2, x, y;

    printf("Enter First Number\n");
    scanf("%d", &num1);

    printf("Enter Second Number\n");
    scanf("%d", &num2);

    int GCD_Result = do_Extended_Euclid_Computation(num1, num2, &x, &y);

    printf("The GCD of %d and %d is = %d", num1, num2, GCD_Result);
    printf("\n");
    printf("The Values of Coeficient X and Y is %d and %d", x, y);
    printf("\n");

    // assert(x == -2);
    // assert(y == 3);
    // assert(GCD_Result == 3);
    // printf("Test Case Passed.\n");

    return 0;
}
