//Problem: Count Inversions in an Array
//Given an integer array arr, count the number of inversions in the array.
#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;

            // All remaining elements from i to mid
            // are greater than arr[j]
            inversions += (mid - i + 1);
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSort(int arr[], int temp[], int left, int right)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long inversions = 0;

    inversions += mergeSort(arr, temp, left, mid);

    inversions += mergeSort(arr, temp, mid + 1, right);

    inversions += merge(arr, temp, left, mid, right);

    return inversions;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions = %lld\n", result);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}