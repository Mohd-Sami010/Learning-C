#include <stdio.h>
#define MAX 100
#define INF 9999

int minKey(int key[], int mstSet[], int n)
{
    int min = INF, min_index, i;

    for (i = 0; i < n; i++)
    {
        if (mstSet[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void prim(int graph[MAX][MAX], int n)
{
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];
    int i, count;

    for (i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (i = 0; i < n; i++)
        {
            if (graph[u][i] && mstSet[i] == 0 && graph[u][i] < key[i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }

    printf("Edges in MST:\n");
    for (i = 1; i < n; i++)
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
}

int main()
{
    int n = 5;

    int graph[MAX][MAX] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    prim(graph, n);
    return 0;
}