#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node * Link;

// Return the number of matches in the two lists, i.e. the number of
// values which occur at the same position in both linked lists.
int countMatches(Link list1, Link list2);
Link strings_to_list(int len, char *strings[]);

