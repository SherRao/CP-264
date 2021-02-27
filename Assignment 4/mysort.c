/*
 -------------------------------------
 File:    myrecord.c
 Project: cp264_a4_koha5160
 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-02-12
 -------------------------------------
 */

#include "mysort.h"

BOOLEAN is_sorted(int *a, int left, int right) {
	for(int i = left; i < right; i++)
		if(*(a + i) > *(a + i + 1))
			return false;
	
	return true;
}

void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

void select_sort(int *a, int left, int right) {
	int i, j, k;
	for(i = left; i <= right; i++) {
		k = i;
		for(j = i + 1; j <= right; j++) 
			if (*(a + j) < *(a + k)) 
				k = j;
			
		if(i != k) 
			swap(a + k, a + i);	
	}
}

int part(int *a, int left, int right) {
	int pivot = *(a + right);
	int i = left - 1;
	for(int j = left; j < right; j++) {
		if(*(a + j) < pivot) {
			i++;
			swap(a + i, a + j);
		}
	}

	swap(a + i + 1, a + right);
	return i + 1;
}

void quick_sort(int *a, int left, int right) {
	if(left < right) {
		int pi = part(a, left, right);
		quick_sort(a, left, pi - 1);
		quick_sort(a, pi + 1, right);
	}
}

