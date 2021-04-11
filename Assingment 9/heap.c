/*
 -------------------------------------
 File:    heap.c
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
#include <string.h>

#include "heap.h"

HEAP* new_heap(int capacity) {
	HEAP *heap = malloc(sizeof(HEAP));
	heap->capacity = capacity;
	heap->size = 0;
	heap->hnap = malloc(sizeof(HNODE) * capacity);
	
    return heap;
}

void insert(HEAP *heap, HNODE new_node) {
	if(heap->size == heap->capacity) {
		heap->capacity *= 2;
		HNODE *temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
		if(temp) {
			heap->hnap = temp;

		} else {
			temp = malloc(sizeof(HNODE) * heap->capacity);
			if(temp) {
				memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
				free(heap->hnap);
				heap->hnap = temp;
			
            } else
				printf("Resizing Heap Array Failure");
		}
	}

	heap->size++;
	heap->hnap[heap->size - 1] = new_node;
	int parent_index = (heap->size - 2) / 2;
	int child_index = heap->size - 1;
	if(heap->size > 1 && (cmp(heap->hnap[child_index].key, heap->hnap[parent_index].key) == -1))
		heapify_up(heap);

}

void heap_swap(HNODE *a, HNODE *b) {
	KEYTYPE temp1 = a->key;
	a->key = b->key;
	b->key = temp1;

	DATA temp2 = a->data;
	a->data = b->data;
	b->data = temp2;    
}

void heapify_up(HEAP *heap) {
	int parent_index = (heap->size - 2) / 2;
	int child_index = heap->size - 1;
	HNODE *parent = &heap->hnap[parent_index];
	HNODE *child = &heap->hnap[child_index];

	while(child->key < parent->key && child_index != 0) {
		heap_swap(parent, child);
		child_index = parent_index;
		parent_index = (child_index - 1) / 2;
		parent = &heap->hnap[parent_index];
		child = &heap->hnap[child_index];

	}
}

void heapify_down(HEAP *source) {
	int run = 1;
	while(run == 1) {
		run = 0;
		for(int child_index = 0; child_index < source->size; child_index++) {
			int parent_index = (child_index - 1) / 2;
			if(source->hnap[child_index].key < source->hnap[parent_index].key) {
				heap_swap(&source->hnap[child_index], &source->hnap[parent_index]);
				run = 1;
                
			}

		}
    }
}

HNODE extract_min(HEAP *heap) {
	HNODE result = heap->hnap[0];
	heap->hnap[0] = heap->hnap[heap->size - 1];
	heap->hnap[heap->size - 1].data = 0;
	heap->hnap[heap->size - 1].key = 0;
	heap->size--;
	if(heap->size > 0) {
		if((cmp(heap->hnap[0].key, heap->hnap[1].key) == 1) || cmp(heap->hnap[0].key, heap->hnap[2].key) == 1)
			heapify_down(heap);

		if((float) ((float) heap->size / (float) heap->capacity) * 100 <= 25)
			heap->capacity = heap->capacity / 4;

	}

	return result;
}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value) {
	heap->hnap[node_index].key = key_value;
	int parent_index = (node_index - 2) / 2;
	int child_index = node_index;

	if(heap->size > 1 && (cmp(heap->hnap[child_index].key, heap->hnap[parent_index].key) == -1)) {
		HNODE *parent = &heap->hnap[parent_index];
		HNODE *child = &heap->hnap[child_index];

		while(child->key < parent->key && child_index != 0) {
			heap_swap(parent, child);
			child_index = parent_index;
			parent_index = (child_index - 1) / 2;
			parent = &heap->hnap[parent_index];
			child = &heap->hnap[child_index];

		}
	}
}

int find_index(HEAP *heap, DATA value) {
	int index = 0;
	int i = 0;
	while(heap->size > i && heap->hnap[i].data != value)
		i++;

	if(heap->hnap[i].data == value)
		index = i;

	return index;
}

void display_heap(HEAP *hp) {
	printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
	printf("(index, key, data):\n");
	int i;
	for (i = 0; i < hp->size; i++) {
		printf("(%d %d %d) ", i, hp->hnap[i].key, hp->hnap[i].data);
		if (i % 10 == 9)
			printf("\n");
	}
}

int cmp(KEYTYPE a, KEYTYPE b) {
	if(a < b)
		return -1;
	
    else if(a == b)
		return 0;
	
    else
		return 1;
}
