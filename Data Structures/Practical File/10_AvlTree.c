#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data, height;
    struct node *left, *right;
};

int h(struct node *n) { return n ? n->height : 0; }

int max(int a, int b) { return a > b ? a : b; }

struct node *newNode(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

int balance(struct node *n) { return n ? h(n->left) - h(n->right) : 0; }

struct node *insert(struct node *n, int key)
{
    if (n == NULL)
        return newNode(key);

    if (key < n->data)
        n->left = insert(n->left, key);
    else
        n->right = insert(n->right, key);

    n->height = 1 + max(h(n->left), h(n->right));

    int b = balance(n);

    if (b > 1 && key < n->left->data)
        return rightRotate(n);
    if (b < -1 && key > n->right->data)
        return leftRotate(n);
    if (b > 1 && key > n->left->data)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (b < -1 && key < n->right->data)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void inorder(struct node *r)
{
    if (r)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

int main()
{
    struct node *root = NULL;

    int a[6] = {10, 20, 30, 40, 50, 25}; // forces rotations

    for (int i = 0; i < 6; i++)
        root = insert(root, a[i]);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}