/*
 -------------------------------------
 File:    fibonacci.h
 calculates the fibonacci series
 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-01-29
 -------------------------------------
 */

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

extern int *la; 

int recursive_fibonacci(int n) {
	if (&n < la)
		la = &n;

	if (n == 0 || n == 1) 
		return n;

	else 
		return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);

}

int iterative_fibonacci(int n) {
	int prev, curr = 0, next = 1, i;

	if (&n < la) la = &n;
	if (&prev < la) la = &prev;
	if (&curr < la) la = &curr;
	if (&i < la) la = &i;
	if (&next < la) la = &next;

	for (i = 1; i < n; i++) {
		prev = curr;
		curr = next;
		next = prev + curr;

	}

	return next;
}

#endif /* FIBONACCI_H_ */
