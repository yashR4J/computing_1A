// Author: Yash Raj (z5317349)
// Date Modified: 30/06/2020
/* Implement a function to sum two numbers via pointers */

#include <stdio.h>

void sumByPointers(int *sum, int *num1, int *num2);

int main(void) {
    int num1;
    int num2;
    int sum = 0;
    printf("Please enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);

    sumByPointers(&sum, &num1, &num2);
    printf("Sum is: %d\n", sum);

    return 0;
}

void sumByPointers(int *sum, int *num1, int *num2) {
    
	*sum = *num1 + *num2;

}
