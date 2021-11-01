#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(int argc, char * argv[]){
    Queue *q;
    q = queueCreate(3);   
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    printf("%d\n", queueSize(q)); 
    printf("%d\n", queueFront(q));
    printf("%d\n", dequeue(q)); 
    enqueue(q, 13);
    printf("%d\n", dequeue(q)); 
    enqueue(q, 14);
    printf("%d\n", dequeue(q)); 
    printf("%d\n", dequeue(q)); 
    printf("%d\n", dequeue(q)); 
    printf("%d\n", queueSize(q)); 
    enqueue(q, 15);
    printf("%d\n", queueSize(q)); 
    queueDestroy(q);
    return EXIT_SUCCESS;
}
