//Problem Statement : Given an array of integers, move all the 0's to the end of the array while maintaining the 
// relative order of the non-zero elements.
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int j = 0;

    // Move all non-zero elements to the front
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}