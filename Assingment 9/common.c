/*
 -------------------------------------
 File:    common.c
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

NODE *new_node(int data, int type) {
    NODE *np = (NODE *) malloc(sizeof(NODE));
    np->data = data;
    np->type = type;
    np->next = NULL;

    return np;
}

void display(NODE *start) {
    while(start) {
        if(start->type == 0) 
            printf("%d ", start->data);

        else 
            printf("%c ", start->data);      
    
        start = start->next;
    }
}

void clean(NODE **topp) {
    NODE *curr = *topp;
    while(curr) {
        NODE *tmp = curr;
        curr = curr->next;
        
        free(tmp);
    }
    
    *topp = NULL;
}
