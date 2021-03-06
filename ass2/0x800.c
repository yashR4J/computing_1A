/*
 ============================================================================
 Name        : 0x800.c
 Author      : Hayden Smith; Yash Raj (z5317349)
 Description : Hex based console version of the game "2048" for GNU/Linux
 ============================================================================
*/

// This includes a special file used for this assignment that was made 
// for COMP1911
#include "0x800.h"

int main(int argc, char *argv[]) {
	char c;
	bool success = FALSE, undo = FALSE;
	int seed = getSeed(argc, argv);
	int finishedGame = FALSE;

	Board board = newBoard();
	Stack s = stackCreate();
		
	// Do not move, replace, rename, or delete this function.
	// It carries out some necessary magic - be nice to it!
	// setAntiCrashMode(1);
	ignoreThisFunction1(board, seed, SIZE, DEBUG, TEXT_ONLY);

	// The function to populate the board from the command line
	// argument is called. If there is no argument in command line
	// then two random.
	bool boardWasPopulated = populateBoard(board, argc, argv);
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
		} else if (c == QUIT) {
			printfGame(">> QUIT? (y/n)");
			c = getcharX();
			if (c == 'y') {
				finishedGame = TRUE;
			} else {
				drawBoard(board);
			}
		} else if (c == RESTART) { 
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
		} else if (c == UNDO) {
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
		
		// Push onto stack after key press
		if (success && !undo) {
			stackPush(s, board);
		} 		

	}

	// Because the game is finished, we need to call a function
	//  that frees the board pointer, then set that board pointer to NULL
	//  to ensure that no one can accidentally use free'd memory.

	stackDestroy(s); 
	freeBoard(board);

	// Do not move, replace, rename, or delete this function.
	// It carries out some necessary magic - be nice to it!
	ignoreThisFunction3(board);

	return 0;
}

/////////////////////////////////////////////////////////////////////
////////////////////////////// Part 1 ///////////////////////////////
/////////////////////////////////////////////////////////////////////

// You do not need to edit the main function to complete this section.
// You only need to edit the code below.

// You need to malloc some memory (hint: most likely requiring multiple
//  malloc's), set all values in the board to be default to NULL, then
//  return a pointer to the board.
Board newBoard(void) {

	Board board = malloc(SIZE * sizeof(char **)); 
	// Error message if malloc is unsuccessful
	if (board == NULL) {
        fprintf(stderr, "Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
	for (int i = 0; i < SIZE; ++i) {
		board[i] = malloc(SIZE * sizeof(char *));
		// Error message if malloc is unsuccessful
		if(board[i] == NULL) {
			fprintf(stderr, "Insufficient Memory\n");
			exit(EXIT_FAILURE);
    	}	
		for (int j = 0; j < SIZE; ++j) {
			board[i][j] = NULL; 	
		}
	}	
	return board;
}

// The pointer to your board needs to be free'd. Before you free "board"
//  you also need to make sure you free any other memory you've malloced
//  that are contained within board
void freeBoard(Board board) {

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] != NULL) {
				free(board[i][j]);
				board[i][j] = NULL;
			}
		}
		free(board[i]);
		board[i] = NULL;
	}
	free(board);
	board = NULL;
}

// The second argument passed into the program is the "input string". 
// For more information on this please see the assignment specification.
bool populateBoard(Board board, int argc, char *argv[]) {

	if (argc >= 2) {
		if (strlen(argv[1]) == SIZE * SIZE) {	
			inputToBoard(board, argc, argv);		
			return TRUE;
		} else {
			printf("Please enter a valid populate string\n");
			exit(EXIT_FAILURE);
		}
	} 
	return FALSE;
}

// Logic for populateBoard has been shifted to the following function.
void inputToBoard(Board board, int argc, char *argv[]) {

	int decValue[SIZE][SIZE] = {0};

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			// Convert terminal input to decimal value and store in 
			// 2D integer array
			if ((argv[1][i*SIZE + j] == 'A') || 
    			(argv[1][i*SIZE + j] == 'B')) {
    			decValue[i][j] = 
    			pow(2, argv[1][i*SIZE + j] - 'A' + 10);
    		} else if ((argv[1][i*SIZE + j] >= '1') && 
    			(argv[1][i*SIZE + j] <= '9')) {
    			decValue[i][j] = 
    			pow(2, argv[1][i*SIZE + j] - '0');
    		} else if (argv[1][i*SIZE + j] == '0') {
    			decValue[i][j] = 0;
    		} else {
    			printf("Please enter a valid populate string\n");
				exit(EXIT_FAILURE);
    		}
		}
	}
	// Transfer values in 2D integer array from terminal to hexadecimal
	// game board.
	decToHexBoard(board, decValue);
}

