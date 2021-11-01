#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Currently the program is setup to have the board automatically 
//  print out "over itself" (some magic) so that it feels more like
//  a game. If you set Debug to be "1" (i.e. true) then the program
//  will stop doing this, and print out all output sequentially.
//  It will look like printing out each board line after line.
//  This is VERY!!!!!!!! useful for debugging
#define DEBUG 0

// This only prints the game out as text
#define TEXT_ONLY 0

// Standard TRUE and FALSE definitions
//  to make code easier to read
#define TRUE 1
#define FALSE 0

// Size of the board. You CAN edit this if you want, but at your own 
// peril. It's kind of fun, though.
#define SIZE 4

// The following just abstracts the particular ascii characters for 
// keyboard left, right, up, and down arrows.
#define KEYBOARD_LEFT 'a'
#define KEYBOARD_RIGHT 'd'
#define KEYBOARD_UP 'w'
#define KEYBOARD_DOWN 's'

// The same has also been done for quit, restart and undo.
#define QUIT 'q'
#define RESTART 'r'
#define UNDO 'u'

// Stack Size
#define STACK_SIZE 1024

// These are the typedefs for the type of an individual CELL (which is
// just a string) and the BOARD which is a 2D array that contains type 
// cells.
typedef char *cell;
typedef cell **Board;

typedef struct stack *Stack; 

struct stack {
    Board gameStates[STACK_SIZE]; 
    int size;  
};

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

//            You can ignore everything below here

// These functions are used by your program and they are implemented else
//  where. You do not need to worry about these functions
void ignoreThisFunction1(Board board, int seed, int size, int debug, int textonly);
void ignoreThisFunction2(Board board);
void ignoreThisFunction3(Board board);
void drawBoard(Board board);
void addRandom(Board board);
int gameEnded(Board board);
void printfGame(char *str);
void setAntiCrashMode(int mode);
char getcharX(void);

// You can safely ignore this
#ifdef WIN32
#include <conio.h>
#define getchar _getch
#endif

// These are the function prototypes used in this program
// for part 1.
Board newBoard(void);
bool populateBoard(Board board, int argc, char *argv[]);
void inputToBoard(Board board, int argc, char *argv[]);
int getSeed(int argc, char *argv[]);
void freeBoard(Board board);

// These are the function prototypes used in this program
// for part 2.
bool moveUp(Board board);
bool moveLeft(Board board);
bool moveDown(Board board);
bool moveRight(Board board);

void setAntiCrashMode(int mode);
char getcharX(void);

// These are the function prototypes associated with the stack and 
// used in this program for part 4.
Stack stackCreate(void);
void stackPush(Stack s, Board board);
void stackPop(Stack s, Board board);
void stackDestroy(Stack s);
int stackSize(Stack s);


// These are the function prototypes used in this program
// for part 2, 3, 4.

// Converts 2D integer array to hexadecimal 2D string array (i.e. board).
void decToHexBoard(Board board, int decValue[SIZE][SIZE]);
// Function handles all logic associated with move functions (see 
// Student Note)
bool moveCommands(Board board, bool move);
// Rotates board anticlockwise. 
void rotate(Board board);
// Converts hexadecimal 2D string array (i.e. board) to 2D integer array.
void hexToDecBoard(Board board, int decValue[SIZE][SIZE]);
// Slides all rows of 2D integer array to left.
void slideLeft(int arr1[SIZE][SIZE]);
// Merges matching adjacent cells and adds corresponding integers.
void mergeLeft(int arr1[SIZE][SIZE]);
// Compares before and after boards to check if move was successful. 
// Returns TRUE if move was successful (i.e. before and after are 
// different) and FALSE otherwise.
bool compareBeforeAndAfter(int before[SIZE][SIZE], int after[SIZE][SIZE]);

