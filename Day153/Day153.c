//Problem Statement : You are given an N × N matrix. Rotate the matrix by 90 degrees clockwise in-place.
#include <stdio.h>

void rotateMatrix(int matrix[][100], int n)
{
    int i, j, temp;

    // Transpose
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse each row
    for(i = 0; i < n; i++)
    {
        int left = 0, right = n - 1;
        while(left < right)
        {
            temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}

int main()
{
    int n;
    int matrix[100][100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    rotateMatrix(matrix, n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}