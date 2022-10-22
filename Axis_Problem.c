#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the X-Coordinate point\n");
    scanf("%d",&a);
    printf("Enter the Y-Coordinate point\n");
    scanf("%d",&b);
    printf("So you entered the point (%d,%d)\n" , a,b);
    if (a>0&&b>0)
    {
        printf("Your point lies in 1st Quadrant");
    }
    else if (a<0&&b<0)
    {
        printf("Your point lies in 3rd Quadrant");
    }
    else if (a>0&&b<0)
    {
        printf("Your point lies in 4th Quadrant");
    }
    
    else if (a<0&&b>0)
    {
        printf("Your point lies in 2nd Quadrant");
    }
    else{
        printf("The given points are at origin");
    }
    
    return 0;
}