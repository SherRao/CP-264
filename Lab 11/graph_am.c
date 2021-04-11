/*
 -------------------------------------
 File:    graph_am.c
 Project: raox6250_l11

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-04-03
 -------------------------------------
 */
#include "My_Definitions.h"
#include "graph_am.h"

void randomGraph(int adj[][MAX]) {
	int v;

	srand(time(NULL));
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			if(j == i)
				adj[i][j] = 0;
			
            else {
				v = rand() % 2;
				adj[i][j] = v;
				adj[j][i] = v;
			}
		}
	}
}

void displayAdjacentMatrix(int adj[][MAX]) {
	printf("    ");
	for(int i = 0; i < MAX; i++) 
        printf("%d ", i);
	
    printf("  <=== Node Number\n\n");
	for(int i = 0; i < MAX; i++) {
		printf("%d  ", i);
		for(int j = 0; j < MAX; j++)
            printf(" %d", adj[i][j]);

		printf("\n");
	}

    printf("^\n");
    printf("|__ Node Number\n");
    printf("\n");
}

void connected(int adj[][MAX], int node) {
    printf("\nNodes connected to node %d: [ ", node);
    for(int i = 0; i < MAX; i++)
        if(adj[node][i] > 0)
            printf("%d ", i);

    printf("]");
}

void node_counts(int adj[][MAX], int count) {
    printf("\nNodes connected to %d other nodes [ ", count);
    for(int i = 0; i < MAX; i++) {
        int connections = 0;
        for(int j = 0; j < MAX; j++) {
            if(connections > count)
                break;

            if(adj[i][j] != 0)
                connections++;

        }

        if(connections == count)
            printf("%d ", i);
    }

    printf("]");
}
