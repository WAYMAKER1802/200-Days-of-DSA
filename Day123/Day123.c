//Problem: Leaders in an Array
//An element is called a Leader if it is greater than all elements to its right.
//The rightmost element is always a leader.
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int leaders[n];
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxRight = arr[n - 1];
    leaders[count++] = maxRight;

    for(int i = n - 2; i >= 0; i--)
    {
        if(arr[i] > maxRight)
        {
            maxRight = arr[i];
            leaders[count++] = arr[i];
        }
    }

    for(int i = count - 1; i >= 0; i--)
    {
        printf("%d ", leaders[i]);
    }

    return 0;
}