// Author: Yash Raj
// Date modified: 13/06/2020
/* Program that prints the sum of integers from 1 to k, for all values of k
between 1 and 20 */

#include <stdio.h>

int main (void) {
	
	int i = 1, n = 20, sum = 1;

	printf(" k sum\n");
	printf("\n");

	while (i <= n) {
		printf("%2d%4d\n",i,sum);
		i = i + 1;
		sum = sum + i; 
	}

	return 0;
}
