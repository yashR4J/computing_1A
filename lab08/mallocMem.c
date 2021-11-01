// Mallocing Memory
// Last Modified by : Yash Raj
// Date Last Modified : 21/07/2020

#include <stdio.h>
#include <stdlib.h>

int *createInteger(int value1);
double *createDouble(double value2);

int main(int argc, char* argv[]) {

    int *heapInteger = createInteger(3);
    double *heapDouble = createDouble(4.0);

    printf("heapInteger: %d\n", *heapInteger);
    printf("heapDouble: %lf\n", *heapDouble);

    // TODO BELOW
    //  part 3: don't forget to free your memory and set their values
    //          to NULL
    // TODO ABOVE
    
    free(heapInteger);
    heapInteger = NULL;
    free(heapDouble);
    heapDouble = NULL;
    
    return EXIT_SUCCESS;
}

// TODO BELOW
//  part 1: Complete the "createInteger" function that uses
//          malloc to store a new integer on the heap
int *createInteger(int value1) {

	int *a = malloc(sizeof(int)); // Should this have (int *) at the 
								  // beginning? 
	
	if (a == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	*a = value1;
	
    return a; // You don't want to return null
}
// TODO ABOVE

// TODO BELOW
//  part 2: Complete the "createDouble" function that uses
//          malloc to store a new integer on the heap
double *createDouble(double value2) {

	double *b = malloc(sizeof(double));
	
	if (b == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	*b = value2;
	
    return b; // You don't want to return null
}
// TODO ABOVE
