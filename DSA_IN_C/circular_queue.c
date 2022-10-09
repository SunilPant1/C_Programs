#include<stdio.h>

struct CQueue{
    int arr[5];
    int front,rear;
};

void insert(struct CQueue *, int num);
int delete(struct CQueue *);

int main(){
    struct CQueue c;
    c.rear = -1;
    c.front = -1;
    printf("Insert the element : ");
    insert(&c,45);
    insert(&c,15);
    insert(&c,85);
    
    delete(&c);
    delete(&c);
    delete(&c);
    delete(&c);
    
    return 0;
}

void insert(struct CQueue *q, int num){
    

    // if ((q->rear+1 == q->front) || (q->rear ==4 && q->front ==0))
    if ((q->rear+1)% (sizeof(q->arr)/sizeof(int)) == q->front)
    {
        printf("\nQueue is overflow");
        return;
    }

    if (q->rear == 4)
        q->rear ==0;
    else
        q->rear += 1;
    // q->rear = (q->rear+1)%(sizeof(q->arr)/sizeof(int));

    q->arr[q->rear] = num;
    printf("\n%d is inserted succusfully.",num);

    if(q->front == -1)
        q->front = 0;
        
}

int delete(struct CQueue *q){
    int x;
    if(q->front == -1){
        printf("\nUnderflow");
        return 0;
    }

    x= q->arr[q->front];

    if(q->front == q->rear)
        q->front = q->rear = -1;
    // else if(q->front == 4)
    //     q->front = 0;
    // else q->front += 1;
    else q->front = (q->front+1)%(sizeof(q->arr)/sizeof(int));
    printf("\n%d is deleted",x);
    return x;
}