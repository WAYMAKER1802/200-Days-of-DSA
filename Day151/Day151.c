//Problem Statement : Given an array of integers, find the next greater element for every element in the array.
//The next greater element of an element x is the first greater element to its right.
//If there is no greater element, print -1.
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

    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                printf("%d --> %d\n", arr[i], arr[j]);
                found = 1;
                break;
            }
        }

        if(!found)
            printf("%d --> -1\n", arr[i]);
    }

    return 0;
}