#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

void kruskal(struct Edge edges[], int n, int e)
{
    int i, count = 0;
    int cost = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, e, sizeof(edges[0]), compare);

    printf("Edges in MST:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v)
        {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Total Cost = %d\n", cost);
}

int main()
{
    int n = 4, e = 5;

    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    kruskal(edges, n, e);
    return 0;
}