/*
 -------------------------------------
 File:    graph.c
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
#include "graph.h"

GRAPH *new_graph(int order) {
    GRAPH *graph = malloc( sizeof(GRAPH) );
    graph->nodes = malloc(order * sizeof( GNODE *) );
    graph->order = order;
    graph->size = 0;

    for(int i = 0; i < order; i++) {
        graph->nodes[i] = malloc( sizeof(GNODE) );
        graph->nodes[i]->nid = i;
        graph->nodes[i]->neighbor = NULL;

    }

    return graph;
}

void add_edge(GRAPH *g, int from, int to, int weight) {
	ADJNODE *prev = NULL;
	ADJNODE *curr = g->nodes[from]->neighbor;
	if(curr == NULL) {
		ADJNODE *node = malloc(sizeof(ADJNODE));
		node->nid = to;
		node->weight = weight;
		node->next = NULL;
		g->nodes[from]->neighbor = node;

	} else {
		while(curr) {
			prev = curr;
			curr = curr->next;
		
        }

		if(curr == NULL) {
			ADJNODE *node = malloc(sizeof(ADJNODE));
			node->nid = to;
			node->weight = weight;
			node->next = NULL;
			prev->next = node;
		}
	}

	g->size++;
}


void bf_traverse(GRAPH *graph, int nid) {
    if(!graph)
        return;

    QUEUE queue = {0};
    GNODE *graph_node = NULL;
    ADJNODE *adj_node = NULL;

    int n = graph->order;
    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;  

    enqueue(&queue, graph->nodes[nid]);
    visited[nid] = 1;
    while(queue.front) {
        graph_node = dequeue(&queue);
        adj_node = graph_node->neighbor;

        printf("%d ", graph_node->nid);
        while(adj_node) {
            int i = adj_node->nid;
            if(visited[i] == 0) {
                visited[i] = 1;
                enqueue(&queue, graph->nodes[i]);

            }

            adj_node = adj_node->next;
        }
    }

    clean_queue(&queue);
}


void df_traverse(GRAPH *graph, int nid) {
   if(!graph)
        return;    

    STACK stack = {0};
    GNODE *graph_node = NULL;
    ADJNODE *adj_node = NULL;

    int n = graph->order;
    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;  

    push(&stack, graph->nodes[nid]);
    visited[nid] = 1;
    while(stack.top) {
        graph_node = peek(&stack); pop(&stack);
        adj_node = graph_node->neighbor;

        printf("%d ", graph_node->nid);
        while(adj_node) {
            int i = adj_node->nid;
            if(visited[i] == 0) {
                visited[i] = 1;
                push(&stack, graph->nodes[i]);

            }

            adj_node = adj_node->next;
        }
    }

    clean_stack(&stack);

}

int get_weight(GRAPH *graph, int from, int to) {
    ADJNODE *node = graph->nodes[from]->neighbor;
    while(node) {
        if(node->nid == to) 
            return node->weight;
    
        node = node->next;
    }

    return INFINITY;
}

void clean_graph(GRAPH **gp)
{
    int i;
    GRAPH *g = *gp;
    ADJNODE *temp, *ptr;
    for (i = 0; i < g->order; i++)
    {
        ptr = g->nodes[i]->neighbor;
        while (ptr != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        free(g->nodes[i]);
    }
    free(g->nodes);
    free(g);
    *gp = NULL;
}

void display_graph(GRAPH *g)
{
    if (g == NULL)
        return;
    printf("order:%d\n", g->order);
    printf("size:%d\n", g->size);
    printf("from:(to weight)");
    int i;
    ADJNODE *ptr;
    for (i = 0; i < g->order; i++)
    {
        printf("\n%d:", g->nodes[i]->nid);
        ptr = g->nodes[i]->neighbor;
        while (ptr != NULL)
        {
            printf("(%d %d) ", ptr->nid, ptr->weight);
            ptr = ptr->next;
        }
    }
}

// queue functions adapted and modified from a7
void enqueue(QUEUE *qp, void *data)
{
    QNODE *p = (QNODE *)malloc(sizeof(QNODE));
    if (p == NULL)
        return;
    else
    {
        p->data = data;
        p->next = NULL;

        if (qp->front == NULL)
        {
            qp->front = p;
            qp->rear = p;
        }
        else
        {
            (qp->rear)->next = p;
            qp->rear = p;
        }
    }
}
void *dequeue(QUEUE *qp)
{
    void *temp = NULL;
    if (qp->front)
    {
        QNODE *p = qp->front;
        temp = p->data;
        if (qp->front == qp->rear)
        {
            qp->front = NULL;
            qp->rear = NULL;
        }
        else
        {
            qp->front = p->next;
        }
        free(p);
        return temp;
    }
    return NULL;
}
void clean_queue(QUEUE *qp)
{
    QNODE *temp, *p = qp->front;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}

// stack functions adapted and modified from a6q3
void push(STACK *sp, void *data)
{
    SNODE *p = (SNODE *)malloc(sizeof(SNODE));
    p->data = data;
    p->next = NULL;
    if (sp->top == NULL)
    {
        sp->top = p;
    }
    else
    {
        p->next = sp->top;
        sp->top = p;
    }
}
void pop(STACK *sp)
{
    if (sp->top != NULL)
    {
        SNODE *p = sp->top;
        sp->top = p->next;
        free(p);
    }
}
void *peek(STACK *sp)
{
    if (sp->top != NULL)
    {
        return sp->top->data;
    }
    return NULL;
}
void clean_stack(STACK *sp)
{
    SNODE *temp, *p = sp->top;
    while (p)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    sp->top = NULL;
}