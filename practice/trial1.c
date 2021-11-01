// Practice source code 
/* Lecture 2
4.06.2020 */
// Author: Yash Raj

#include <stdio.h>

int main(void) {
	double  answer;
	int  result;

	answer  = 18.1;
	result = 100;

	printf("The answer, for how old I will be, is %.2f. However, the result for the lifespan of a human is %d.\n", answer, result);
	
	printf("Enter answer: ");
	scanf("%lf\n\n", &answer);

	return 0;
	}
