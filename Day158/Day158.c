//Problem Statement : Given an array of N integers, find the second largest distinct element in the array.
//If there is no second largest element, print -1.
#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    if(secondLargest == INT_MIN)
        printf("-1");
    else
        printf("%d", secondLargest);

    return 0;
}