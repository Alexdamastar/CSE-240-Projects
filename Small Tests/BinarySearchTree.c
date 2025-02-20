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
    return 0;
}