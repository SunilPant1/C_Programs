#include<stdio.h>
#include<stdlib.h>


struct BST{
    struct BST *left;
    int data;
    struct BST *right;
    int flag;
};

struct Stack {
    struct BST *arr[20];
    int tos;
};

void push(struct Stack *,struct BST *);
struct BST * pop(struct Stack *);
void append(struct BST **,int );
void preorder(struct BST *);
void inorder(struct BST *);
void postorder(struct BST *);
int search_node(struct BST *, int , struct BST **, struct BST **);
void delete_node(struct BST **,int);

int main(){
    struct BST *root = NULL;
    append(&root,45);
    append(&root,32);
    append(&root,37);
    append(&root,31);
    append(&root,96);
    append(&root,213);
    // append(&root,78);
    preorder(root);
    delete_node(&root,96);
    preorder(root);
    return 0;
}

int search_node(struct BST *root,int num,struct BST **child,struct BST **parent){
    struct BST *q=NULL;
    while(root != NULL){
        if(root->data == num){
            *child = root;
            *parent = q;
            return 1;
        }      
        q = root;

        if(root->data > num)
            root = root->left;
        else
            root = root->right;
    }   
    return 0;
}

void delete_node(struct BST **pr,int num){
    struct BST *child, *parent,*q;


    if(*pr == NULL){
        printf("Tree is Empty");
        return;
    }

    int result = search_node(*pr,num,&child,&parent);
    //if searched element is not found
    if(result == 0){
        printf("Element not found \n");
        return;
    }

    //if deleted note has 2 children
    if(child->left != NULL && child->right != NULL){
        q = child->right;
        parent = child;
        while( q->left != NULL){
            parent = q;
            q = q->left;
        }

        child->data = q->data;
        child = q;
    }

    //if deleted node has no child
    if(child->left == NULL && child->right == NULL){

        if(parent  == NULL)
            *pr = NULL;
        if(parent->left == child)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(child);
    }

    //if deleted node has only left child
    if(child->left != NULL && child->right == NULL){
        if(parent == NULL)
            child = child->left;
        else if(parent->left == child)
            parent->left = child->left;
        else
            parent->right = child->left;
        free(child);
    }

    //if deleted node has only right child
    if(child->left == NULL && child->right != NULL){
        if(parent == NULL)
            child = child->right;
        else if(parent->left == child)
            parent->left = child->right;
        else
            parent->right = child->right;
        free(child);
    }

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

void preorder(struct BST *p){
    struct Stack s;
    if(p == NULL){
        printf("Empty Tree \n");
        return;
    }

    s.tos = -1;
    push(&s,p);
    //checking right node and push to stack if exist and go to left node
    while(s.tos !=  -1){
        p = pop(&s);
        while(p!= NULL){
            //printing current node
            printf("%d \t",p->data);
            //checking if right node is empty or not
            if(p->right != NULL){
                push(&s,p->right); //pushing to the stack
            }
            //moving toward left
            p= p->left;
        }
    }

    printf("\n");
}


void push(struct Stack *p,struct BST *num){
    
    if(p->tos == 19){
        printf("Stack overflow\n");
        return;
    }
    p->arr[++p->tos] = num;
}

struct BST * pop(struct Stack *p){
    struct BST * parr;
    if(p->tos == -1){
        printf("Underflow\n");
        return NULL;
    }
    parr = p->arr[p->tos--];
    return parr;
}

void inorder(struct BST *p){

    if(p == NULL){
        printf("EMPTY TREE\n");
        return;
    }

    struct Stack s;
    s.tos = -1;

   push_node:
        while(p!=NULL){
            push(&s,p);
            p=p->left;
        }

        p= pop(&s);

        while(p!=NULL){
            printf("%d \t",p->data);

            if(p->right !=NULL){
                p = p->right;
                goto push_node;
            }

            p = pop(&s);
        }
}

void postorder(struct BST *p){

    if(p == NULL){
        printf("Tree is empty\n");
        return;
    }

    struct Stack s;
    s.tos = -1;


    push_back:
    while(p!= NULL){
        p->flag = 1;
        push(&s,p);
        if(p->right != NULL){
            p->right->flag = -1;
            push(&s,p->right);
        }
        p= p->left;
    }

    p = pop(&s);

    while(p != NULL){
        if(p->flag == 1)
            printf("%d , ",p->data);
        else
            goto push_back;
        p = pop(&s);
    }
}


