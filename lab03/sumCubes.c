// Yash Raj
// Date Modified: 13/06/2019
// Prints the sum of the cubes of the integers from 1 to k, for all values of k between 1 and 20

#include <stdio.h>

int main (void) {
	
	int i = 1, n = 20, sum = 1;

	printf(" k  cubes\n");
	printf("\n");

	while (i <= n) {
		printf("%2d%7d\n", i, sum);
		i = i + 1;
		sum = sum + (i * i * i); 
	}

	return 0;
}
