#include <stdio.h>

enum day {sunday, monday, tuesday, wednesday, thursday, friday, saturday};

int main()
{
    enum day today;
    
    today = tuesday;
    today++;

    if (today == tuesday)
        printf("See you next Tuesday!\n");
    else if (today == wednesday)
        printf("See you next Wednesday!\n");
}