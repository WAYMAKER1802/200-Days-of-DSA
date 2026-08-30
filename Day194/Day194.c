//Removing Minimum and Maximum From Array - You are given a 0-indexed array of distinct integers nums. The element with the smallest value is the minimum.
//The element with the largest value is the maximum. In one deletion, you can remove one element from either the front or the back of the array.
#include <stdio.h>

int minimumDeletions(int nums[], int n)
{
    int minIndex = 0;
    int maxIndex = 0;

    // Find minimum and maximum
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[minIndex])
            minIndex = i;

        if (nums[i] > nums[maxIndex])
            maxIndex = i;
    }

    // Make minIndex smaller than maxIndex
    if (minIndex > maxIndex)
    {
        int temp = minIndex;
        minIndex = maxIndex;
        maxIndex = temp;
    }

    // Remove both from front
    int front = maxIndex + 1;

    // Remove both from back
    int back = n - minIndex;

    // Remove min from front and max from back
    int both = (minIndex + 1) + (n - maxIndex);

    // Find minimum
    int answer = front;

    if (back < answer)
        answer = back;

    if (both < answer)
        answer = both;

    return answer;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = minimumDeletions(nums, n);

    printf("Minimum number of deletions = %d\n", result);

    return 0;
}