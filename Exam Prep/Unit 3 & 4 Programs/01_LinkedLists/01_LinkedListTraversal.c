#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *nextNode;
};
void TraverseList(struct Node *ptr){
    while (ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> nextNode;
    }
    printf("Null");
}
void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 10;
    head -> nextNode = second;

    second -> data = 20;
    second -> nextNode = third;

    third -> data = 23;
    third -> nextNode = NULL;

    TraverseList(head);
    
}