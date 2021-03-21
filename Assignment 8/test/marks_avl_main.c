/*
--------------------------------------------------
Project: cp264-a8q2
File:    avl_markstats_main.c
Description: test driver program
Author:  HBF  
Version: 2020-03-03
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "marks_avl.h"

int main(int argc, char* args[]) {
  char infilename1[40] = "marks.txt.1";
  char infilename2[40] = "marks.txt.2";
  char outfilename[40] = "report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename1, args[1]);
    if (argc >= 3) strcpy(infilename2, args[2]);
    if (argc >= 4) strcpy(outfilename, args[3]);
  }  
  
  printf("\nLoad data from file %s\n", infilename1);
  MARKS ds1 = {0};
  import_data(&ds1, infilename1);
  display_marks(&ds1);
  
  printf("\nLoad data from file %s\n", infilename2);
  MARKS ds2 = {0};
  import_data(&ds2, infilename2); 
  display_marks(&ds2);

  printf("\nMerge\n");
  merge_data(&ds1, &ds2);
  clean_marks(&ds2);
  display_marks(&ds1);

  printf("\nWrite report to file %s\n", outfilename);
  report_data(&ds1, outfilename);    
  clean_marks(&ds1);
  
  printf("\nRead file %s\n", outfilename);
  FILE *fp =fopen(outfilename, "r");
  if ( fp == NULL ) {
    printf("output file does not exist\n");
    return 0;
  }
  char buf[100];
  while( !feof(fp) ) {
     fgets(buf, sizeof(buf), fp);
     printf("%s", buf);
     buf[0] = 0;
  }
  fclose(fp);
  
  return 0;
}

