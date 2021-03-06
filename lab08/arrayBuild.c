#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

void printArray(int **arr);

int main(int argc, char *argv[]) {

    // TODO BELOW
    //  part1: ensure the right number of arguments have been passed in
    //  part2: ensure the argument we're interested is in of right length
    //  part3: malloc your 2D array and populate it
    if (argc == 2) {
    
    	if(strlen(argv[1]) == SIZE*SIZE) {
    		// Create myArray with 3 columns i.e. 3 integer pointers
			int **myArray = malloc(SIZE * sizeof(int *)); 
			if (myArray == NULL) {
				printf("malloc error\n");
				exit(EXIT_FAILURE);
			}
			
			int i = 0, j = 0;
			while (i < SIZE) {
				myArray[i] = malloc(SIZE * sizeof(int));
				
				if (myArray[i] == NULL) {
					printf("malloc error\n");
					exit(EXIT_FAILURE);
				}
				
				j = 0;
				while (j < SIZE) {
				    myArray[i][j] = argv[1][i*SIZE + j] - '0';
				    j++;
				}
				i++;
			}
			printArray(myArray);
			for (i = 0; i < SIZE; i++) {
				free(myArray[i]);
			}
			free(myArray);
			myArray = NULL;
		} else {
			printf("Please enter the correct size\n");
		}
	} else {
		printf("Please enter 1 argument: Your array\n");
		exit(0);
	}    
   
    // TODO ABOVE

	return 0;
}

void printArray(int **arr) {
    int i = 0;
    int j = 0;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
