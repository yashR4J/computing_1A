// Author: Yash Raj (z5317349)
// Date Modified: 15/07/2020
/* Read a string and test if it is a palindrome (modified to read 
sentences and ignore non-letters and treat all lower-case and upper-case
letters equally */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 4096

int palindrome(char *);

int main(void) {

    char input[MAXLINE] = {0};
    
    printf("Enter a string: ");
    fgets(input, MAXLINE, stdin);
    
    // Check if palindrome() function executes successfully
    if (palindrome(input) == EXIT_SUCCESS) {
        printf("String is a palindrome\n");
	} else {
		printf("String is not a palindrome\n");
	}
	
    return EXIT_SUCCESS;
}

int palindrome(char *s) {

	int i, j = strlen(s);

	// Convert string to lowercase
    for (i = 0; i < j; i++) {
    	s[i] = tolower(s[i]);
    }
    
    i = 0;
    while (i < j) {
    	// Ignore non-letter characters
    	if (!(s[i] >= 'a' && s[i] <= 'z')) { 
    		i++;
		} else if (!(s[j] >= 'a' && s[j] <= 'z')) {
			j--;
		} 
		// Test if string is a palindrome
		else if (s[i] == s[j]) {
			i++, j--;
		} else {
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

