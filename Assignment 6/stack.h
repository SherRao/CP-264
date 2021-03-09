/*
 -------------------------------------
 File:    stack.h
 Project: raox6250_a06

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct stack {
  NODE *top;
  
} STACK;

void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif