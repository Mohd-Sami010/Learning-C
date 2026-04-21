#include <stdio.h>

void print(int a[])
{
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Merge
void merge(int a[], int l, int m, int h)
{
    int b[100], i = l, j = m + 1, k = l;
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= h)
        b[k++] = a[j++];
    for (i = l; i <= h; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

// Quick
int part(int a[], int l, int h)
{
    int p = a[l], i = l + 1, j = h, t;
    while (1)
    {
        while (i <= h && a[i] <= p)
            i++;
        while (a[j] > p)
            j--;
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        else
        {
            t = a[l];
            a[l] = a[j];
            a[j] = t;
            return j;
        }
    }
}

void quick(int a[], int l, int h)
{
    if (l < h)
    {
        int pi = part(a, l, h);
        quick(a, l, pi - 1);
        quick(a, pi + 1, h);
    }
}

// Heap
void heapify(int a[], int n, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, largest = i, t;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

int main()
{
    int a[10] = {5, 3, 8, 4, 2, 7, 1, 9, 6, 0};

    mergeSort(a, 0, 9);
    quick(a, 0, 9);
    heapSort(a, 10);

    print(a);
    return 0;
}