/*
 -------------------------------------
 File:    stack.c
 Project: raox6250_a06

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    if(!sp->top) { //If the Stack is empty
        sp->top = np;

    } else {
        np->next = sp->top;
        sp->top = np;
    }
}

NODE *pop(STACK *sp) {
    if(sp->top) {
        NODE *node = sp->top;
        sp->top = sp->top->next;
        return node;

    } else 
        return NULL;

}

void clean_stack(STACK *sp) {
    clean(&sp->top);
    
}