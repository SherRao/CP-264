/*
 -------------------------------------
 File:    polynomial.h
 Project: mayb8910_a02
 Methods for the polynomial_main, horners algorithm,

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-01-29
 -------------------------------------
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#define EPSILON 1e-6

#include<stdio.h>
#include<math.h>

//prints the polynomial in format like p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0 with 2
//digits after the point, e.g., 1.00*10.00^3+2.00*10.00^2+3.00*10.00^1+4.00*10.00^0
void display_polynomial(float p[], int n, float x) {
	for (int i; i < n; i++) 
		if (i < n - 1) 
			printf("%.2f*%.2f^%d+", p[i], x, n - (i + 1));
		
		else 
			printf("%.2f*%.2f^%d", p[i], x, n - (i + 1));

	return;
}


//computes and returns the value of the following polynomial P(x) of order n and coefficients p[0], …, p[n-1].
//P(x) = p[0] * xn − 1 + p[1] * xn − 2 + ... + p[n − 2] * x1 + p[n − 1] * x0
float horner(float p[], int n, float x) {
	float result = 0;
	for (int i = 0; i < n; i++) 
		result = result * x + p[i];

	if (result > -0.00000382 && result < EPSILON)
		result = 0;

	return result;

}


//finds an approximate real root c in interval [a, b] of polynomial P(x), using the bisection
//method (supplementary link). Use the fault tolerant 1e-6 (or 0.000001) as a stop condition,
//i.e., if x0 is the actual root, stop the iteration if |c-x0|<1e-6 or |P(c)| < 1e-6.
float bisection(float p[], int n, float a, float b) {
	float root = 0;
	float c = a;
	while (root == 0) {
		c = (a + b) / 2; 
		if ((c - a) < 1e-6 && fabs(horner(p, b, c)) < 1e-6)
			root = c;

		else if (horner(p, n, c) * horner(p, n, a) < 0)
			b = c;
		
		else 
			a = c;

	}

	return root;
}

#endif /* POLYNOMIAL_H_ */