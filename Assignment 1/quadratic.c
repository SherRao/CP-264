/*
 --------------------------------------------------
 Project: CP264-a1q3
 File:    factorial.c
 Author:  Nausher Rao
 Version: 2021-01-18
 --------------------------------------------------
 */
#include <stdio.h>
#include <math.h>

int main() {
	double a;
	double b;
	double c;
	while(a + b + c != 0) {
		printf("Please enter the coefficients a,b,c\n");
		int inputLength = scanf("%f,%f,%f", &a, &b, &c);
		char temp;
		do {
			scanf("%c", &temp);
	        if (temp == '\n')
	        	break;
	    } while (1);

		if(inputLength == 3) {
			if(a != 0) {
				double d = pow(b, 2) - (4.0000000 * a * c) + 0.000005;
				if(d == 0) {
					double x = -b / (2.0000000 * a);
					printf("The equation has two equal real roots\nx:%f\n", x);

				} else if (d < 0) {
					double real = -b / (2.0000000 * a);
					double imag = sqrt( fabs(d) ) / (2.0000000 * a);
					printf("The equation has two complex roots\nreal:%f\nimaginary:%f\n", real, imag);

				} else {
					double x1 = ((-b + sqrt(d)) / (2.0000000 * a));
					double x2 = ((-b - sqrt(d)) / (2.0000000 * a));
					printf("The equation has two distinct real roots\nx1:%f\nx2:%f\n", x1, x2);

				}

			} else
				printf("input:not a quadratic equation\n");

		} else
			printf("input:Invalid input\n");

	}

	return 0;
}

