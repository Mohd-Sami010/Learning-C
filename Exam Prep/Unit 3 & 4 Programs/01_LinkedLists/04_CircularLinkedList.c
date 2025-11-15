#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *nextNode;
};

void TraverseList(struct Node *head){
    struct Node *ptr = head;
    printf("\n");
    do{
        printf("%d -> ", ptr -> data);
        ptr = ptr -> nextNode;
    }while(ptr != head);
    printf("head");
}
void main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));

    head -> data = 2;
    head -> nextNode = second;

    second -> data = 7;
    second -> nextNode = third;

    third -> data = 13;
    third -> nextNode = forth;

    forth -> data = 29;
    forth -> nextNode = head;

    TraverseList(head);
}