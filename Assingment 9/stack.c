/*
 -------------------------------------
 File:    stack.c
 Project: raox6250_a09

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-31
 -------------------------------------
 */
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
  if (sp == NULL || np == NULL) return; 	
  if (sp->top == NULL) {
    sp->top = np;
    sp->top->next = NULL;
  
  } else {
    np->next = sp->top;
    sp->top = np;
  
  }
}

NODE *pop(STACK *sp) {
  if (sp == NULL || sp->top == NULL) return NULL;
  
  NODE *tmp = sp->top;
  sp->top = tmp->next;
  tmp->next = NULL;
  return tmp;
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
}

