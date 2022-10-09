 #include<stdio.h>
void Insertion_sort(int [],int );


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

    Insertion_sort(arr,n);

    printf("\nAfter Sort : \n\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    } 
    return 0;
}

void Insertion_sort(int arr[],int n ){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j > 0; j--)
        {
            if(arr[j] < arr[j-1]){
                int temp  = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else
                break;
        }
    }
}
