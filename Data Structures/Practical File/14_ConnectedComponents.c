#include <stdio.h>

int main()
{
    int graph[5][5] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};

    int visited[5] = {0};
    int q[100], f, r;
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            count++;
            f = r = 0;

            q[r++] = i;
            visited[i] = 1;

            while (f < r)
            {
                int v = q[f++];

                for (int j = 0; j < 5; j++)
                {
                    if (graph[v][j] && !visited[j])
                    {
                        q[r++] = j;
                        visited[j] = 1;
                    }
                }
            }
        }
    }

    printf("Connected Components: %d", count);
    return 0;
}