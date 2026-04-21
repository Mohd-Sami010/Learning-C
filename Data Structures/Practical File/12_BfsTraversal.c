#include <stdio.h>

int main()
{
    int graph[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}};

    int visited[4] = {0};
    int q[100], f = 0, r = 0;

    q[r++] = 0;
    visited[0] = 1;

    printf("BFS: ");

    while (f < r)
    {
        int v = q[f++];
        printf("%d ", v);

        for (int i = 0; i < 4; i++)
        {
            if (graph[v][i] && !visited[i])
            {
                q[r++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}