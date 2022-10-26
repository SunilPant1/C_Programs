#include <stdio.h>
int main()
{
    int a = 10;
    int *add = &a;
    printf("The num is %d\n", a);
    printf("The num using pointer is also %d\n", *add);
    printf("The address of num using pointer is also %x\n", add);
    printf("The address of pointer using pointer is also %x\n", &add);

    return 0;
}