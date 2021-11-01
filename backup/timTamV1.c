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

void timTam(int input[SIZE]);

int main(void) {

	int input[SIZE] = {0};
	int n = 0;
	
	while (n < SIZE) {
		scanf("%d", &input[n]);
		n++;
	}

	timTam(input);	

	return EXIT_SUCCESS;
}

void timTam(int input[SIZE]) {

	int i = 1, j, k, l, m, n, RULE = 1; 
	// REMOVE VARIABLES AFTER j AND k 
	// RENAME j to NEXT and k to PREVIOUS at END OF ASSIGNMENT
	int x = 0, score = 0;

// Sequence 2-3

	i = 1;
	while (i < SIZE) {
		j = i - 1; 
		if (input[j] + 1 == input[i]) {
			RULE = 7, score = 2 * input[i] + 19;
			x = input[i]; // Rule = Sequence-2
		} i++;
	}
	i = 2;
	while (i < SIZE) {
		j = i - 1, k = j - 1;
		if (input[k] + 2 == input[i] && RULE == 7) {
			RULE = 8, score = 3 * input[i] + 18;
			x = input[i]; // Rule = Sequence-3
		} i++;
	}

// Match 2-6

	i = 1;
	while (i < SIZE) {
		j = i - 1;
		if (input[i] == input[j]) {
			RULE = 2, score = 2 * input[i] + 19;
			x = input[i]; // Rule = Match-2
		} i++;
	}
	i = 2;
	while (i < SIZE) {
		j = i - 1, k = j - 1;
		if (input[i] == input[j] && input[i] == input[k]) {
			RULE = 3, score = 3 * input[i] + 21;
			x = input[i]; // Rule = Match-3
		} i++;
	}
	i = 3;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1;
		if (input[i] == input[j] && input[i] == input[k] && 
		input[i] == input[l]) {
			RULE = 4, score = 4 * input[i] + 23;
			x = input[i]; // Rule = Match-4
		} i++;
	}
	i = 4;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1;
		if (input[i] == input[j] && input[i] == input[k] && 
		input[i] == input[l] && input[i] == input[m]) {
			RULE = 5, score = 5 * input[i] + 25;
			x = input[i]; // Rule = Match-5
		} i++;
	}
	i = 5;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1, n = m - 1;
		if (input[i] == input[j] && input[i] == input[k] && 
		input[i] == input[l] && input[i] == input[m] && 
		input[i] == input[n]) {
			RULE = 6, score = 6 * input[i] + 27;
			x = input[i]; // Rule = Match-6
		} i++;
	}

// Sequences 4-6

	i = 3;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1;
		if (input[l] + 3 == input[i] && RULE == 8) {
			RULE = 9, score = 4 * input[i] + 19;
			x = input[i]; // Rule = Sequence-4
		} i++;
	}
	i = 4;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1;
		if (input[m] + 4 == input[i] && RULE == 9) {
			RULE = 10, score = 5 * input[i] + 20;
			x = input[i]; // Rule = Sequence-5
		} i++;
	}
	i = 5;
	while (i < SIZE) {
		j = i - 1, k = j - 1, l = k - 1, m = l - 1, n = m - 1;
		if (input[m] + 4 == input[i] &&	RULE == 10) {
			RULE = 11, score = 6 * input[i] + 21;
			x = input[i]; // Rule = Sequence-6
		} i++;
	}

// SEVERAL Incorrect Output ERRORS NEED FIXING!!! Account for Matches in this!

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
		i = 0;
		while (i < SIZE) {
			score = input[i] + score;
			i++;
		} printf("Rule total - score %d.\n", score);
		// Rule = Total (When no other rule is satisfied)
	} else if (RULE >= 2 && RULE <= 6) {
		printf("Rule match-%d(%d) - score %d.\n", RULE, x, score);
		// Rule = Match
	} else if (RULE >= 7 && RULE <= 11) {
		printf("Rule sequence-%d(%d) - score %d.\n", RULE - 5, x, score);
		// Rule = Sequence
	} else if (RULE >= 12 && RULE <= 15) {
		printf("Rule sum-%d(%d) - score %d.\n", RULE - 10, x, score);
		// Rule = Sequence
	} else {
		printf("Rule timTam(%d) - score %d.\n", x, score);
	}
}
