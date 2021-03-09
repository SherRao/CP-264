/*
-------------------------------------
File:    llstack.h
Project: stack_queue
file description
-------------------------------------
Author:  Heider Ali
ID:      9999999999
Email:   heali@wlu.ca
Version  2020-10-29
-------------------------------------
 */

#include "llist.h"

/*********************
 *  PUBLIC INTERFACE
 *********************/
typedef LinkedList_t Stack_t;

Stack_t stackCreate();

void stackDestroy(Stack_t* stack);

void stackPrint(const Stack_t stack);

bool stackIsEmpty(const Stack_t stack);

void stackPopAll(Stack_t* stack);

int stackSize(const Stack_t stack);

void stackPush(Stack_t* stack, ItemType value);

ItemType stackTop(const Stack_t stack);

ItemType stackPop(Stack_t* stack);
