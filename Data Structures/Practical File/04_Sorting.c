#include <stdio.h>

void print(int a[])
{
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[10] = {5, 3, 8, 4, 2, 7, 1, 9, 6, 0};

    // Bubble
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9 - i; j++)
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }

    // Selection
    for (int i = 0; i < 9; i++)
    {
        int min = i;
        for (int j = i + 1; j < 10; j++)
            if (a[j] < a[min])
                min = j;
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }

    // Insertion
    for (int i = 1; i < 10; i++)
    {
        int temp = a[i], j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    print(a);
    return 0;
}