// Author: Yash Raj
// Date created: 09/06/2020
// Convert height from centimetres to feet.

#include <stdio.h>

#define INCHES_IN_FOOT  12
#define CM_IN_INCH      2.54

int main (void) {
    int heightCentimetres;
    int heightInches;

    printf("Enter your height in centimetres: ");
    scanf("%d", &heightCentimetres);

    heightInches = (heightCentimetres / CM_IN_INCH);

    printf("Your height in inches is %d\n", heightInches);

    return 0;
}

