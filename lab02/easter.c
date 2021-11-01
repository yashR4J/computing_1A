// Author: Yash Raj
// Date created: 9/06/2020
// Dating Easter 

#include <stdio.h>
#include <math.h>

int main (void) {

	int year, easterMonth, easterDate;
	int a, c, e, h, k, l, p;
	int b, d, f, g, i, m;

	printf("Enter year: ");
	scanf("%d", &year);

		a = year % 19;
		b = floor(year / 100);
		c = year % 100;
		d = floor(b / 4);
		e = b % 4;
		f = floor((b + 8) / 25);
		g = floor((b - f + 1) / 3);
		h = (19 * a + (int)b - (int)d - (int)g + 15) % 30;
		i = floor(c / 4);
		k = c % 4;
		l = (32 + 2 * e + 2 * (int)i - h - k) % 7;
		m = floor((a + 11 * h + 22 * l) / 451);
		easterMonth = (int)floor((h + l - 7 * m + 114) / 31);
		p = (int)(h + l - 7 * m + 114) % 31;
		easterDate=(int)p + 1; 

	if(easterMonth == 3)
		printf("Easter is March %d in %d.\n", easterDate, year);
	else
		printf("Easter is April %d in %d.\n", easterDate, year);

	return 0;
}

