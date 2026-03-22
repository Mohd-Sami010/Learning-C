#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];
int queue[MAX], front = 0, rear = -1;
int n, e;

void bfs(int start)
{
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("BFS Traversal starting from vertex 0: ");
    bfs(0);
    printf("\n");
    return 0;
}