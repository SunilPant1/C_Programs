#include<stdio.h>
int main(){
    int n,i,flag=0;
    printf("Enter a number: \n");
    scanf("%d",&n);
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            flag=flag+1;
        }
    }
    if(flag==0){
        printf("%d is a Prime number",n);
    }
    else{
        printf("%d is not a Prime number",n);
    }
    return 0;
}
