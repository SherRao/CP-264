/*
 -------------------------------------
 File:    common.h
 Project: raox6250_a06

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#ifndef COMMON_H
#define COMMON_H

/* node structure for postfix expression by queue and evaluation by stack */ 
typedef struct node {
	int data; // int data is used for int operand, a operator, parenthesis 
	int type; // 0: int operand; 1:operator; 3: parenthesis 
	struct node *next;
} NODE;

NODE *new_node(int data, int type);
void display(NODE *start);
void clean(NODE **startp);

#endif
