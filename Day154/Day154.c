//Problem Statement : Given an m x n matrix, print all elements of the matrix in spiral order.
#include <stdio.h>

void spiralPrint(int matrix[][100], int rows, int cols)
{
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    while (top <= bottom && left <= right)
    {
        // Left to Right
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Right to Left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Bottom to Top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

int main()
{
    int rows, cols;
    int matrix[100][100];

    scanf("%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    spiralPrint(matrix, rows, cols);

    return 0;
}