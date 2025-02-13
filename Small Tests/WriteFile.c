#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[] = "C:/Users/wwwra/Downloads/VSCode Projects/CSE 240 Projects/Small Tests/file2.txt";
    FILE* fp = NULL;

    fp = fopen(filename, "w");

    if (fp == NULL)
    {
        fprintf(stderr, "Cannot open %s.\n", filename);
        exit(1);
    }

    fputs("Hello file!", fp); //This is what is written into the file
    fclose(fp);
    return 0;
}