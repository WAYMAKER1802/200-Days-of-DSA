//Problem : You are given an m x n grid of characters consisting of '1' (land) and '0' (water).
//Count the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
#include <stdio.h>

void dfs(char **grid, int m, int n, int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    dfs(grid, m, n, i + 1, j);
    dfs(grid, m, n, i - 1, j);
    dfs(grid, m, n, i, j + 1);
    dfs(grid, m, n, i, j - 1);
}

int numIslands(char **grid, int gridSize, int *gridColSize)
{
    int count = 0;
    int m = gridSize;
    int n = *gridColSize;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfs(grid, m, n, i, j);
            }
        }
    }

    return count;
}

int main()
{
    char row1[] = {'1', '1', '0', '0', '0'};
    char row2[] = {'1', '1', '0', '0', '0'};
    char row3[] = {'0', '0', '1', '0', '0'};
    char row4[] = {'0', '0', '0', '1', '1'};

    char *grid[] = {row1, row2, row3, row4};

    int cols = 5;

    printf("Number of Islands = %d\n", numIslands(grid, 4, &cols));

    return 0;
}