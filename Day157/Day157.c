//Given an array of N integers, determine whether the array is sorted in non-decreasing order.
//Print "Sorted" if it is sorted. Otherwise, print "Not Sorted"
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sorted = 1;

    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            sorted = 0;
            break;
        }
    }

    if(sorted)
        printf("Sorted");
    else
        printf("Not Sorted");

    return 0;
}