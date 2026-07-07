//Problem Statement : Given an array of N integers, print all the leaders in the array.
//A leader is an element that is greater than or equal to all the elements to its right. The rightmost element is always a leader.
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Leaders are:\n");

    for(int i = 0; i < n; i++) {
        int leader = 1;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                leader = 0;
                break;
            }
        }

        if(leader)
            printf("%d ", arr[i]);
    }

    return 0;
}