#include <stdlib.h>
#include <stdio.h>
#include  "Stack.h"

struct stack {
    struct node *top;
    int size;  
};

struct node {
	char item;
	struct node *next;
};


Stack *stackCreate(void) {
   	// Create stack
    Stack *s = malloc(sizeof(struct stack));
	// Error message if malloc is unsuccessful
    if(s == NULL) {
        fprintf(stderr,"Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
    s->size = 0;
    s->top = NULL;
    return s;
}

void stackPush(Stack *s, char item) {
	Node *n = malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Cannot allocate memory for a node.\n");
        exit(EXIT_FAILURE);
    }
    n->item = item;
    n->next = s->top;
    s->top = n;
    s->size++;
}

void stackDestroy(Stack *s) {
	while(s->top != NULL) {
		stackPop(s);
	}
    free(s);
}

int stackSize(Stack *s) {
    return s->size;
}

char stackTop(Stack *s) {
   if(s->size == 0) {
       fprintf(stderr,"Stack empty\n");
       stackDestroy(s);
       exit(EXIT_FAILURE);
   }
   return s->top->item;
}

char stackPop(Stack *s) {
    if(s->top == NULL) {
        printf("Stack is empty, cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    // keep a pointer to the node so we can free it
    Node *n = s->top;
    char item = n->item;
    s->top = s->top->next;
    free(n);
    s->size--;
    return item;
}


