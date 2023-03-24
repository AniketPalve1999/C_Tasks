#include <stdio.h>

int perform_Extended_Binary_GCD(int num1, int num2, int *x, int *y)
{
    int cofactor = 0;

    // if integers are even divide them by 2.
    if ((num1 & 1) == 0 && (num2 & 1) == 0)
    {
        do
        {
            num1 >>= 1;
            num2 >>= 1;
            cofactor++;
        } while ((num1 & 1) == 0 && (num2 & 1) == 0);
    }

    // Variable initializations.
    int u = num1, v = num2, x1 = 1, x2 = 0, y1 = 0, y2 = 1;

    // if a is even & b is odd then dividing a by 2.
    while ((u & 1) == 0)
    {
        u >>= 1;
        if ((x1 & 1) == 0 && (x2 & 1) == 0)
        {
            x1 >>= 1;
            x2 >>= 1;
        }
        else
        {
            x1 = (x1 + num2) >> 1;
            x2 = (x2 - num1) >> 1;
        }
    }

    // if a is odd & b is even then dividing b by 2.
    while ((v & 1) == 0)
    {
        v >>= 1;
        if ((y1 & 1) == 0 && (y2 & 1) == 0)
        {
            y1 >>= 1;
            y2 >>= 1;
        }
        else
        {
            y1 = (y1 + num2) >> 1;
            y2 = (y2 - num1) >> 1;
        }
    }

    // Both a & b are odd.
    while (u != v)
    {
        if (u > v)
        {
            u -= v;
            x1 -= y1;
            x2 -= y2;
            while ((u & 1) == 0)
            {
                u >>= 1;
                if ((x1 & 1) == 0 && (x2 & 1) == 0)
                {
                    x1 >>= 1;
                    x2 >>= 1;
                }
                else
                {
                    x1 = (x1 + num2) >> 1;
                    x2 = (x2 - num1) >> 1;
                }
            }
        }
        else
        {
            v -= u;
            y1 -= x1;
            y2 -= x2;
            while ((v & 1) == 0)
            {
                v >>= 1;
                if ((y1 & 1) == 0 && (y2 & 1) == 0)
                {
                    y1 >>= 1;
                    y2 >>= 1;
                }
                else
                {
                    y1 = (y1 + num2) >> 1;
                    y2 = (y2 - num1) >> 1;
                }
            }
        }
    }
    // Returning the Bezout's coeficients value and the GCD.
    *x = y1;
    *y = y2;
    return v << cofactor;
}

int main()
{
    int num1, num2, x, y, GCD_Result;

    printf("***** Extended GCD Binary Algorithm *****\n\n");

    printf("Enter first integer\n");
    scanf("%d", &num1);
    printf("Enter second integer\n");
    scanf("%d", &num2);

    GCD_Result = perform_Extended_Binary_GCD(num1, num2, &x, &y);

    printf("The GCD of %d and %d is = %d", num1, num2, GCD_Result);
    printf("\n");
    printf("The Values of Coeficient X and Y is %d and %d", x, y);
    printf("\n");

    return 0;
}
