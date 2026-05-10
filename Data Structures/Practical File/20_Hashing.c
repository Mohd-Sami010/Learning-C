#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// ---------- Linear Probing ----------
int hashTable[SIZE];

void initTable()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insertLinear(int key)
{
    int index = key % SIZE;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

void displayLinear()
{
    printf("Hash Table using Linear Probing:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d -> %d\n", i, hashTable[i]);
    }
}

// ---------- Chaining ----------
struct node
{
    int data;
    struct node *next;
};

struct node *chain[SIZE];

void insertChain(int key)
{
    int index = key % SIZE;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = chain[index];

    chain[index] = temp;
}

void displayChain()
{
    printf("\nHash Table using Chaining:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d -> ", i);

        struct node *p = chain[i];

        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }

        printf("\n");
    }
}

int main()
{

    int values[] = {15, 25, 35, 20, 30, 10};
    int n = 6;

    initTable();

    // Linear Probing
    for (int i = 0; i < n; i++)
        insertLinear(values[i]);

    displayLinear();

    // Chaining
    for (int i = 0; i < n; i++)
        insertChain(values[i]);

    displayChain();

    return 0;
}