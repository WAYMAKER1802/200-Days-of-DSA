//Problem statement - Given an array nums and integer k, for every index i calculate:
//instability = max(nums[0...i]) - min(nums[i...n-1])
//Return the smallest index whose instability is <= k. If none exists, return -1.
#include <stdio.h>

int firstStableIndex(int nums[], int n, int k) {

    int right[n];

    // Suffix minimum
    right[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < right[i + 1])
            right[i] = nums[i];
        else
            right[i] = right[i + 1];
    }

    // Prefix maximum
    int left = nums[0];

    for (int i = 0; i < n; i++) {

        if (nums[i] > left)
            left = nums[i];

        int instability = left - right[i];

        if (instability <= k)
            return i;
    }

    return -1;
}

int main() {

    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = firstStableIndex(nums, n, k);

    printf("Smallest stable index = %d\n", result);

    return 0;
}