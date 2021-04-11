/*
 -------------------------------------
 File:    graph_am.h
 Project: raox6250_l11

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-04-03
 -------------------------------------
 */
#ifndef GRAPH_AM_H_
#define GRAPH_AM_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "My_Definitions.h"

#define  MAX 10

void randomGraph(int adj[][MAX]);

void displayAdjacentMatrix(int adj[][MAX]);

void connected(int adj[][MAX],
		       int node);

void node_counts(int adg[][MAX],
		         int count);

#endif /* GRAPH_AM_H_ */
