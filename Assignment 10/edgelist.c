/*
 -------------------------------------
 File:    edgelist.c
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
#include "edgelist.h"

EDGELIST *new_edgelist() {
    EDGELIST *list = malloc( sizeof(EDGELIST) );
    list->start = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
    EDGE *edge = malloc(sizeof(EDGE));
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->next = NULL;
    
    if(g->size == 0)
        g->start = g->end = edge;

    else if(g->size == 1) 
        g->start->next = g->end = edge;

    else {
        g->end->next = edge;
        g->end = g->end->next;

    }
    
    g->size += 1;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
    EDGE *edge = malloc(sizeof(EDGE));
    edge->from = from;
    edge->to = to;
    edge->weight = weight;
    edge->next = g->start;

    if(g->size == 0) {
        g->start = g->end = edge;

    } else 
        g->start = edge; 

    g->size += 1;   
}

int weight_edgelist(EDGELIST *g) {
    EDGE *node = g->start;
    int weight = 0;
    while(node) {
        weight += node->weight;
        node = node->next;
    } 

    return weight;
}

void clean_edgelist(EDGELIST **gp) {
  EDGELIST *g = *gp;
  EDGE *temp, *p = g->start;
  while (p) {
    temp = p; 
    p = p->next;
    free(temp);
  }
  free(g);
  *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
  if (g == NULL) return;
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;
  while (p) {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}
