// Author: Yash Raj (z5317349)
// Date Modified: 24/06/2020
/* Extension of tttBoard.c to see if there is a winner and print a suitable message */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void readBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
int winner(int board[SIZE][SIZE]);

int main(void) {

	int board[SIZE][SIZE] = {0};
	
	printf("Please enter the board:\n");
	readBoard(board);


	printf("Here is the board:\n\n");
	printBoard(board);
	printf("\n");

	int x = winner(board);

	if (x == 0) {
		printf("Noughts win\n");
	} else if (x == 1) {
		printf("Crosses win\n");
	} else if (x == 2) {
		printf("There are no winners\n");
	} else {
		printf("It is a draw\n");
	}

	return EXIT_SUCCESS;
}

void readBoard(int board[SIZE][SIZE]) {
	
	int row = 0, column = 0;	

		while (row < SIZE) {
			column = 0;
			while (column < SIZE) {
				scanf("%d\n", &board[row][column]);
				column++;
			} 
			row++;
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
		} 
		row++;
		printf("\n");
	}
}

int winner(int board[SIZE][SIZE]) {

	int row = 0, column = 0;
	int x = 0;

		
	while (row < SIZE) {
		column = 0;
		while (column < SIZE) {
			if (board[row][column] == 2) {
				x = 2;
			}
			column++;
		} 
		row++;
	}

	row = 0, column = 0;
	while (row < SIZE) {
		if (board[row][column] == board[row][column + 1] && 
		board[row][column] == board[row][column + 2]) {
			
			if (board[row][column] == 0) {
				x = 0;
			} else if (board[row][column] == 1) {
				x = 1;	
			}

		} 
		row++;
	} 

	row = 0;
	while (column < SIZE) {
		if (board[row][column] == board[row + 1][column] && 
		board[row][column] == board[row + 2][column]) {
			
			if (board[row][column] == 0) {
				x = 0;
			} else if (board[row][column] == 1) {
				x = 1;	
			}
		} 
		column++;
	} 
		
	column = 0;
	if (board[row][column] == board[row + 1][column + 1] && 
	board[row + 1][column + 1] == board[row + 2][column + 2]) {
		
		if (board[row][column] == 0) {
			x = 0;
		} else if (board[row][column] == 1) {
			x = 1;
		}

	} else if (board[row][column + 2] == board[row + 1][column + 1] && 
	board[row + 1][column + 1] == board[row + 2][column] ) {

		if (board[row][column] == 0) {
			x = 0;
		} else if (board[row][column] == 1) {
			x = 1;
		}
	}

	return x;
}
