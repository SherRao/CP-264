/*
--------------------------------------------------
Project: CP264-a2q3
File:    matrix_main.c  public test driver
Author:  HBF
Version: 2021-01-15
--------------------------------------------------
*/

#include<stdio.h>
#include "matrix.h"

int main() {
  int n = 3;
  int m1[n][n];
  int m2[n][n];
  int m3[n][n];
  
/* assign 3X3 matrix to following values
 8     1     6
 3     5     7
 4     9     2
 */
  int v[9] = { 8, 1, 6, 3, 5, 7, 4, 9, 2 };
  int i, *p = &v[0];
	
  int *p1 = &m1[0][0];
  for (i = 0; i < 9; i++) *p1++ = *p++;
  
  p1 = &m1[0][0];
  //printf("\nm1:");
  //display_matrix(p1, n);
  printf("sum(m1):%d\n", sum(p1, n));
  printf("is_magic_square(m1):%d\n", is_magic_square(p1, n));  
  
  int *p2 = &m2[0][0];  
  //printf("\nm1':");
  transpose_matrix(p1, p2, n);
  //display_matrix(p2, n);
  printf("sum(m1'):%d\n", sum(p2, n));
  printf("is_magic_square(m1'):%d\n", is_magic_square(p2, n));  
  
  int *p3 = &m3[0][0];
  multiply_matrix(p1, p2, p3, n);  
  //printf("\nm1*m1':");
  //display_matrix(p3, n);
  printf("sum(m1*m1'):%d\n", sum(p3, n));
  printf("is_magic_square(m1*m1'):%d\n", is_magic_square(p3, n));  
  
  return 0;
}
