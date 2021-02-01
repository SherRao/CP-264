/*
--------------------------------------------------
Project: cp264-a2q2
File:    polynomial_main.c   public test driver 
Author:  HBF
Version  2021-01-15
--------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "polynomial.h"
 
int main()
{  
  int n = 4;
  float p[] = {1, 2, 3, 4};
  
  int m = 3;
  float x[] = {0,1,10};
  
  // test display and horner functions
  int i;
  for (i=0; i<m; i++) {
    printf("P(%.2f)=", x[i]);
    display_polynomial(p, n, x[i]);
    printf("=");  
    printf("%.2f\n", horner(p, n, x[i]));
  }
  
  // test bisection function
  float a=-2, b=2;
  float pa = horner(p, n, a); 
  printf("P(%.2f)=%.2f\n", a, pa);      
  float pb = horner(p, n, b);
  printf("P(%.2f)=%.2f\n", b, pb);

  if (pa * pb <= 0) {
    float root = bisection(p, n, a, b);   
    printf("root=%.2f\n", root);
    printf("P(%.2f)=%.2f\n", root, fabs(horner(p, n, root))); 
  }
  else {
    printf("have the same sign on both sides\n");
  }  
  return 0;
}
