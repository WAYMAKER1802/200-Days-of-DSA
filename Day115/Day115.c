//Problem: Number of Islands
//Given a 2D grid of 1s (land) and 0s (water), count the number of islands using DFS.
#include<stdio.h>

int rows,cols;

void dfs(int grid[][5],int r,int c){
    if(r<0||r>=rows||c<0||c>=cols)return;
    if(grid[r][c]!=1)return;
    grid[r][c]=0;
    dfs(grid,r+1,c);
    dfs(grid,r-1,c);
    dfs(grid,r,c+1);
    dfs(grid,r,c-1);
}

int main(){
    int grid[][5]={
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
    rows=4;cols=5;
    int count=0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(grid[i][j]==1){dfs(grid,i,j);count++;}
    printf("Number of Islands: %d\n",count);
}