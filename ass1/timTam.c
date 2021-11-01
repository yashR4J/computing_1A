// COMP1911 Assignment 1 - Tim-Tam Game
// Author: Yash Raj (z5317349@ad.unsw.edu.au)
// Date modified: 11/07/2020
/* This C program aims to calculate the score of 6 input integers
(entered in sorted ascending order) in accordance with the rules of the
game. */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define NUM_RULES 17

// Rule Book
void timTam(int input[], int size); 
// Finds the Total Sum of an Array
int sumArray(int array[SIZE]); 
// Initialises an Array
void initialise(int array[], int size); 
// Checks for the highest possible score
int ruleCheck(int score[], int size); 

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

	// Variables used to allow the program to find sequences and sums 
	int i, j, k, l, m, n; 

	int rule = 1;
	int sum[SIZE] = {0}, sequence[SIZE] = {0}, match[SIZE] = {0};
    int timTam[SIZE] = {0};
	int score[NUM_RULES] = {0};

    // RULE: Total

	score[1] = sumArray(input);

    // RULES: Match 2-6

	i = 1;
	while (i < SIZE) {
		if (input[i] == input[i - 1]) {
			rule = 2, score[2] = 2 * input[i] + 19;
			match[1] = input[i]; // Rule = Match-2
		} 
		i++;
	}

	i = 2;
	while (i < SIZE) {
		if (rule == 2 && input[i] == input[i - 2]) {
			rule = 3, score[3] = 3 * input[i] + 21;
			match[2] = input[i]; // Rule = Match-3
		} 
		i++;
	}

	i = 3;
	while (i < SIZE) {
		if (rule == 3 && input[i] == input[i - 3]) {
			rule = 4, score[4] = 4 * input[i] + 23;
			match[3] = input[i]; // Rule = Match-4
		} 
		i++;
	}
	i = 4;
	while (i < SIZE) {
		if (rule == 4 && input[i] == input[i - 4]) {
			rule = 5, score[5] = 5 * input[i] + 25;
			match[4] = input[i]; // Rule = Match-5
		} 
		i++;
	}
	i = 5;
	while (i < SIZE) {
		if (rule == 5 && input[i] == input[i - 5]) {
			rule = 6, score[6] = 6 * input[i] + 27;
			match[5] = input[i]; // Rule = Match-6
		} 
		i++;
	}

    // RULES: Sequence 2-6

    /* The following sequence code attempts to make use of the
     ascending order inputs to satisfy sequence conditions even if
     matches are found in between. The sequence order is then saved to
     the sequence array. */
     
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			if (input[j] + 1 == input[i]) {
				rule = 7, sequence[5] = input[i];
				sequence[4] = input[j];
				for (k = 0; k < j; k++) {
					if (input[k] + 1 == input[j]) {
						rule = 8, sequence[3] = input[k];
						for (l = 0; l < k; l++) {
							if (input[l] + 1 == input[k]) {
								rule = 9, sequence[2] =	input[l];
								for (m = 0; m < l; m++) {
									if (input[m] + 1 ==	input[l]) {
										rule = 10;
										sequence[1] = input[m];
										for (n = 0; n < m; n++) {
											if (input[n] + 1 == 
											input[m]) {
												rule = 11;
												sequence[0] = input[n];
											}
										}
								 	}
								}
                        	}
						}
                    }
				}
			}				
		}
	}

	if (rule == 7) { // Sequence 2
		score[7] = 2 * sequence[5] + 17;
	} else if (rule == 8) { // Sequence 3
		score[8] = 3 * sequence[5] + 18;
	} else if (rule == 9) { // Sequence 4
		score[9] = 4 * sequence[5] + 19;
	} else if (rule == 10) { // Sequence 5
		score[10] = 5 * sequence[5] + 20;
	} else if (rule == 11) { // Sequence 6
		score[11] = 6 * sequence[5] + 21;
	}

    // RULES: Sum 2-5

	for (i = 0; i < SIZE; i++) {
		for(j = 0; j < i; j++) {
			for(k = 0; k < j; k++) {
				if (input[j] + input[k] == input[i]) {
					score[12] = input[k] + input[i] + 22;
					rule = 12, initialise(sum, SIZE);
					sum[4] = input[k];
					sum[5] = input[j]; // Rule = Sum-2
				}
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < j; k++) {
				for (l = 0; l < k; l++) {
					if (input[j] + input[k] + input[l] == input[i]) {
						score[13] = input[l] + input[i] + 29;
						rule = 13, initialise(sum, SIZE);
						sum[3] = input[l]; sum[4] = input[k];
						sum[5] = input[j]; // Rule = Sum-3
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
						if (input[j] + input[k] + input[l] + input[m]
						== input[i]) {
							score[14] = input[m] + input[i] + 38;
							rule = 14; initialise(sum, SIZE);
							sum[2] = input[m];
							sum[3] = input[l];
							sum[4] = input[k];
							sum[5] = input[j]; // Rule = Sum-4
						}
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
						for(n = 0; n < m; n++) {
							if (input[j] + input[k] + input[l] + 
							input[m] + input[n] == input[i]) {
								score[15] =	input[n] + input[i] + 49;
								rule = 15, initialise(sum, SIZE);
								sum[1] = input[n];
								sum[2] = input[m];
								sum[3] = input[l];
								sum[4] = input[k];
								sum[5] = input[j]; // Rule = Sum-5
							}
						}
					}
				}
			}
		}
	}

    // RULE: TIM-TAM

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < j; k++) {
				for (l = 0; l < i; l++) {
					for (m = 0; m < l; m++) {
						for(n = 0; n < m; n++) {
							if ((k != l) && (k != m) & (k != n) && 
							(j != l) && (j != m) & (j != n)) {
								if (input[j] + input[k] == input[i] &&
								input[m] + input[n] == input[l]) {
									score[16] =	input[n] + 2*input[m] +
									3*input[l] + 4*input[k] + 
									5*input[j] + 6*input[i], rule = 16;
									timTam[0] = input[n];
									timTam[1] = input[m];
									timTam[2] = input[l];
									timTam[3] = input[k];
									timTam[4] = input[j];
									timTam[5] = input[i]; 
								}
							}
						}
					}
				}
			}
		}
	}


    // RULE: Invalid Statement

	i = 1;
	while (i < SIZE) {
		k = i - 1;
		if ((input[i] > 9) || (input[i] < input[i - 1]) || 
		((input[i - 1] > 9)) || input[i] == 0) {
			rule = 0, score[0] = 999;
		} 
		i++; 
		/* Specifies the range of accepted input values and
		bounds input to be in ascending order only */
	}

    // Print Outputs for Each Rule

	rule = ruleCheck(score, NUM_RULES);

	if (rule == 0) { // Rule = Invalid Statement
		printf("Invalid input: 6 integers 1..9 in sorted ");
		printf("order must be supplied.\n");

	} else if (rule == 1) { // Rule = Total
		printf("Rule total - score %d.\n", score[1]);

	} else if (rule >= 2 && rule <= 6) { // Rule = Match
		printf("Rule match-%d(%d) - score", rule, match[rule - 1]);
		printf(" %d.\n", score[rule]);

	} else if (rule >= 7 && rule <= 11) { // Rule = Sequence
		printf("Rule sequence-%d(", rule - 5);
		for (i = 0; i < SIZE - 1; i++) {
			if (sequence[i] != 0) {
				printf("%d,", sequence[i]);
			} 
		} printf("%d) - score %d.\n", sequence[5], score[rule]);

	} else if (rule >= 12 && rule <= 15) { // Rule = Sum
		printf("Rule sum-%d(", rule - 10);
		for (i = 0; i < SIZE - 1; i++) {
			if (sum[i] > 0) {
				printf("%d+", sum[i]);
			}
		}
		printf("%d=%d) - score %d.\n", sum[5], sumArray(sum),
		score[rule]);

	} else if (rule == 16) { // Rule = TIM-TAM
		printf("Rule tim-tam(%d+%d=%d,%d+%d=%d) - score %d.\n", 
		timTam[0], timTam[1], timTam[2], timTam[3], timTam[4],
		timTam[5], score[rule]);
	}
}

int sumArray(int array[SIZE]) {

	int i = 0, sum = 0;

	while (i < SIZE) {
		sum = sum + array[i];
		i++;
	}
	
	return sum;
}

void initialise(int array[], int size) {

	int i;

	for (i = 0; i < SIZE; i++) {
		array[i] = 0;
	}
}

int ruleCheck(int score[], int size) {

	int i, x = 0;
	int max = 0;

	for (i = 0; i < NUM_RULES; i++) {
		if (score[i] > max) {
			max = score[i];
			x = i;
		}
	}
	// Return Rule No. with Highest Score
	return x; 
}

