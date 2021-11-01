// Author: Yash Raj (z5317349)
// Date Modified: 02/07/2020
/* Reads 10 integers from standard input, prints the odd numbers on one line, then prints the even numbers on one line */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

int main (void) {

	int array[SIZE] = {0}, odd[SIZE] = {0}, even[SIZE] = {0};
	int i;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &array[i]);
	}

	for (i = 0; i < SIZE; i++) {
		if (array[i] % 2 == 0) {
			even[i] = array[i];
		} else {
			odd[i] = array[i];
		}
	}

	printf("Odd numbers were: ");
	for (i = 0; i < SIZE; i++) {
		if (odd[i] > 0) {
			printf("%d ", odd[i]);
		}
	}

	printf("\nEven numbers were: ");
	for (i = 0; i < SIZE; i++) {
		if (even[i] > 0) {
			printf("%d ", even[i]);
		}
	}

	printf("\n");

	return EXIT_SUCCESS;

}
