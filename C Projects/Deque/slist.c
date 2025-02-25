#include "slist.h"

void insertHead(SList* list, char* data)
{
    struct node* newNode; 
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = list->head;

    //adjust pointers
    list->head = newNode;
    if(list->tail == NULL)
        list->tail = newNode;

}

char* removeHead(SList* list)
{
    if (list->head == NULL)
        return NULL;
    struct node* temp;
    temp = list->head;
    char* data = temp->data;
    list->head = temp->next;
    //check if the list is empty after removal
    if (list->head == NULL)
        list->tail = NULL;
    free(temp); //removes the memory associated with temp, preventing memory leaks
    return data;
}

void insertTail(SList* list, char* data)
{
    struct node* newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    //adjust pointers
    if(list->tail == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

char* removeTail(SList* list)
{
    //if the list has no nodes
    if (list->head == NULL)
    {
        return NULL;
    }
    struct node* current;
    current = list->head;
    char* data;
    //if the list is only one node
    if (list->head == list->tail){
        data = current->data;
        list->head = NULL;
        list->tail = NULL;
        free(current);
    }
    else{
        //get to second to last node
        while(current->next != list->tail)
        {
            current = current->next;
        }
        data = list->tail->data;
        free(list->tail); //remove the tail from memory
        list->tail = current;
        current->next = NULL;
    }
    return data;
}