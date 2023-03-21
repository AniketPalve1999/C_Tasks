// Program to generate and count the all prime numbers up to  given input 'n'.

#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int num, i, j, factor;
    int prime_No_Count = 0;

    printf("***** Generation of Prime Numbers *****\n\n");

    printf("Enter the number upto you want to generate the prime numbers: \n");
    scanf("%d", &num);

    printf("\nThe Prime Numbers from 1 to %d are: \n", num);

    for (i = 1; i <= num; i++)
    {
        factor = 0;

        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                factor++;
                break;
            }
        }

        if (factor == 0 && i != 1)
        {
            printf("%d ", i);
            prime_No_Count++;
        }
    }

    printf("\n\n");
    printf("The count of prime numbers from 1 to %d is : %d", num, prime_No_Count);
    printf("\n");

    // assert(prime_No_Count == 1229);
    // printf("Test Case Passed.\n");

    return 0;
}
