/*
 -------------------------------------
 File:    common.h
 Project: raox6250_a09

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-31
 -------------------------------------
 */
#ifndef COMMON_H
#define COMMON_H

typedef struct node {
    int data; 
	int type; 
	struct node *next;

} NODE;

NODE *new_node(int data, int type);

void display(NODE *start);

void clean(NODE **startp);

#endif
