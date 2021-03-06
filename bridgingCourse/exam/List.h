#include <stdio.h>
#include <stdlib.h>

typedef struct _node * Link;
typedef struct _node node;

// Create a new node and set it's next value
// value must be an integer >= 0
Link createNode(int value, Link next);

// Delete and free a list
void freeList(Link list);

// Print a visual representation of the list out to terminal
void printList(Link list);

// Given a new integer, append a new node to the end of the list
//  that stores that integer value
// value must be an integer >= 0
Link append(Link list, int value);

// Given a node, append it to the end of the list
Link appendL(Link list, Link node);

// Get the length of the list (number of nodes)
int length(Link list);


////////////////////////////////////////////////////////////////////////
//////////         TO IMPLEMENT IN LIST.C               ////////////////
////////////////////////////////////////////////////////////////////////

// Given an integer value, delete (and free) the first element
//  in the list that contains that same value
// value must be an integer >= 0
Link delete(Link list, int value);

// Join list2 onto list1 and return a pointer to the new list1
Link join(Link list1, Link list2);

// Sum the data values in every list node and return the result
int sum(Link list);

// Given an integer, create a new node, and then insert it at a particular
//  index within an already existing linked list.
// Indexes start at 0. Inserting at index 0 means inserting to the
//  front of the linked list.
// If an index is invalid, no insert is made.
Link insert(Link list, int value, int index);

// Given a value, find the first instance of this value appearing in one
//  of the nodes in the list, then return a pointer to that node
Link find(Link list, int value);

// Get the item from the list that has index "index"
// E.G. for list L => 5 => 4 => 3 => 4 => 7 => NULL
// getItem(L, 2) would return 3
// getItem(L, 4) would return 7
// index must be an integer >= 0
// If the index does not exist, return -1
int getValue(Link list, int index);

// If the list has an odd number of elements, return -1
// If the list has an event number of elements, return the average
// of the middle two elements.
// E.G. For a list 1 => 2 => 3 => 4 it would return the average
//  of 2 and 3 (i.e. 2.5)
double midValue(Link list);

