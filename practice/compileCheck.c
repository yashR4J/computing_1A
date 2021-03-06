#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 4

typedef char* cell;
typedef cell** Board;
/*
void slideAndMerge(int **nums);
void slide(int **nums);
void merge(int **nums);
*/

void DecToHexStr(int dec, char *str);
Board newBoard();
void freeBoard(Board board);
long int HexToDecInt(char *str);

int main(int argc, char* argv[]) {
	int myArray[SIZE][SIZE] = {0};
	int i,j;
	long int newArray[SIZE][SIZE] = {0};

	Board board = newBoard();

	i = 0;
    while (i < SIZE) {
       	j = 0;
	    while (j < SIZE) {
	        int number = getchar() - '0';
	        myArray[i][j] = number;
	        DecToHexStr(myArray[i][j], board[i][j]);
	        j++;
	    }
       	printf("\n");
      	i++;
   	}
	
	i = 0;
    while (i < SIZE) {
       	j = 0;
	    while (j < SIZE) {
	        printf("%d\t%s\t%ld\n", myArray[i][j], board[i][j], 
	        	newArray[i][j] = pow(3, HexToDecInt(board[i][j])));
	        j++;
	    }
       	printf("\n");
      	i++;
   	}
   	/*
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			slideAndMerge(myArray[i][j]);
		}
	}
	
	i = 0;
    while (i < SIZE) {
       	j = 0;
	    while (j < SIZE) {
	        printf("%#0x", myArray[i][j]);
	        j++;
	    }
       	printf("\n");
      	i++;
   	}*/

	freeBoard(board);

	return 0;
}

/*

void slideAndMerge(int **nums) {
	
	slide(nums);
	merge(nums);
	slide(nums);

}

void slide(int **nums) {

	int i, j, counter = 0;
	
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if(nums[i][j] != 0) {
				nums[i][counter++] = nums[i][j];
			}
		}
	}
	for (i = 0; i < SIZE; i++) {
		for (counter = 0; counter < SIZE; counter++) {
			nums[i][counter] = 0;
		}
	}

}

void merge(int **nums) {

	int i, j;
	
	for (i = 0; i < SIZE; i++) {
		for (j = 1; j < SIZE; j++) {
			if (nums[i][j - 1] ==  nums[i][j]) {
				nums[i][i - 1] = nums[i][j] + nums[i][j - 1];
				nums[i][j] = 0;
			}
		}
	}

}

*/
void DecToHexStr(int dec, char *str) { 
	sprintf(str, "%#0x", dec);
}

long int HexToDecInt(char *str) { 
	long int value;
	value = strtol(str, NULL, 16);
	return value;
}

void freeBoard(Board board) {

	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			free(board[i][j]);
		}
		free(board[i]);
	}
	free(board);

}
Board newBoard() {

	int i, j, k;
	Board board = malloc(SIZE * sizeof(cell)); 
	
			for (i = 0; i < SIZE; i++) {
				board[i] = malloc(SIZE * sizeof(* board[i]));

				for (j = 0; j < SIZE; j++) {
					// The size of memory allocated to the string 
					// in each cell is a max. of 6 bytes (for "0x800")
					board[i][j] = 
					malloc(SIZE * sizeof(* board[i][j]) + 2);

					for (k = 0; k < SIZE + 2; k++) {
						board[i][j][k] = '\0'; 
						//Check if this is what the task implies
					}
				}
			}
			
	return board;
}


