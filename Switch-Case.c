//Program using switch case
#include <stdio.h>
int main()
{
    printf("Enter your preferred number\n");
    int age ;
    scanf("%d" , &age);
    switch (age)
    {
    case 18:
        printf("You are mature enough");
        break;

     case 17 :
        printf("Just one year more");
        break;

    case 19:
        printf("You are perfectly ready");
        break;

    
    default:
        printf("Hey bro program has ended");
      
    }
    return 0;
}
