// Author: Yash Raj
// Date created: 07/06/2020
// Program for Area of a Triangle

#include <stdio.h>
#include <math.h>

int main(void) {

	double a, b, c;
	double s;
	double area;

	printf("Enter side 1: ");
	scanf("%lf", &a);

	printf("Enter side 2: ");
	scanf("%lf", &b);

	printf("Enter side 3: ");
	scanf("%lf", &c);

	s = (a + b + c)/2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));

	printf("Area = %lf\n",area);

    return 0;
}
