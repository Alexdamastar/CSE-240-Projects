#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    else
        return n* factorial(n-1);
}
int main()
{
    int n;
    printf("Give us the factorial number: ");
    scanf("%d", n);
    factorial(n);
}