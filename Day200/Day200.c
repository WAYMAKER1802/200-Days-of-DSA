//Question: Given rowIndex, return the rowIndex-th 0-indexed row of Pascal's Triangle. Each number is the sum of the two numbers directly above it.
#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    int n = rowIndex + 1;

    int* row = (int*)malloc(n * sizeof(int));

    *returnSize = n;

    // Initialize all elements to 1
    for (int i = 0; i < n; i++) {
        row[i] = 1;
    }

    // Build Pascal's row
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i - 1; j >= 1; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}

int main() {
    int rowIndex;

    printf("Enter row index: ");
    scanf("%d", &rowIndex);

    int size;
    int* result = getRow(rowIndex, &size);

    printf("Pascal's Row: [");

    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);

        if (i < size - 1)
            printf(", ");
    }

    printf("]\n");

    free(result);

    return 0;
}