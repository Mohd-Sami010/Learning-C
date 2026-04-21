#include <stdio.h>

int parent[10], rank[10];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]); // path compression
    return parent[x];
}

void unionSet(int a, int b)
{
    int x = find(a), y = find(b);

    if (x == y)
        return;

    if (rank[x] < rank[y])
        parent[x] = y;
    else if (rank[x] > rank[y])
        parent[y] = x;
    else
    {
        parent[y] = x;
        rank[x]++;
    }
}

int main()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    unionSet(0, 1);
    unionSet(1, 2);
    unionSet(3, 4);

    printf("Find(2): %d\n", find(2));
    printf("Find(4): %d\n", find(4));

    unionSet(2, 4);

    printf("After Union(2,4):\n");
    printf("Find(4): %d\n", find(4));

    return 0;
}