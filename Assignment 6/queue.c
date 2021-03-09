/*
 -------------------------------------
 File:    queue.c
 Project: raox6250_a06

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
    if(qp->front) {  
        qp->rear->next = np;
        qp->rear = qp->rear->next;

    } else
        qp->front = qp->rear = np;

}

NODE *dequeue(QUEUE *qp) {
    if(!qp->front) { //Queue is empty
        return NULL;

    } else if(qp->front->data == qp->rear->data || qp->rear->data == qp->front->next->data) { //Queue is of size 1 or 2
        NODE *node = qp->front;
        qp->front = qp->front->next;
        qp->rear = qp->front;
        return node;

    } else {
        NODE *node = qp->front;
        qp->front = qp->front->next;
        return node;

    }
}

void clean_queue(QUEUE *qp) {
    clean(&qp->front);
    qp->rear = NULL;

} 