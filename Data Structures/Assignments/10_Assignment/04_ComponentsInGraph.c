#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];
int n, e;

void dfs(int node)
{
    visited[node] = 1;
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int u, v, components = 0;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Each DFS call that starts from an unvisited node = one new component
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            components++;
        }
    }

    printf("Number of connected components: %d\n", components);

    if (components == 1)
        printf("The graph IS connected.\n");
    else
        printf("The graph is NOT connected.\n");

    return 0;
}