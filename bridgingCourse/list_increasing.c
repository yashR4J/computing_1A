#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int increasing(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = increasing(head);
    printf("%d\n", result);

    return 0;
}


// return 1 if values in a linked list are in increasing order,
// return 0, otherwise

int increasing(struct node *head) {
    // PUT YOUR CODE HERE (change the next line!)
    /*
    if (head == NULL || head->next == NULL) {
    	return 1;
    }

    for (struct node * current = head; current->next != NULL; 
    	current = current->next) {
    	if (current->next->data <= current->data) {
    		return 0;
    	}
    }
    return 1;
    */
    if (head == NULL || head->next == NULL) {
    	return 1;
    } else if (head->data >= head->next->data) {
    	return 0;
    } else {
    	return increasing(head->next);
	}
}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
