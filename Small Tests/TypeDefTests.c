#include <stdio.h>
#include <string.h>

typedef struct 
{
    char first_name[30];
    char last_name[30];
    int final_grade;   
} student;

int main()
{
    student s1;

    strcpy(s1.first_name, "Jack");
    strcpy(s1.last_name, "Black");
    s1.final_grade = 88;

    printf("Name: %s %s \n", s1.first_name, s1.last_name);
    printf("Final Grade: %i", s1.final_grade);
}
