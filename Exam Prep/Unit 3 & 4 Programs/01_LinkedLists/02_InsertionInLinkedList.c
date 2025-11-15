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

// Insertion
struct Node* InsetAtStart(struct Node *head, int data){
    struct Node *newHead = (struct Node *)malloc(sizeof(struct Node));
    newHead -> nextNode = head;
    newHead -> data = data;
    return newHead;
}
struct Node* InsertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i != index -1){
        i++;
        p = p -> nextNode;
    }
    ptr -> data = data;
    ptr -> nextNode = p -> nextNode;
    p -> nextNode = ptr;

    return head;
}
struct Node* InsertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;

    while (p -> nextNode != NULL){
        p = p -> nextNode;
    }
    ptr -> data = data;
    ptr -> nextNode = NULL;
    p -> nextNode = ptr;

    return head;
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

    printf("\n");
    printf("Default List: ");
    TraverseList(head);

    // Inserting a new head
    head = InsetAtStart(head, 7);

    printf("List after inserting new head: ");
    TraverseList(head);
    
    // Inserting at third one
    head = InsertAtIndex(head, 27, 2);

    printf("List after inserting at third: ");
    TraverseList(head);

    // Inserting at End
    head = InsertAtEnd(head, 53);

    printf("List after inserting at End: ");
    TraverseList(head);

    printf("\n");
}