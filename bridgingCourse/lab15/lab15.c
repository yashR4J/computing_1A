#include "List.h"

struct node {
    int  data;
    Link next;
};

/*
 * create a node and place the specified values in the fields
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
 * return pointer to last node in list
 * NULL is returned if list is empty
 */
Link last(Link list) {
    Link n = list;
    if (n == NULL)
        return NULL;
    while (n->next != NULL)
        n = n->next;
    return n;
}


/*
 * append integer to end of list
 */
Link append(int value, Link list) {
    Link n;

    n =  create_node(value, NULL); /* will be last node in list */

    if (list == NULL) {
       return n;                  /* new node is now  head of the list */
    } else {
        last(list)->next = n;  /* append node to list */
        return list;
    }
}

/*
 * print contents of list
 */
void print_list(Link list) {
    Link n;

    printf("[");
    for (n = list; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL)
            printf(", ");
    }
    printf("]");
}



/*
 * delete first node in the list
 */
Link delete_first(Link list) {
    if (list == NULL) {
		return NULL;
	}
	
	Link n = list->next;
	free(list);
	
    return n;
}

/*
 * delete last node in the list
 */
Link delete_last(Link list) {	
	if (list == NULL) {
		return list;
	} 
	if (list->next == NULL) {
		free(list);
		return NULL;
	}
	
	Link n = list;
    while (n->next->next != NULL) {
        n = n->next;
	}
	free(n->next);
	n->next = NULL;
	
    return list;
}

/* 
 * delete function needs previous value to connect lists 
 * after deleting nodes in between
 */
Link findPrevious(int i, Link list) {
	Link previous = NULL;
	for (Link x = list; x != NULL; x = x->next) {
    	if (x->data == i) {
    		return previous;
    	}
    	previous = x;
	}
	return NULL;
}

/*
 * delete first node containing specified int
 */
Link delete(int i, Link list) {
	Link deleteMe = NULL;
	Link previous = findPrevious(i, list);
	
	if (previous != NULL) {
		deleteMe = previous->next;
		previous->next = previous->next->next;
	} else if (list != NULL && list->data == i) {
		deleteMe = list;
		list = list->next;
	}
	
	if (deleteMe != NULL) 
		free(deleteMe);
		
    return list;
}

/*
 * reverse the nodes in list
 */
Link reverse(Link list) {
	Link current, next, previous;
	if (list == NULL) 
		return NULL;
	previous = NULL;
	
	current = list;
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	// Current now points to NULL so return previous, which is the head 
	// of the linked list
    return previous;
}

Link free_list(Link list) {
	Link current = list;
	while (current->next != NULL) {
		Link temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
    return NULL;	
}
