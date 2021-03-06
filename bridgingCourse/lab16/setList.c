// Implement a dynamic expanding array based implementation of a 'set'
// Credit to Emmet Murray's soln which was used for reference.

#include <stdio.h>
#include <stdlib.h>
#include "Set.h"
#define INIT_SET_SIZE 64

typedef struct list * List;
struct list {
	int data;
	List next;
};

struct set {
	int nelems;
	List elems;
};

// create new empty set
Set createSet(void) {
	Set s = malloc(sizeof(struct set));
	if (s == NULL) {
		fprintf(stderr, "ERROR - Out of memory");
		exit(EXIT_FAILURE);
	}
	
	// Create internal array with size of 64 integers
	s->elems = NULL;
	
	// Initialising initial values
	s->nelems = 0;
	
	return s;
}

// free memory used by set
void destroySet(Set s) {
	if(s == NULL)
		return;
	
	List current = s->elems; 
	while (current != NULL) {
		List tmp = current;
		current = current->next;
		free(tmp);
	}
	
	free(s);
	s = NULL;
}

// add value into set
void insertSet(Set s, int item) {
	// Do not do anything for duplicates
	if (isMemberSet(s, item)) 
		return;
	// Check if array size is full
	List elem = malloc(sizeof(struct list));
	if (elem == NULL) {
		fprintf(stderr, "ERROR - Out of memory");
		exit(EXIT_FAILURE);
	}
	
	// Easy to just insert at the head of the list
	elem->data = item;
	elem->next = s->elems;
	
	// Update s
	s->elems = elem;
	s->nelems++;
}

// remove value from set
void deleteSet(Set s, int item) {
	
	
	for (List prev = NULL, current = s->elems;
		current != NULL; prev = current, current = current->next) {
		if (current->data == item) {
			if (prev == NULL) {
				s->elems = s->elems->next;
				free(current);
				s->nelems--;
				return;
			}
			prev->next = current->next;
			free(current);
			s->nelems--;
			return;
		}
	}
}

//returns 1 if item is an element of the set s and 0 otherwise
int isMemberSet(Set s, int item) {
	for (List current = s->elems; current != NULL; 
		current = current->next) {
		if (current->data == item) 
			return 1;
	}
	return 0;
}

//returns a new set that is the union of s1 and s2
//Note: s1 and s2 must remain unchanged
Set unionSet(Set s1, Set s2) {
	Set s = createSet();
	List current;
	for (current = s1->elems; current != NULL; 
		current = current->next) {
		insertSet(s, current->data);
	}
	for (current = s2->elems; current != NULL; 
		current = current->next) {
		insertSet(s, current->data);
	}
	return s;
}

// returns a new set that is the intersection of s1 and s2
// Note: s1 and s2 must remain unchanged
Set intersectionSet(Set s1 ,Set s2) {
	Set s = createSet();
	for (List current = s1->elems; current != NULL; 
		current = current->next) {
		if (isMemberSet(s2, current->data))
			insertSet(s, current->data);
	}
	return s;
}

// cardinality (#elements)
int cardinalitySet(Set s) {
	if (s == NULL)
		return -1;
	return s->nelems;
}

/*
 * Provided set functions
 * To assist with testing
 */ 

// Prints the set s to screen
void setShow(Set s) {
    printf("{");
    for (List current = s->elems; current != NULL; 
    	current = current->next) {
        printf("%d", current->data);
        // Don't print a comma if last element
        if (current->next != NULL) 
        	printf(", ");
    }
    printf("}\n");
}

// Reads a set in from stdin
void readSet(FILE * in, Set s) {
	int val;
	while (fscanf(in, "%d", &val))
		insertSet(s, val);
}

