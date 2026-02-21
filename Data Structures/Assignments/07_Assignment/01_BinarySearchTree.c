#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateNode(int value){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct Node* Insert(struct Node* rootNode, int value){
    if (rootNode == NULL){
        return CreateNode(value);
    }
    if (value < rootNode -> data){
        rootNode->left = Insert(rootNode -> left, value);
    }
    else if (value > rootNode -> data){
        rootNode -> right = Insert(rootNode -> right, value);
    }
    return rootNode;
}

void PrintInorder(struct Node* rootNode){
    if (rootNode != NULL){
        PrintInorder(rootNode -> left);
        printf("%d ", rootNode -> data);
        PrintInorder(rootNode -> right);
    }
}
void PrintPreorder(struct Node* rootNode){
    if (rootNode !=NULL){
        printf("%d ", rootNode -> data);
        PrintPreorder(rootNode -> left);
        PrintPreorder(rootNode -> right);
    }
}
void PrintPostorder(struct Node* rootNode){
    if (rootNode != NULL){
        PrintPostorder(rootNode -> left);
        PrintPostorder(rootNode -> right);
        printf("%d ", rootNode -> data);
    }
}

int main(){

    struct Node* rootNode = NULL;

    int data[] = {32, 56, 21, 4, 1, 56, 2, 5, 3, 21};
    int n = sizeof(data) / sizeof(int);

    for (int i = 0; i < n; i++){
        rootNode = Insert(rootNode, data[i]);
    }

    printf("Inorder: ");
    PrintInorder(rootNode);
    printf("\n");
    
    printf("Preorder: ");
    PrintPreorder(rootNode);
    printf("\n");
    
    printf("Postorder: ");
    PrintPostorder(rootNode);
    printf("\n");

    return 0;
}