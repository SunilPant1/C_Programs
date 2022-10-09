
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int arr[5];
    int rear;  // insert data in queue
    int front;  //delete data in queue
};

void enqueue(struct Queue *, int );
int dequeue(struct Queue *);

int main(){

    struct Queue q;
    q.rear = -1;
    q.front = 0;
    printf("Insert a element in a queue : \n");
    enqueue(&q,25);
    enqueue(&q,34);
    enqueue(&q,85);
    enqueue(&q,125);
    enqueue(&q,452);
    // enqueue(&q,45);
    printf("%d is deleted sucessfully\n",dequeue(&q));
    printf("%d is deleted sucessfully\n",dequeue(&q));
    printf("%d is deleted sucessfully\n",dequeue(&q));
    printf("%d is deleted sucessfully\n",dequeue(&q));
    printf("%d is deleted sucessfully\n",dequeue(&q));
    printf("%d is deleted sucessfully\n",dequeue(&q));
    return 0;
}


void enqueue(struct Queue *p, int num){
    if(p->rear == 4){
        printf("Queue Overflow \n");
        return;
    }

    p->rear += 1;
    p->arr[p->rear] = num;
    printf("%d inserted Sucessfully!!!\n",num);
}

int dequeue(struct Queue *p){
    if(p->front > p->rear){
        printf("Queue underflow\n");
        exit(1);
    }
    return p->arr[p->front++];
}