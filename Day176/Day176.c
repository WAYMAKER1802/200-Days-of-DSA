//Problem: Find the First and Last Position of an Element
//Given a sorted array of integers, find the starting and ending position of a given target. If the target does not exist, return -1 -1.
#include <stdio.h>

int firstPosition(int a[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int lastPosition(int a[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter sorted array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int first = firstPosition(a, n, target);
    int last = lastPosition(a, n, target);

    if (first == -1)
    {
        printf("Target not found.\n");
    }
    else
    {
        printf("First position = %d\n", first);
        printf("Last position = %d\n", last);
    }

    return 0;
}