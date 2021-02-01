/*
 -------------------------------------
 File:    matrix.c
 Project: raox6250_a02
 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-01-29
 -------------------------------------
 */

#include<stdio.h>
#include "matrix.h"


/*
 -------------------------------------------------------
 Displays the n by n matrix in 2d format.
 Use: display_matrix(int *m, int n)
 -------------------------------------------------------
 Parameters:
 *m - pointer to the first element in the matrix (pointer)
 n - length of the matrix: amount of columns (int)
 Returns:
 None
 -------------------------------------------------------
 */
void display_matrix(int *m, int n) {
	int *p = m, i, j;
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%4d", *p++);
	
	}
	
	printf("\n");

}


/*
 -------------------------------------------------------
 computes and returns the sum of all elements of the n by n matrix m
 Use: sum(int *m, int n)
 -------------------------------------------------------
 Parameters:
 *m - pointer to the first element in the matrix (pointer)
 n - length of the matrix: amount of columns (int)
 Returns:
 sum - sum of the 2d matrix
 -------------------------------------------------------
 */
int sum(int *m, int n) {
	int sum = 0;
	int *p = m;
	int i;
	int j;
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			sum += *p++;

	return sum;
}


/*
 -------------------------------------------------------
 Computes and returns if the n by n matrix m is a magic square.
 Returns 1 if true or zero if false. A square matrix is a magic square
 if the sum of every row, column, and diagonal is of the same magic constant rowsum.
 Use: is_magic_square(int *m, int n)
 -------------------------------------------------------
 Parameters:
 *m - pointer to the first element in the matrix (pointer)
 n - length of the matrix: amount of columns (int)
 Returns:
 is_magic - returns 1 if true, 0 if false
 -------------------------------------------------------
 */
int is_magic_square(int *m, int n) {
	int magic = 1;
	int leftDiaganol = 0;
	int rightDiaganol = 0; 
	int rowsum = n * (n * n + 1) / 2; 
	int *q = m;
	int *p = m;
	int i;
	int j;
	int row;
	int col; 

	for(row = 0, j = 0; row < n; row++, j++) {
		int row_val = 0;
		int col_val = 0;
		for (col = 0, i = 0; col < n; col++, i++) {
			if (row == n - (i + 1)) 
				rightDiaganol += *p;
			
			if (i == j)
				leftDiaganol += *q;

			row_val += *p++;
			col_val += *q++;
		}
	
		if (row_val != rowsum || col_val != rowsum)
			magic = 0;

	}

	if (rightDiaganol != rowsum || leftDiaganol != rowsum) 
		magic = 0;

	return magic;
}


/*
 -------------------------------------------------------
 Transposes the n by n matrix m1 and save the resulted matrix in m2
 Use: transpose_matrix(int *m1, int *m2, int n)
 -------------------------------------------------------
 Parameters:
 *m1 - pointer to the first element in the matrix (pointer)
 *m2 - pointer to the first element in the blank matrix (pointer)
 n - length of the matrix: amount of columns (int)
 Returns:
 none
 -------------------------------------------------------
 */
void transpose_matrix(int *m1, int *m2, int n) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			*(m2 + j * n + i) = *(m1 + i * n + j);
	
	return;
}


/*
 -------------------------------------------------------
 Computes the matrix multiplication m1*m2 and saves the resulted matrix in m3
 Use: multiply_matrix(int *m1, int *m2, int *m3, int n)
 -------------------------------------------------------
 Parameters:
 *m1 - pointer to the first element in the matrix (pointer)
 *m2 - pointer to the first element in the blank matrix (pointer)
 n - length of the matrix: amount of columns (int)
 Returns:
 none
 -------------------------------------------------------
 */
void multiply_matrix(int *m1, int *m2, int *m3, int n) {
	int temp;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			temp = 0;
			for (int i = 0; i < n; i++) 
				temp += *(m1 + row * n + i) * *(m2 + i * n + col);

			*(m3 + row * n + col) = temp;
		}
	}

	return;
}