// COMP1911 Assignment 1 - Tim Tam Game
// Author: Yash Raj (z5317349)
// Date modified: 24/06/2020
/* Tim-Tam is a popular game in some regions of Antarctica and Spain. 
Tim-Tam starts with the creation of 6 random numbers. Historically the
numbers were produced by rolling 9 sided dice carved out of Giraffe horns
in North Africa.
This C program aims to calculate the score of 6 input integers (entered
in sorted ascending order) in accordance with the rules of the game. */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 6

void timTam(int input[], int size);
int sum_array(int pattern[SIZE]);
int minimum(int input[], int size);
void type(int pattern[], int size);
void initialise(int pattern[], int size);

int main(void) {

	int input[SIZE] = {0};
	int n = 0;
	
	while (n < SIZE) {
		scanf("%d", &input[n]);
		n++;
	}

	timTam(input, SIZE);	

	return EXIT_SUCCESS;
}

void timTam(int input[], int size) {

	int i = 1, j, k, l, m, n;
	int RULE = 1, score = 0, x = 0;
	int pattern[SIZE] = {0};

// Sequence 2-6

	i = 1;
	while (i < SIZE) {
		j = i - 1; 
		if (input[j] + 1 == input[i] && 
		input[SIZE - 1] != input[SIZE - 2]) {
			RULE = 7, score = 2 * input[i] + 19;
			pattern[5] = input[i], pattern[4] = input[j];
			// Rule = Sequence-2
		} i++;
	}

	i = 2;
	while (i < SIZE) {
		j = i - 1, k = j - 1;
		if (input[k] + 2 == input[i] 
		&& input[j] + 1 == input[i]) {
			RULE = 8, score = 3 * input[i] + 18, x = 1;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k]; // Rule = Sequence-3
		} i++;
	}

	i = 3;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1;
		if (((input[l] + 3 == input[i]) || 
		((input[l] == input[k] && input[k] != input[j]) ||
		(input[l] == input[k] && input[k] == input[j] && 
		input[j] != input[i]))) && input[k] + 2 == input[i] 
		&& input[j] + 1 == input[i]) {
			RULE = 9, score = 4 * input[i] + 19;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k], pattern[2] = input[l]; 
			// Rule = Sequence-4
		} i++;
	}
	i = 4;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1;
		if (input[m] + 4 == input[i] && input[l] + 3 
		== input[i] && input[k] + 2 == input[i] && 
		input[j] + 1 == input[i]) {
			RULE = 10, score = 5 * input[i] + 20;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k], pattern[2] = input[l];
			pattern[1] = input[m]; 
			// Rule = Sequence-5
		} i++;
	}
	i = 5;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1, n = m - 1;
		if (input[n] + 5 == input[i] && 
		input[m] + 4 == input[i] && input[l] + 3 == input[i] 
		&& input[k] + 2 == input[i] 
		&& input[j] + 1 == input[i]) {
			RULE = 11, score = 6 * input[i] + 21;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k], pattern[2] = input[l];
			pattern[1] = input[m], pattern[0] = input[n];
			// Rule = Sequence-6
		} i++;
	}

// Match 2-6

	i = 1;
	while (i < SIZE) {
		if (input[i] == input[i - 1] && 
		(RULE < 8 || RULE > 10) && input[SIZE - 2] + 1 
		!= input[SIZE - 1]) {
			RULE = 2, score = 2 * input[i] + 19;
			x = input[i]; // Rule = Match-2
		} i++;
	}

	i = 2;
	while (i < SIZE) {
		if (RULE == 2 && input[i] == input[i - 2]) {
			RULE = 3, score = 3 * input[i] + 21;
			x = input[i]; // Rule = Match-3
		} i++;
	}

	i = 3;
	while (i < SIZE) {
		if (input[i] == input[i - 1] && 
		input[i] == input[i - 2] && 
		input[i] == input[i - 3]) {
			RULE = 4, score = 4 * input[i] + 23;
			x = input[i]; // Rule = Match-4
		} i++;
	}
	i = 4;
	while (i < SIZE) {
		if (RULE == 4 && input[i] == input[i - 4]) {
			RULE = 5, score = 5 * input[i] + 25;
			x = input[i]; // Rule = Match-5
		} i++;
	}
	i = 5;
	while (i < SIZE) {
		if (RULE == 5 && input[i] == input[i - 5]) {
			RULE = 6, score = 6 * input[i] + 27;
			x = input[i]; // Rule = Match-6
		} i++;
	}


