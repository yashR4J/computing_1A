// Last Modified by: Yash Raj
// Date last modified: 18/08/2020
// Question 5 

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Defined Tax Brackets (2017-2018)
#define HIGHEST_END 180000
#define HIGH_END 87000
#define MED_END 37000
#define LOW_END 18200
#define LOWEST_END 0

int main(void) {

	int income;
	int tax = 0;

	printf("Enter your income:");
	scanf("%d", &income);

	if (income > HIGHEST_END) {
		tax = (income - HIGHEST_END)*0.45 + 54232;
	} else if (income > HIGH_END) {
		tax = (income - HIGH_END)*0.37 + 19822;
	} else if (income > MED_END) {
		tax = (income - MED_END)*0.325 + 3572;
	} else if (income > LOW_END) {
		tax = (income - LOW_END)*0.19;
	} else if (income > LOWEST_END) {
		tax = 0;
	}
	
	printf("The estimated tax on your income is $%d\n", tax);

	return 0;
}


