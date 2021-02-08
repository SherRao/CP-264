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
#ifndef MYWORD_H_
#define MYWORD_H_

#define MAX_WORD 30
#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

typedef struct word {
	char word[MAX_WORD];
	int frequency;
} WORD;

typedef struct words {
	WORD word_array[MAX_WORDS];
	int line_count;
	int word_count;
	int keyword_count;
} WORDSUMMARY;

void set_stopword(char *filename, char *stopwordsp[]);
int contain_word(char *str, char *word);
int is_stopword(char *stopwords[], char *word);
int process_word(char *filename, WORDSUMMARY *ws, char *stopwords[]);
int save_to_file(char *filename, WORDSUMMARY *ws);

#endif /* MYWORD_H_ */
