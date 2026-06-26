//Problem Statement
//You are given an array containing n-1 distinct integers from 1 to n. One number is missing. Find the missing number.
#include <stdio.h>

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n - 1];

    printf("Enter elements:\n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int totalSum = n * (n + 1) / 2;
    int arraySum = 0;

    for (int i = 0; i < n - 1; i++) {
        arraySum += arr[i];
    }

    printf("Missing number is: %d\n", totalSum - arraySum);

    return 0;
}