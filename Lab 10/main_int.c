/*
-------------------------------------
File:    main_int.c
Project: 202101_CP264_Lab10_Heap
file description
-------------------------------------
Author:  Heider Ali & Rick Magnotta
ID:      9999999999
Email:   heali@wlu.ca & rmagnotta@wlu.ca
Version  2021-03-25
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "max_heap_int.h"

#define MAX_STR_SIZE 1024
#define SENTINEL_VAL -9999


int main(int argc, char *argv[])
//==============================
{
//	int  values[] = { 11, 7, 15, 15, 15, 6, 9, 12, 18, 8 };

	int  val_count;
    int  input_val;
	int  saved_heap_values[MAX_HEAP_SIZE];

	max_heap *source;

	setbuf(stdout, NULL);

	printf("Initialize a max heap:\n");
	printf("===================== \n");
	source = max_heap_initialize();

	printf("Heap Capacity = [%d]\n", source->capacity);
//	printf("Heap size     = [%d]\n", source->size    );      // or can call "max_heap_size" function to get "size" of heap!
	printf("Heap size     = [%d]\n", max_heap_size(source));

	if ( max_heap_empty(source) ) printf("Max heap [Source] is EMPTY! \n");
	else                          printf("Max heap [Source] is NOT EMPTY! \n");

	if ( max_heap_full(source) )  printf("Max heap [Source] is FULL! \n"    );
	else                          printf("Max heap [Source] is NOT FULL! \n");

	                                                     // Read the next value to insert in heap from keyboard.
	printf("\n");
	printf("Enter next Heap Value [%d to quit]: ", SENTINEL_VAL);
	scanf("%d", &input_val);

	val_count = 0;

	while ( (input_val != SENTINEL_VAL) ) {
       val_count ++;

       if ( !max_heap_insert(source, input_val) ) {
                                                          // Heap INSERTION failed!  Heap size exceeded.
    	   printf(">>>ERR: Heap is FULL!\n");
    	   input_val = SENTINEL_VAL;

       }else {
    	   saved_heap_values[val_count-1] = input_val;
                                                          // Print ALL heap values input so far.
           printf("\n");
           printf("==> INPUT Values: [");
           for (int i=0; i < val_count; i++) {
             printf("%d ", saved_heap_values[i]);
           }
	       printf("]\n");
                                                          // Print contents of Heap, so far.
	       printf("\n");
           printf("Contents of Heap Array: (Value at TOP of Heap = [%d])\n", max_heap_peek(source));
           printf("====================== \n");
           printf("[");
           for (int i=0; i < source->size; i++) {
              printf("%d ", source->values[i]);
           }
           printf("]\n");

           heap_nice_print(source);                  // Print HEAP structure "nice"

           printf("\n");
           printf("Enter next Heap Value [%d to quit]: ", SENTINEL_VAL);
	       scanf("%d", &input_val);
	       printf("\n");
       }
	}
	printf("\n");
	printf("::: Program Ended. Till next time.\n\n");

    return( 0 );
}
