#include <stdio.h>

#define INF 9999

int minDist(int dist[], int vis[], int n)
{
    int min = INF, idx;
    for (int i = 0; i < n; i++)
        if (!vis[i] && dist[i] < min)
        {
            min = dist[i];
            idx = i;
        }
    return idx;
}

int main()
{
    int n = 5;

    int graph[5][5] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}};

    int dist[5], vis[5] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int u = minDist(dist, vis, n);
        vis[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !vis[v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex Distance\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);

    return 0;
}