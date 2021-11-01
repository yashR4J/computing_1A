// Yash Raj
// Date Modified: 13/06/2019
// Prints out boxes inside boxes.

#include <stdio.h>

int main (void) {
	int boxes ;
	int row, column;

	// Obtain input
	printf("How many boxes: ");
	scanf("%d", &boxes);

	row = 1;
	while (row <= boxes) {
		column = 1;
		while (column <= boxes) {

			if () {
				printf("#");
			} else {

			}
			column = column + 1;
		}
		printf("\n");
		row = row + 1;
	}
	
	return 0;
}

/*

For a standard input of size 2,

R1: C1-C7
R2: C1, C7
R3: C1, C3-C5, C7
R4: C1, C3, C5, C7
R5: C1, C3-C5, C7
R6: C1, C7
R7: C1-C7

So, odd numbers: 2*n*n + 1 and even numbers: 

*/

