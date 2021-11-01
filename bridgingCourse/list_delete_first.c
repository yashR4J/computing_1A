#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node * Link;
struct node {
    Link next;
    int          data;
};


Link delete_first(Link head);
Link strings_to_list(int len, char *strings[]);
void print_list(Link head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    Link head = strings_to_list(argc - 1, &argv[1]);

    Link new_head = delete_first(head);
    print_list(new_head);

    return 0;
}


//
// Delete the first node in list.
// The deleted node is freed.
// The head of the list is returned.
//
Link delete_first(Link head) {
	if (head == NULL) {
		return NULL; // Nothing to delete
	} 
	
	Link newHead = head->next;
	free(head);
    return newHead;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
Link strings_to_list(int len, char *strings[]) {
    Link head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        Link n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(Link head) {
    printf("[");

    for (Link n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

