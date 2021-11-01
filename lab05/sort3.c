// Author: Yash Raj (z5317349)
// Date Modified: 30/06/2020
/* Takes three float pointers as arguments and sorts the values they point to in increasing order. */

#include <stdio.h>

void sort3(double *x, double *y, double *z);
void swap(double *a, double *b);

int main(int argc, char *argv[]) {
  double x, y, z;
  
  scanf("%lf %lf %lf", &x, &y, &z);
  sort3(&x, &y, &z);
  printf("%lf %lf %lf\n", x, y, z);
  
  return 0;
}

void sort3(double *x, double *y, double *z) {

	if (*x > *y) {
		swap(x, y); // Swapping y and x (so order = y, x, z)
	} if (*x > *z) {
		swap(x, z); // Swapping z and x (so order = y, z, x)
	} if (*y > *z) {
		swap(y, z); // Swapping z and y (so order = z, y, x)
	}

}

void swap(double *a, double *b) {
	double temp;
	
	temp = *a;
	*a = *b;
	*b = temp;

}
