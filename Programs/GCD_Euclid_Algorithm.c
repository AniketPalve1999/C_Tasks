// Program to perform the computation of GCD of two numbers using Euclid's algorithm.

#include <stdio.h>
#include <assert.h>

int findGCD(int n1, int n2)
{
    if (n1 == 0)
    {
        return n2;
    }
    else if (n2 == 0)
    {
        return n1;
    }
    else
    {
        return findGCD(n2, (n1 % n2));
    }
}

int main(int argc, char *argv[])
{
    int num1, num2;
    int GCD_Result;

    printf("***** GCD Of Two Numbers using Euclid's Algorithm *****\n\n");

    printf("Enter the first number: \n");
    scanf("%d", &num1);

    printf("Enter the second number: \n");
    scanf("%d", &num2);

    GCD_Result = findGCD(num1, num2);

    printf("The GCD of %d and %d using an Euclid's algorithm is = %d \n", num1, num2, GCD_Result);

    //    assert(GCD_Result == 10);
    //    printf("Test Case passed!\n");

    return 0;
}
