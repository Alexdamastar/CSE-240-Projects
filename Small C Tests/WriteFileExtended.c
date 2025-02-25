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
    for (int i = 0; i < 5; i++)
        fprintf(fp, "%d Hello file!\n", i);
    fclose(fp);
    return 0;
}