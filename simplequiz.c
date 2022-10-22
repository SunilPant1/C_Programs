#include <stdio.h>
int main()
{
    int a, b, c, d = 0, e;
    printf("Hey , Welcome to small Quiz app\n");
    printf("Press 1 to start\n");
    scanf("%d", &e);
    if (e == 1)
    {

        for (b = 0; b < 5; b++)
        {
            if (b == 0)
            {
                printf("What is capital city of Nepal?\n");
                printf("1.Pokhara\n2.Kathmandu\n3.Mahendranagar\n");
                printf("Give ans in numbers \n");
                scanf("%d", &c);
                if (c == 2)
                {
                    d = d + 10;
                }
            }
            else if (b == 1)
            {
                printf("How many bits are there in one Byte?\n");
                printf("1.Three\n2.Five\n3.Eight\n");
                printf("Give ans in numbers \n");
                scanf("%d", &c);
                if (c == 3)
                {
                    d = d + 10;
                }
            }
            else if (b == 2)
            {
                printf("What is the collection of 4 bits called?\n");
                printf("1.One Byte\n2.One Nibble\n3.One KiloBye\n");
                printf("Give ans in numbers \n");
                scanf("%d", &c);
                if (c == 2)
                {
                    d = d + 10;
                }
            }
            else if (b == 3)
            {
                printf("What is capital city of USA?\n");
                printf("1.Washington DC\n2.New York\n3.LA\n");
                printf("Give ans in numbers \n");
                scanf("%d", &c);
                if (c == 1)
                {
                    d = d + 10;
                }
            }
            else
            {
                printf("What is capital city of India?\n");
                printf("1.Chennai\n2.Mumbai\n3.Delhi\n");
                printf("Give ans in numbers \n");
                scanf("%d", &c);
                if (c == 3)
                {
                    d = d + 10;
                }
            }
        }
    }
    printf("You scored %d points out of 50 points\n", d);
    return 0;
}