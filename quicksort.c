#include<stdio.h>
void Quick_Sort(int [],int , int );
int partation(int [],int,int);
void swap(int*, int* );


 int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the value of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    } 
    
    printf("\nBefore Sort : \n\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    } 

    int left = 0;
    int right = n-1;

    Quick_Sort(arr,left,right);

    printf("\nAfter Sort : \n\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    } 
    return 0;
}

void Quick_Sort(int arr[],int left , int right ){
    int midpart;
    if(left < right){
        midpart = partation(arr,left,right);
        Quick_Sort(arr,left, midpart);
        Quick_Sort(arr,midpart+1,right);
    }
}

int partation(int arr[25],int left, int right){
    int i = left, j = right, temp, pivot = left;
    while(i<j){
        while(arr[i]<=arr[pivot]) i++;  
        while(arr[j]>arr[pivot]) j--;
        if(i< j )  swap(&arr[i],&arr[j]);
    }
    swap(&arr[pivot],&arr[j]);
    return j;
}

void swap(int* arri, int* arrj){
    int temp;
    temp = *arri;
    *arri = *arrj;
    *arrj = temp;
}

