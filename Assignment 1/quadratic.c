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

const float EPSILON = 1e-6;

int main() {
	float a;
  	float b;
  	float c;
  	char temp;
  
	do {
    	do {   
      		printf("Please enter the coefficients a,b,c\n");
      		int inn = scanf("%f,%f,%f", &a, &b, &c);
      		if (inn != 3 ) {
         		printf("input:Invalid input\n");
	   		
			} else
        		break;
       
      		do {
        		scanf("%c", &temp);
        		if (temp == '\n') 
					break;
      		
			  } while (1);
    	
		} while (1);

		if(fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON) {
			printf("input:quit\n");
			break;
		
		} else if (fabs(a) < EPSILON) {
			printf("input:not a quadratic equation\n");
		
		} else { 
			float d = pow(b, 2) - (4 * a * c);
			if(fabs(d) == 0) {
				double x = -b / (2 * a);
				printf("The equation has two equal real roots\nx:%f\n", x);

			} else if (d < 0) {
				double real = -b / (2 * a);
				double imag = sqrt( fabs(d) ) / (2 * a);
				printf("The equation has two complex roots\nreal:%f\nimaginary:%f\n", real, imag);

			} else {
				double x1 = ((-b + sqrt(d)) / (2 * a));
				double x2 = ((-b - sqrt(d)) / (2 * a));
				printf("The equation has two distinct real roots\nx1:%f\nx2:%f\n", x1, x2);
				
			}
		
		}

	} while (1);
  
  return 0;

}