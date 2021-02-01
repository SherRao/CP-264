/*
--------------------------------------------------
Project: cp264a2q1
File:    fibonacci_main.c public test driver
Author:  HBF
Version  2021-01-15
--------------------------------------------------
*/
#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int *la;
int *ha;

int main(){
  int n = 40;
  printf("iterative_fibonacci(%d):%d\n", n, iterative_fibonacci(n));
  printf("recursive_fibonacci(%d):%d\n", n, recursive_fibonacci(n));
  return 0;
}
