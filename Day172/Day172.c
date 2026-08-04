//Problem: Number of Connected Components in an Undirected Graph (Medium)
//Given an undirected graph with n vertices numbered from 0 to n-1 and a list of edges, determine the number of connected components.
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void dfs(int node, int n)
{
    visited[node] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[node][i] == 1 && !visited[i])
        {
            dfs(i, n);
        }
    }
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int components = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, n);
            components++;
        }
    }

    printf("Connected Components = %d\n", components);

    return 0;
}