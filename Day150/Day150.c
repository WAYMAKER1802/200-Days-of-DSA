//Problem Statement : Given an array of integers, find the first element that occurs exactly once.
//If no such element exists, print -1.
#include <stdio.h>

int firstNonRepeating(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count == 1) {
            return arr[i];
        }
    }

    return -1;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = firstNonRepeating(arr, n);

    if (result == -1)
        printf("No non-repeating element found.\n");
    else
        printf("First non-repeating element: %d\n", result);

    return 0;
}