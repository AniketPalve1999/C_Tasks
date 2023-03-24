// Program for computation of GCD of two integers using the Binary GCD Algorithm.

#include <stdio.h>

int perform_GCD_Operation(int num1, int num2)
{

    // if num1 & num2 both are zero then GCD is zero.
    if (num1 == 0 && num2 == 0)
        return 0;

    // If num1 is zero then GCD is num2.
    if (num1 == 0)
        return num2;

    // If num2 is zero then GCD is num1.
    if (num2 == 0)
        return num1;

    int factorNum;
    // If num1 & num2 both are even then divide them by 2.
    for (factorNum = 0; ((num1 | num2) & 1) == 0; ++factorNum)
    {
        num1 >>= 1;
        num2 >>= 1;
    }

    // If num1 is even then divide it by 2.
    while ((num1 & 1) == 0)
        num1 >>= 1;
    do
    {
        while ((num2 & 1) == 0)
            num2 >>= 1; // If num2 is even then divide it by 2.

        // Both num1 & num2 are odd then find difference and divide it by 2.
        if (num1 > num2)
        {
            int temp = num2;
            num2 = num1;
            num1 = temp;
        }
        num2 = num2 - num1;
    } while (num2 != 0);

    return num1 << factorNum;
}

int main(int argc, char *argv[])
{
    int num1, num2, GCD_Result;

    printf("***** GCD Of Two Integers using GCD Binary Algorithm *****\n\n");

    printf("Enter first integer\n");
    scanf("%d", &num1);
    printf("Enter second integer\n");
    scanf("%d", &num2);

    GCD_Result = perform_GCD_Operation(num1, num2);

    printf("The GCD of %d and %d integers is: %d \n", num1, num2, GCD_Result);
    return 0;
}