void decToHexBoard(Board board, int decValue[SIZE][SIZE]) {
	
	// Convert 2D integer array to Hexadecimal Board
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			// Dynamically allocate memory for each cell
			if (board[i][j] == NULL) {
				board[i][j] = malloc(SIZE * sizeof(*board[i][j]) + 2);
				// Error message if malloc is unsuccessful
				if (board[i][j] == NULL) {
					fprintf(stderr, "Insufficient Memory\n");
					exit(EXIT_FAILURE);
    			}
			}
			// Convert integers to hexadecimal string and store in 
			// board. Also, free memory if integer equivalent is 0 and 
			// board has memory allocated.
			if (decValue[i][j] != 0) {
				sprintf(board[i][j], "%#0x", decValue[i][j]);
			} else if (decValue[i][j] == 0 && board[i][j] != NULL) {
				free(board[i][j]);
				board[i][j] = NULL;
			}
		}
	}
}

// THIS FUNCTION IS ALREADY COMPLETE, IT IS HERE PURELY FOR DEMONSTRATION.
// The first argument passed into the program is the "seed" for the
//  random number generator (that you don't have to worry about)
int getSeed(int argc, char *argv[]) {
	int ret = FALSE;
	if (argc == 3) {
		ret = atoi(argv[2]);
	}
	return ret;
}

/////////////////////////////////////////////////////////////////////
////////////////////////////// Part 2 ///////////////////////////////
/////////////////////////////////////////////////////////////////////

// You do not need to edit the main function to complete this section.
// You only need to edit the code below.
// You are welcome to write/define more functions of your own and 
// include them in this section. In fact - we encourage you to write 
// more of your own functions down here.

/////////////////////////////////////////////////////////////////////
/////////////////////////// STUDENT NOTE ////////////////////////////
/////////////////////////////////////////////////////////////////////

// Each function below has the same logic, which has been moved to the 
// moveCommands function for clarity. The functions below are present 
// merely to indicate different numbers of board rotations corresponding 
// to the key pressed (w, a, s, d) by the user. 

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

// Function moves all of the cells to the very bottom of the board. 
// During the process any two cells that are adjacent in the vertical 
// direction should be merged. The function returns TRUE if ANY cells 
// were moved, and FALSE if no cells were moved.
bool moveUp(Board board) {

	bool move = FALSE;
	
	rotate(board);
	move = moveCommands(board, move);
	rotate(board);
	rotate(board);
	rotate(board);
	
	return move;
}

// Function moves all of the cells to the very bottom of the board. 
// During the process any two cells that are adjacent in the vertical 
// direction should be merged. The function returns TRUE if ANY cells 
// were moved, and FALSE if no cells were moved.
bool moveDown(Board board) {
	 
	bool move = FALSE;
		
	rotate(board);
	rotate(board);
	rotate(board);
	move = moveCommands(board, move);
	rotate(board);
	
	return move;
}

// Function moves all of the cells to the very bottom of the board. 
// During the process any two cells that are adjacent in the vertical 
// direction should be merged. The function returns TRUE if ANY cells 
// were moved, and FALSE if no cells were moved.
bool moveLeft(Board board) {

	bool move = FALSE;
		
	move = moveCommands(board, move);

	return move;
}

// Function moves all of the cells to the very bottom of the board. 
// During the process any two cells that are adjacent in the vertical 
// direction should be merged. The function returns TRUE if ANY cells 
// were moved, and FALSE if no cells were moved.
bool moveRight(Board board) { 

	bool move = FALSE;

	rotate(board);
	rotate(board);
	move = moveCommands(board, move);
	rotate(board);
	rotate(board);

	return move;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////// STUDENT NOTE ////////////////////////////
/////////////////////////////////////////////////////////////////////

// The moveCommands function first creates two copies of the current 
// board gameState to keep track of the Before/After gameState. This 
// will tell us whether a move has been made or not.

// The function then executes the slideAndMerge, which slides each row 
// to the left only and merges adjacent cells with same values. Once 
// the slideAndMerge is executed to after[][] 2D integer array, the 
// array is compared to before[][] using the compareBeforeAndAfter 
// function. This function returns TRUE only if both 2D arrays are 
// different (in which case a successful move has been made). 

// Finally, the board is updated in the moveCommands function, and the 
// function returns the the value associated with move, which is also 
// returned in the respective move function called. This ultimately 
// determines whether success is TRUE or FALSE in the main function.

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

bool moveCommands(Board board, bool move) {

	int before[SIZE][SIZE] = {0};
	int after[SIZE][SIZE] = {0};
	
	// Convert Board to Decimal and store in two temporary integer 
	// arrays.
	hexToDecBoard(board, after);
	hexToDecBoard(board, before);
	
	// Slide and Merge
	slideLeft(after);
	mergeLeft(after);
	slideLeft(after);
	
	// Compare to before gameState to test whether move was successful
	// and then, modify the board again.
	move = compareBeforeAndAfter(after, before);
	decToHexBoard(board, after);
	
	return move;
}

void rotate(Board board) {

	int rotatedBoard[SIZE][SIZE] = {0};
	int copy[SIZE][SIZE] = {0};
	
	// Convert Board to Decimal and store in two temporary integer 
	// arrays.
	hexToDecBoard(board, rotatedBoard);
	hexToDecBoard(board, copy);
	
	// Rotate 2D integer array anti-clockwise
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			rotatedBoard[i][j] = copy[j][SIZE - i - 1];
		}
	}
	
	// Modify board state to reflect changes made to rotated board.
	decToHexBoard(board, rotatedBoard);
}

