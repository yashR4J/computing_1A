// Author: Yash Raj (z5317349)
// Date Modified: 23/06/2020
/* Reads 2 vectors of 10 positive integers the prints a count of how many times
the 2 vectors have the same value in the same position. */

#include <stdio.h>

#define SIZE 10

int match(int vector1[SIZE], int vector2[SIZE]);

int main(void) {

	int vector1[SIZE], vector2[SIZE];
	int i = 0;
	
	printf("Enter vector 1 of 10 positive numbers: ");
	while (i < SIZE) {
		scanf("%d", &vector1[i]);
		i++;
	}	
	
	printf("Enter vector 2 of 10 positive numbers: ");
	i = 0;
	while (i < SIZE) {
		scanf("%d", &vector2[i]);
		i++;
	}	

	printf("Vectors match in %d positions.\n", match(vector1, vector2));

	return 0;
}

int match(int vector1[SIZE], int vector2[SIZE]) {

	int x = 0, i = 0;

	while (i < SIZE) {
		if (vector1[i] == vector2[i]) {
			x++;
		} i++;
	}

	return x;

}
