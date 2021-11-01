// Author: Yash Raj (z5317349)
// Date modified: 20/06/2020
/* Use a function to calculate whether an year is a leap year */

#include<stdio.h>

int isLeapyear(int year);

int main(void) {

	int year;

	printf("Enter year: ");
	scanf("%d", &year);

	if (isLeapyear(year) == 0) {
		printf("%d is not a leap year.\n", year);
	} else {
		printf("%d is a leap year.\n", year);
	}

	return 0;
}

int isLeapyear(int year) {

	int x;

	if (year % 4 != 0) {
		x = 0;
	} else if (year % 100 != 0) {
		x = 1;
	} else if (year % 400 != 0) {
		x = 0;
	} else {
		x = 1;
	}

	return x;
}
