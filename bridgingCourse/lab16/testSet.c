/*
 * runTests.c
 *
 * Runs a suite of prewritten tests
 *
 * Written by: YOU
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

#define BIGSIZE 2048

void runTests(void);

int main(void){
    runTests();
    return EXIT_SUCCESS;
}

void runTests(void) {
    // TODO: Write your own tests  in here. 
    // This does not test all aspects of the ADT but is a starting point and an example of how testing can be done.

    printf("Testing cardinalitySet, isMemberSet and insertSet...\n");
    Set s = createSet(); // Create s to be an empty set

    // Test initial conditions
    assert(cardinalitySet(s) == 0); // cardinalitySet(s) must return 0 
    								// i.e. an empty set
    assert(isMemberSet(s, 1) == 0); // No set elements so 
    								// isMemberSet(s, 1) must be false(0)

    // Insert 3 elements
    insertSet(s,1);
    assert(cardinalitySet(s) == 1);
    assert(isMemberSet(s, 1) == 1);

    insertSet(s,2);
    assert(cardinalitySet(s) == 2);
    assert(isMemberSet(s, 2) == 1);

    insertSet(s,3);
    assert(cardinalitySet(s) == 3);
    assert(isMemberSet(s, 3) == 1);

    // Test duplicates - this should not increase set size (which is 3)
    insertSet(s,3);
    assert(cardinalitySet(s) == 3);
    assert(isMemberSet(s, 3) == 1);
    assert(isMemberSet(s, 2) == 1);
    assert(isMemberSet(s, 1) == 1);

    insertSet(s,2);
    assert(cardinalitySet(s) == 3);
    assert(isMemberSet(s, 3) == 1);
    assert(isMemberSet(s, 2) == 1);
    assert(isMemberSet(s, 1) == 1);

    insertSet(s,1);
    assert(cardinalitySet(s) == 3);
    assert(isMemberSet(s, 3) == 1);
    assert(isMemberSet(s, 2) == 1);
    assert(isMemberSet(s, 1) == 1);

    printf("Testing deleteSet...\n");

    // Remove an element not in the set
    deleteSet(s,0);
    assert(cardinalitySet(s) == 3);
    assert(isMemberSet(s, 3) == 1);
    assert(isMemberSet(s, 2) == 1);
    assert(isMemberSet(s, 1) == 1);

    // Remove the first element (implicitly testing array shifting)
    deleteSet(s,1);
    assert(cardinalitySet(s) == 2);
    assert(isMemberSet(s, 3) == 1);
    assert(isMemberSet(s, 2) == 1);
    assert(isMemberSet(s, 1) == 0);

    // Delete the others
    deleteSet(s,2);
    assert(cardinalitySet(s) == 1);
    assert(isMemberSet(s, 3) == 1);
    assert(isMemberSet(s, 2) == 0);
    assert(isMemberSet(s, 1) == 0);

    deleteSet(s,3);
    assert(cardinalitySet(s) == 0);
    assert(isMemberSet(s, 3) == 0);
    assert(isMemberSet(s, 2) == 0);
    assert(isMemberSet(s, 1) == 0);

    printf("Putting in %d numbers...\n", BIGSIZE);

    int i = 0, j;
    while (i < BIGSIZE) {
        // Insert current i
        insertSet(s, i);
        i++;

        // Check all numbers up to current i exist
        j = 0;
        assert(cardinalitySet(s) == i);
        while (j < i) { // Since i is incremented already
            assert(isMemberSet(s,j));
            j++;
        }
    }

    printf("Removing %d numbers...\n", BIGSIZE);
    i = 0;
    while (i < BIGSIZE) {
        // Remove current element
        deleteSet(s, i);
        i++;

        // Check all numbers up to current i don't exist
        j = 0;
        assert(cardinalitySet(s) == BIGSIZE - i);
        while (j < i) {
            assert(!isMemberSet(s,j));
            j++;
        }
    }
    destroySet(s);

    printf("Testing union...\n");
    Set s1 = createSet();
    Set s2 = createSet();

    // Insert 4 elements into s1
    insertSet(s1,1);
    insertSet(s1,3);
    insertSet(s1,5);
    insertSet(s1,7);

    // Union should contain only elements in s1 (no elements in s2 yet)
    Set s3 = unionSet(s1,s2);
    assert(cardinalitySet(s3) == 4);

    i = 1;
    while (i <= 8) {
        assert(isMemberSet(s3,i));
        i += 2;
    }

	Set s4 = intersectionSet(s1, s2);
	assert(cardinalitySet(s4) == 0);
	
	// Insert into s2
    insertSet(s2,2);
    insertSet(s2,4);
    insertSet(s2,6);
    insertSet(s2,8);
    
	assert(cardinalitySet(s4) == 0); // Since no common elements in
									 // 1,3,5,7 and 2,4,6,8
	
	Set s5 = unionSet(s1,s2); // contains 1,2,3,4,5,6,7,8
	for (i = 1; i <= 8; i++) {
		assert(isMemberSet(s5,i));
	}			 
			
	Set s6 = intersectionSet(s1,s5);
	assert(cardinalitySet(s6) == 4);
	
	for (i = 1; i <= 8; i += 2) {
		assert(isMemberSet(s6, i)); // since s1 contains 1,3,5,7
	}	 
		
    // Clear everything up till now...
    destroySet(s1);
    destroySet(s2);
    destroySet(s3);
    destroySet(s4);
	destroySet(s5);
	destroySet(s6);
	
    printf("All tests passed!\n");
}
