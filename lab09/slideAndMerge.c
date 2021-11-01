// Last Modified by: Yash Raj
// Date last modified: 29/07/2020
// Slides all elements of array to the leftmost point of the array and
// merges if adjacent items of array are the same

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void slideAndMerge(int *nums);
void slide(int *nums);
void merge(int *nums);

int main(int argc, char* argv[]) {
	int numbers[SIZE] = {0};
	int i;

	i = 0;
	while (i < SIZE) {
		int number = getchar() - '0';
		numbers[i] = number;
		i++;
	}

	i = 0;
	while (i < SIZE) {
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");

	slideAndMerge(numbers);

	i = 0;
	while (i < SIZE) {
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");

	return 0;
}

void slideAndMerge(int *nums) {
	
	slide(nums);
	merge(nums);
	slide(nums);

}

void slide(int *nums) {

	int i, j = 0;
	
	for (i = 0; i < SIZE; i++) {
		if(nums[i] != 0) {
			nums[j++] = nums[i];
		}
	}
	for (i = j; i < SIZE; i++) {
		nums[i] = 0;
	}

}

void merge(int *nums) {

	int i;
	
	for (i = 1; i < SIZE; i++) {
		if (nums[i - 1] ==  nums[i]) {
			nums[i - 1] = nums[i] + nums[i - 1];
			nums[i] = 0;
		}
	}

}
