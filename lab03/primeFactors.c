// Author: Yash Raj
// Date modified: 19/06/2020
/* Reads an integer n from standard input and prints the decomposition of n into prime factors and otherwise, for prime numbers, prints a message indicating this */

#include<stdio.h>

int counter(int n);
void primeFactors(int n);

int main (void) {

	int n;
	
	printf("Enter number: ");
	scanf("%d", &n);	

	if (n > 0) {
		if (counter(n) == 1) {
			printf("The prime factorization of %d is:\n", n);
			primeFactors(n);
		} else {
			printf("%d is prime\n", n);
		}
	} else {
		printf("%d cannot be factorised\n", n);
	}

	return 0;
}

void primeFactors(int n) {

	int i, j = n, counter = 0;	

	while (n % 2 == 0 && j / n < j/2) {	
		printf("%d * ", 2);
		n = n/2, counter++;
	}

		if (j / n == j/2) {
			printf("%d ", 2);
		}

	i = 3;
	
	while (i <= n) {
		while (n % i == 0) {

			if (n / i != 1) {
				printf("%d * ", i);
			} else {
				printf("%d ", i);
			}
			n = n/i, counter++;
		
		}
		i = i + 2; 
	}
	if (counter != 0) {
		printf("= %d\n", j);
	}
		
}

int counter(int n) {

	int i = 2, counter = 0;

	while (i <= n/2) {
		while (n % i == 0) {
			counter = 1; 
			n = n/i;
		} i++;
	}

	return counter;
}

