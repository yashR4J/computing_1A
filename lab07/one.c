// Author: Yash Raj (z5317349)
// Date Modified: 15/07/2020
/*  */

#include <stdio.h>

#define MAXLINE 4096

int main(void) {

	char line[MAXLINE] = {0};
	int i;
    
    printf("Enter a string: ");
    fgets(line, MAXLINE, stdin);

	FILE *fptr;
	
	fptr = fopen("data.txt", "w");

	for (i = 0; (line[i] != '\0') && (line[i] != '\n'); i++) {
		fprintf(fptr,"%c\n", line[i]);
	}
	
	fclose(fptr);

	return 0;
}
