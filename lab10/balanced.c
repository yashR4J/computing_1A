// Last Modified by: Yash Raj
// Date last modified: 09/08/2020
// Check whether brackets are balanced

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

bool bracket(char *input);
bool matching(char a, char b);
bool openBracket(char input);
bool closedBracket(char input);
bool emptyStack(Stack *s);

int main(void) {

	char c, input[50];
	int i = 0;
	
	while ((c = getchar()) != '\n') { 
		input[i++] = c;
	}
	input[i] = '\0';
	
	if (bracket(input)) {
		printf("Yes, balanced.\n");
	} else {
		printf("No, not balanced.\n");
	}
	
	return 0;
}

bool bracket(char *input) {

	bool balanced = true;
	Stack *s = stackCreate();
	
	for (int i = 0; input[i] != '\0'; i++) {
		if (openBracket(input[i])) {
			stackPush(s, input[i]);
		} else if (closedBracket(input[i]) && (emptyStack(s) || 
			!matching(stackPop(s), input[i]))) {
			balanced = false;
		}
	}
	if (!emptyStack(s)) {
		balanced = false;
	}
	stackDestroy(s);
	
	return balanced;
}

bool matching(char a, char b) {

	if ((a == '(' && b == ')') || (a == '[' && b == ']') 
		|| (a == '{' && b == '}')) {
		return true;
	} else {
		return false;
	}
}

bool openBracket(char input) {
	if (input == '(' || input == '[' || input == '{') {
		return true;
	}
	return false;
}

bool closedBracket(char input) {
	if (input == ')' || input == ']' || input == '}') {
		return true;
	}
	return false;
}

bool emptyStack(Stack *s) {
	if (stackSize(s) == 0) {
		return true;
	}
	return false;
}
