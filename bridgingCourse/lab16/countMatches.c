
#include "count.h"

struct node {
	int data;
	Link next;
};

// Return the number of matches in the two lists, i.e. the number of
// values which occur at the same position in both linked lists.
int countMatches(Link list1, Link list2) {
	Link x = list1, y = list2;
	int counter = 0;
	
	while (x && y) { // if linked lists are truthy
		if (x->data == y->data) {
			counter++;
		}
		x = x->next;
		y = y->next;
	}
	
	return counter;
	
}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
Link strings_to_list(int len, char *strings[]) {
    Link head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        Link n = malloc(sizeof(struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}




