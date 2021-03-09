/*
-------------------------------------
File:    llqueue.c
Project: stack_queue
file description
-------------------------------------
Author:  Heider Ali
ID:      9999999999
Email:   heali@wlu.ca
Version  2020-10-29
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "llqueue.h"

Queue_t qCreate() {
   return llCreate();

}

void qDestroy(Queue_t* q) {
    llDestroy(q);

}

void qPrint(const Queue_t q) {
   llPrint(q);

}

bool qIsEmpty(const Queue_t q) {
   return llIsEmpty(q);

}

void qClear(Queue_t* q) {
    Node_t *prev = NULL;
    Node_t *curr = q->head->next;
    while(curr) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }

    q->head = q->tail = NULL;
}

int qLength(const Queue_t q) {
   return llLength(q);

}

void qEnqueue(Queue_t* q, ItemType value) {
   llAppend(q, value);

}

ItemType qFront(const Queue_t q) {
    return llHead(q);

}

ItemType qDequeue(Queue_t* q) {
    return llPop(q);

}
