//Problem Statement : Given an m x n 2D grid where:
//'1' represents land.
//'0' represents water.
//Return the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
#include <stdlib.h>

void dfs(char** grid, int rows, int cols, int i, int j) {

    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    dfs(grid, rows, cols, i + 1, j);
    dfs(grid, rows, cols, i - 1, j);
    dfs(grid, rows, cols, i, j + 1);
    dfs(grid, rows, cols, i, j - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {

    int rows = gridSize;
    int cols = gridColSize[0];
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == '1') {
                count++;
                dfs(grid, rows, cols, i, j);
            }
        }
    }

    return count;
}