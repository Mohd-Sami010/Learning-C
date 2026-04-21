#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int u, v, w;
};

int parent[10];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void uni(int a, int b)
{
    parent[a] = b;
}

int cmp(const void *a, const void *b)
{
    return ((struct edge *)a)->w - ((struct edge *)b)->w;
}

int main()
{
    int n = 4, e = 5;

    struct edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    for (int i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, e, sizeof(edges[0]), cmp);

    int cost = 0, count = 0;

    printf("MST Edges:\n");

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v)
        {
            printf("%d-%d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            uni(u, v);
            count++;
        }
    }

    printf("Total Cost: %d", cost);
    return 0;
}