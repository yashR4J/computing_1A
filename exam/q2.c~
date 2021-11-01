// Last Modified by: Yash Raj
// Date last modified: 18/08/2020
// Question 2: Assuming valid inputs, convert 24 hour time to 12 hour 
// time

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 5

int main(void) {

	int i = 0, size = 0;
	char time[MAX_LINES][MAX_LEN + 4];
	
	// Excuse the hard coding here. Exam stress makes such necessary :)
	
	while (fgets(time[i], MAX_LEN, stdin) != NULL) {
		time[i][8] = '\0';
		time[i][7] = 'M';
		if (time[i][0] == '0' || (time[i][0] == '1' && 
			time[i][1] < '2')) {
			time[i][6] = 'A';
			time[i][5] = ' ';
			time[i][4] = time[i][3];
			time[i][3] = time[i][2]; 
			time[i][2] = ':';
		} else if (time[i][0] == '1' && time[i][1] == '2') {
			time[i][6] = 'P';
			time[i][5] = ' ';
			time[i][4] = time[i][3];
			time[i][3] = time[i][2]; 
			time[i][2] = ':';
		} else if (time[i][0] == '1' && time[i][1] > '2') {
			time[i][6] = 'P';
			time[i][5] = ' ';
			time[i][4] = time[i][3];
			time[i][3] = time[i][2]; 
			time[i][2] = ':';
			time[i][1] = time[i][1] - 2;
			time[i][0] = '0';
		} else if (time[i][0] == '2') {
			time[i][6] = 'P';
			time[i][5] = ' ';
			time[i][4] = time[i][3];
			time[i][3] = time[i][2]; 
			time[i][2] = ':';
			if (time[i][1] == '0') {
				time[i][0] = '0';
				time[i][1] = '8';
			} else if (time[i][1] == '1') {
				time[i][0] = '0';
				time[i][1] = '9';
			} else if (time[i][1] == '2') { 
				time[i][0] = '1';
				time[i][1] = '0';
			} else {
				time[i][0] = '1';
				time[i][1] = time[i][1] - 2;
				if (time[i][1] == '2') {
					time[i][6] = 'A';
				}
			}
		}
		i++;
	}

	size = --i; 
	for (i = 0; i < size; i++) {
		printf("%s", time[i]);
	}
	printf("\n");

	return 0;
}


