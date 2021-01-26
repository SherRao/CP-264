/*
-------------------------------------
File:    cubes_02.c
Project: Lab02_cp264_t2
file description
-------------------------------------
Author:  Nausher Rao
ID:      190906250
Email:   raox6250@mylaurier.ca
Version  2021-01-20
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR_SIZE 12

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    int i;          
    int values [ARR_SIZE];
    long int cubes[ARR_SIZE];
    int *pV = values;
    long int *pS = cubes;

    for(int i = 0; i < ARR_SIZE; i++) 
        *(pV + i) = i + 1;

    for(int i = 0; i < ARR_SIZE; i++) 
        *(pS + i) = *(pV + i) **(pV + 1) **(pV + 1);

    printf("\n");
    printf("Array traversal by \"POINTER INDEXING\"\n");
    printf("=====================================\n");
    printf("\n");
    printf("Value       Cube  \n");
    printf("=====     ==========\n");

    for(int i = 0; i < ARR_SIZE; i++)
		printf("%3d     %8ld\n", *(pV + i), *(pS + i));

    printf(":::\n");
    printf("::: Program Terminated.\n");
    printf(":::\n");

    return 0;
}
