#include <stdio.h>
#include <stdlib.h>

struct person
{
    char fname[20];
    char lname[20];
    int id;
};

int main()
{
    FILE* fp = fopen("C:/Users/wwwra/Downloads/VSCode Projects/CSE 240 Projects/Small Tests/students.bin", "wb");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    struct person s1 = {"Jack", "Black", 5};

    size_t num = fwrite(&s1, sizeof(struct person), 1, fp);
    if (num == 1)
        printf("struct written succesffully \n");
    else
        printf("Error Writing to File!\n");

    fclose(fp);
    return 0;
}