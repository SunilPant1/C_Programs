#include<stdio.h>

int main(){
    int days,ConY,ConM;
    printf("Enter the days : ");
    scanf("%d",&days);


    ConY = days / 365;//year
    days = days%365;//remaining days after year
    ConM = days / 12;
    days = days%12;


    printf("\n Total Year = %d",ConY);
    printf("\n Months  = %d",ConM);
    printf("\n Days  = %d",days);


    return 0;
}
