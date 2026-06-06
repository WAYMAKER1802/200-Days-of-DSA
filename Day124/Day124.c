//Problem: Two Sum
//Given an array of integers and a target value, find the indices of the two numbers such that they add up to the target.
//Assume exactly one solution exists, and you may not use the same element twice.
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No Solution");
    return 0;
}