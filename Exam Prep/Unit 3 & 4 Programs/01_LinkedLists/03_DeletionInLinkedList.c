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
    printf("\n");
}

struct Node * DeleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head -> nextNode;
    free(ptr);
    return head;
}
struct Node * DeleteAtIndex(struct Node * head, int index){
    struct Node * ptr = head;
    int i = 0;

    while (i != index -1){
        i++;
        ptr = ptr -> nextNode;
    }
    struct Node * deletedNode = ptr -> nextNode;
    ptr -> nextNode = NULL;
    free(deletedNode);

    return head;
}
struct Node * DeleteAtEnd(struct Node * head){
    struct Node * ptr = head;

    while (ptr -> nextNode -> nextNode != NULL){
        ptr = ptr -> nextNode;
    }
    struct Node * deletedNode = ptr -> nextNode;
    ptr -> nextNode = NULL;
    free(deletedNode);
}

void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 10;
    head -> nextNode = second;

    second -> data = 20;
    second -> nextNode = third;

    third -> data = 23;
    third -> nextNode = forth;

    forth -> data = 27;
    forth -> nextNode = NULL;

    printf("\n");
    printf("Default List: ");
    TraverseList(head);

    // Deleting Head
    head = DeleteFirst(head);

    printf("List after deleting First Element: ");
    TraverseList(head);

    // Deleting at Index
    head = DeleteAtIndex(head, 2);

    printf("List after deleting 2nd Element: ");
    TraverseList(head);

    // Deleting at End
    head = DeleteAtEnd(head);

    printf("List after deleting Last Element: ");
    TraverseList(head);
}