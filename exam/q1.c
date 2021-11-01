// Last Modified by: Yash Raj
// Date last modified: 18/08/2020
// Question 1: Given a list of integers, return a list containing unique
// integers in sorted order

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void) {

	int i = 0, size = 0;
	int array[100];
	
	while (fscanf(stdin, "%d", &array[i++]) == 1) {
		++size;
	}
	
	printf("[%d", array[0]);
	for (i = 1; i < size - 1; i++) {
		if (array[i] != array[i - 1]) {
			fprintf(stdout, " %d", array[i]);
		}
	}
	if (array[i] != array[i - 1]) {
		fprintf(stdout, " %d]\n", array[i]);
	} else {
		fprintf(stdout, "]\n");
	}
	
	return 0;
}


