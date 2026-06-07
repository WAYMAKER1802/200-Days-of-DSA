//Problem Statement
//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int nums[], int n) {
    if(n == 0) return 0;

    qsort(nums, n, sizeof(int), compare);

    int longest = 1;
    int current = 1;

    for(int i = 1; i < n; i++) {

        if(nums[i] == nums[i-1])
            continue;

        if(nums[i] == nums[i-1] + 1) {
            current++;
        }
        else {
            if(current > longest)
                longest = current;
            current = 1;
        }
    }

    if(current > longest)
        longest = current;

    return longest;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("%d\n", longestConsecutive(nums, n));

    return 0;
}