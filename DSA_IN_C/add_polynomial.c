#include<stdio.h>
#include<stdlib.h>
struct Poly{
    int cofficient;
    int exponential;
    struct Poly *next;
};

void append(struct Poly **, int, int);
void display(struct Poly *);
void add(struct Poly *, struct Poly * , struct Poly **);

int main(){
    struct Poly *first,*second,*sum;
    sum = first = second = NULL;
    append(&first,3,2);
    append(&first,2,4);
    append(&first,7,6);
    append(&first,9,9);
    append(&second,1,1);
    append(&second,3,3);
    append(&second,2,6);
    append(&second,3,8);

    display(first);
    display(second);
    add(first,second,&sum);
    display(sum);
    return 0;
}

void append(struct Poly **pnum, int cofficient, int exponential){
    struct Poly *p,*temp;

    p = (struct Poly *)malloc(sizeof(struct Poly));
    //for the first node
    if(*pnum == NULL){
        *pnum = p;
        (*pnum)->cofficient = cofficient;
        (*pnum)->exponential = exponential;
        (*pnum)->next = NULL;
        return;
    }
    temp = *pnum;
    while(temp->next != NULL){
        temp = temp->next;
    }

    p->cofficient = cofficient;
    p->exponential = exponential;
    p->next =NULL;
    temp->next = p;
}

void display(struct Poly *p){
    if(p == NULL){
        printf("List is Empty\n");
        return;
    }
    
    while(p != NULL){
        printf("%dx^%d \t",p->cofficient,p->exponential);
        p = p->next;
    }
    printf("\n");
}


void add(struct Poly *first, struct Poly *second , struct Poly **ps){
    struct Poly *p,*temp,*q;
    if( first == NULL && second == NULL ){
        printf("Adding is not possible\n");
        return;
    }

    while(first != NULL && second != NULL){
        p = (struct Poly *)malloc(sizeof(struct Poly));
        p->next = NULL;

        //if the node is first node of add node then
        if(*ps ==NULL)
            *ps = p;
        else
            temp->next = p;

        temp = p;

        if(first->exponential < second->exponential){
            temp->cofficient = first->cofficient;
            temp->exponential = first->exponential;
            first = first->next;
        }
        else if(second->exponential < first->exponential)
        {
            temp->cofficient = second->cofficient;
            temp->exponential = second->exponential;
            second = second->next;
        }
        else{
            temp->cofficient = first->cofficient + second->cofficient;
            temp->exponential = first->exponential;
            first = first->next;
            second = second->next;
        }
    }
    if(first != NULL) 
        q = first;
    else 
        q = second;


    while(q != NULL){
        p = (struct Poly *)malloc(sizeof(struct Poly));
        p->cofficient = q->cofficient;
        p->exponential = q->exponential;
        p->next = NULL;
        //if the one of the node is not created between first and second
        if(*ps == NULL) 
            *ps = p;
        else
            temp->next = p;

        temp = p;
        q = q->next;
    
    }


}
