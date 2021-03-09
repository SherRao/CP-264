/*
 -------------------------------------
 File:    expression.c
 Project: raox6250_a06

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function 
*/
int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}

/*
 * auxiliary function 
*/
int type(char c) {
  if (c >= '0' &&  c <= '9' )
     return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if ( c == ')')
    return 3;  
  else 
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
	QUEUE queue = {0};
	STACK stack = {0};
	int multiplier = 1; 
	int n = 0; 
	char *c = infixstr;
	while(*c) {
		if(*c == '-' && (c == infixstr || *(c - 1) == '('))
			multiplier = -1;

		else if(*c >= '0' && *c <= '9' ) {
			n = *c - '0';
			while(*(c + 1) >= '0' && *(c + 1) <= '9') {
				n = n * 10 + (*(c + 1) - '0');
				c++;

			}

			enqueue(&queue, new_node(multiplier * n, 0)); 
			multiplier = 1;

		} else if (*c == '(') 
			push(&stack, new_node(*c, 2)); 

		else if (*c == ')') {
			int a = 0;
			while(a == 0) {
				NODE *op = pop(&stack);
				if (op->data != '(')
					enqueue(&queue, op);
				else
					a = 1;

			}
		} else if (type(*c) == 1) 
			push(&stack, new_node(*c, 1));

		c++;
	}

	while (stack.top)
		enqueue(&queue, pop(&stack));

	return queue;

}

int evaluate_postfix(QUEUE queue) {
	NODE *node = queue.front;
	STACK stack = {0}; 
	while(node) {
		int type = node->type;
		char operator = node->data;
        if (type == 1) {
			int operand2 = pop(&stack)->data;
			int operand1 = pop(&stack)->data;
			int temp = 0; 

			if(operator == '/')
				temp = operand1 / operand2;

			else if(operator == '*')
				temp = operand1 * operand2;

			else if(operator == '%')
				temp = operand1 % operand2;

			else if (operator == '+')
				temp = operand1 + operand2;

			else if (operator == '-')
				temp = operand1 - operand2;

			push(&stack, new_node(temp, 0));
		} else if (type == 0) 
			push(&stack, new_node(node->data, 0));

		node = node->next; 

	}

	int result = stack.top->data;
	clean_stack(&stack);
	return result;

}

int evaluate_prefix(char *infixstr) {
	QUEUE queue = infix_to_postfix(infixstr);
	int result = evaluate_postfix(queue);
	return result;

}