// Last Modified by: Yash Raj
// Date last modified: 18/08/2020
// Question 3: Determine whether a n x n array is a magic square

// EXAM C Standard Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

bool invalid(int size, int **board);
bool repeated(int *duplicate, int size);
bool horizontal(int size, int magic, int **board);
bool vertical(int size, int magic, int **board);
bool diagonal(int size, int magic, int **board);

int main(void) {

	int i, j, size = 0;
	scanf("%d", &size);
	
	int **board = malloc(size * sizeof(int *)); 
	for (i = 0; i < size; i++) {
		board[i] = malloc(size * sizeof(int));
	}
	int *duplicate = malloc(size*size*(sizeof(int)));
	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {	
			int success = scanf("%d", &board[i][j]);
			if (success == -1) { // Ideally could be moved to a function
				for (i = 0; i < size; i++) {
					free(board[i]);
				}
				free(board);
				free(duplicate);
				printf("Invalid data: missing or repeated number\n");
				exit(EXIT_FAILURE);
			}
			duplicate[size*i + j] = board[i][j];
		}
	}
	
	int magic = 0; 
	for (i = 0; i < size; i++) {	
		magic += board[i][i];
	}
	
	if (invalid(size, board) || repeated(duplicate, size*size)) {
		printf("Invalid data: missing or repeated number\n");
	} else if (horizontal(size, magic, board) 
		&& vertical(size, magic, board) 
		&& diagonal(size, magic, board)) {
		printf("Magic square\n");
	} else {
		printf("Not a magic square\n");
	}
	
	for (i = 0; i < size; i++) {
		free(board[i]);
	}
	free(board);
	free(duplicate);
	return 0;
}

bool invalid(int size, int **board) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {	
			if (board[i][j] > size*size || board[i][j] < 0) {
				return true;
			}
		}
	}
	return false;
}

bool repeated(int *duplicate, int size) {
	// Check for repeated elements by traversing array
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size - 1; j++) {	
			if (duplicate[i] == duplicate[j]) {
				return true;
			}
		}
	} 
	return false;
}

bool horizontal(int size, int magic, int **board) {
	int sum[MAX_SIZE] = {0};
	int counter = 0;
	
	for (int i = 0; i < size; i++) {
		sum[i] = 0;
		for (int j = 0; j < size; j++) {	
			sum[i] += board[i][j];
		}
		if (sum[i] == magic) {
		counter++;
		}
	}
	
	
	if (counter == size) {
		return true;
	}
	return false;
}

bool vertical(int size, int magic, int **board) {
	int sum[MAX_SIZE] = {0};
	int counter = 0;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {	
			sum[i] += board[j][i];
		}
		if (sum[i] == magic) {
		counter++;
		}
	}
		
	if (counter == size) {
		return true;
	}
	return false;
}

bool diagonal(int size, int magic, int **board) {
	int sum[2] = {0}, counter = 0;
	
	for (int i = 0; i < size; i++) {	
		sum[0] += board[i][i];
		if (sum[0] == magic) {
		counter++;
		}
	}
	for (int i = size - 1, j = 0; j < size; i--, j++) {	
		sum[1] += board[i][j];
		if (sum[1] == magic) {
		counter++;
		}
	}
	
	if (counter == 2) {
		return true;
	}
	return false;
}
