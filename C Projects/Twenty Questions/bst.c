#include "bst.h"

struct node* create_node(int data, char* question, char* guess)
{
    struct node* newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->question = question;
    newNode->guess = guess;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data, char* question, char* guess)
{
    if (root == NULL)
    {
        return create_node(data, question, guess);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data, question, guess);
    }
    else
    {
        root->right = insert(root->right, data, question, guess);
    }
    return root;
}

void free_tree(struct node* root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->question);
    free(root->guess);
    free(root);
}
