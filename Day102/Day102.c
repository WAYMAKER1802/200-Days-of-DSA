//Problem: Find if path exists in a directed graph
//Given n nodes, a list of directed edges, a source and destination, find if a path exists from source to destination using BFS.
#include<stdio.h>
#include<string.h>
#define MAXN 100

int adj[MAXN][MAXN],visited[MAXN];
int queue[MAXN],front,rear;

int bfs(int src,int dst,int n){
    memset(visited,0,sizeof(visited));
    front=rear=0;
    queue[rear++]=src;
    visited[src]=1;
    while(front<rear){
        int node=queue[front++];
        if(node==dst)return 1;
        for(int i=0;i<n;i++)
            if(adj[node][i]&&!visited[i]){
                visited[i]=1;
                queue[rear++]=i;
            }
    }
    return 0;
}

int main(){
    int n=6;
    int edges[][2]={{0,1},{0,2},{1,3},{2,4},{3,5},{4,5}};
    int e=6;
    memset(adj,0,sizeof(adj));
    for(int i=0;i<e;i++)
        adj[edges[i][0]][edges[i][1]]=1;
    int src=0,dst=5;
    printf("Path exists: %s\n",bfs(src,dst,n)?"Yes":"No");
}