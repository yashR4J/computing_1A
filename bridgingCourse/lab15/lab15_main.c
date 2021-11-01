#include "List.h"

#define MAX_LINE 4096

/*
 * test the above functions
 */
int main(int argc, char *argv[]) {
    Link list;
    int argument;
    char *s, *t;
    char line[MAX_LINE];
    char action[MAX_LINE];

    list = NULL;
    while (1) {
        printf("list = ");
        print_list(list);
        printf("\n");
        printf("> ");
        if (fgets(line, MAX_LINE, stdin) == NULL)
            break;

        for (s = line; isspace(*s); s++)
            ;

        t = action;
        while (isalpha(*s) || *s == '_')
            *t++ = *s++;
        *t = '\0';

        argument = strtol(s, &s, 10);

        if (strcmp(action, "quit") == 0) {
            list = free_list(list);
            break;
        }
        else if (strcmp(action, "") == 0)
            continue;
        else if (strcmp(action, "insert") == 0)
            list = insert(argument, list);
        else if (strcmp(action, "append") == 0)
            list = append(argument, list);
        else if (strcmp(action, "delete_first") == 0)
            list = delete_first(list);
        else if (strcmp(action, "delete_last") == 0)
            list = delete_last(list);
        else if (strcmp(action, "delete") == 0)
            list = delete(argument, list);
        else if (strcmp(action, "reverse") == 0)
            list = reverse(list);
        else
            printf("Unknown command: '%s'\n", action);
    }
    if (list != NULL) 
    	free_list(list), list = NULL;
    	
    return 0;
}

