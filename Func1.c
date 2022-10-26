#include <stdio.h>
void displayname(char name[])
{
    printf("His name is %s", name);
}
int math(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    else
    {
        return (num * math(num - 1));
    }
}

int main()
{
    int num = 5;
    math(num);
    printf("The factorial of 5 is %d", math(num));
}