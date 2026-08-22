// Problem statement - Move Zeroes
//Given an integer array, move all 0s to the end while maintaining the relative order of the non-zero elements.
#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int j = 0;

    // Move non-zero elements to the front
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            j++;
        }
    }

    // Fill remaining positions with zero
    while (j < n)
    {
        arr[j] = 0;
        j++;
    }

    printf("Array after moving zeroes:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}