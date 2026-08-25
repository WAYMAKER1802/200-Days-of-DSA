//Question : Given an integer array nums and an integer k, return the total number of subarrays whose sum equals k. A subarray is a contiguous part of the array
#include <stdio.h>

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int count = 0;

    // Start from every index
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        // Extend the subarray
        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            if (sum == k)
            {
                count++;
            }
        }
    }

    printf("Number of subarrays with sum %d = %d\n", k, count);

    return 0;
}