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
//----- TEST DRIVER -----
int main( )
{

	ItemType v;
   // Node_t* tmp;

   Stack_t stack = stackCreate();
   assert(stackIsEmpty(stack));
   assert(stackSize(stack) == 0);
   /*
    // insert your code here
   */
   

   printf("Queue\n=====\n");
   Queue_t q = qCreate();
      assert(qIsEmpty(q));
      assert(qLength(q) == 0);
      /*
       // insert your code here
      */
      
}

