/*
 -------------------------------------
 File:    dllist.c
 Project: raox6250_a05

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-02-25
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dllist.h"

/*
 * This creates a new node using malloc().
*/
NODE *new_node(char data) {
    NODE *node = (NODE*) malloc(sizeof(NODE));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

/*
 * This displays char data from start to end.
*/
void display_forward(NODE *start) {
    NODE *node = start;
    while(node != NULL) {
        printf("%c ", node->data);
        node = node->next;

    }
}

/*
 * This displays char data from end to start. 
*/
void display_backward(NODE *end) {
    NODE *node = end;
    while(node != NULL) {
        printf("%c ", node->data);
        node = node->prev;

    }
}

/*
 * This inserts a new node at the beginning the of doubly linked list.
*/
void insert_start(NODE **startp, NODE **endp, NODE *new_np) {
    if(*startp == NULL && *endp == NULL) {
        *startp = new_np;
        *endp = new_np;

    } else {
        (*startp)->prev = new_np;
        new_np->next = *startp;
        *startp = new_np;
    }
}

/*
 * This inserts a new node at the end of the doubly linked list.
*/
void insert_end(NODE **startp, NODE **endp, NODE *new_np) {    
    if(*startp == NULL && *endp == NULL) {
        *startp = new_np;
        *endp = new_np;

    } else {
        (*endp)->next = new_np;
        new_np->prev = *endp;
        *endp = new_np;
    }
}

/*
 * This deletes the first node of the doubly linked list.
*/
void delete_start(NODE **startp, NODE **endp) {
    if (*startp == NULL) {
        return;
    }
    NODE *temp = *startp;
    *startp = (*startp)->next;
    (*startp)->prev = NULL;
    free(temp);
    if (*startp == NULL) {
        *endp = NULL;
    }
}

/*
 * This deletes the last node of the doubly linked list.
*/
void delete_end(NODE **startp, NODE **endp) {
    if (*startp == NULL) {
        return;
    }
    NODE *temp = *endp;
    *endp = (*endp)->prev;
    (*endp)->next = NULL;
    free(temp);
    if (*endp == NULL) {
        *startp = NULL;
    }
}

/*
 * This cleans the doubly linked list.
*/
void clean(NODE **startp, NODE **endp) {
    NODE *curr = *startp;
    NODE *prev = NULL;
    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);

    }

    *startp = NULL;
    *endp = NULL;
}