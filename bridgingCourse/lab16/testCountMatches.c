#include "count.h"

int main(void){
    // create two linked lists from command line arguments
    char* argv[] = {"countMatches", "1", "2", "3", "4", "5", "-", 
    				"1", "0", "2", "4", "5", "/0"};
    				
    int argc = sizeof(argv)/sizeof(char *) - 1;
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    Link head1 = strings_to_list(dash_arg - 1, &argv[1]);
    Link head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);
	
	printf("Testing Sample Input...\n");
	
    for (int i = 1; i < argc - 1; i++) {
        printf("%s ",argv[i]);
    }
	
	int result = countMatches(head1, head2);
	
	printf("%d\n", result);
	assert(result == 3);
    
    printf("All Tests Passed!\n");
    
    return EXIT_SUCCESS;
}

