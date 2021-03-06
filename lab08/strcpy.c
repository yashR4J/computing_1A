#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copyString(char *str);

int main(int argc, char *argv[]) {
    // TODO BELOW
    //  part 2: need to check if "argc" is correct, and return 
    //  part 3: some code here is missing! That will prevent memory leaks
    
	if (argc == 2) {
		char *argvCopy = copyString(argv[1]);
    	printf("String 1: %s\n", argv[1]);
    	printf("String 2: %s\n", argvCopy);
		free(argvCopy);
	} else {
		printf("Please enter 1 argument: Your string\n");
		exit(0);
	}    
    
    // TODO ABOVE
    return 0;
}

char *copyString(char *str) {
    // TODO BELOW
    //  part 1: need to use "malloc" to create new memory of the right
    //  size then use "strcpy" to copy data from string into your new
    //  array
    
    char *copy = malloc(strlen(str)*sizeof(char) + 1);;
    // Create new memory of the same size as str but adds 1 to include
    // the null terminator 
    if (copy == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
    
    strcpy(copy, str);
    
   	return copy;
    // TODO ABOVE
}
