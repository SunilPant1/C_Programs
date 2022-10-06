//WAP to read an array of integer using DMA and
//display the maximum and minimum value
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, max, min;
    int *ptr;
    printf("Enter no. of element in your array : ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));

    //For Input
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the %d element : ", i);
        scanf("%d", ptr + i);
    }

    //Finding Maximum and minimum
    max = *ptr;
    min = *ptr;

    for (i = 0; i < n; i++)
    {
        if (max < *(ptr + i))
            max = *(ptr + i);
        if (min > *(ptr + i))
            min = *(ptr + i);
    }
    free(ptr);

    //For Output
    printf("\nMaximum Element : %d", max);
    printf("\nMinimum Element : %d", min);

    return 0;
}
