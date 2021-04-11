/*
 -------------------------------------
 File:    max_heap_int.c
 Project: 202101_CP264_Lab10_Heap
 file description
 Maximum Heap Source Code
 -------------------------------------
Author:  Heider Ali & Rick Magnotta
ID:      9999999999
Email:   heali@wlu.ca & rmagnotta@wlu.ca
Version  2021-03-25
 ------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "max_heap_int.h"

// Macros
//#define LESS_THAN(x,y)          compare((x), (y)) < 0
//#define LESS_THAN_EQUAL(x,y)    compare((x), (y)) <= 0
//#define GREATER_THAN(x,y)       compare((x), (y)) > 0
//#define GREATER_THAN_EQUAL(x,y) compare((x), (y)) >= 0
//#define EQUALS(x,y)             compare((x), (y)) == 0
//#define NOT_EQUALS(x,y)         compare((x), (y)) != 0
//#define COMPARE(x,y)            compare((x), (y))

// ===================================================== local functions

max_heap* max_heap_initialize() {
    max_heap *source;

    // Allocate storage for the "source" heap "header".
	source = malloc(sizeof *source);
	assert(source != NULL);
    
    // Allocate storage for the "values" array of integers to store the "heap".
	source->values = (int *) malloc(MAX_HEAP_SIZE * (sizeof *source->values));
	assert(source->values != NULL);
    
    // Initialize heap header values.
	source->capacity = MAX_HEAP_SIZE;
	source->size = 0;

    #ifdef DEBUG_LEVEL_01
    if(source->values != NULL) {
        printf("MAX_HEAP_SIZE          = [%d]      \n", MAX_HEAP_SIZE);
	    printf("sizeof *source->values = [%d]      \n", (sizeof *source->values));
	    printf("Size of Values array   = [%d] bytes\n", MAX_HEAP_SIZE * (sizeof *source->values));
    }
    #endif
	
    return source;
}

bool max_heap_empty(const max_heap *source) {
    bool empty_status;
	if(source->size == 0) 
        empty_status = TRUE;
	
    else
        empty_status = FALSE;

    return empty_status;
}

bool max_heap_full(const max_heap *source) {
	bool full_status;
	if(source->size == source->capacity)
        full_status = TRUE;
	
    else
        full_status  = FALSE;
	
    return full_status;
}

int max_heap_size(const max_heap *source) {
	return source->size;

}

int max_heap_peek(const max_heap *source) {
	int return_val = -999999;
	if(source->size > 0) 
        return_val = *source->values;

	return return_val;
}

bool max_heapify(max_heap *source, int keys[], int num_keys) {
    bool heapify_status;
    if(num_keys > source->capacity) {
        heapify_status = FAILURE;
        
    }else {
        for(int i = 0; i < num_keys; i++) 
            max_heap_insert(source, keys[i]);
      
      heapify_status = SUCCESS;
   }
   
   return heapify_status;
}

bool max_heap_insert(max_heap *source, const int value)
//==========================================
{
	bool insert_status;

#ifdef DEBUG_LEVEL_01
       printf(">>> In max_heap_insert()\n");
    #endif

	if (source->size >= MAX_HEAP_SIZE) {
		insert_status = FAILURE
		;             // Cannot insert because have exceeded declared size of Heap storage;

	} else {

		//1. increase the size of the heap
		source->size++;

		//2. Insert the new element at the end of the heap
		source->values[source->size - 1] = value;

		//3. heapify up if needed to maintain heap structure
		if (source->values[source->size - 2] < value)
			heapify_up(source);

		insert_status = SUCCESS
		;             // SUCCESS;
	}
#ifdef DEBUG_LEVEL_01
	   printf("<<< Returning from max_heap_insert()\n");
    #endif

	return (insert_status);
}

void heapify_up(max_heap *source)
//======================================
// Moves a value from location index up the heap until
// it is in its correct location in the heap.
{
#ifdef DEBUG_LEVEL_01
	   printf(">>> In heapify_up()\n");
    #endif

	//init the parent node and the child node position and data
	int parent_index = (source->size - 2) / 2; //this will grab the parent node in the binary tree array
	int child_index = source->size - 1;

	int parent_val = source->values[parent_index];
	int child_val = source->values[child_index];

	//swap the parent node and the current node
	while (child_val > parent_val && child_index != 0) {

		//swap the two values in the list
		heap_swap(&source->values[child_index], &source->values[parent_index]);

		//swap the current indexes
		child_index = parent_index;
		parent_index = (child_index - 1) / 2;

		//grab the new comparible values
		parent_val = source->values[parent_index];
		child_val = source->values[child_index];

	}

#ifdef DEBUG_LEVEL_01
       printf("<<< Returning from heapify_up()\n");
    #endif

	return;
}

/**
 * Moves a value down a heap to its correct position.
 * @param source pointer to a heap.
 */
void heapify_down(max_heap *source) {
    // NOTE: Function not currently used in this lab.

}


void heap_swap(int *a, int *b){
    int temp = *a;
	*a = *b;
	*b = temp;

}

void heap_nice_print(max_heap *source) {
    int max_lvl;                             // Max. level of heap for given heap size: [0,1,2,3,...]
    int lvl;                                 // Current level
    int Lidx;                                // Left-Index of heap array in current level.
    int Ridx;                                // Right-Index of heap array in current level.
    double epsilon = 0.00000001;

    printf("\n");
    printf("Heap Structure:\n");
    printf("============== \n");

    if(source->size == 0) {
        printf("::: Heap is EMPTY!\n");
   
    } else {
        // Calculate maximul level of heap, for given heap size, taking care to
        // incorporate a fix for the rounding error in log2 calculation.
        max_lvl = (int)(log(source->size)/log(2.0) + epsilon);

        for(lvl = 0; lvl <= max_lvl; lvl++) { // Loop through all levels, lvl being the current level of heap.
         Lidx = (int) pow(2.0, lvl) - 1;                     // Calculate the Left index and the Right index for the current heap level.
         Ridx = (int) fmin( 2*Lidx, source->size -1);
         for(int i = Lidx; i <= Ridx; i++) {               // Print all array values of the current level, on the same output line.
    	    printf("%d  ", source->values[i]);
         }
         printf("\n");
      }
      printf("\n");
   }
   return;
}
