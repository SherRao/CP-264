/*
 -------------------------------------
 File:    myword.h
 Project: Assignment 3
 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-02-02
 -------------------------------------
 */
#include <stdio.h>
#include "mystring.c"

int main(int argc, char* args[]) {
  setbuf(stdout, NULL);
  char str[100] = "     This Is    a Test   ";
  printf("str:\"%s\"\n", str);
  printf("str_length(str):%d\n", str_length(str));  
  printf("word_count(str):%d\n", word_count(str)); 
  trim(str);
  lower_case(str);
  printf("trim(str):\"%s\"\n", str);
  printf("str_length(trim(str)):%d\n", str_length(str));
  return 0;
}
