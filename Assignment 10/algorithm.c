/*
 -------------------------------------
 File:    algorithm.c
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

#include "heap.h"
#include "algorithm.h"

EDGELIST *mst_prim(GRAPH *graph, int start) {
    if(!graph)
        return NULL;

    int n = graph->order;
    int T[n];
    int parent[n];
    
    int heap_index;
    HNODE heap_node; 
    HEAP *heap = new_heap(4); 

    for(int i = 0; i < n; i++)
        T[i] = 0;
    
    for(int i = 0; i < n; i++)
        parent[i] = -1; 

    T[start] = 1;
    ADJNODE *temp = graph->nodes[start]->neighbor;
    while(temp) {
        heap_node.key = temp->weight;
        heap_node.data = temp->nid;

        insert(heap, heap_node);

        parent[temp->nid] = start;
        temp = temp->next;
    }

    EDGELIST *mst = new_edgelist();
    while(heap->size > 0) {
        heap_node = extract_min(heap); 
        int i = heap_node.data;
        T[i] = 1;
        add_edge_end(mst, parent[i], i, heap_node.key);
        
        temp = graph->nodes[i]->neighbor;
        while(temp) {
            heap_index = find_index(heap, temp->nid);
            if(heap_index >= 0) {
                if(T[temp->nid] == 0 && temp->weight < heap->hnap->key) {
                    decrease_key(heap, heap_index, temp->weight);
                    parent[temp->nid] = i;

                }

            } else {
                if(T[temp->nid] == 0) {
                    heap_node.key = temp->weight;
                    heap_node.data = temp->nid;
                    insert(heap, heap_node);
                    parent[temp->nid] = i;

                }
            }

            temp = temp->next;
        }
    }

    return mst;
}

EDGELIST *spt_dijkstra(GRAPH *graph, int start) {
	if(!graph) 
		return NULL;
	
    EDGELIST *spt = new_edgelist();
	int heap_index;
    int u;
    
    int n = graph->order;
    int T[n];
    int parent[n];
    int label[n];
	for(int i = 0; i < n; i++) {
		T[i] = 0;
		label[i] = INFINITY;
	}

    HEAP *heap = new_heap(4);
    HNODE heap_node;
	ADJNODE *temp = graph->nodes[start]->neighbor;
	label[start] = 0;
	T[start] = 1;

	while(temp) {
		heap_node.key = temp->weight + label[start];
		heap_node.data = temp->nid;
	
    	insert(heap, heap_node);
    	parent[temp->nid] = start;
		temp = temp->next;
	}

	while(heap->size > 0) {
		heap_node = extract_min(heap);
		u = heap_node.data;
		T[u] = 1;
		
        add_edge_end(spt, parent[u], u, heap_node.key);
		temp = graph->nodes[u]->neighbor;
		while(temp) {
			heap_index = find_index(heap, temp->nid);
			if(heap_index >= 0) {
				if(T[temp->nid] == 0 && temp->weight + label[u] < heap->hnap->key) {
					decrease_key(heap, heap_index, temp->weight + label[u]);
					parent[temp->nid] = u;
				
                }
			
            } else {
				if(T[temp->nid] == 0) {
					heap_node.key = temp->weight;
					heap_node.data = temp->nid;

					insert(heap, heap_node);
					parent[temp->nid] = u;
				}
			}

			temp = temp->next;
		}
	}

	return spt;
}

EDGELIST *sp_dijkstra(GRAPH *graph, int start, int end) {
    if(!graph)
        return NULL;

    int heap_index;
    int u;
    int n = graph->order;
    
    int parent[n];
    int visited[n];
    int label[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        label[i] = INFINITY;
    
    }

    HEAP *heap = new_heap(4);
    ADJNODE *temp = graph->nodes[start]->neighbor;
    HNODE heap_node;
    visited[start] = 1;
    label[start] = 0;

    while(temp) {
        heap_node.key = temp->weight;
        heap_node.data = temp->nid;
        
        insert(heap, heap_node);
        
        parent[temp->nid] = start;
        visited[temp->nid] = 0;
        label[temp->nid] = label[start] + temp->weight;
        temp = temp->next;

    }

    EDGELIST *spt = new_edgelist();
    while(heap->size > 0) {
        //printf("in second while loop");
        HNODE gn = extract_min(heap);
        u = gn.data;
        visited[u] = 1;
        add_edge_end(spt, parent[u], u, label[u] - label[parent[u]]);

        if (u == end)
            break;

        temp = graph->nodes[u]->neighbor;
        HNODE heap_node_temp;
        while (temp) {
            heap_index = find_index(heap, temp->nid);
            if(heap_index >= 0) {
                if(visited[temp->nid] == 0 && temp->weight + label[u] < heap->hnap->key) {
                    decrease_key(heap, heap_index, temp->weight + label[u]);
                    parent[temp->nid] = u;
                    label[temp->nid] = temp->weight + label[u];
                
                }
            }

            else {
                if(visited[temp->nid] == 0) {
                    heap_node_temp.key = temp->weight + label[u];
                    heap_node_temp.data = temp->nid;

                    insert(heap, heap_node_temp);

                    parent[temp->nid] = u;
                    label[temp->nid] = temp->weight + label[u];
                }
            }

            temp = temp->next;
        }
    }

    EDGELIST *sp = new_edgelist();
    sp->size = 0;

    while (u != start) {
        add_edge_start(sp, parent[u], u, label[u] - label[parent[u]]);
        u = parent[u];
    
    }

    return sp;
}