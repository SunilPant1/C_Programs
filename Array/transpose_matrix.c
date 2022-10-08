#include <stdio.h>
#define r 3
#define c 2
int main()
{
    int a[r][c], b[r][c], i, j;

    printf("\nEnter the matrix : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nBefore Transpose\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            b[j][i] = a[i][j];
        }
    }
    printf("\nAfter Transpose\n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}
