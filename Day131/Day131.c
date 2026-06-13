//Problem: Longest Subarray With Sum K
//Given an array of integers and an integer K, find the length of the longest subarray whose sum equals K.
#include <stdio.h>

int main() {
    int n, K;

    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &K);

    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == K) {
                int len = j - i + 1;
                if(len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("%d\n", maxLen);

    return 0;
}