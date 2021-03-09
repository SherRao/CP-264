/*
-------------------------------------
File:    llqueue.h
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
typedef LinkedList_t Queue_t;

Queue_t qCreate();

void qDestroy(Queue_t* q);

void qPrint(const Queue_t q);

bool qIsEmpty(const Queue_t q);

void qClear(Queue_t* q);

int qLength(const Queue_t q);

void qEnqueue(Queue_t* q, ItemType value);

ItemType qFront(const Queue_t q);

ItemType qDequeue(Queue_t* q);
