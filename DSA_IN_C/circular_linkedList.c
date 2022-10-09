#include<stdio.h>
#include<stdlib.h>

struct cnode{
    int data;
    struct cnode *next;
};

void append(struct cnode **, int );
void display(struct cnode *);
void delete_first_node(struct cnode **);
void delete_last_node(struct cnode **);
void delete_any_node(struct cnode **, int);

int main(){
    struct cnode *start = NULL;

    append(&start,25);
    append(&start,39);
    append(&start,48);
    append(&start,92);
    append(&start,73);
    display(start);

    printf("\n\nChecking ...\n\n");
    delete_any_node(&start,25);
    printf("\n\nAfter deleting \n");
    display(start);
    return 0;
}

void append(struct cnode **ps,int num){
    struct cnode *p,*temp;

    p = (struct cnode *)malloc(sizeof(struct cnode ));
    p->data = num;
    
    if(*ps == NULL){
        *ps = p;
        p->next = p;
        return;
    }

    temp = *ps;
    while(temp->next != *ps ){
        temp = temp->next;
    }
    temp->next = p;
    p->next = *ps;
}

void display(struct cnode *p){
    struct cnode *temp;
     if (p == NULL)
    {
        printf("Node is not created\n");
        return;
    }
    temp = p;
    // while (p != NULL) //(my technique)
    // {
    //     printf("%d is added sucessfully\n", p->data);
    //     p = p->next;
    //     if(p == temp)
    //         break;
    // }

    do
    {
        printf("%d is added sucessfully\n",temp->data);
        temp = temp->next;
    } while (temp!=p);
    
}

void delete_first_node(struct cnode **ps){
    struct cnode *temp;
    // struct cnode *prev; //we dont need this in another technique
    //when list is empty
    if(*ps == NULL){
        printf("Node is Empty\n");
        return;
    }

    temp = *ps;
    // while element is one
    if( temp->next == *ps){
        free(temp);
        *ps = NULL;
        return;
    }

    //My technique
    // do{
    //     prev = temp;
    //     temp = temp->next;

    // }while(temp != *ps);
    
    // if(temp == *ps){
    //     prev->next = temp->next;
    //     *ps = temp->next;
    //     free(temp);
    // }

    while(temp->next != *ps){
        temp = temp->next;
    }
    *ps = (*ps)->next;
    free(temp->next);
    temp->next = *ps;
}

void delete_last_node(struct cnode **ps){
    struct cnode *temp,*prev;
    //when list is empty
    if(*ps == NULL){
        printf("Node is Empty\n");
        return;
    }

    // while element is one
    if( (*ps)->next == *ps){
        free(*ps);
        *ps = NULL;
        return;
    }

    temp = *ps;
    while(temp->next != *ps){
        prev = temp;
        temp = temp->next;
    }
     free(temp);
     prev->next = *ps;


}


void delete_any_node(struct cnode **ps, int num){
     struct cnode *prev, *temp;
     //when list is empty
    if(*ps == NULL){
        printf("Node is Empty\n");
        return;
    }

    temp = *ps;
    // if( (*ps)->data == num){
    //         *ps  = temp->next;
    //         free(temp);
            
    //         return;
    // }



    do{
        prev = temp;
        temp = temp->next;
    }while( (temp->data != num) && (temp != *ps));
    
    if( (*ps)->data == num){
        *ps  = (*ps)->next;
        free(temp);
        prev->next = *ps;
        return;
    }

    if(temp == *ps){
        
        printf("List is empty\n");
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}
