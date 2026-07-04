//Problem Statement : Write a C program to check whether a given array is sorted in ascending order.
//If the array is sorted, print - Array is sorted
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sorted = 1;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            sorted = 0;
            break;
        }
    }

    if(sorted)
        printf("Array is sorted.\n");
    else
        printf("Array is not sorted.\n");

    return 0;
}