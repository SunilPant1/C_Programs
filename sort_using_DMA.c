//WAP to sort a array using DMA
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int n, i, j, temp;
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the size of Array : ");
    scanf("%d", &n);

    //Input
    printf("Enter the element of Array : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    //Sorting
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    //Output
    printf("\nYour Sorted array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    free(ptr);
    return 0;
}