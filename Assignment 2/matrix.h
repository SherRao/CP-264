/*
-------------------------------------
File:    matrix.h
Project: raox6250_a02

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-01-29
 -------------------------------------
 */

#ifndef MATRIX_H_
#define MATRIX_H_

void display_matrix(int *m, int n);
int sum(int *m, int n);
int is_magic_square(int *m, int n);
void transpose_matrix(int *m1, int *m2, int n);
void multiply_matrix(int *m1, int *m2, int *m3, int n);

#endif /* MATRIX_H_ */
