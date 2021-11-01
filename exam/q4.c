// Last Modified by: Yash Raj
// Date last modified: 18/08/2020
// Question 4: Convert Roman Numerals to Decimal Equivalents

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int convert(char r);

int main(int argc, char *argv[]) {

	int sum = 0, i; 
	
    if (argc == 2) {
		int size = strlen(argv[1]);
		int *decValue = malloc(size*sizeof(int));
		
    	for (i = 0; i < size; ++i) {
			decValue[i] = convert(argv[1][i]);
			if (decValue[i] == -1) {
				fprintf(stderr, "Invalid Input\n");
				exit(EXIT_FAILURE);
			}
		}        
		
		for (i = 0; i < size; i++) {
			if (i + 1 < size) {
				if (decValue[i] >= decValue[i + 1]) {
					sum = sum + decValue[i];
				} else {
					if (i + 2 < size) {
						if (decValue[i + 1] < decValue[i + 2]) {
							fprintf(stderr, "Invalid Input\n");
							exit(EXIT_FAILURE);
						}
					}
					sum = sum + decValue[i + 1] - decValue[i];
					i++;
				}
			} else {
				sum = sum + decValue[i];
			}
		}
		printf("%d\n", sum);
		free(decValue);
    }
	return 0;
}

int convert(char r) {

	if (r == 'I') {
		return 1; 
	} else if (r == 'V') {
		return 5; 
	} else if (r == 'X') {
		return 10; 
	} else if (r == 'L') {
		return 50; 
	} else if (r == 'C') {
		return 100; 
	} else if (r == 'D') {
		return 500; 
	} else if (r == 'M') {
		return 1000; 
	}
	
	return -1;
}
   
