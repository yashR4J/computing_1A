#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node * Link;

Link create_node(int data, Link next);
Link insert(int value, Link list);
Link last(Link list);
Link append(int value, Link list);
void print_list(Link list);
Link delete_first(Link list);
Link delete_last(Link list);
Link findPrevious(int i, Link list);
Link delete(int i, Link list);
Link reverse(Link list);
Link free_list(Link list);
