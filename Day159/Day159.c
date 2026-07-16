//Problem Statement : Given an array of N integers, return an array result such that:
//result[i] = product of all elements of the array except arr[i]
//Do not use division.
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000];
    int left[1000], right[1000], result[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    left[0] = 1;
    for(int i = 1; i < n; i++)
        left[i] = left[i - 1] * arr[i - 1];

    right[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] * arr[i + 1];

    for(int i = 0; i < n; i++)
        result[i] = left[i] * right[i];

    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}