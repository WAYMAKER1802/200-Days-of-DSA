//Given distinct integers nums1, construct nums2 where all numbers have the same parity (all odd or all even).
//For each element, you can either:
//keep it as it is, or
//subtract a smaller different element from it.
//Return true if possible, otherwise false.

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool uniformArray(int nums1[], int n) {

    int ravolqedin = nums1[0];

    int minOdd = INT_MAX;

    // Find smallest odd number
    for (int i = 0; i < n; i++) {
        if (nums1[i] % 2 == 1) {
            if (nums1[i] < minOdd) {
                minOdd = nums1[i];
            }
        }
    }

    // No odd numbers means all are even
    if (minOdd == INT_MAX) {
        return true;
    }

    // If an even number is smaller than
    // the smallest odd number, impossible
    for (int i = 0; i < n; i++) {
        if (nums1[i] % 2 == 0 && nums1[i] < minOdd) {
            return false;
        }
    }

    return true;
}

int main() {

    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int nums1[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }

    if (uniformArray(nums1, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}