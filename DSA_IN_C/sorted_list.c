#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insert(struct node **, int);
void display(struct node *);

int main()
{
    struct node *start = NULL;
    insert(&start, 8);
    insert(&start, 6);
    insert(&start, 4);
    insert(&start, 14);
    insert(&start, 25);
    insert(&start, 2);
    insert(&start, 28);
    insert(&start, 10);
    display(start);

    return 0;
}
void insert(struct node **ps, int num)
{
    struct node *p, *temp, *prev;

    p = (struct node *)malloc(sizeof(struct node));
    p->data = num;
    p->next = NULL;

    //Inserting first node
    if (*ps == NULL)
    {
        *ps = p;
        return;
    }

    temp = *ps;
    if ((*ps)->data > num)
    {
        *ps = p;
        (*ps)->next = temp;
        return;
    }

    while ( (num > temp->data) && temp->next != NULL )
    {
        prev =temp;
        temp = temp->next;
    }
    if(num < temp->data){
        prev->next = p;
        p->next = temp;
        return;
    }

    
    temp->next = p;
}

void display(struct node *p)
{
    if (p == NULL)
    {
        printf("Node is not created\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d is added sucessfully\n", p->data);
        p = p->next;
    }
}