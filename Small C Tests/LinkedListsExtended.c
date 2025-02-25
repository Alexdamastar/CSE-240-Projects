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

    // create a node and insert it at head
    struct node* newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = 3;
    newnode->next = head;
    head = newnode;

    // traverse the list and print the data
    struct node* tmp = head;
    while(tmp != NULL)
    {
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
    return 0;
}