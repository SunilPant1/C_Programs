#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void append(struct node **, int);
void display(struct node *);
void delete_first_node(struct node **);
void delete_last_node(struct node **);
void delete_any_node(struct node **, int);

int main(){
    struct node *start = NULL;
    append(&start,45);
    append(&start,63);
    append(&start,78);
    append(&start,35);
    append(&start,92);
    append(&start,96);
    display(start);
    printf("\n\nChecking .... \n");
    delete_any_node(&start, 45 );
    printf("\n\nAfter deleting \n");
    display(start);
    return 0;
}


void append(struct node **ps,int num){
    struct node *p,*temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = num;
    // printf("%d is added sucessfully \n",p->data); //for displaying the data of node
    p->next = NULL;

    if (*ps == NULL)
    {
        *ps = p;
        return;
    }

    temp = *ps;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = p;
}

void display(struct node *p){
    if (p == NULL)
    {
        printf("Node is not created\n");
        return;
    }
    while(p != NULL){
    printf("%d is added sucessfully\n",p->data);
    p = p->next;
    }
    
}

void delete_first_node(struct node **ps){
    struct node *temp = NULL;
    if(*ps == NULL){
        printf("Empty Node\n");
        return;
    }

    // deleting if there is one node but there is no use of this 
    // if((*ps)->next == NULL){
    //     printf("%d is deleted now linked list is empty\n",(*ps)->data);
    //     free(*ps);
    //     *ps = NULL;
    //     return;
    // }
    printf("%d is deleted\n",(*ps)->data);
    temp = (*ps);
    (*ps) = (*ps)->next;
    free(temp);
    return;
}


void delete_last_node(struct node **ps){
    struct node *temp,*prev;
    if(*ps == NULL){
        printf("Empty Node\n");
        return;
    }

    temp = *ps;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
}

void delete_any_node(struct node **ps, int num){
    struct node *temp,*prev,*next;
    
    //Case 1: IF Linked List is Empty
    if(*ps == NULL){
        printf("Empty Node\n");
        return;
    }

    //Case 2: IF the node is first
    // if( (*ps)->next == NULL ){
    //     free(ps);
    //     *ps == NULL;
    //     return;
    // }

    //for first node
    temp = *ps;
    if( (*ps)->data == num ){
        *ps =temp->next;
        free(temp);
        return;
    }

    //Case 3: If the node is last
    // temp = *ps;
    // while(temp->next != NULL){
    //     prev = temp;
    //     temp = temp->next;
    // }
    // free(temp);
    // prev->next = NULL;

    //Case 4: if there is no item in the list (my technique )
    // temp  = *ps;
    while(temp->data != num){
        prev = temp;
        temp = temp->next;
        if(temp->next == NULL){
            printf("Element not fouund\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);

    // while(temp != NULL && temp->data != num){
    //     prev =temp;
    //     temp = temp->next;
    // }

    // if(temp == NULL){
    //     printf("List is empty\n");
    // }
    // else{
    //     prev->next = temp->next;
    //     free(temp);
    // }
    
}