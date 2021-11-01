#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(int argc, char * argv[]){
    Queue *q;
    q = queueCreate(100);   
    
    printf("%d\n", queueSize(q)); // prints 0    
    printf("%d\n", dequeue(q));    
    
    queueDestroy(q);
    return EXIT_SUCCESS;
}
