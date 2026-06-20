//Problem Statement : Given an integer array nums, return an array answer such that:
//answer[i] is equal to the product of all the elements of nums except nums[i].
#include <stdio.h>

void productExceptSelf(int nums[], int n) {
    int answer[n];

    answer[0] = 1;

    // Prefix products
    for (int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    productExceptSelf(nums, n);

    return 0;
}