// Author: Yash Raj (z5317349)
// Date Modified: 02/07/2020
/* Scanf in a number of doubles, and then reverse the array */

#include <stdio.h>

#define MAX_SIZE 99


int readIntoArray(double numbers[]);
void reverseArray(double numbers[], int size);
void printArray(double numbers[], int size);
void swap(double *a, double *b);

int main(void) {
	double numbers[MAX_SIZE];
	int size = readIntoArray(numbers);

	reverseArray(numbers, size);
	printArray(numbers, size);
	return 0;
}

int readIntoArray(double numbers[]) {
	double in;
	int i = 0;

	while (i < MAX_SIZE && scanf("%lf", &in) != -1) {
		numbers[i] = in;
		i++;
	}

	return i;
}

void reverseArray(double numbers[], int size) {

	int i = 0;

	while (i < size/2) {
		swap(&numbers[i], &numbers[size - 1 - i]);
		i++;
	}

}

void printArray(double numbers[], int size) {

	int i = 0;

	for(i = 0; i < size; i++) {
		printf("%lf ", numbers[i]);
	}
	printf("\n");
}

void swap(double *a, double *b) {

	double temp;
	
	temp = *a; 
    *a = *b; 
    *b = temp;

}
