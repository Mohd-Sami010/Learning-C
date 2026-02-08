#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void Enqueue(int data){
    if (rear == SIZE -1) return;

    if (front == -1) front = 0;
    queue[++rear] = data;
}
int Dequeue(){
    if (front == -1 || front > rear) return -1;

    return queue[front++];
}
void Display(){
    for (int i = front; i<= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    
    Enqueue(56);
    Enqueue(5);
    Enqueue(25);
    Enqueue(6);

    Display();

    Dequeue();

    Display();

    return 0;
}