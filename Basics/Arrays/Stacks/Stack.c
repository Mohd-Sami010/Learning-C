#include <stdio.h>

int stack[10];
int size = 10;
int top = -1;

void Push(int data){
    if (top >= size-1) return;
    top++;
    stack[top] = data;
}
int Pop(){
    if (top <= -1) return -1;
    return stack[top--];
}
int Peek(){
    if (top <= -1 && top >= size-1) return -1;
    return stack[top];
}
void Display(){
    for (int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(){

    Push(5);
    Push(78);
    Push(59);

    Display();

    Pop();

    Display();

    Push(10);
    Push(14);
    Push(21);

    Display();
}