#include<stdio.h>
#include<stdlib.h>
struct pqueue{
    int priority;
    int data;
    struct pqueue*next;
};

void insert(struct pqueue**,int, int);
int delete(struct pqueue**);
void display(struct pqueue*);

int main(){
    struct pqueue *start = NULL;

    insert(&start,4,10);
    insert(&start,14,5);
    insert(&start,3,15);
    insert(&start,1,25);
    insert(&start,2,18);
    display(start);
    printf("\nProcessed %d\n",delete(&start));
    displa y(start);

    return 0;
}

void insert(struct pqueue **pq,int priority, int data){
    
    struct pqueue *p,*temp,*prev;
    p = (struct pqueue *)malloc(sizeof(struct pqueue));
    p->data = data;
    p->next = NULL;
    p->priority = priority;

    if(p == NULL){
        printf("Node is not created");
        return;
    }
    temp = *pq;
    if(*pq == NULL){
        *pq = p;
        return;
    }


    while(temp != NULL && (temp->priority < p->priority)){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        prev->next = p;
        return;
    }
    else if( temp == *pq){
         p->next = *pq;
         *pq = p;
    }
    else{
        prev->next = p;
        p->next = temp;
    }

}

int delete(struct pqueue **ps){

    struct pqueue *temp;

    if(*ps == NULL){
        printf("Empty Queue");
        return 0;
    }

    temp = *ps;
    int x = temp->data;
    *ps = temp->next;
    free(temp);
    return x;
    
}

void display(struct pqueue *ps){
    struct pqueue *temp;
    if(ps == NULL){
        printf("Queue is Empty\n");
        return;
    }
    temp = ps;
    while(temp != NULL){
        printf("%d \t",temp->data);
        temp = temp->next;
    }
}