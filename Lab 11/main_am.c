/*
 -------------------------------------
 File:    main_am.c
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

enum em_GraphOrigin {HARD_CODED,
		             RANDOM
                    };

/**
 * @param argc unused
 * @param argv unused
 * @return
 */
int main(int argc, char *argv[]) {
	int i;
	int adj[MAX][MAX] = { {0, 0, 0, 0, 1, 1, 0, 1, 0, 1},    // Declare and fill adjacency matrix with
                          {0, 0, 0, 0, 1, 0, 1, 1, 1, 1},    // hard-coded values for easier debugging and validation.
                          {0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
                          {1, 1, 1, 1, 0, 1, 0, 0, 1, 1},
                          {1, 0, 0, 1, 1, 0, 1, 0, 0, 0},
                          {0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
                          {1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
                          {0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                          {1, 1, 0, 0, 1, 0, 0, 1, 1, 0}
                        };
	enum em_GraphOrigin GraphOrigin;    // Enum variable to process choice of the source of adjacency matrix values.

	GraphOrigin = HARD_CODED;           // Choose to execute program with the HARD CODED adjacency matrix.

	switch ( GraphOrigin ) {
	   case HARD_CODED:                 // Use above-filled hard-coded adjacency matrix.
		 printf("\n");
		 printf("Hard-Coded Adjacency Matrix:\n");
		 printf("=========================== \n");
		 break;

	   case RANDOM:                     // Use Randomly generated Graph/adjacency matrix.
	      randomGraph(adj);             // Generate the random Graph.

  	      printf("\n");
	      printf("Randomly-Generated Adjacency Matrix:\n");
	      printf("=================================== \n");
	      break;
	   default:
		  printf(">>> ERR: Internal Error.\n");
		  printf("       : Invalid -GraphOrigin- specified: [%d]\n", GraphOrigin);
	}
	displayAdjacentMatrix(adj);       // Display the Graph.

	printf("\n\n");
	printf("Connected:\n");
	printf("========= \n");

	for (i = 0; i < MAX; i++) {
		connected(adj, i);            // Output the node connections.
	}

	printf("\n\n");
	printf("Node Counts:\n");
	printf("=========== \n");
	for (i=0; i < MAX; i++ ) {
	    node_counts(adj, i);          // Output the number of node connections.
	}

	return 0;
}
