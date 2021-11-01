// Author: Yash Raj (z5317349)
// Date modified: 20/06/2020
/* A Bad Array Example */

/*

#include <stdio.h>

// This is a bad program


int main(void) {
    int i;
    int numbers[] = {2,4,6,8};
    
    i = 0;
       
    while(i <= 4){ 
        printf("%d\n",numbers[i]);
        i = i + 1;
    }    
    
    i = i*1000;
    
    numbers[i] = 3; 

    return 0;
}

*/

#include <stdio.h>

#define SIZE 10

// This is a bad program

int main(void) {
    int numbers[SIZE];
    int i;
    i = 0;
    
    //initialise array
    while(i < SIZE){
        numbers[i] = i;
        i = i + 2; 
    }    
    
    //print array
    i = 0;
    while(i < SIZE){
        printf("%d: %d\n",i, numbers[i]);
        i = i + 1;
    }  
       
    return 0;
}


