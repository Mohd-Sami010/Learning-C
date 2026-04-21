#include <stdio.h>

#define INF 9999

struct edge
{
    int u, v, w;
};

int main()
{
    int n = 5, e = 8;

    struct edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    int dist[5];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // check negative cycle
    for (int j = 0; j < e; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("Negative cycle");
            return 0;
        }
    }

    printf("Vertex Distance\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);

    return 0;
}