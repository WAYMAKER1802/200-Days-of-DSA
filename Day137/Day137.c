//Problem Statement
//Given an array of integers, find the next greater element for every element.
//The next greater element of an element is the first greater element on its right. If there is no greater element, output -1.
#include <stdio.h>

void nextGreaterElement(int arr[], int n) {
    int stack[n], top = -1;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i]) {
            top--;
        }

        if (top == -1)
            result[i] = -1;
        else
            result[i] = stack[top];

        stack[++top] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    nextGreaterElement(arr, n);

    return 0;
}