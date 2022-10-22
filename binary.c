// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int a[10], n, i;
//     // system ("cls");
//     printf("Enter the number to convert: ");
//     scanf("%d", &n);
//     for (i = 0; n > 0; i++)
//     {
//         a[i] = n % 2;
//         n = n / 2;
//     }
//     printf("\nBinary of Given Number is=");
//     for (i = i - 1; i >= 0; i--)
//     {
//         printf("%d", a[i]);
//     }
//     return 0;
// }
#include <stdio.h>
int main()
{
    int a, b, c[100];
    printf("Enter the number to convert into binary:\n");
    scanf("%d", &a);
    for (b = 0; a > 0; b++)
    {
        c[b] = a % 2;
        a = a / 2;
    }

    printf("\n The value of b is = %d", b);
    printf("The binary number is:\n");
    for (b = b - 1; b >= 0; b--)
    {
        printf("%d", c[b]);
    }
    return 0;
}