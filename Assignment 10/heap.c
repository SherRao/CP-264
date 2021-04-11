/*
 -------------------------------------
 File:    heap.c
 Project: raox6250_a10

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-04-04
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"

HEAP *new_heap(int capacity)
{
  HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
  if (hp == NULL) return NULL;
  hp->hnap = (HNODE *) malloc(sizeof(HNODE) * capacity);
  if ( hp->hnap == NULL) { free(hp); return NULL; };

  hp->capacity = capacity;
  hp->size = 0;
  return hp;
}

void insert(HEAP *heap, HNODE new_node)
{
  unsigned int index, parent;
  HNODE *temp;

  // Resize the array if it is overflow
  if (heap->size == heap->capacity)
  {
    heap->capacity <<= 1;
    
    temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
      if (temp) {
      heap->hnap = temp;
    } else {
      temp = malloc(sizeof(HNODE) * heap->capacity);
      if (temp) {
        memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
        free(heap->hnap);
        heap->hnap = temp;
      } else {
        printf("memory expansion failed\n");
        exit(1);
      }
    }
  }
  
  for(index = heap->size; index; index = parent)
  {
    parent = (index - 1) >> 1;
    if (cmp(heap->hnap[parent].key, new_node.key)<=0)
      break;
    heap->hnap[index] = heap->hnap[parent];
  }
  heap->hnap[index] = new_node;
  heap->size++;
}

HNODE extract_min(HEAP *heap)
{
  unsigned int index, swap, other;
  HNODE top = heap->hnap[0];
  HNODE temp = heap->hnap[--heap->size];

  // Resize the array size to a 1/4
  if ((heap->size <= (heap->capacity >> 2)) && (heap->capacity > MIN_CAPACITY)) {
    heap->capacity >>= 1;
    heap->hnap = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
    if (!heap->hnap) exit(1); // Exit if the memory allocation fails
  }

  //heapify_down
  for(index = 0; 1; index = swap) {
    swap = (index << 1) + 1;
    if (swap >= heap->size) break;
    other = swap + 1;
    if ((other < heap->size) && cmp(heap->hnap[other].key, heap->hnap[swap].key)<=0)
      swap = other;
    if (cmp(temp.key, heap->hnap[swap].key)<=0)
      break;
    heap->hnap[index] = heap->hnap[swap];
  }

  heap->hnap[index] = temp;
  return top;
}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value)
{
  unsigned int index, parent; 
  HNODE temp; 
  heap->hnap[node_index].key = key_value;
  for(index = node_index; index; index = parent)
  {
    parent = (index - 1) >> 1;
    if (heap->hnap[parent].key <= key_value) 
      break;
    //swap with parent
    temp = heap->hnap[parent];
	heap->hnap[parent] = heap->hnap[index];
	heap->hnap[index] = temp;
  }  
}

int find_index(HEAP *heap, DATA value) {
  int i;
  for (i=0; i<heap->size; i++) {
    if (heap->hnap[i].data == value)
      return i;
  }
  return -1;
}

void display_heap(HEAP *hp) {
  printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
  printf("(index, key, data): ");
  int i;
  for (i=0; i < hp->size; i++) {
    printf("(%d %d %d) ", i, hp->hnap[i].key, hp->hnap[i].data);
    if (i % 10 == 9) printf("\n");    
  }
  printf("\n");
}

int cmp(KEYTYPE a, KEYTYPE b) {
  if (a < b) 
    return -1;
  else if (a==b) 
    return 0;
  else 
    return 1;
}
