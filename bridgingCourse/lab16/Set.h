// Set.h ... interface to Set ADT

#include <stdio.h>

typedef struct set * Set;

// create new empty set
Set createSet(void);

// free memory used by set
void destroySet(Set s);

// add value into set
void insertSet(Set s, int item);

// remove value from set
void deleteSet(Set s, int item);

//returns 1 if item is an element of the set s and 0 otherwise
int isMemberSet(Set s, int item);

//returns a new set that is the union of s1 and s2
//Note: s1 and s2 must remain unchanged
Set unionSet(Set s1, Set s2);

// returns a new set that is the intersection of s1 and s2
// Note: s1 and s2 must remain unchanged
Set intersectionSet(Set s1 ,Set s2);

// cardinality (#elements)
int cardinalitySet(Set s);

/*
 * Provided set functions
 * To assist with testing
 */ 

// Displays a set to screen
void setShow(Set s);

// Reads a set in from stdin
void readSet(FILE * in, Set s);


