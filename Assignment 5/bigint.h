/*
 -------------------------------------
 File:    bigint.h
 Project: raox6250_a05

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-02-25
 -------------------------------------
 */
#ifndef BIGINT_H
#define BIGINT_H

#include "dllist.h"

typedef struct {
	NODE *start;
	NODE *end;

} BIGINT;

/*
 * This takes a big number in digit string and coverts 
 * and returns it in BIGINT type. 
 *
*/
BIGINT bigint(char *digitstr);

/*
*  This prints the digits of the big_number. 
*/
void display_bigint(BIGINT big_number);

/*
*  This cleans the doubly linked list of the big_numberp. 
*/
void clean_bigint(BIGINT *big_numberp);

/*
*  This adds the two BIGINT operants and return the resulted sum BIGINT.   
*/
BIGINT add(BIGINT oprand1, BIGINT oprand2);

/*
*  This computes nth Fibonacci number F(n) using the above the add function and returns F(n) in BIGINT type   
*/
BIGINT Fibonacci(int n);

#endif