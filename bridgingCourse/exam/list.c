#include "List.h"
#include <assert.h>

struct _node {
    int value;
    Link next;
};

Link createNode(int value, Link next) {
    Link n = malloc(sizeof(struct _node));
    if (n == NULL) {
        fprintf(stderr, "Malloc error\n");
        exit(1);
    }
    n->value = value;
    n->next = next;
    return n;
}

void printList(Link list) {
    printf("[ ");
    Link current = list;
    while (current != NULL) {
        printf("%d, ", current->value);
        current = current->next;
    }
    printf("]\n");
}

Link append(Link list, int value) {
    Link n = createNode(value, NULL);
    Link current = list;
    if (current == NULL) {
        return NULL;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = n;
    return list;
}

Link appendL(Link list, Link n) {
    Link current = list;
    if (current == NULL) {
        return NULL;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = n;
    return list;
}

void freeList(Link list) {
    Link current = list;
    while (current != NULL) {
        Link temp = current;
		current = current->next;
		free(temp);
    }
}

int length(Link list) {
    int count = 0;
    Link current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// TODO
Link delete(Link list, int value) {
	if (list == NULL) {
    	return NULL;
    }
    if (list->value == value) {
    	Link n = list->next;
    	free(list);
    	return n;
    }
    if (list->next == NULL) {
    	return list;
    }
    
    Link current;
    for (current = list; current->next->next != NULL && 
    	current->next->value != value; current = current->next) {
    }
    if (current->next->value == value) {
    	Link n = current->next->next;
    	free(current->next);
    	current->next = n;
    }
    return list;
}

// TODO

Link join(Link list1, Link list2) {
	if (list1 == NULL) {
		return list2;
	} 
	if (list2 == NULL) {
		return list1;
	}
	
	if (list1->next == NULL) {
		list1->next = list2;
	} else {
		join(list1->next, list2);
	}
	
	return list1;
}



// TODO
int sum(Link list) {
	if (list == NULL) {
		return 0;
	}
	return list->value + sum(list->next);
}

// TODO
Link insert(Link list, int value, int index) {
	if (list == NULL) {
		return append(list, value);
	}
	Link n = createNode(value, NULL);
	
	if (index == 0) {
		n->next = list;
	} else {
		Link current = list;
		while (index != 0) {
			if (current == NULL) {
				return list; // Invalid Index
			}
			current = current->next;
			index -= 1;
		}
		n = current;
		n->next = current->next;
	}
		
    return n;
}

// TODO
Link find(Link list, int value) {
    for (Link current = list; current != NULL; 
    	current = current->next) {
    	if (current->value == value) {
    		return current;
    	}
    }
    return NULL;
}

// TODO
int getValue(Link list, int index) {
	assert(index >= 0);
	
	Link current = list;
    for (current = list; current != NULL && index != 0; 
    	current = current->next, index--) {
    }
    if (current == NULL) 
    	return -1; // Index does not exist;
    else 
    	return current->value;
}

// TODO
double midValue(Link list) {
	if (list == NULL) {
		return -1;
	}
	
    if (length(list) % 2 == 0) {
    	int middleIndex = length(list) / 2;
    	double x = getValue(list, middleIndex - 1);
    	double y = getValue(list, middleIndex);
    	return (x + y) / 2;
    } else {
    	return -1;
    }
}



