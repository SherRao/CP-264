/*
 -------------------------------------
 File:    expression_symbol.c
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
#include <string.h>

#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression_symbol.h"

int type_of_symbol(char c) {
	if (c >= '0' && c <= '9')
		return 0;

	else if(c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
		return 1;

	else if(c == '(')
		return 2;

	else if(c == ')')
		return 3;

	else
		return 4;
}

QUEUE infix_to_postfix_symbol(char *infixstr, HASHTABLE *table) {
	QUEUE queue = {0};
	STACK stack = {0};
	char *node = infixstr;
	int multiplier = 1; 
	int n = 0; 
	while(*node) {
		if(*node == '-' && (node == infixstr || *(node - 1) == '('))
			multiplier = -1;

		else if(*node <= '9' && *node >= '0') {
			n = *node - '0'; 
			while (*(node + 1) <= '9' && *(node + 1) >= '0') {
				n = n * 10 + (*(node + 1) - '0');
				node++;
			}

			enqueue(&queue, new_node(multiplier * n, 0));
			multiplier = 1;

		} else if(*node == '(') 
			push(&stack, new_node(*node, 2)); 

		else if(*node == ')') {
			int found = 0;
			while(found == 0) {
				NODE *operation = pop(&stack);
				if (operation->data != '(')
					enqueue(&queue, operation);

				else
					found = 1; 
			}

		} else if (type_of_symbol(*node) == 1) { 
			push(&stack, new_node(*node, 1));

		} else if ((*node >= 'a' && *node <= 'z') || (*node >= 'A' && *node <= 'Z')) {
			char character[] = { *node, '\0' };
			HTNODE *snode = search(table, character);
			if (snode != NULL)
				enqueue(&queue, new_node(snode->value, 0));
		}

		node++;
	}

	while (stack.top)
		enqueue(&queue, pop(&stack));

	clean_stack(&stack);
	return queue;
}

int evaluate_infix_symbol(char *infixstr, HASHTABLE *table) {
	if ((*infixstr >= '0' && *infixstr <= '9') && *(infixstr + 1))
		return (*infixstr - '0');

	else return evaluate_postfix(infix_to_postfix_symbol(infixstr, table));
}

int evaluate_postfix(QUEUE queue) {
	NODE *node = queue.front;
	STACK stack = {0} ;
	while(node) {
		char operator = node->data;
		int type = node->type;
		if(type == 0) {
			push(&stack, new_node(node->data, 0));
		
        } else if (type == 1) {
			int operand2 = pop(&stack)->data;
			int operand1 = pop(&stack)->data;
			int temp = 0;

			if(operator == '+')
				temp = operand1 + operand2;
			
            else if(operator == '-')
				temp = operand1 - operand2;
			
            else if(operator == '*')
				temp = operand1 * operand2;
			
            else if (operator == '%')
				temp = operand1 % operand2;

            else if(operator == '/')
				temp = operand1 / operand2;

			push(&stack, new_node(temp, 0));
		}

		node = node->next;
	}

	int result = stack.top->data;
	clean_stack(&stack);

	return result;
}

int resolve_symbol(char *statement, HASHTABLE *ht) {
	char name[10] = {0};
	char *dest = strstr(statement, "=");
	if(dest)
		*dest = '\0';

	else
		dest = statement;
	strcpy(name, statement);

	if((name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z')) {
		int value = evaluate_infix_symbol(dest + 1, ht);
		if(value == 99999)
			return 2;

		else
            insert(ht, new_hashnode(name, value));
	
    	return 1;
	}

	return 0;
}