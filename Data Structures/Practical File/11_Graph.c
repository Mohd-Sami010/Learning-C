#include <stdio.h>
#include <stdlib.h>

struct node
{
    int v;
    struct node *next;
};

int main()
{
    int n = 4;

    int graph[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}};

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    struct node *adj[4] = {NULL};

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (graph[i][j])
            {
                struct node *t = (struct node *)malloc(sizeof(struct node));
                t->v = j;
                t->next = adj[i];
                adj[i] = t;
            }
        }
    }

    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        struct node *p = adj[i];
        while (p)
        {
            printf("%d ", p->v);
            p = p->next;
        }
        printf("\n");
    }

    return 0;
}