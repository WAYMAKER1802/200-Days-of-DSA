//Input a number from the user and print 
// a. Number of 1 and number of 0 in its binary representation.
//  b. Number of consecutive 1 in the binary representation
#include <stdio.h>

int main()
{
    int n;
    int ones = 0, zeros = 0;
    int count = 0, max = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Number of 1s = 0\n");
        printf("Number of 0s = 1\n");
        printf("Consecutive 1s = 0\n");
        return 0;
    }

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ones++;
            count++;

            if (count > max)
                max = count;
        }
        else
        {
            zeros++;
            count = 0;
        }

        n = n / 2;
    }

    printf("Number of 1s = %d\n", ones);
    printf("Number of 0s = %d\n", zeros);
    printf("Maximum consecutive 1s = %d\n", max);

    return 0;
}