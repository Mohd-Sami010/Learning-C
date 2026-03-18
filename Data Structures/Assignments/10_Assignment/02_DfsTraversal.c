#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

// DFS function
void DFS(int node, int n)
{
    int i;

    printf("%d ", node);
    visited[node] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] == 0)
        {
            DFS(i, n);
        }
    }
}

int main()
{
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    DFS(start, n);

    return 0;
}