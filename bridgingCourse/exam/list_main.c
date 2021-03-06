#include <stdlib.h>
#include <assert.h>

#include "List.h"

int main(int argc, char* argv[]) {

	printf("Testing...\n");
	
	Link list = createNode(1, NULL);
	
	append(list, 2);
	append(list, 3);
	append(list, 4);
	append(list, 5);
	assert(length(list) == 5);
	
	// List is currently as follows: 1->2->3->4->5
	// Check delete
	list = delete(list, 3);
	assert(length(list) == 4);
	list = delete(list, 1);
	assert(length(list) == 3);
	list = delete(list, 7);
	assert(length(list) == 3);
	
	// Check join(list1, list2)
	
	Link list1 = createNode(1, NULL);
	
	append(list1, 2);
	append(list1, 3);
	append(list1, 4);
	append(list1, 5);
	
	// list1 is 1->2->3->4->5
	
	Link list2 = createNode(6, NULL);
	
	append(list2, 7);
	append(list2, 8);
	append(list2, 9);
	append(list2, 10);
	
	// list2 is 6->7->8->9->10
	
	// Check join 
	Link list3 = join(list1, list2);
	assert(length(list3) == 10);
	assert(getValue(list3, 6) == 7);
	
	// list3 is 1->2->3->4->5->6->7->8->9->10
	
	// Check sum
	assert(sum(list1) == 55);
	
	// Check insert and also getValue
	list1 = insert(list1, 2, 0);
	assert(getValue(list1, 0) == 2);
	list1 = insert(list1, 1, 0);
	assert(getValue(list1, 0) == 1);
	list1 = insert(list1, 1, 10);
	assert(getValue(list1, 10) == -1); // Check for invalid index input
	
	// Check find
	// Link list4 = find(list1, 2);
	
	// assert(getValue(list4, 0) == 2);
	// assert(getValue(list4, 1) == 3);
	
	// Check midValue
	assert(midValue(list3) == 5.5);
	assert(midValue(list) == -1);
	
	
	printf("All tests passed!\n");
	
	return 0;
}
