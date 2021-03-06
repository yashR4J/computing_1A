// Author: Yash Raj (z5317349)
// Date Modified: 15/07/2020
/* Read characters and print characters without lowercase vowels */

#include <stdio.h>

int lowercase_vowel(int x);

int main(void) {

    int x;
    
    for (x = getchar(); x != EOF; x = getchar()) {
        if (lowercase_vowel(x) == 0) {
            putchar(x);
        }
    }

    return 0;
}

int lowercase_vowel(int x) {

    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        return 1;
    }  
    return 0;
}
