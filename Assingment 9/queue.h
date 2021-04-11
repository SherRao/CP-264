/*
 -------------------------------------
 File:    queue.h
 Project: raox6250_a09

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-31
 -------------------------------------
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

typedef struct queue {
  NODE *front;
  NODE *rear;
} QUEUE;	

void enqueue(QUEUE *qp, NODE *np);
NODE *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif