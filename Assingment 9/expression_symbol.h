/*
 -------------------------------------
 File:    expression_symbol.h
 Project: raox6250_a09

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-31
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "queue.h"
#include "stack.h"
#include "hash.h"

/* 
 * convert infix expression string to postfix expression queue, 
 * getting symbol values from the hash table
*/
QUEUE infix_to_postfix_symbol(char *infixstr, HASHTABLE *ht);

/*
 * evaluate symbolic infix expression, 
 * call queue = infix_to_postfix_symbol(char *infixstr, HASHTABLE *ht); 
 * then call evaluate_postfix(QUEUE queue);
*/ 
int evaluate_infix_symbol(char *infixstr, HASHTABLE *ht);

/*
 * parse statement symbol=expression, to get left-side symbol string, and 
 * evaluate the right side expression using evaluate_infix_symbol(char *infixstr, HASHTABLE *ht);
 * insert the symbol and its value into hash table
*/ 
int resolve_symbol(char* statement, HASHTABLE *ht);

/*
 * the same as A6Q3
*/
int evaluate_postfix_symbol(QUEUE *queue);

/**
 * Helper function to return the type for a given character.
 */
int type_of_symbol(char c);