// Sum 2-5

	for (i = 0; i < SIZE; i++) {
		for(j = 0; j < i; j++) {
			if (minimum(input, SIZE) + 
			input[j] == input[i] && (minimum(input, SIZE) 
			!= input[j] || (input[0] == input[j] && 
			j != 0))) {
				score = minimum(input,SIZE) 
				+ input[i] + 22;
				initialise(pattern, SIZE), RULE = 12;
				pattern[4] = minimum(input,SIZE);
				pattern[5] = input[j]; // Rule = Sum-2
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < j; k++) {
				if (minimum(input, SIZE) + input[j] + 
				input[k] == input[i] &&
				(minimum(input, SIZE) != input[k] ||
				(input[0] == input[k] && k != 0))) {
					score = minimum(input,SIZE) +
					input[i] + 29;
					initialise(pattern, SIZE);
					RULE = 13;
					pattern[3] = 
					minimum(input,SIZE);
					pattern[4] = input[k];
					pattern[5] = input[j];
					// Rule = Sum-3
				}
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < j; k++) {
				for (l = 0; l < k; l++) {
					if (minimum(input, SIZE) + 
					input[j] + input[k] + 
					input[l] == input[i] &&
					minimum(input, SIZE) 
					!= input[l]) {
						score = 
						minimum(input,SIZE) + 
						input[i] + 38;
						RULE = 14;
						initialise(pattern,
						SIZE);
						pattern[2] = 
						minimum(input,SIZE);
						pattern[3] = input[l];
						pattern[4] = input[k];
						pattern[5] = input[j];
						// Rule = Sum-4
					}
				}
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < j; k++) {
				for (l = 0; l < k; l++) {
					for (m = 0; m < l; m++) {
						if (minimum(input,
						SIZE) + input[j] + 
						input[k] + input[l] +
						input[m] == input[i] &&
						minimum(input, SIZE) 
						!= input[m]) {
							score = minimum
							(input,SIZE) + 
							input[i] + 49;
							RULE = 15;
							initialise
							(pattern, SIZE);
							pattern[1] =
							minimum
							(input,SIZE);
							pattern[2] =
							input[m];
							pattern[3] =
							input[l];
							pattern[4] =
							input[k];
							pattern[5] =
							input[j];
							// Rule = Sum-5
						}
					}
				}
			}
		}
	}

// Invalid Statement

	i = 1;
	while (i < SIZE) {
		k = i - 1;
		if ((input[i] > 9) || (input[i] < input[k]) || 
		input[i] == 0) {
			RULE = 0; // Invalid Array
		} i++;
	}

// Print Outputs for Each Rule

	if (RULE == 0) {
		printf("Invalid input: 6 integers 1..9 in sorted ");
		printf("order must be supplied.\n");
		/* Specifies the range of accepted input values and
		bounds input to be in ascending order only */
	} else if (RULE == 1) {
		score = sum_array(input);
		printf("Rule total - score %d.\n", score);
		// Rule = Total (When no other rule is satisfied)
	} else if (RULE >= 2 && RULE <= 6) {
		printf("Rule match-%d(%d) - score", RULE, x);
		printf(" %d.\n", score);
		// Rule = Match
	} else if (RULE >= 7 && RULE <= 11) {
		printf("Rule sequence-%d(", RULE - 5);
			i = 11 - RULE;
			while (i < SIZE - 1) {
				if (i > 1 && pattern[i] != 
				pattern[i - 1] && pattern[i] != 
				pattern[i - 2]) {
					printf("%d,", pattern[i]);
				} else if (i == 1 && pattern[i] 
				!= pattern[i - 1]) {
	 				printf("%d,", pattern[i]);
				} else if (i == 0) {
					printf("%d,", pattern[i]);
				} i++; 
				/* To avoid repeated numbers from being
				printed */
			}
			if (pattern[4] != pattern[5]) {
				printf("%d) - score %d.\n", pattern[5], score);
			} else {
				printf(") - score %d.\n", score);
			}
		// Rule = Sequence
	} else if (RULE >= 12 && RULE <= 15) {
		printf("Rule sum-%d(", RULE - 10);
		type(pattern, SIZE);
		printf(") - score %d.\n", score);
		// Rule = SUM
	} else {
		printf("Rule timTam(%d) - score %d.\n", pattern[5], score);
	}
}

int sum_array(int array[SIZE]) {

	int i = 0, sum = 0;

	while (i < SIZE) {
		sum = sum + array[i];
		i++;
	}
	
	return sum;
}

int minimum(int input[], int size) {

	int i;
	int min = input[0];

	for (i = 1; i < SIZE; i++) {
		if (input[i] < min) {
			min = input[i];
		}
	}
	
	return min;

}

void type(int pattern[], int size) {

	int i;

	for (i = 0; i < SIZE - 1; i++) {
		if (pattern[i] > 0) {
			printf("%d+", pattern[i]);
		}
	}
	printf("%d=%d", pattern[5], sum_array(pattern));

}

void initialise(int pattern[], int size) {

	int i;

	for (i = 0; i < SIZE; i++) {
		pattern[i] = 0;
	}

}

