/*
--------------------------------------------------
Project: CP264-a5q1
File:    myrecord_llist_main.c   public test driver
Author:  HBF
Version: 2021-01-11
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "myrecord_llist.h"

int main(int argc, char* args[]) {
  char infilename[40] = "marks.txt";
  char outfilename[40] = "report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  

  NODE *start = NULL;
  import_data(&start, infilename);
  
  // display data
  display(start);

  // testing insert and search
  char name[20] = "Moore";
  insert(&start, name, 92.0);
  NODE *p = search(start, name);
  if (p == NULL)
    printf("%s:not fount\n", name);
  else
    printf("%s:%.1f\n", p->data.name, p->data.score);
  
  // testing delete and search
  strcpy(name, "Wang");
  delete(&start, name);
  p = search(start, name);
  if (p == NULL)
    printf("%s:not fount\n", name);
  else
    printf("%s:%.1f\n", p->data.name, p->data.score);

  // test report
  REPORT report = report_data(start, outfilename);
  printf("count:%d\n", report.count);
  printf("mean:%.1f\n", report.mean);
  printf("stddev:%.1f\n", report.stddev);
  
  // test clean
  clean(&start);
  printf("start:%d\n", start);
  return 0;
}

