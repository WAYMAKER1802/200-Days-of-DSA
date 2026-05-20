//Problem: Detect Cycle in Undirected Graph
//Given n nodes and edges, detect if a cycle exists using DFS.
#include<stdio.h>
#include<string.h>
#define MAXN 100

int adj[MAXN][MAXN],visited[MAXN],n;

int dfs(int node,int parent){
    visited[node]=1;
    for(int i=0;i<n;i++){
        if(adj[node][i]){
            if(!visited[i]){
                if(dfs(i,node))return 1;
            } else if(i!=parent)return 1;
        }
    }
    return 0;
}

int hasCycle(int edges[][2],int e){
    memset(adj,0,sizeof(adj));
    memset(visited,0,sizeof(visited));
    for(int i=0;i<e;i++){
        adj[edges[i][0]][edges[i][1]]=1;
        adj[edges[i][1]][edges[i][0]]=1;
    }
    for(int i=0;i<n;i++)
        if(!visited[i])
            if(dfs(i,-1))return 1;
    return 0;
}

int main(){
    int e1[][2]={{0,1},{1,2},{2,3},{3,4},{4,1}};
    n=5;
    printf("Test 1: %s\n",hasCycle(e1,5)?"Cycle Detected":"No Cycle");

    int e2[][2]={{0,1},{1,2},{2,3}};
    n=4;
    printf("Test 2: %s\n",hasCycle(e2,3)?"Cycle Detected":"No Cycle");
}