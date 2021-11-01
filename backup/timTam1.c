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
	int RULE = 1, score = 0, sum = 0, x = 0;
	int pattern[SIZE] = {0};

// Match 4-6

	i = 3;
	while (i < SIZE) {
		if (RULE == 3 && input[i] == input[i - 3]) {
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

// Sequence 2-6

	i = 1;
	while (i < SIZE) {
		j = i - 1; 
		if (input[j] + 1 == input[i]) {
			RULE = 7, score = 2 * input[i] + 19;
			pattern[5] = input[i], pattern[4] = input[j];
			sum = sum_array(pattern);
			// Rule = Sequence-2
		} i++;
	}

	i = 2;
	while (i < SIZE) {
		j = i - 1, k = j - 1;
		if (input[k] + 2 == input[i] && input[j] + 1 == input[i]) {
			RULE = 8, score = 3 * input[i] + 18, x = 1;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k], sum = sum_array(pattern);
			// Rule = Sequence-3
		} i++;
	}

	i = 3;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1;
		if (((input[l] + 3 == input[i]) || ((input[l] == input[k] 
		&& input[k] != input[j]) || (input[l] == input[k] && 
		input[k] == input[j] && input[j] != input[i]))) &&
		input[k] + 2 == input[i] && input[j] + 1 == input[i]) {
			RULE = 9, score = 4 * input[i] + 19;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k], pattern[2] = input[l];
			sum = sum_array(pattern); // Rule = Sequence-4
		} i++;
	}
	i = 4;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1;
		if (input[m] + 4 == input[i] && input[l] + 3 == input[i] 
		&& input[k] + 2 == input[i] && input[j] + 1 == input[i]) {
			RULE = 10, score = 5 * input[i] + 20;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k], pattern[2] = input[l];
			pattern[1] = input[m], sum = sum_array(pattern); 
			// Rule = Sequence-5
		} i++;
	}
	i = 5;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1, n = m - 1;
		if (input[n] + 5 == input[i] && input[m] + 4 == input[i] 
		&& input[l] + 3 == input[i] && input[k] + 2 == input[i] 
		&& input[j] + 1 == input[i]) {
			RULE = 11, score = 6 * input[i] + 21;
			pattern[5] = input[i], pattern[4] = input[j];
			pattern[3] = input[k], pattern[2] = input[l];
			pattern[1] = input[m], pattern[0] = input[n];
			sum = sum_array(pattern); 
			// Rule = Sequence-6
		} i++;
	}

// Match 2-3

	i = 1;
	while (i < SIZE && score ) {
		if (input[i] == input[i - 1] && (RULE < 8 || RULE > 10)) {
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
		printf("Rule match-%d(%d) - score %d.\n", RULE, x, score);
		// Rule = Match
	} else if (RULE >= 7 && RULE <= 11) {
		printf("Rule sequence-%d(", RULE - 5);
			i = 11 - RULE;
			while (i < SIZE - 1) {
				if (i > 1 && pattern[i] != pattern[i - 1] && pattern[i] != pattern[i - 2]) {
					printf("%d,", pattern[i]);
				} else if (i > 0 && pattern[i] != pattern[i - 1]) {
	 				printf("%d,", pattern[i]);
				} i++;
			}
			if (pattern[4] != pattern[5]) {
				printf("%d) - score %d.\n", pattern[5], score);
			} else {
				printf(") - score %d.\n", score);
			}
		// Rule = Sequence
	} else if (RULE >= 12 && RULE <= 15) {
		printf("Rule sum-%d(%d) - score %d.\n", RULE - 10, pattern[5], score);
		// Rule = Sequence
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
