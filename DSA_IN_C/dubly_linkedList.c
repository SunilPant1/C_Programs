#include<stdio.h>
#include<stdlib.h>

struct doubly{
    struct doubly *prev;
    int data;
    struct doubly *next;
};


void append(struct doubly **, int );
void display(struct doubly *);
void delete_first_node(struct doubly **);
void delete_last_node(struct doubly **);
void delete_any_node(struct doubly **, int);

int main(){
    struct doubly *start = NULL;

    append(&start,25);
    append(&start,39);
    append(&start,48);
    append(&start,92);
    append(&start,73);
    display(start);
    delete_any_node(&start,25);
    printf("\n\n");
    display(start);


    
    return 0;
}

void append(struct doubly **ps, int num ){
    struct doubly *temp,*p;

    p = (struct doubly *)malloc(sizeof(struct doubly));
    p->data = num;
    p->next = NULL;

    if (*ps == NULL)
    {
        p->prev = NULL;
        *ps = p;
        return;
    }

    temp = *ps;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
    
}

void display(struct doubly *p){
    if(p == NULL){
        printf("List is Emply\n");
        return;
    }

    while (p != NULL)
    {
        printf("%d is added sucessfully\n", p->data);
        p = p->next;
    }
}


void delete_first_node(struct doubly **ps){
    struct doubly *temp;
    //If there are no nodes
    if(*ps == NULL){
        printf("Node are not created\n");
        return;
    }

    temp = *ps;
    //we can handel both situation in one code
    //if there is only one node
    // if(temp->next == NULL){
    //     free(temp);
    //     *ps = NULL;
    //     return;
    // }

    // //if there are multiple nodes

    // *ps = (*ps)->next;
    // (*ps)->prev = NULL;
    // free(temp);

    *ps = (*ps)->next;
    if(*ps != NULL)
        (*ps)->prev = NULL;
    free(temp);
}

void delete_last_node(struct doubly **ps){
    struct doubly *temp;
    // struct doubly *prev;
    //If there are no nodes
    if(*ps == NULL){
        printf("Node are not created\n");
        return;
    }

    temp = *ps;
    //if there is only one node
    if(temp->next == NULL){
        free(temp);
        *ps = NULL;
        return;
    }

    //Using two pointer "temp" and "prev"
    // while(temp->next != NULL){
    //     prev = temp;
    //     temp = temp->next;
    // }

    // free(temp);
    // prev->next = NULL;

    // //Using one opinter only "temp"
    // while(temp->next->next != NULL )
    //     temp = temp->next;
    
    // free(temp->next);
    // temp->next = NULL;

    // or

    while(temp->next != NULL)
        temp = temp->next;
    
    temp->prev->next = NULL;
    free(temp);

}

void delete_any_node(struct doubly **ps, int num){
     struct doubly *temp;
     //If there are no nodes
    if(*ps == NULL){
        printf("Node are not created\n");
        return;
    }

    temp = *ps;
    if( (*ps)->data == num ){
        (*ps) = (*ps)->next;
        free(temp);
        return;
    }

    while( temp != NULL && temp->data != num)
        temp = temp->next;
    
    if(temp == NULL){
        printf("Element not found on list");
        return;
    }
    else{
        temp->prev->next = temp->next;
        free(temp);
    }
}
