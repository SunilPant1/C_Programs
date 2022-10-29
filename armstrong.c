//Program to find armstrong number using C
#include <stdio.h>
int main()
{
    int a, b, c = 0, d, e;
    printf("Enter your number\n");
    scanf("%d", &a);
    e = a;
    while (a != 0)
    {
        b = a % 10;
        d = b * b * b;
        c = c + d;
        a = a / 10;
    }

    if (e == c)
    {
        printf("The number is armstrong\n");
    }
    else
    {
        printf("The number is not armstrong");
    }

    return 0;
}
