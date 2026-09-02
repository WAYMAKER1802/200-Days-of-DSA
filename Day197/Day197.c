//You are given an array nums1 of distinct integers. For every index i, choose either:
//nums2[i] = nums1[i], or
//nums2[i] = nums1[i] - nums1[j], where j != i.
//Return true if nums2 can be made all odd or all even.
#include <stdio.h>
#include <stdbool.h>

bool uniformArray(int nums1[], int n) {
    return true;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums1[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }

    if (uniformArray(nums1, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}