// Author: Yash Raj
// Date created: 9/06/2020
// Largest to Smallest

#include <stdio.h>
#include <math.h>

int main(void) {

	int a, b, c, temp;

	printf("Please enter three integers: \n");
	scanf("%d %d %d", &a, &b, &c);

	if (a < b) {
		temp = a;
		a = b;
		b = temp; // Swapping b and a (so order = b, a, c)
	} if (a < c) {
		temp = a;
		a = c;
		c = temp; // Swapping c and a (so order = b, c, a)
	} if (b < c) {
		temp = b;
		b = c;
		c = temp; // Swapping c and b (so order = c, b, a)
	}
	printf("Your integers after sorting: \n%d %d %d\n", a, b, c);

	return 0;
}


/*
	if (a>=b && a>=c){
		printf("%d ", a);
		if (b>=c){
			printf("%d %d\n", b, c);
			}if (b<c) {
             printf("%d %d\n", c, b);
		}
	} else if (b>=a && b>=c){
		printf("%d ", b);
		if (a>=c){
			printf("%d %d\n", a, c);
			}if (a<c) {
             printf("%d %d\n", c, a);
		}
	} else {
		if (c>=a && c>=b){
		printf("%d ", c);
		if (a>=b){
			printf("%d %d\n", a, b);
			}if (a<b) {
             printf("%d %d\n", b, a);
			}
		}
	}
*/

