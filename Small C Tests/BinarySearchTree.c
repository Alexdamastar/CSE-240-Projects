#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int data)
{
    //create a new node
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    //if tree is empty
    if (root == NULL)
    {
        return temp;
    }

    //search for new node's parent
    struct node* current = root;
    struct node* parent = root;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    //insert node
    if (data < parent->data)
        parent->left = temp;
    else
        parent->right = temp;
    return temp;
}

struct node* search(struct node* root, int data)
{
    struct node* current = root;
    while (current != NULL && data != current->data)
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    return current;
}

struct node* find_minimum(struct node *root)
{
    if (root == NULL || root->left == NULL)
        return root;
    else
        return find_minimum(root->left);
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 70);
    insert(root, 40);

    if (search(root,40) == NULL)
        printf("%d not found\n", 40);
    else
        printf("%d found\n", 40);

    printf("Minumum: %p, num: %d", find_minimum(root), find_minimum(root)->data);
    return 0;
}