#ifndef bst_h
#define bst_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    char* question;
    char* guess;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data, char* question, char* guess);
struct node* insert(struct node* root, int data, char* question, char* guess);
void free_tree(struct node* root);


#endif