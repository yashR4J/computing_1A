// Author: Yash Raj (z5317349)
// Date Modified: 24/06/2020
/* Reads in a 3x3 noughts and crosses (Tic-Tac-Toe) board, stores it in a 2D
array and then prints it out. Assumes a valid input, with 0 for Noughts, 1 for
Crosses and 2 for Empty Squares (or Dots rather) */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void readBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);

int main(void) {

	int board[SIZE][SIZE] = {0};
	
	printf("Please enter the board:\n");
	readBoard(board);


	printf("Here is the board:\n\n");
	printBoard(board);
	printf("\n");

	return EXIT_SUCCESS;
}

void readBoard(int board[SIZE][SIZE]) {
	
	int row = 0, column = 0;	

		while (row < SIZE) {
			column = 0;
			while (column < SIZE) {
				scanf("%d\n", &board[row][column]);
				column++;
			} row++;
		}
}

void printBoard(int board[SIZE][SIZE]) {
	
	int row = 0, column = 0;

	while (row < SIZE) {
		column = 0;
		while (column < SIZE) {
			if (board[row][column] == 0) {
			printf("O ");
			} else if (board[row][column] == 1) {
			printf("X ");
			} else if (board[row][column] == 2) {
			printf(". ");
			}
			column++;
		} row++;
		printf("\n");
	}
}
