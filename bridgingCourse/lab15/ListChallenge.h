#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node * Link;

int is_empty(Link list);
Link create_node(int data, Link next);
Link insert(int value, Link list);
Link first(Link list);
Link last(Link list);
Link append(int value, Link list);
void print_list(Link list);
int length(Link list);
int sum(Link list);
Link nth(int index, Link list);
Link middle(Link list);
int is_ascending(Link list);
int getData(Link l);
Link free_list(Link list);
