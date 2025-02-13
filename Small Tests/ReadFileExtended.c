#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[] = "C:/Users/wwwra/Downloads/VSCode Projects/CSE 240 Projects/Small Tests/file2.txt";
    FILE* fp = NULL;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Cannot open %s.\n", filename);
        exit(1);
    }

    int idx;
    char line[80];
    while (fscanf(fp, "%d %s %s", &idx, line, line) == 3)
        printf("%d\n", idx);

    fclose(fp);
    return 0;
}
