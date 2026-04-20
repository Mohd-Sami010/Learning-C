#include <stdio.h>

int queue[100], front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == 99)
        printf("Full\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = x;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("Empty\n");
    else
        front++;
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return rear == 99;
}

int main()
{
    enqueue(10);
    enqueue(20);
    dequeue();

    if (isEmpty())
        printf("Empty\n");
    else
        printf("Not Empty\n");

    return 0;
}