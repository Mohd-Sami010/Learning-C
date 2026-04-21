#include <stdio.h>

int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 0},
    {0, 1, 0, 0}};

int visited[4] = {0};

void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < 4; i++)
    {
        if (graph[v][i] && !visited[i])
            dfs(i);
    }
}

int main()
{
    printf("DFS: ");
    dfs(0);
    return 0;
}