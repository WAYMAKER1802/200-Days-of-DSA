//Problem: Minimum Cost to Connect All Cities (Prim's Algorithm) There are N cities numbered from 0 to N-1 and M bidirectional roads.
//Each road is represented as: u v w
//where:
//u = source city
//v = destination city
//w = cost of building/using the road.
//Find the minimum total cost to connect all cities. If it is impossible to connect every city, print -1.
#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000000

int graph[MAX][MAX];
int visited[MAX];
int key[MAX];

int prim(int n)
{
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    int cost = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        int min = INF;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        if (u == -1)
            return -1;

        visited[u] = 1;
        cost += key[u];

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != INF && !visited[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
            }
        }
    }

    return cost;
}

int main()
{
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int ans = prim(n);

    if (ans == -1)
        printf("Graph is not connected.\n");
    else
        printf("Minimum Cost = %d\n", ans);

    return 0;
}