//Problem: Majority Element
//Given an array of size n, find the element that appears more than n/2 times.
#include <stdio.h>

int majorityElement(int arr[], int n) {
    int candidate = arr[0];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
        }

        if (arr[i] == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Majority Element = %d\n", majorityElement(arr, n));

    return 0;
}