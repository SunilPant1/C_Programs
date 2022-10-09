 #include<stdio.h>
void Selection_sort(int [],int );


 int main(){
 int n,x;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
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

    Selection_sort(arr,n);

    printf("\nAfter Sort : \n\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    } 
    return 0;
}

void Selection_sort(int arr[],int n ){
    for (int i = 0; i < n-1; i++)
    {
        int min = i;

        for (int j = i+1; j < n; j++)
        {
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        

        int temp  = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

    }
    
}
