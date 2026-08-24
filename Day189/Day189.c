//You are given a large integer represented as an integer array digits, where digits[i] is the i-th digit of the integer.
// The digits are ordered from most significant to least significant.
//Increment the large integer by one and return the resulting array of digits.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    int *digits = (int *)malloc(n * sizeof(int));

    printf("Enter the digits:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &digits[i]);
    }

    // Start from the last digit
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            break;
        }

        // 9 becomes 0 and carry goes to the previous digit
        digits[i] = 0;

        // If we reached the first digit
        if (i == 0)
        {
            int *result = (int *)malloc((n + 1) * sizeof(int));

            result[0] = 1;

            for (int j = 1; j <= n; j++)
            {
                result[j] = 0;
            }

            free(digits);
            digits = result;
            n++;
        }
    }

    printf("Result: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d", digits[i]);

        if (i < n - 1)
            printf(" ");
    }

    printf("\n");

    free(digits);

    return 0;
}