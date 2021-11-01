// Implement a dynamic expanding array based implementation of a 'set'
// Credit to Emmet Murray's soln which was used for reference.

#include <stdio.h>
#include <stdlib.h>
#include "Set.h"
#define INIT_SET_SIZE 64

// Internal Function
static void setResize(Set s, int size);

struct set {
	int *elems;
	int nelems;
	int maxelems;
};

// create new empty set
Set createSet(void) {
	Set s = malloc(sizeof(struct set));
	if (s == NULL) {
		fprintf(stderr, "ERROR - Out of memory");
		exit(EXIT_FAILURE);
	}
	
	// Create internal array with size of 64 integers
	s->elems = malloc(INIT_SET_SIZE * sizeof(int));
	if (s->elems == NULL) {
		fprintf(stderr, "ERROR - Out of memory");
		free(s);
		exit(EXIT_FAILURE);
	}
	
	// Initialising initial values
	s->nelems = 0;
	s->maxelems = INIT_SET_SIZE;
	
	return s;
}

// free memory used by set
void destroySet(Set s) {
	if(s == NULL)
		return;
	
	free(s->elems);
	s->elems = NULL;
	free(s);
	s = NULL;
}

// add value into set
void insertSet(Set s, int item) {
	// Do not do anything for duplicates
	if (isMemberSet(s, item)) 
		return;
	// Check if array size is full
	if (s->nelems == s->maxelems) {
		setResize(s, s->maxelems * 2.0); // Give twice memory to array
	}
	s->elems[s->nelems] = item; // Place item in last slot
	s->nelems++;
}

// remove value from set
void deleteSet(Set s, int item) {
	for (int i = 0; i < s->nelems; i++) {
		if (s->elems[i] == item) {
			i++;
			while (i < s->nelems) {
				s->elems[i - 1] = s->elems[i];
				i++;
			}
			s->nelems--;
			// Resize array if too big
			if (s->nelems <= s->maxelems/4 && 
				s->maxelems/2 >= INIT_SET_SIZE) {
				setResize(s, s->maxelems / 2);
			}
			return;
		}
	}
}

//returns 1 if item is an element of the set s and 0 otherwise
int isMemberSet(Set s, int item) {
	for (int i = 0; i < s->nelems; i++) {
		if (s->elems[i] == item) 
			return 1;
	}
	return 0;
}

//returns a new set that is the union of s1 and s2
//Note: s1 and s2 must remain unchanged
Set unionSet(Set s1, Set s2) {
	Set s = createSet();
	int i;
	for (i = 0; i < s1->nelems; i++) {
		insertSet(s, s1->elems[i]);
	}
	for (i = 0; i < s2->nelems; i++) {
		insertSet(s, s2->elems[i]);
	}
	return s;
}

// returns a new set that is the intersection of s1 and s2
// Note: s1 and s2 must remain unchanged
Set intersectionSet(Set s1 ,Set s2) {
	Set s = createSet();
	for (int i = 0; i < s1->nelems; i++) {
		if (isMemberSet(s2, s1->elems[i]))
			insertSet(s, s1->elems[i]);
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

// Displays a set to screen
void setShow(Set s) {
	if (s == NULL)
		return;
	printf("{");
	for (int i = 0; i < s->nelems; i++) {
		printf("%d", s->elems[i]);
		if (i != s->nelems - 1) 
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

static void setResize(Set s, int size) {
	if (s == NULL)
		return;
	
	s->elems = realloc(s->elems, size*sizeof(int));
	if (s->elems == NULL) {
		fprintf(stderr, "ERROR - Out of memory");
		exit(EXIT_FAILURE);
	}
	
	s->maxelems = size;
}
