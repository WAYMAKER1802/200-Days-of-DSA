//Problem: Majority Element
//Given an array of size n, find the element that appears more than n/2 times.
#include <stdio.h>

int majorityElement(int nums[], int n) {
    int candidate = nums[0];
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            candidate = nums[i];
        }

        if(nums[i] == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", majorityElement(nums, n));

    return 0;
}