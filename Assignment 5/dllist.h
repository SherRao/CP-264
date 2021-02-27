/*
 -------------------------------------
 File:    dllist.h
 Project: raox6250_a05

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-02-25
 -------------------------------------
 */

#ifndef DLLIST
#define DLLIST

typedef struct {
    char data;
    struct NODE *prev;
    struct NODE *next;

} NODE;

/*
 * This creates a new node using malloc().
*/
NODE *new_node(char data);

/*
 * This displays char data from start to end.
*/
void display_forward(NODE *start); 

/*
 * This displays char data from end to start. 
*/
void display_backward(NODE *end);

/*
 * This inserts a new node at the beginning the of doubly linked list.
*/
void insert_start(NODE **startp, NODE **endp, NODE *new_np);

/*
 * This inserts a new node at the end of the doubly linked list.
*/
void insert_end(NODE **startp, NODE **endp, NODE *new_np);

/*
 * This deletes the first node of the doubly linked list.
*/
void delete_start(NODE **startp, NODE **endp);

/*
 * This deletes the last node of the doubly linked list.
*/
void delete_end(NODE **startp, NODE **endp);

/*
 * This cleans the doubly linked list.
*/
void clean(NODE **startp, NODE **endp);

#endif