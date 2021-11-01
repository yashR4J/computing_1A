// Author: Yash Raj
// Date created: 9/06/2020
// Compute student WAM and grade

#include <stdio.h>

#define HD 85
#define D 75
#define CR 65
#define PS 50

int main (void) {
  double course1, course2, course3, course4;
  double average;

  printf("Enter marks for 4 courses enrolled in past semester:\n");

  scanf("%lf %lf %lf %lf", &course1, &course2, &course3, &course4);
  
  average = (course1 + course2 + course3 + course4)/4;

  // %.2f -- the .2 makes sure only two decimal points are printed
  printf("Your WAM  is: %.2lf\n", average);

  if (average >= HD) {
     printf("Your grade is HD\n");
  }
  else if (average >= D) {
     printf("Your grade is D\n");
  }
  else if (average >= CR) {
     printf("Your grade is CR\n");
  }
  else if (average >= PS) {
     printf("Your grade is PS\n");
  }
  else if (average < PS) {
     printf("Your grade is FL\n");
  }

  return 0;
}
