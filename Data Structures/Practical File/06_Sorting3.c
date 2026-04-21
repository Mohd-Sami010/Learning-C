#include <stdio.h>

void print(int a[])
{
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Count
void countSort(int a[], int n)
{
    int count[100] = {0}, b[100];
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    for (int i = 1; i < 100; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
        b[--count[a[i]]] = a[i];
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

// Radix (only 1 digit simplified)
void radix(int a[], int n)
{
    int count[10] = {0}, b[100];
    for (int i = 0; i < n; i++)
        count[a[i] % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
        b[--count[a[i] % 10]] = a[i];
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

// Bucket (simple)
void bucket(int a[], int n)
{
    int b[10][10], count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        int d = a[i] / 10;
        b[d][count[d]++] = a[i];
    }
    int k = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < count[i]; j++)
            a[k++] = b[i][j];
}

int main()
{
    int a[10] = {12, 45, 23, 10, 5, 67, 89, 34, 2, 9};

    countSort(a, 10);
    radix(a, 10);
    bucket(a, 10);

    print(a);
    return 0;
}