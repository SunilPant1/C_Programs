#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n;
    printf("Enter the value of N : ");
    scanf("%d", &n);

    int *ptr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of array[ %d ] : ", i + 1);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", (ptr[i]));
    }

    free(ptr);
    return 0;
}