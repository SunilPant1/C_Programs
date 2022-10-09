#include<stdio.h>
#include<stdlib.h>
struct BST{
    struct BST *left;
    int data;
    struct BST *right;
};

void append(struct BST **,int );

int main(){
    struct BST *root = NULL;
    append(&root,45);
    append(&root,96);
    append(&root,213);
    append(&root,78);
    
    return 0;
}

void append(struct BST ** pr,int num){
    struct BST *p,*temp,*prev;
    
    p = (struct BST *)malloc(sizeof(struct BST));

    //if memory is not allocated to the new node
    if(p == NULL){
        printf("Insufficient memory \n");
        return;
    }

    p->data = num;
    p->left = p->right = NULL;
    //for inserting first data in a node
    if(*pr == NULL){
        *pr = p;
        return;
    }

    temp = *pr;
    
   

    while(temp != NULL){
        prev  = temp;
        if(temp->data > num)
            temp = temp->left;
        else
            temp= temp->right;
    }

    if(prev->data>num)
        prev->left = p;
    else
        prev->right = p;
        
}
