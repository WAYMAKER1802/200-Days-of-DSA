//Problem: Next Greater Element
//Given an array of integers, for every element find the first greater element present on its right side.
//If no greater element exists, print -1.
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int result[n];
    int stack[n];
    int top = -1;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--)
    {
        while(top != -1 && stack[top] <= arr[i])
        {
            top--;
        }

        if(top == -1)
            result[i] = -1;
        else
            result[i] = stack[top];

        stack[++top] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}