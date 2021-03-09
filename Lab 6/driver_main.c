/*
-------------------------------------
File:    driver_main.c
Project: stack_queue
file description
-------------------------------------
Author:  Heider Ali
ID:      9999999999
Email:   heali@wlu.ca
Version  2020-10-29
-------------------------------------
 */
/* This lab give you a practice on how to build and test stacks
 * and queues. You have to give or complete the given code to
 * get the required output
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "llstack.h"
#include "llqueue.h"
#include "llist.h"

//----- TEST DRIVER -----
int main() {
Stack_t stack = stackCreate();
	assert(stackIsEmpty(stack));
	assert(stackSize(stack) == 0);

	//push CP264
	char first[] = "462PC";
	char *ptrf = first;
	Stack_t *ptr2stack = &stack;

	//printf("\n %c, %c \n\n", ptrf[0], ptrf[1]);
	for (int i = 0; i < sizeof(first) - 1; i++) {
		if (ptrf[i] != '/0') {
			stackPush(ptr2stack, ptrf[i]);
		}
	}

	//print the stack
	printf("Stack \n===\n\n");
	printf("Stack:  ");

	Node_t *tmp = ptr2stack->head->next;

	for (int i = 0; i < stackSize(stack); i++) {

		if (i == stackSize(stack) - 1) {
			printf("[%c]--|\n", tmp->data);
		} else {
			printf("[%c]-->", tmp->data);
		}
		tmp = tmp->next;
	}
	printf("\n");

	//
	//push LAB6
	//
	char second[] = "6BAL";
	char *ptrs = second;
	Stack_t *toStack2 = &stack;

	for (int i = 0; i < sizeof(second) - 1; i++) {
		if (ptrs[i] != '/0') {
			stackPush(toStack2, ptrs[i]);
		}
	}

	//print the stack
	printf("Stack:  ");

	tmp = ptr2stack->head->next;
	for (int i = 0; i < stackSize(stack); i++) {

		if (i == stackSize(stack) - 1) {
			printf("[%c]--|\n", tmp->data);
		} else {
			printf("[%c]-->", tmp->data);
		}
		tmp = tmp->next;
	}
	printf("\n");

	//pop LAB6//
	for (int i = 0; i < 4; i++) {
		stackPop(ptr2stack);
	}

	//print the stack
	printf("Stack:  ");

	tmp = ptr2stack->head->next;
	for (int i = 0; i < stackSize(stack); i++) {

		if (i == stackSize(stack) - 1) {
			printf("[%c]--|\n", tmp->data);
		} else {
			printf("[%c]-->", tmp->data);
		}
		tmp = tmp->next;
	}

	/*------ testing for queue ------*/
	printf("\nQueue\n=====\n\n");
	Queue_t q = qCreate();
	assert(qIsEmpty(q));
	assert(qLength(q) == 0);

	//insert -Hallo
	char test[] = "-Hallo";
	char *ptrt = test;
	Stack_t *ptr2queue = &q;

	for (int i = 0; i < sizeof(test) - 1; i++) {
		if (ptrt[i] != '/0') {
			qEnqueue(ptr2queue, ptrt[i]);
		}
	}

	//print the q
	Node_t *tmpq = ptr2queue->head->next;

	printf("Queue:  ");
	for (int i = 0; i < qLength(q); i++) {

		if (i == qLength(q) - 1) {
			printf("[%c]--|\n", tmpq->data);
		} else {
			printf("[%c]-->", tmpq->data);
		}
		tmpq = tmpq->next;
	}
	printf("\n");

	//dq the front
	qDequeue(ptr2queue);

	//print the q
	Node_t *tmpq1 = ptr2queue->head->next;

	printf("Queue:  ");
	for (int i = 0; i < qLength(q); i++) {

		if (i == qLength(q) - 1) {
			printf("[%c]--|\n", tmpq1->data);
		} else {
			printf("[%c]-->", tmpq1->data);
		}
		tmpq1 = tmpq1->next;
	}
	printf("\n");

	//enqueue ween
	char test2[] = "ween";
	char *ptrw = test2;

	for (int i = 0; i < sizeof(test2) - 1; i++) {
		if (ptrw[i] != '/0') {
			qEnqueue(ptr2queue, ptrw[i]);
		}
	}
	//print the q
	Node_t *tmpq2 = ptr2queue->head->next;

	printf("Queue:  ");
	for (int i = 0; i < qLength(q); i++) {

		if (i == qLength(q) - 1) {
			printf("[%c]--|\n", tmpq2->data);
		} else {
			printf("[%c]-->", tmpq2->data);
		}
		tmpq2 = tmpq2->next;
	}
	printf("\n");
    llDestroy(ptr2queue);
    llDestroy(ptr2stack);

}

