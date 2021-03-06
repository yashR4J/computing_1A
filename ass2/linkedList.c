/*
 ============================================================================
 Name        : 0x800.c
 Author      : Hayden Smith; Yash Raj
 Description : Hex based console version of the game "2048" for GNU/Linux
 ============================================================================
 */

// This is your standard includes for external modules
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// This includes a special file used for this assignment 
//  that was made for COMP1911
#include "0x800.h"

struct stack {
	int size;
	struct boardCopy *top;
};

struct boardCopy {
	 Board gameState;
	 struct boardCopy *next;
};

int main(int argc, char *argv[]) {
	char c;
	int success, undo;
	int seed = getSeed(argc, argv);
	int finishedGame = FALSE;

	Board board = newBoard();
	Stack s = stackCreate();
	
	// Do not move, replace, rename, or delete this function.
	// It carries out some necessary magic - be nice to it!
	//setAntiCrashMode(1);
	ignoreThisFunction1(board, seed, SIZE, DEBUG, TEXT_ONLY);

	// The function to populate the board from the command line
	//  argument is called. If there is no argument in command line
	//  then two random 
	int boardWasPopulated = populateBoard(board, argc, argv);
	if (!boardWasPopulated) {
		addRandom(board);
		addRandom(board);
	}
	
	stackPush(s, board);

	drawBoard(board);
	ignoreThisFunction2(board);
	
	// Continually executing the game loop until the game is finished
	while (!finishedGame) {
		c = getcharX();
			
		success = FALSE;
		undo = FALSE;
		
		// Check what kind of key press was made using getchar
		if (c == KEYBOARD_LEFT) {
			success = moveLeft(board);
		} else if (c == KEYBOARD_RIGHT) {
			success = moveRight(board); 
		} else if (c == KEYBOARD_UP) {
			success = moveUp(board);
		} else if (c == KEYBOARD_DOWN) {
			success = moveDown(board);
		} else if (c == 'q') {
			printfGame(">> QUIT? (y/n)");
			c = getcharX();
			if (c == 'y') {
				finishedGame = TRUE;
			} else {
				drawBoard(board);
			}
		} else if (c == 'r') { 
			printfGame(">> RESTART? (y/n)");
			c = getcharX();
			if (c == 'y') {
				freeBoard(board);
				board = newBoard();
				stackDestroy(s);
				s = stackCreate();
				if (boardWasPopulated) {
					populateBoard(board, argc, argv);
				} else {
					addRandom(board);
					addRandom(board);
				}
				stackPush(s, board);
				drawBoard(board); 
			} else {
				drawBoard(board);
			}
		} else if (c == 'u') {
			// Condition ensures that when 'u' is pressed, the board is 
			// not pushed into Stack s.
			undo = TRUE;
			if (stackSize(s) > 1) {
				stackPop(s, board);
				drawBoard(board);
			} else {
				drawBoard(board);
			}
		}

		// If a move key was pressed and the board was actually moved,
		//  then draw the board again, add a new random cell, draw the
		//  board again, and check if the game is finished
		
		if (success) {
			drawBoard(board);
			addRandom(board);
			drawBoard(board);
			if (gameEnded(board)) {
				printfGame(">> GAME OVER");
				finishedGame = TRUE;
			}
		}

		// Do not move, replace, rename, or delete this function.
		// It carries out some necessary magic - be nice to it!
		ignoreThisFunction2(board);
		
		if (success && !undo) {
			stackPush(s, board);
		}
		
	}

	// Because the game is finished, we need to call a function
	//  that frees the board pointer, then set that board pointer to NULL
	//  to ensure that no one can accidentally use free'd memory.
	stackDestroy(s); 
	s = NULL;
	freeBoard(board);
	board = NULL;

	// Do not move, replace, rename, or delete this function.
	// It carries out some necessary magic - be nice to it!
	ignoreThisFunction3(board);

	return 0;
}

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 1 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You do not need to edit the main function to complete this section.
// You only need to edit the code below.


