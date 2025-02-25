#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"  // Include the singly linked list header

#define max_name 100

typedef SList Deque;  // Deque is just a singly linked list

void push_back(Deque* q, char* data)
{
    insertTail(q, data);
}

void push_front(Deque* q, char* data)
{
    insertHead(q, data);
}

char* pop_back(Deque* q)
{
    return removeTail(q);
}

char* pop_front(Deque* q)
{
    return removeHead(q);
}

int main(int argc, char* argv[])
{
    //First lets add the file contents into the deque
    if (argc != 2) {
        printf("Usage: %s names.txt\n", argv[0]);
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    Deque q = {NULL, NULL};
    char* name;
    while(1){
        name = (char*)malloc(max_name);
        if (fscanf(fp, "%s", name) == 1)
        {
            push_back(&q, name);
        }
        else{
            free(name);
            break;
        }
    }
    fclose(fp);

    //Now comes the user manipulations
    char choice;
    printf("To scroll through the names type\n");
    printf("f: forwards, b: backwards, q: quit\n");
    int running = 1;
    while (running)
    {
        scanf(" %c", &choice);
        if (choice == 'f')
        {
            char* frontname = pop_front(&q);
            printf("%s\n", frontname);
            push_back(&q, frontname);
        }
        else if (choice == 'b') {
            char* backName = pop_back(&q);
            printf("%s\n", backName);
            push_front(&q, backName);
        }
        else if (choice == 'q') {
            printf("Bye!\n");
            running = 0;
        }
        else {
            printf("Invalid choice. Please enter f, b, or q.\n");
        }
    }
    return 0;
}