// COMP1911 Assignment 1 - Tim Tam Game
// Author: Yash Raj (z5317349)
// Date modified: 24/06/2020
/* This C program aims to calculate the score of 6 input integers
(entered in sorted ascending order) in accordance with the rules of the
game. */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 6

void timTam(int input[], int size);
int sum_array(int pattern[SIZE]);
int minimum(int input[], int size);
void type(int pattern[], int size);
void initialise(int pattern[], int size);
int rulecheck(int score[], int size);

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

	int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
	int RULE = 1, x = 0;
	int pattern[SIZE] = {0}, sequence[SIZE] = {0};
	int score[17] = {0};


// Match 2-6

	i = 1;
	while (i < SIZE) {
		if (input[i] == input[i - 1]) {
			RULE = 2, score[2] = 2 * input[i] + 19;
			x = input[i]; // Rule = Match-2
		} i++;
	}

	i = 2;
	while (i < SIZE) {
		if (RULE == 2 && input[i] == input[i - 2]) {
			RULE = 3, score[3] = 3 * input[i] + 21;
			x = input[i]; // Rule = Match-3
		} i++;
	}

	i = 3;
	while (i < SIZE) {
		if (RULE == 3 && input[i] == input[i - 3]) {
			RULE = 4, score[4] = 4 * input[i] + 23;
			x = input[i]; // Rule = Match-4
		} i++;
	}
	i = 4;
	while (i < SIZE) {
		if (RULE == 4 && input[i] == input[i - 4]) {
			RULE = 5, score[5] = 5 * input[i] + 25;
			x = input[i]; // Rule = Match-5
		} i++;
	}
	i = 5;
	while (i < SIZE) {
		if (RULE == 5 && input[i] == input[i - 5]) {
			RULE = 6, score[6] = 6 * input[i] + 27;
			x = input[i]; // Rule = Match-6
		} i++;
	}

// Sequence 2-6

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			if (input[j] + 1 == input[i]) {
				RULE = 7, sequence[5] = input[i];
				sequence[4] = input[j];
			for (k = 0; k < j; k++) {
				if (input[k] + 1 == input[j]) {
					RULE = 8, sequence[3] = 
					input[k];
				for (l = 0; l < k; l++) {
					if(input[l] + 1 == input[k]) {
						RULE = 9, sequence[2] =
						input[l];
					for (m = 0; m < l; m++) {
						if (input[m] + 1 ==
						input[l]) {
							RULE = 10;
							sequence[1] =
							input[m];
						for (n = 0; n < m; 
						n++) {
							if (input[n] + 1
							== input[m]) {
								RULE =
								11;
								sequence
								[0] =
								input
								[n];
							}
						} }
					} }
				} }
			} }
		}				
	}

	if (RULE == 7) { // Sequence 2
		score[7] = 2 * sequence[5] + 19;
	} else if (RULE == 8) { // Sequence 3
		score[8] = 3 * sequence[5] + 18;
	} else if (RULE == 9) { // Sequence 4
		score[9] = 4 * sequence[5] + 19;
	} else if (RULE == 10) { // Sequence 5
		score[10] = 5 * sequence[5] + 20;
	} else if (RULE == 11) { // Sequence 6
		score[11] = 6 * sequence[5] + 21;
	}

// Sum 2-5

	for (i = 0; i < SIZE; i++) {
		for(j = 0; j < i; j++) {
			if (minimum(input, SIZE) + 
			input[j] == input[i] && (minimum(input, SIZE) 
			!= input[j] || (input[0] == input[j] && 
			j != 0))) {
				score[12] = minimum(input,SIZE) 
				+ input[i] + 22, RULE = 12;
				initialise(pattern, SIZE);
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
					score[13] = minimum(input,SIZE)
					+ input[i] + 29; RULE = 13;
					initialise(pattern, SIZE);
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
						score[14] = 
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
							score[15] =
							minimum
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
			RULE = 0, score[0] = 200; // Invalid Array
		} i++;
	}

// Print Outputs for Each Rule

	RULE = rulecheck(score, 17);

	if (RULE == 0) {
		printf("Invalid input: 6 integers 1..9 in sorted ");
		printf("order must be supplied.\n");
		/* Specifies the range of accepted input values and
		bounds input to be in ascending order only */
	} else if (RULE == 1) {
		score[1] = sum_array(input);
		printf("Rule total - score %d.\n", score[1]);
		// Rule = Total (When no other rule is satisfied)
	} else if (RULE >= 2 && RULE <= 6) {
		printf("Rule match-%d(%d) - score", RULE, x);
		printf(" %d.\n", score[RULE]);
		// Rule = Match
	} else if (RULE >= 7 && RULE <= 11) {
		printf("Rule sequence-%d(", RULE - 5);
			for (i = 0; i < SIZE - 1; i++) {
				if (sequence[i] != 0) {
					printf("%d,", sequence[i]);
				} 
			} printf("%d) - score %d.\n", sequence[5], 
			score[RULE]); // Rule = Sequence
	} else if (RULE >= 12 && RULE <= 15) {
		printf("Rule sum-%d(", RULE - 10);
		type(pattern, SIZE);
		printf(") - score %d.\n", score[RULE]);
		// Rule = SUM
	} else {
		printf("Rule timTam(%d) - score %d.\n", pattern[5], score[RULE]);
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

int rulecheck(int score[], int size) {

	int i, x = 0;
	int max = 0;

	for (i = 0; i < 17; i++) {
		if (score[i] > max) {
			max = score[i];
			x = i;
		}
	}
	
	return x;

}

