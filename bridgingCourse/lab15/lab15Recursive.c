#include "ListRecursion.h"

struct node {
    int data;
    Link next;
};

/*
 * return 1 iff list contains no elements, 0 otherwise
 */
int is_empty(Link list) {
	/*
	if (list == NULL) 
		return 1;
	return 0; 
	*/
	return list == NULL;
}

/*
 * create a struct node and place the specified values in the fields
 */
Link create_node(int data, Link next) {
    Link n;

    n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}

/*
 * insert integer at front of list
 */
Link insert(int value, Link list) {
	return create_node(value, list);
}

/*
 * return pointer to first node in list
 * NULL is returned if list is empty
 */
Link first(Link list) {
   	return list;
}

/*
 * return pointer to last node in list
 * NULL is returned if list is empty
 */
Link last(Link list) {
    if (list == NULL)
        return NULL;
    if (list->next == NULL)
        return list;
    return last(list->next);
}

/*
 * append integer to end of list
 */
Link append(int value, Link list) {
	Link n;
    n =  create_node(value, NULL); /* will be last node in list */

    if (list == NULL) {
       return n;                /* new node is now  head of the list */
    } else {
        last(list)->next = n;  /* append node to list */
        return list;
    }
}

/*
 * print contents of list
 * e.g: [11, 12, 13, 42, 24]
 */
 
void print(Link list) {
	printf("%d", list->data);
	if (list->next != NULL) {
		printf(", ");
		print(list->next);
	}
}
void print_list(Link list) {
    printf("[");
    if (list != NULL) {
        print(list);
    }
    printf("]");
}

/*
 * return number of nodes in list
 */
int length(Link list) {
	if (is_empty(list))
    	return 0; 
    return 1 + length(list->next);
}

/*
 * return cumulative sum of nodes in list (e.g. sum = node = node->next + node->next->next etc)
 */
int sum(Link list) {
	if (is_empty(list))
    	return 0; 
    return list->data + sum(list->next);
}

// Get data
int getData(Link l) {
	return l->data;
}

// Free linked lists
Link free_list(Link list) {
	Link current = list;
	while (current != NULL) {
		Link temp = current;
		current = current->next;
		free(temp);
	}
    return NULL;	
}