// You need to malloc some memory (hint: most likely requiring multiple
//  malloc's), set all values in the board to be default to NULL, then
//  return a pointer to the board.
Board newBoard() {

	int i, j;
	Board board = malloc(SIZE * sizeof(char **)); 
	
	// Error message if malloc is unsuccessful
	if(board == NULL) {
        fprintf(stderr,"Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
	for (i = 0; i < SIZE; i++) {
		board[i] = malloc(SIZE * sizeof(char *));
		
		// Error message if malloc is unsuccessful
		if(board[i] == NULL) {
        	fprintf(stderr,"Insufficient Memory\n");
       		exit(EXIT_FAILURE);
    	}
		for (j = 0; j < SIZE; j++) {
			board[i][j] = NULL; 	
		}
	}	
	
	return board;
}

// The pointer to your board needs to be free'd. Before you free "board"
//  you also need to make sure you free any other memory you've malloced
//  that are contained within board
void freeBoard(Board board) {

	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] != NULL) {
				free(board[i][j]);
			}
		}
		free(board[i]);
	}
	free(board);

}

// The second argument passed into the program is the "input string". For
//  more information on this please see the assignment specification.
int populateBoard(Board board, int argc, char* argv[]) {

	int i, j;
	int decValue[SIZE][SIZE] = {0};
	
	if (argc >= 2) {
		if(strlen(argv[1]) == SIZE*SIZE) {
			
			for (i = 0; i < SIZE; i++) {
				for (j = 0; j < SIZE; j++) {
					// Convert input to decimal value
					if ((argv[1][i*SIZE + j] == 'A') || 
    					(argv[1][i*SIZE + j] == 'B')) {
    					decValue[i][j] = 
    					pow(2, argv[1][i*SIZE + j] - 'A' + 10);
    				} else if ((argv[1][i*SIZE + j] != '0')) {
    					decValue[i][j] = 
    					pow(2, argv[1][i*SIZE + j] - '0');
    				} else {
    					decValue[i][j] = 0;
    				}
    				// Convert decimal to hexadecimal string and store 
    				// in board
    				if (decValue[i][j] != 0) {
    				// The size of memory allocated to the string in
    				// each cell is a max. of 6 bytes (for "0x800")
    					board[i][j] = 
    					malloc(SIZE * sizeof(* board[i][j]) + 2);
    					
    					// Error message if malloc is unsuccessful
    					if(board[i][j] == NULL) {
        					fprintf(stderr,"Insufficient Memory\n");
       						exit(EXIT_FAILURE);
    					}
    					decToHexStr(decValue[i][j], board[i][j]);
    				}
				}

			}
			return TRUE;
		} else {
			printf("Please enter a valid populate string\n");
			exit(EXIT_FAILURE);
		}
	} 

	return FALSE;
}

void decToHexStr(int dec, char *str) { 
	sprintf(str, "%#0x", dec);
}

// THIS FUNCTION IS ALREADY COMPLETE, IT IS HERE PURELY FOR DEMONSTRATION
// The first argument passed into the program is the "seed" for the
//  random number generator (that you don't have to worry about)
int getSeed(int argc, char* argv[]) {
	int ret = FALSE;
	if (argc == 3) {
		ret = atoi(argv[2]);
	}
	return ret;
}

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 2 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You do not need to edit the main function to complete this section.
// You only need to edit the code below.
// You are welcome to write/define more functions of your own and include
//  them in this section. In fact - we encourage you to write more of your
//  own functions down here.


// STUDENT'S NOTE:
// The functions below behave as bool functions and utilise the same 
// approach. Each function creates two copies of the current board
// gameState in order to check whether a successful move has been made.
// By rotating each board different numbers of times, each function is 
// made simpler such that the slideAndMerge part always slides each row 
// to the left only. Once the slideAndMerge is made to the decValue[][], 
// this 2D integer array is compared to duplicate[][] using the 
// compareToDuplicate function, which returns TRUE only if both 2D 
// arrays are different (in which case a successful move has been made).


