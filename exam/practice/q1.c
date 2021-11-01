// Last Modified by: Yash Raj
// Date last modified: 15/08/2020
// Question 1: Program returns the sum of all positive, odd numbers 
// that are entered

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void) {

	int num = 0, sum = 0;
	
	while (scanf("%d", &num) == 1) {
		if (num % 2 != 0 && num > 0) {
			sum = sum + num;
		}
	}

	printf("%d\n", sum);
	
	return 0;
}


