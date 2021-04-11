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
#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

#include "My_Definitions.h"
// #include "int_data.h"

#define MAX_HEAP_SIZE 20
#define HEAP_INIT 20               // Defines three full rows of heap

/**
 * Heap header.
 */
typedef struct {
	int   capacity;          ///< current capacity of the max_heap.
	int   size;              ///< count of number of values in the max_heap.
	int *values;             ///< pointer to array of "int" data values.
} max_heap;

                                  //===== Prototypes
/**
 * Initialize a heap structure
 * @return a pointer to the heap.
 */
max_heap* max_heap_initialize();

/**
 * Determines if a heap is empty.
 * @param heap pointer to a heap.
 * @return TRUE if the heap is empty, FALSE otherwise.
 */
bool max_heap_empty(const max_heap *heap);

/**
 * Determines if the heap is full.
 * @param heap pointer to a heap.
 * @return TRUE if the heap is full, FALSE otherwise.
 */
bool max_heap_full(const max_heap *heap);

/**
 * Returns the size of the heap.
 * @param heap pointer to a heap.
 * @return Number of elements in heap.
 */
int max_heap_size(const max_heap *heap);

/**
 * Returns the value on the front of a heap, the heap is unchanged.
 * @param heap pointer to a heap.
 * @return the value on the top of the max_heap.
 */
int max_heap_peek(const max_heap *heap);

/**
 * Create a heap from an array of values.
 * @param heap Pointer to a heap
 * @param keys Values to insert into heap.
 * @param size Number of values in keys.
 */
bool max_heapify(max_heap *source,
		         int       keys[],
				 int       num_keys);

/**
 * Insert a single value in the appropriate/correct spot in the heap: "source"
 * @param source
 * @param value
 * @return TRUE if successful, FALSE if heap was FULL before insertion.
 */
bool max_heap_insert(      max_heap *source,
		             const int       value );

/**
 * Moves a value from location index up the heap until it is in its correct location
 * in the heap.
 * @param source pointer to a heap.
 */
void heapify_up(max_heap *source);


/**
 * Moves a value down a heap to its correct position.
 * @param source pointer to a heap.
 */
void heapify_down(max_heap *source);


/**
 * Swaps values in two data pointers.
 * @param a pointer to data.
 * @param b pointer to data.
 */
void heap_swap(int *a, int *b);


/**
 * Determines if a heap is valid: i.e. all values are <= parent
 * values.
 * @param source pointer to heap
 * @return TRUE if heap is valid, FALSE otherwise
 */
//bool max_heap_valid(const max_heap *source);

void heap_nice_print(max_heap *source);

#endif /* MAX_HEAP_H_ */

