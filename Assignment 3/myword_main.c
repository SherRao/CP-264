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
#include <string.h>
#include "mystring.h"
#include "myword.h"

void display_word_summary(WORDSUMMARY *ws) {
  printf("%s:%d\n", "line count", ws->line_count);
  printf("%s:%d\n", "word count", ws->word_count);
  printf("%s:%d\n", "non-common word count", ws->keyword_count);
  int i;
  for (i = 0; i < ws->keyword_count; i++) {
    printf("%s:%d\n", ws->word_array[i].word, ws->word_array[i].frequency);
  }
}

int main(int argc, char *args[]) {  
  char infilename[40] = "textdata.txt"; //default input file name
  char outfilename[40] = "result.txt";  //default output file name
  char stopwordfilename[40] = "common-english-words.txt"; //default stop word file
  if (argc > 1) {  
	if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
	if (argc >= 4) strcpy(stopwordfilename, args[3]);
  }

  //stop word dictionary as an array of strings
  char stopword_arrays[26][100] = {0};
  char *stopwords[26];
  int i;
  for (i=0; i<26; i++) {
    stopwords[i] = &stopword_arrays[i][0];
  }
  set_stopword(stopwordfilename, stopwords);
  printf("stop word checker:ready\n");
  printf("is_stopword(%s):%d\n","is", is_stopword(stopwords, "is"));
  printf("is_stopword(%s):%d\n","hello", is_stopword(stopwords, "hello"));
  
  //my word processor
  WORDSUMMARY wordsummary = {0}; 
  process_word(infilename, &wordsummary, stopwords);  
  printf("word processing:done\n");
  display_word_summary(&wordsummary);
  save_to_file(outfilename, &wordsummary); 
  printf("saving result to file:done\n");

  return 0;
}


