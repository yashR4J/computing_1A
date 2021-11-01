#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(int argc, char * argv[]){
    Queue *q;
    q = queueCreate(100);   
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    printf("%d\n", queueSize(q)); // prints 3
    printf("%d\n", queueFront(q)); // prints 10
    printf("%d\n", dequeue(q)); // prints 10
    printf("%d\n", dequeue(q)); // prints 11
    printf("%d\n", dequeue(q)); // prints 12
    queueDestroy(q);
    return EXIT_SUCCESS;
}
