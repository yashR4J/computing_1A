// Last Modified by: Yash Raj
// Date last modified: 18/08/2020
// Question XXXXX

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void) {

	int size, i, j;
	int up, down, left, right;
	printf("Enter size: ");
	scanf("%d", &size);
	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			// 		( \ diag     &&   / diag           && alt lines);
			up =    (j > i - 3   && j + i < size       && !(i % 2));
			right = (j > i       && j + i > size - 1   && !(j % 2));
			down =  (j < i + 1   && j + i > size - 1   && !(i % 2));
			left =  (j < i - 1   && j + i < size       && !(j % 2));
			
			if (up || right || down || left) {
			printf("*");
			} else {
			printf("-");
			}
		}
		printf("\n");
	}
	
	return 0;
}


 
 


