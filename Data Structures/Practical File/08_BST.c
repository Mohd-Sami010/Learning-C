#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
        return create(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *min(struct node *r)
{
    while (r->left)
        r = r->left;
    return r;
}

struct node *del(struct node *root, int x)
{
    if (root == NULL)
        return root;
    if (x < root->data)
        root->left = del(root->left, x);
    else if (x > root->data)
        root->right = del(root->right, x);
    else
    {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        struct node *t = min(root->right);
        root->data = t->data;
        root->right = del(root->right, t->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);

    inorder(root);
    printf("\n");

    root = del(root, 3);
    inorder(root);

    return 0;
}