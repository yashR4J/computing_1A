#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getRandomNumber() {
    return rand() % 10 + 2;
}

bool checkGuess(int a, int b);

int main(int argc, char* argv[]) {
	int a = getRandomNumber(), b = getRandomNumber();
   
    bool answer = checkGuess(a, b);
    
    // When answer is false, while loop is true
    while (!answer) {
		answer = checkGuess(a, b);
    }
   
    return 0;
}

bool checkGuess(int a, int b) {

	int answer = a*b;
	int guess;
    printf("What is %d x %d? ", a, b);
	scanf("%d", &guess);
	
	if (guess == answer) {
		printf("Correct!\n");
		return true;
	}
	
	printf("Incorrect - try again.\n");
	
	return false;
}

