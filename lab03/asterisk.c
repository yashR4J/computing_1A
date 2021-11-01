// Yash Raj
// Date Modified: 13/06/2019
// Prints a n x n pattern of asterisk and dashes in the shape of a "+"

#include <stdio.h>

int main (void) {
	int number;
	int row, column;

	// Obtain input
	printf("Enter size: ");
	scanf("%d", &number);

	row = 1;
	while (row <= number) {
		column = 1;
		while (column <= number) {

			if ((column == ((number + 1) / 2) && row != ((number + 1) / 2)) 
				|| column == row || column == number - row + 1) {
				printf("*");
			} else { 
				if (row == ((number + 1) / 2)) {
					printf("*");
				} else { 
					printf("-");
				}
			}
			column = column + 1;
		}
		printf("\n");
		row = row + 1;
	}
	
	return 0;
}

/*

For a standard input of size 5, assume 2 separate codes such that,

Code 1:
R1 - C((N+1)/2)
R2 - C((N+1)/2)
R3 - C((N+1)/2)
R4 - C((N+1)/2)
R5 - C((N+1)/2)

Code 2:
Row ((N+1)/2) - N

*/

