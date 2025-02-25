#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[] = "C:/Users/wwwra/Downloads/VSCode Projects/CSE 240 Projects/Small Tests/file1.txt";
    FILE* fp = NULL;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Cannot open %s.\n", filename);
        exit(1);
    }

    char c;
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);
    printf("\n");

    fclose(fp);
    return 0;
}
