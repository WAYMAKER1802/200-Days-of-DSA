//Problem : You are given n cities and an n × n adjacency matrix isConnected.
//isConnected[i][j] = 1 means city i is directly connected to city j. Cities connected directly or indirectly belong to the same province.
//Return the total number of provinces.
#include <stdio.h>

void dfs(int n, int graph[n][n], int visited[n], int city)
{
    visited[city] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[city][i] == 1 && visited[i] == 0)
        {
            dfs(n, graph, visited, i);
        }
    }
}

int main()
{
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int graph[n][n];
    int visited[n];

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int provinces = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(n, graph, visited, i);
            provinces++;
        }
    }

    printf("Number of provinces = %d\n", provinces);

    return 0;
}