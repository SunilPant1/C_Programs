#include<stdio.h>
void insert_heep(int [],int , int);
int delete_root_node(int [],int );

void swap(int arr[],int i, int j){
    int temp  = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    int arr[8];
    int i,x;

    for ( i = 1; i <= 7; i++)
    {
        printf("\nEnter the element : ");
        scanf("%d",&x);
        insert_heep(arr,x,i);
    }

    printf("Heep style is : \n");
    for ( i = 1; i <= 7; i++) {
        printf("%d \t",arr[i]);
    }
    printf("\n");

    for (i = 7;i >=1;i--)
    {
        arr[i] = delete_root_node(arr,i);        
    }
    

    for ( i = 1; i <=  7; i++) printf("%d \t",arr[i]);
    
    return 0;
}

void insert_heep(int arr[],int num, int last_index){
    int parent;   
    while(last_index > 1){
        parent = last_index/2;
        if(arr[parent] >= num){
            arr[last_index] = num;
            return;
        }
        arr[last_index] = arr[parent];
        last_index = parent;
    }
    arr[1] = num;
}


int delete_root_node(int arr[],int last_node){

    int x = arr[1];
    arr[1] = arr[last_node];
    last_node -= 1;
    int i = 1;
    int left = 2*i;
    

    while(left<=last_node){
        
        if(left<last_node){
            if(arr[left+1] > arr[left] )
                left += 1;
        }
        
       
       

        if(arr[i] < arr[left]){
        //    swap(arr,i,larger);
            int temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp; 
            i = left;

            left = 2*left;
        }
        else break;
    }
    return x;
}
