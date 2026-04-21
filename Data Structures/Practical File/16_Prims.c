#include <stdio.h>

#define INF 9999

int minKey(int key[], int mst[], int n)
{
    int min = INF, idx;
    for (int i = 0; i < n; i++)
    {
        if (!mst[i] && key[i] < min)
        {
            min = key[i];
            idx = i;
        }
    }
    return idx;
}

int main()
{
    int n = 5;
    int g[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int key[5], mst[5] = {0}, parent[5];

    for (int i = 0; i < n; i++)
        key[i] = INF;

    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < n - 1; c++)
    {
        int u = minKey(key, mst, n);
        mst[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (g[u][v] && !mst[v] && g[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = g[u][v];
            }
        }
    }

    int cost = 0;
    printf("MST:\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d-%d : %d\n", parent[i], i, g[i][parent[i]]);
        cost += g[i][parent[i]];
    }
    printf("Cost: %d", cost);

    return 0;
}