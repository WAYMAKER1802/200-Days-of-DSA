//Problem: Next Smaller Element
//Given an array of integers, find the next smaller element for every element. If there is no smaller element to its right, print -1.
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], ans[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = n - 1; i >= 0; i--)
    {
        while(!isEmpty() && peek() >= arr[i])
            pop();

        if(isEmpty())
            ans[i] = -1;
        else
            ans[i] = peek();

        push(arr[i]);
    }

    printf("Next Smaller Elements:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}