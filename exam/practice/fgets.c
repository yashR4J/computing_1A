// Last Modified by: Yash Raj
// Date last modified: 18/08/2020
// This program reads the number of lines inputted.

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 50

int main(void) {

	char lines[MAX_LINES][MAX_LEN];
	
	int i = 0;
	
	// char *str = "Hello"
	// fgets(str, MAX_LEN, stdin);
	
	while (fgets(lines[i], MAX_LEN, stdin) != NULL) {
		i++;
	}
	
	i--; 
	printf("Reversed Lines: \n");
	while (i >= 0) {
		fputs(lines[i], stdout);
		i--;
	}
	
	return 0;
}


