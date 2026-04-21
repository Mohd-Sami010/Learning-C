#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void inorder(struct node *root)
{
    struct node *stack[100];
    int top = -1;

    while (root || top != -1)
    {
        while (root)
        {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        printf("%d ", root->data);
        root = root->right;
    }
}

int main()
{
    struct node *r = newNode(5);
    r->left = newNode(3);
    r->right = newNode(7);

    inorder(r);
    return 0;
}