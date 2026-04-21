#include <stdio.h>

struct sparse
{
    int row, col, val;
};

int main()
{
    struct sparse a[10] = {{3, 3, 3}, {0, 0, 5}, {1, 1, 8}, {2, 2, 3}};
    struct sparse b[10], c[10];
    int n = a[0].val;

    // Transpose
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;

    int k = 1;
    for (int i = 0; i < a[0].col; i++)
        for (int j = 1; j <= n; j++)
            if (a[j].col == i)
                b[k++] = (struct sparse){a[j].col, a[j].row, a[j].val};

    // Addition (same matrix for demo)
    c[0] = a[0];
    for (int i = 1; i <= n; i++)
    {
        c[i].row = a[i].row;
        c[i].col = a[i].col;
        c[i].val = a[i].val + a[i].val;
    }

    // Print transpose
    for (int i = 0; i <= n; i++)
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].val);

    return 0;
}