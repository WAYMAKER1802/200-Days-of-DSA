//Problem: Two Sum
//Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.
#include <stdio.h>

int main() {
    int n, target;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                printf("Indices: %d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No solution found\n");

    return 0;
}