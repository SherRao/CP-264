/*--------------------------------------------------
Project: CP264-a5q3
File:    bigint_main.c
Author:  HBF
Version: 2019-11-01
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"
#include "bigint.h"

int main(int argc, char* args[]) {
  char *opr1 = "1111111111111111111";
  char *opr2 = "8888888888888888889";
  int n = 100;
  if (argc > 1) opr1 = args[1];
  if (argc > 2) opr2 = args[2];
  if (argc > 3 ) n = atoi(args[3]); 

  //testing add()
  BIGINT a = bigint(opr1);
  BIGINT b = bigint(opr2); 
  BIGINT s = add(a, b); 
  display_bigint(a);
  printf("%c", '+');
  display_bigint(b);
  printf("=");
  display_bigint(s);
  clean_bigint(&a);
  clean_bigint(&b);
  clean_bigint(&s);

  //testing Fibonacci()
  printf("\nFibonacci(%d)=", n);
  s = Fibonacci(n);
  display_bigint(s);
  clean_bigint(&s);
  return 0;
}
