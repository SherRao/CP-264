/*
 -------------------------------------
 File:    queue.c
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
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
  if (qp == NULL || np == NULL) return;
  if (qp->front == NULL) {
    qp->front = np;
    qp->rear = np;
  }
  else {
    qp->rear->next = np;
    qp->rear = np;  
  }
}  

NODE *dequeue(QUEUE *qp) {
  if (qp == NULL || qp->front == NULL) return NULL;
	
  NODE *ptr = qp->front;
  if (qp->front == qp->rear) {
    qp->front = NULL;
    qp->rear = NULL;
  } 
  else {
    qp->front = ptr->next;    
  }
  //free(ptr);  // don't free, as the node is returned. 
  return ptr; 
}

void clean_queue(QUEUE *qp) {
  clean(&(qp->front));
  qp->front = NULL;
  qp->rear = NULL;
}