// Function moves all of the cells to the very bottom
//  of the board. During the process any two cells that are
//  adjacent in the vertical direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveUp(Board board) {

	int move = FALSE;
	int decValue[SIZE][SIZE] = {0};
	int duplicate[SIZE][SIZE] = {0};
	
	rotate(board);
	
	// Convert Board to Decimal and store in temporary integer array. 
	// Then, create a temporary duplicate of the integer array.
	hexToDecBoard(board, decValue);
	copyArray(duplicate, decValue);
	
	// Slide and Merge
	slideLeft(decValue);
	mergeLeft(decValue);
	slideLeft(decValue);
	
	// Compare to original duplicate to test whether move was successful
	// and then, modify the board again.
	move = compareToDuplicate(decValue, duplicate);
	decToHexBoard(board, decValue);
	
	rotate(board);
	rotate(board);
	rotate(board);
	
	return move;
}

// Function moves all of the cells to the very bottom
//  of the board. During the process any two cells that are
//  adjacent in the vertical direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveDown(Board board) {
	 
	int move = FALSE;
	int decValue[SIZE][SIZE] = {0};
	int duplicate[SIZE][SIZE] = {0};
	
	rotate(board);
	rotate(board);
	rotate(board);
	
	hexToDecBoard(board, decValue);
	copyArray(duplicate, decValue);
	
	slideLeft(decValue);
	mergeLeft(decValue);
	slideLeft(decValue);
	
	move = compareToDuplicate(decValue, duplicate);
	decToHexBoard(board, decValue);
	
	rotate(board);
	
	return move;
}

// Function moves all of the cells to the very left hand
//  side of the board. During the process any two cells that are
//  adjacent in the horizontal direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveLeft(Board board) {

	int move = FALSE;
	int decValue[SIZE][SIZE] = {0};
	int duplicate[SIZE][SIZE] = {0};
	
	hexToDecBoard(board, decValue);
	copyArray(duplicate, decValue);
	
	slideLeft(decValue);
	mergeLeft(decValue);
	slideLeft(decValue);
	
	move = compareToDuplicate(decValue, duplicate);
	decToHexBoard(board, decValue);

	return move;
}

// Function moves all of the cells to the very right hand
//  side of the board. During the process any two cells that are
//  adjacent in the horizontal direction should be merged.
// The function returns TRUE if ANY cells were moved, and FALSE if no
//  cells were moved
int moveRight(Board board) { 

	int move = FALSE;
	int decValue[SIZE][SIZE] = {0};
	int duplicate[SIZE][SIZE] = {0};
	
	rotate(board);
	rotate(board);
	
	hexToDecBoard(board, decValue);
	copyArray(duplicate, decValue);
	
	slideLeft(decValue);
	mergeLeft(decValue);
	slideLeft(decValue);
	
	move = compareToDuplicate(decValue, duplicate);
	decToHexBoard(board, decValue);
		
	rotate(board);
	rotate(board);

	return move;
}

void rotate(Board board) {

	int i, j;
	int decValue[SIZE][SIZE] = {0};
	int duplicate[SIZE][SIZE] = {0};
	
	// Convert Board to Decimal and store in temporary integer array. 
	// Then, create a temporary duplicate of the integer array.
	hexToDecBoard(board, decValue);
	copyArray(duplicate, decValue);
	
	// Rotate 2D integer array anti-clockwise
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			decValue[i][j] = duplicate[j][SIZE - i - 1];
		}
	}
	
	// Update board state
	decToHexBoard(board, decValue);
}

void hexToDecBoard(Board board, int decValue[SIZE][SIZE]) { 
	
	int i, j;
	
	// Convert Board to Decimal and store in temporary integer array
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] != NULL) {
			decValue[i][j] = hexToDecInt(board[i][j]);
			} else {
			decValue[i][j] = 0;
			}
		}
	}
	
}

