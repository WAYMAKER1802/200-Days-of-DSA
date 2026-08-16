//Problem : Given an array of integers and a target value, find two different elements whose sum equals the target. Return their indices.
#include <stdio.h>

int main()
{
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("Indices: %d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No pair found\n");

    return 0;
}