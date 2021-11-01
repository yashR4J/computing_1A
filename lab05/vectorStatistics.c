// Author: Yash Raj (z5317349)
// Date Modified: 02/07/2020
/* Reads a vector of 10 integers then prints the minimum, maximum & mean of the integers */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int min(int vector[], int size);
int max(int vector[], int size);
double avg(int vector[], double size);
double sum(int vector[], int size);

int main (void) {

	int vector[SIZE] = {0};
	int i = 0;

	printf("Enter vector of 10 numbers: ");

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &vector[i]);
	}

	printf("Minimum vector value is %d\n", min(vector, SIZE));

	printf("Maximum vector value is %d\n", max(vector, SIZE));

	printf("Average vector value is %.1lf\n", avg(vector, SIZE));

	return EXIT_SUCCESS;
}

int min(int vector[], int size) {
	int i, min = vector[0];

	for (i = 0; i < size; i++) {
		if (vector[i] < min) {
			min = vector[i];
		}
	}

	return min;
}

int max(int vector[], int size) {
	int i, max = vector[0];

	for (i = 0; i < size; i++) {
		if (vector[i] > max) {
			max = vector[i];
		}
	}

	return max;
}

double avg(int vector[], double size) {

	double avg;

	return avg = (sum(vector, SIZE) / size);
}

double sum(int vector[], int size) {

	double sum = 0;
	int i;

	for (i = 0; i < SIZE; i++) {
		sum = sum + vector[i];
	}
	
	return sum;
}
