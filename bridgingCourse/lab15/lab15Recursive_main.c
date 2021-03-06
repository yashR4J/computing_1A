#include "ListRecursion.h"

/*
 * test the above functions
 */
int main(int argc, char *argv[]) {
    //Turn output buffering off to make testing and debugging easier
    setbuf(stdout, NULL); 
    Link list = NULL;
    int number;

    printf("Enter a number: ");
    while (scanf("%d", &number) == 1) {
        list =  append(number, list);
        printf("Enter a number: ");
    }
    if (is_empty(list)) {
        printf("List is empty.\n");
        return 0;
    }
    printf("\nList entered was: ");
    print_list(list);
    printf("\nFirst element in list is: %d.\n", getData(first(list)));
    printf("Last element in list is: %d.\n", getData(last(list)));
    printf("Length of list is: %d.\n", length(list));
    printf("Sum of the list is: %d.\n", sum(list));
    
    free_list(list);
   
    return 0;
}
