// Author: Yash Raj (z5317349)
// Date Modified: 15/07/2020
/* Read a string and test if it is a palindrome */

#include <stdio.h>

#define MAXLINE 4096

int palindrome(char line[]);

int main(void) {

    char line[MAXLINE] = {0};
    
    printf("Enter a string: ");
    fgets(line, MAXLINE, stdin);
    
    // Check if palindrome() function executes successfully
    if (palindrome(line)) {
        printf("String is a palindrome\n");
	} else {
		printf("String is not a palindrome\n");
	}
	
    return 0;
}

int palindrome(char line[]) {

	int i, j;

    for (i = 0; (line[i] != '\0') && (line[i] != '\n'); i++);
    i = i - 1; 
    
    for (j = 0; j < i; j++, i--) {
    	if (line[i] != line[j]) {
    		return 0;
    	}
    }

	return 1;
}
