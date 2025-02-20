#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{
    struct node* head = NULL;
    struct node* tail = NULL;

    // create a node and insert it at head
    head = malloc(sizeof(struct node));
    head->data = 7;
    head->next = NULL;
    tail = head;
}