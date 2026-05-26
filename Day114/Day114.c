//Problem: Flood Fill AlgorithmGiven a 2D grid, a starting cell (sr,sc) and a new color, 
// fill all connected cells of the same original color with the new color (like Paint bucket tool).
#include<stdio.h>

int rows,cols;

void dfs(int grid[][3],int r,int c,int oc,int nc){
    if(r<0||r>=rows||c<0||c>=cols)return;
    if(grid[r][c]!=oc)return;
    grid[r][c]=nc;
    dfs(grid,r+1,c,oc,nc);
    dfs(grid,r-1,c,oc,nc);
    dfs(grid,r,c+1,oc,nc);
    dfs(grid,r,c-1,oc,nc);
}

int main(){
    int grid[][3]={{1,1,1},{1,1,0},{1,0,1}};
    rows=3;cols=3;
    int sr=1,sc=1,nc=2;
    int oc=grid[sr][sc];
    if(oc!=nc)dfs(grid,sr,sc,oc,nc);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            printf("%d ",grid[i][j]);
        printf("\n");
    }
}