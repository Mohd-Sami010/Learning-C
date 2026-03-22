#include <stdio.h>

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

int isConnected()
{
    bfs(0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return 0; // some vertex was never reached
    }
    return 1;
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

    if (isConnected())
        printf("The graph IS connected.\n");
    else
        printf("The graph is NOT connected.\n");

    return 0;
}