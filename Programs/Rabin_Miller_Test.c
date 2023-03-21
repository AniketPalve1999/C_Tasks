// Program for implementation of Miller Rabin primality testing algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

long long int perform_Power_Operation(long long int x, long long int y, long long int z) // x is Base, y is Exponent and z is Modulus Number
{
    long long int power_Result = 1;

    x = x % z;

    while (y > 0)
    {
        if (y % 2 == 1)
            power_Result = (power_Result * x) % z;
        y = y / 2;
        x = (x * x) % z;
    }
    return power_Result;
}

int check_Prime_No(long long int num, long long int no_Of_Iterartions)
{
    // Basic Prime Number Cases.
    if (num <= 1 || num == 4)
        return 0;
    if (num <= 2)
        return 1;

    // Finding d using d*(2^r) = n-1 where r >= 1
    long long int d = num - 1;
    long long int r = 0;

    while (d % 2 == 0)
    {
        d = d / 2;
        r++;
    }

    for (int i = 0; i < no_Of_Iterartions; i++)
    {

        // Picking a random number a in the range [2, n-2]
        long long int a = 2 + rand() % (num - 3);

        // Computing a^d % n
        long long int x = perform_Power_Operation(a, d, num);

        // If x == 1 or x == n-1, continue with next iteration
        if (x == 1 || x == num - 1)
            continue;

        // Repeat r-1 times
        int flag = 0;
        for (int j = 1; j < r; j++)
        {
            x = (x * x) % num;

            if (x == num - 1)
            {
                flag = 1;
                break;
            }
        }

        // If x != n-1, returning composite
        if (flag == 0)
            return 0;
    }
    // returning Prime.
    return 1;
}

int main(int argc, char *argv[])
{
    printf("***** Rabin-Miller Primatility Testing Algorithm *****\n");

    long long int number, iteration_No;

    printf("Enter the number you want to check i.e prime or composite number: \n");
    scanf("%lld", &number);

    printf("Enter the iteration number : \n");
    scanf("%lld", &iteration_No);

    int prime_Result = check_Prime_No(number, iteration_No);

    if (prime_Result)
    {
        printf("The Given Number %lld is a Prime Number.\n", number);
    }
    else
    {
        printf("The Given Number %lld is a Composite Number.\n", number);
    }

    // assert(prime_Result);
    // printf("Test Case Passed.\n");

    return 0;
}
