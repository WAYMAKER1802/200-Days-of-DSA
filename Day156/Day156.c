//Problem Statement : Given an array of integers, print all the leaders in the array.
//A leader is an element that is greater than or equal to all the elements to its right.
//The last element is always a leader.
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000], leader[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max = arr[n - 1];
    int k = 0;

    leader[k++] = max;

    for(int i = n - 2; i >= 0; i--)
    {
        if(arr[i] >= max)
        {
            max = arr[i];
            leader[k++] = arr[i];
        }
    }

    for(int i = k - 1; i >= 0; i--)
        printf("%d ", leader[i]);

    return 0;
}