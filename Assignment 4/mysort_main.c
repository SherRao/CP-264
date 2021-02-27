/*
--------------------------------------------------
Project: cp264-a4q1 
File:    mysort_main.c, public test driver  
Author:  HBF
Version: 2021-02-06
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>  
#include <time.h> 
#include "mysort.h"

void display_array(int *a, int n)
{
  int i; 
  for (i=0; i<n; ++i) {
    printf("%d,", *(a+i));
  }
}

void copy_array(int *a, int *b, int n)
{
  int i;
  for (i = 0; i < n; i++)
    *(b+i) = *(a+i); 
}

int main(int argc, char *args[])
{
  int a[] = {3, 1, 4, 5, 2, 7, 6, 9, 8}; // input array for correctness testing
  int n = sizeof(a)/sizeof(int);         // array length
  int b[n], i;                           // array to sort
  
  printf("Algorithm correctness testing:\n");  
  printf("a[]:");  
  display_array(a, n);
  printf("\n"); 
  printf("is_sorted(a):%d\n", is_sorted(a, 0, n-1));  
  
  printf("Selection sort:");
  copy_array(a, b, n);
  select_sort(b, 0, n-1);
  display_array(b, n);
  printf("\nis_sorted(b):%d\n", is_sorted(b, 0, n-1));  

  printf("Quick sort:");
  copy_array(a, b, n);
  quick_sort(b, 0, n-1); 
  display_array(b, n);
  printf("\nis_sorted(b):%d\n", is_sorted(b, 0, n-1));  
  
  
  // un-comment the following for runtime testing
  
 /*
  printf("Algorithm runtime testing:\n");  
  //run time measurement
  clock_t t1, t2;    
  int len = 10000;
  int a1[len];
  int b1[len];
  //generate randomly an array of len elements more modular len
  
  
  srand(time(NULL)); 
  for (i=0;i<len;i++) {
    a1[i] = rand()% len;
  }

  //run time measuring for selection_sort
  int m1 = 10;
  t1=clock();
  for (i=0; i< 1; i++) {
    copy_array(a1, b1, len);
    select_sort(b1, 0, len-1); 
    if (is_sorted(b1, 0, len-1) == false) printf("not sorted:\n");  
  }
  t2=clock();
  double time_span1 = (double) t2-t1;
  printf("time_span(selection_sort(%d numbers) for %d times)(ms):%0.1f\n", len, m1, time_span1);
  
  //run time measuring for quick_sort
  int m2 = 1000;
  t1=clock();
  for (i=0; i< m2; i++) {
    copy_array(a1, b1, len);
    quick_sort(b1, 0, len-1); 
    if (is_sorted(b1, 0, len-1)== false) printf("not sorted:%d\n");  
  }
  t2=clock();
  double time_span2 = (double) t2-t1;
  printf("time_span(quick_sort(%d numbers) for %d times)(ms):%0.1f\n", len, m2, time_span2);
  
  printf("time_span(selection_sort(%d numbers))/time_span(quick_sort(%d numbers)):%0.1f\n", len, len, (time_span1/10)/(time_span2/m2));
*/
  return 0;
} 
