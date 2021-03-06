// Author: Yash Raj (z5317349)
// Date Modified: 14/07/2020
/* Read characters from stdin and print number of characters entered */

#include <stdio.h>

#define MAXLINE 1024

int strlength(char *);

int main(void) {
   
    char line[MAXLINE];
    
    fgets(line, MAXLINE, stdin);
    printf("Strlen is %d\n", strlength(line));

}

int strlength(char *s) {
    
    int i;

    for (i = 0; (s[i] != '\0') && (s[i] != '\n'); i++);
    
    return i;
    
}