void copyArray(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]) {
		
	int i, j;
	
	// Create a duplicate copy of arr2 in arr1.
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}	

void slideLeft(int arr1[SIZE][SIZE]) {

	int i, j, counter; 

	// Slide all cells to the left and move all zeroes (i.e. NULL in 
	// board) to the right.
	for (i = 0; i < SIZE; i++) {
		counter = 0;
		for (j = 0; j < SIZE; j++) {
			if(arr1[i][j] != 0) {
				arr1[i][counter++] = arr1[i][j];
			}
		}
		while (counter < SIZE) {
			arr1[i][counter] = 0;
			counter++;
		} 
	}	
}

void mergeLeft(int arr1[SIZE][SIZE]) {

	int i, j;
	
	// If adjacent cell to the left is the same, merge and add 
	// corresponding integer values.
	for (i = 0; i < SIZE; i++) {
		for (j = 1; j < SIZE; j++) {
			if (arr1[i][j - 1] ==  arr1[i][j]) {
				arr1[i][j - 1] = arr1[i][j] + arr1[i][j - 1];
				arr1[i][j] = 0;
			}
		} 	
	}
}

int compareToDuplicate(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]) {

	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				return TRUE; // Move was successful.
			}
		}
	}
	return FALSE; // Move was unsuccessful.
}

void decToHexBoard(Board board, int decValue[SIZE][SIZE]) {
	
	int i, j;
	
	// Convert Board Back to Hexadecimal
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			// Dynamically allocated memory for each cell
			if (board[i][j] == NULL) {
				board[i][j] = malloc(SIZE * sizeof(* board[i][j]) + 2);
				
				// Error message if malloc is unsuccessful
				if(board[i][j] == NULL) {
        			fprintf(stderr,"Insufficient Memory\n");
       				exit(EXIT_FAILURE);
    			}
			}
			// Assign hex. string to board and free memory if 
			// decimal equivalent is zero
			if (decValue[i][j] != 0) {
				decToHexStr(decValue[i][j], board[i][j]);
			} else if (decValue[i][j] == 0 && board[i][j] != NULL) {
				free(board[i][j]);
				board[i][j] = NULL;
			}
			
		}
	}
}

int hexToDecInt(char *str) {
	int value;
	// Convert hex. string to long using strtol and assign to integer, 
	// which implicitly converts the value by copying it.
	value = strtol(str, NULL, 16);
	return value;
}

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 3 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You probably don't need to write any code down here, you can just
//  write it into the main function.

/////////////////////////////////////////////////////////////////////
//////////////////////////// Part 4 /////////////////////////////////
/////////////////////////////////////////////////////////////////////

// You will need to write code down here AND inside the main function.
// We have not given you any starter code for this section. You will
//  have to start your own

Stack stackCreate(void) {
	// Create stack
    Stack s = malloc(sizeof(struct stack));
	
	// Error message if malloc is unsuccessful
    if(s == NULL) {
        fprintf(stderr,"Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
    
    s->size = 0;
    s->top = NULL;
    
    return s;
}

void stackDestroy(Stack s) {
	Board board = newBoard();	
	while (s->top != NULL) {
		stackPop(s, board);
	}
	freeBoard(board);
    free(s);
}

void stackPush(Stack s, Board board) {
	int decValue[SIZE][SIZE] = {0};	
    struct boardCopy *b = malloc(sizeof(struct boardCopy));
    b->gameState = newBoard();
    hexToDecBoard(board, decValue);
	decToHexBoard(b->gameState, decValue);
    b->next = s->top;
    s->top = b;
    s->size++;
}

void stackPop(Stack s, Board board) {
	int decValue[SIZE][SIZE] = {0};	
	struct boardCopy *b = s->top;
	s->top = b->next;
	hexToDecBoard(b->gameState, decValue);
	decToHexBoard(board, decValue);
	free(b->gameState);
	free(b);
	s->size--;
}
	
int stackSize(Stack s) {
    return s->size;
}


