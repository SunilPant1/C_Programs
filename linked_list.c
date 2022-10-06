//Single linked list
#include <stdlib.h>
#include <stdio.h>

typedef struct sNode {
	struct sNode *next;
	void *data;
} node;


node *start(void *value) {
	node *n = calloc(1,sizeof(node));
	n->data = value;
	n->next = NULL;
}

void push(node *list, void* value) {
	while(list->next != NULL) {
		list = list->next;
	}

	node *n = calloc(1,sizeof(node));
	n->data = value;
	n->next = NULL;
	list->next = n;
}

void pop(node *list) {
	if(list->next == NULL) {
		list->next = NULL;
		return;
	}
	while(list->next->next != NULL) {
		list = list->next;
	}
	list->next = NULL;
}


void printll(node *list) {
	while(list->next != NULL) { \
		list = list->next;
		printf("Node %p\nHas Next? %s\n",list, list->next == NULL ? "No" : "Yes");
		
	}
}

int main(void) {
	int val1 = 1;
	node *startNode = start((void*)&val1);

	int val2 = 2;
	int val3 = 3;
	push(startNode,(void*)&val2);

	push(startNode,(void*)&val3);
	
	printll(startNode);

	return 0;
}
