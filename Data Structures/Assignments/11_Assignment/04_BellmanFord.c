#include <stdio.h>
#define MAX 100
#define INF 9999

struct Edge
{
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int n, int e, int src)
{
    int dist[MAX];
    int i, j;

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (i = 1; i <= n - 1; i++)
    {
        for (j = 0; j < e; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (j = 0; j < e; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    int n = 5, e = 8;

    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    bellmanFord(edges, n, e, 0);
    return 0;
}