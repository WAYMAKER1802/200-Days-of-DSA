//Problem Statement : Given an array of N integers, print all the leaders in the array.
//A leader is an element that is greater than or equal to all the elements to its right.
#include <stdio.h>

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxRight = arr[n - 1];

    printf("Leaders are:\n");
    printf("%d ", maxRight);

    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] >= maxRight) {
            maxRight = arr[i];
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}