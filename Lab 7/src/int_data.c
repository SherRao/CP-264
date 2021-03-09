/*
 -------------------------------------
 File:    data.c
 -------------------------------------
 Author:  Heider Ali & David Brown
 ID:      999999999 & 999999999
 Email:   heali@wlu.ca & dbrown@wlu.ca
 Version: 2021-03-03
 -------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "int_data.h"

char *int_to_string(      char *string,
		                  int   string_size,
					const int  *source     )
//==========================================
{
	sprintf(string, "%d", *source);
	return (string);
}

void int_destroy(int **source)
//============================
{
	free(*source);
	*source = NULL;
}

int int_compare(const int *target,
		        const int *source)
//================================
{
	int result;

	result = 0;
	if (*source < *target) {
		result = -1;
	} else if (*source > *target) {
		result = 1;
	}
	return (result);
}

int *int_copy(const int *source)
//==============================
{
	int *target;

	target = malloc(sizeof *target);
	assert(target != NULL);

	*target = *source;
	return (target);
}
