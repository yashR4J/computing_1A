// Last Modified by: Yash Raj
// Date last modified: 09/08/2020
// Implementing a Queue

#include <stdlib.h>
#include <stdio.h>
#include  "Queue.h"

struct queue {
	int elements;
	int front;
	int rear;
    int size;
    int maxSize;
};

Queue queueCreate(int maxSize) {

}


void enqueue(Queue q, int item) {
	Link new_node = create_node(item);
	
	if (queue->rear == NULL) {
		q->rear = new_node;
		q->front = q->rear;
	} else {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	
	q->size++;
}
int queueFront(Queue q) {
	int item = ;
	return item;
}
int dequeue(Queue q) {
	int item = q->front->element;
	
	return item;
}
int queueSize(Queue q) {
	return q->size;
}
void queueDestroy(Queue q) {
	
	free(q);
}

/*
struct queue {
    Link front;
    Link rear;
    int size;
};

struct node {
	int item;
	Link next;
};


Queue queueCreate(void) {
	// Create queue
    Queue q = malloc(sizeof(struct queue));
	// Error message if malloc is unsuccessful
    if(q == NULL) {
        fprintf(stderr,"Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}
void enqueue(Queue q, int item) {
	Link new_node = create_node(item);
	
	if (queue->rear == NULL) {
		q->rear = new_node;
		q->front = q->rear;
	} else {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	
	q->size++;
}
int queueFront(Queue q) {
	int item = q->front->element;
	return item;
}
int dequeue(Queue q) {
	int item = q->front->element;
	
	Link free_me = q->front;
	
	if (q->front == q->rear) {
		q->front = NULL;
		q->rear = NULL;
	} else {
		q->front = q->front->next;
	}
	
	free(free_me);
	
	q->size--;
	return item;
}
int queueSize(Queue q) {
	return q->size;
}
void queueDestroy(Queue q) {
	if (q == NULL) {
		return 0;
	}
	free_list(q->front);
	free(q);
}

void free_list(Link head) {
	if (head == NULL) {
		return 0;
	}
	free_list(head->next);
	free(head);
}

*/
