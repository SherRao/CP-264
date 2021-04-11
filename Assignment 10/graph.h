/*
 -------------------------------------
 File:    graph.h
 Project: raox6250_a10

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-04-04
 -------------------------------------
 */
#ifndef GRAPH_H
#define GRAPH_H

#define INFINITY 99999

typedef struct adjnode  {
    int nid;
    int weight;
    struct adjnode *next;

} ADJNODE;

typedef struct gnode  {
    int nid;           
    ADJNODE *neighbor;  

} GNODE;

typedef struct graph {
    int order;       
    int size;           
    GNODE **nodes;

} GRAPH;

/* create and return a new adjacent list graph of order n */
GRAPH *new_graph(int n);

/* add a new edge (from, to, weight) to the graph passed by GRAPH *g, 
  if the edge (from, to) exists, update its weight.
*/
void add_edge(GRAPH *g, int from, int to, int weight);

/* traverse and display node id by breadth-first order starting from nid */
void bf_traverse(GRAPH *g, int nid);

/* traverse and display node id by depth-first order starting from nid*/
void df_traverse(GRAPH *g, int nid); 


int get_weight(GRAPH *g, int from, int to);
void display_graph(GRAPH *g);
void clean_graph(GRAPH **gp);

typedef struct queue_node {
  void *data;
  struct queue_node *next;
  
} QNODE;

typedef struct queue {
  QNODE *front, *rear;

} QUEUE;

void enqueue(QUEUE *qp, void *data);
void *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

typedef struct stack_node {
  void *data;
  struct stack_node *next;

} SNODE;

typedef struct stack {
  SNODE *top;

} STACK;

void push(STACK *sp, void *data);
void pop(STACK *sp);
void *peek(STACK *sp);
void clean_stack(STACK *sp);

#endif