//Problem: Assign Cookies
//You are given two integer arrays:
//g[] = greed factor of each child.
//s[] = size of each cookie.
//A child is satisfied if the cookie size is greater than or equal to the child's greed factor. Each child can receive only one cookie, and each cookie can be assigned to only one child.
//Return the maximum number of satisfied children.
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {

    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int i = 0, j = 0;

    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            i++;
        }
        j++;
    }

    return i;
}

int main() {
    int g[] = {1, 2, 3};
    int s[] = {1, 1};

    int gSize = sizeof(g) / sizeof(g[0]);
    int sSize = sizeof(s) / sizeof(s[0]);

    printf("Maximum satisfied children = %d\n",
           findContentChildren(g, gSize, s, sSize));

    return 0;
}