void hexToDecBoard(Board board, int decValue[SIZE][SIZE]) { 
	// Convert Board to Decimal and store in temporary integer array
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] != NULL) {
				// Convert hex. string to long using strtol and assign 
				// to integer array,  converting the long to integer by 
				// copying it.
				decValue[i][j] = strtol(board[i][j], NULL, 16);
			} else {
				decValue[i][j] = 0;
			}
		}
	}
}

void slideLeft(int arr1[SIZE][SIZE]) {

	int counter; 
	// Slide all cells to the left and move all zeroes (i.e. NULL in 
	// board) to the right.
	for (int i = 0; i < SIZE; ++i) {
		counter = 0;
		for (int j = 0; j < SIZE; ++j) {
			if (arr1[i][j] != 0) {
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

	// If adjacent cell to the left is the same, merge and add 
	// corresponding integer values.
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 1; j < SIZE; ++j) {
			if (arr1[i][j - 1] ==  arr1[i][j]) {
				arr1[i][j - 1] = arr1[i][j] + arr1[i][j - 1];
				arr1[i][j] = 0;
			}
		} 	
	}
}

bool compareBeforeAndAfter(int before[SIZE][SIZE], int after[SIZE][SIZE]) {

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (before[i][j] != after[i][j]) {
				return TRUE; // Move was successful.
			}
		}
	}
	return FALSE; // Move was unsuccessful.
}

/////////////////////////////////////////////////////////////////////
////////////////////////////// Part 3 ///////////////////////////////
/////////////////////////////////////////////////////////////////////

// You probably don't need to write any code down here, you can just
//  write it into the main function.

/////////////////////////////////////////////////////////////////////
////////////////////////////// Part 4 ///////////////////////////////
/////////////////////////////////////////////////////////////////////

// You will need to write code down here AND inside the main function.
// We have not given you any starter code for this section. You will
// have to start your own.

Stack stackCreate(void) {
	// Create stack
    Stack s = malloc(sizeof(struct stack));
	// Error message if malloc is unsuccessful
    if (s == NULL) {
        fprintf(stderr, "Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
    s->size = 0;
    return s;
}

void stackPush(Stack s, Board board) {

	int decValue[SIZE][SIZE] = {0};
	
	// Create new boards that hold the same cells as the 
	// current gameState
	Board copyBoard = newBoard();

	hexToDecBoard(board, decValue);
	decToHexBoard(copyBoard, decValue);
	
    if (s->size < STACK_SIZE) {
		s->gameStates[s->size] = copyBoard;
		s->size++;
	} else {  
		// If game cannot push any further, return error. 
		// Ideally, a linked list implementation which allocates memory 
		// as required could be implemented rather than a gameState 
		// array with a fixed STACK_SIZE.
		fprintf(stderr, "Stack Overflow\n");
		stackDestroy(s);
		exit(EXIT_FAILURE);
	}		
}

void stackPop(Stack s, Board board) {
	int decValue[SIZE][SIZE] = {0};
	int index = s->size - 1;

	if (index == 0) {
		fprintf(stderr, "Empty Stack\n");
		stackDestroy(s);
		exit(EXIT_FAILURE);	
	}
	
	// Free gameState being popped
	freeBoard(s->gameStates[index]);
	s->gameStates[index] = NULL;
	
	// Decrement size of gameState elements in stack
	s->size--; 
	
	// Update board to return to its previous gameState
	hexToDecBoard(s->gameStates[index - 1], decValue);
	decToHexBoard(board, decValue);
}
 
int stackSize(Stack s) {
    return s->size;
}

void stackDestroy(Stack s) {	
	for (int index = s->size - 1; index >= 0; index--) {
		// Free each element in the gameStates[] (which holds a history 
		// of all played moves (up to max. of STACK_SIZE moves))  
		freeBoard(s->gameStates[index]);
		s->gameStates[index] = NULL;
	}
    free(s);
    s = NULL;
} 
