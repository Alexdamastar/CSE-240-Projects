#ifndef slist_h
#define slist_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char* data;
    struct node* next;
};

struct singlylinkedlist
{
    struct node* head;
    struct node* tail;
};

typedef struct singlylinkedlist SList;

//Function Prototypes
void insertHead(SList* list, char* data);
char* removeHead(SList* list);
void insertTail(SList* list, char* data);
char* removeTail(SList* list);

#endif