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

#ifndef MYSORT_H_
#define MYSORT_H_

typedef enum {
	false, true,

} BOOLEAN;

void select_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);
BOOLEAN is_sorted(int *a, int left, int right);

#endif 