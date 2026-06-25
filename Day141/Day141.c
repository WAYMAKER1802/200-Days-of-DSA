//Given an array of integers, print all the leaders in the array.
//A leader is an element that is greater than or equal to all the elements to its right. The rightmost element is always a leader.
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int leaders[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxRight = arr[n - 1];
    leaders[count++] = maxRight;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            maxRight = arr[i];
            leaders[count++] = arr[i];
        }
    }

    // Print in correct order
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }

    return 0;
}