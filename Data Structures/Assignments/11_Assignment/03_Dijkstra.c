#include <stdio.h>
#define MAX 100
#define INF 9999

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, min_index, i;

    for (i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX], visited[MAX];
    int i, count;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && graph[u][i] &&
                dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    int n = 5;

    int graph[MAX][MAX] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}};

    dijkstra(graph, n, 0);
    return 0;
}