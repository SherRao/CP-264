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

void set_stopword(char *filename, char *stopwords[]) {
	FILE *fp = fopen(filename, "r");
	char line[1000];
	char delimiters[] = ".,\n\t\r";
	char *token;
	int i;
	while (fgets(line, 1000, fp) != NULL) {
		token = (char*) strtok(line, delimiters);
		while (token != NULL) {
			i = (int) (*token - 'a');
			strcat(stopwords[i], token);
			strcat(stopwords[i], ",");
			token = (char*) strtok(NULL, delimiters);
		}
	}
	fclose(fp);

}

// this function check if word is a word in string str,
// returns 1 if yes, 0 otherwise
int contain_word(char *str, char *word) {
	if (str == NULL || word == NULL)
		return 0;
	// your code
	char temp[20] = { 0 };
	strcat(temp, ",");
	strcat(temp, word);
	strcat(temp, ",");

	if (strstr(str, temp))
		return 1;
	return 0;
}

// this function check if the word is contained in directory stopwords[]
// returns 1 if yes, 0 otherwise. It use function contain_word()
int is_stopword(char *stopwords[], char *word) {
// your code
	if (word == NULL || *word == '\0')
		return 0;
	else {
		return contain_word(stopwords[*word - 'a'], word);
	}
}

int process_word(char *filename, WORDSUMMARY *ws, char *stopwords[]) {
	const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
	// your implementation
	char line[1000];
	char *word_token;
	FILE *fp = fopen(filename, "r");
	int i;
	while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
		ws->line_count++;
		lower_case(line);
		trim(line);
		word_token = strtok(line, delimiters);
		while (word_token != NULL) {
			if (is_stopword(stopwords, word_token) == 0) {
				//Insert word in words->array[]
				for (i = 0; i < ws->keyword_count; i++) {
					if (strcmp(ws->word_array[i].word, word_token) == 0) {
						ws->word_array[i].frequency++;
						break;
					}
				}
				if (i == ws->keyword_count) {
					strcpy(ws->word_array[i].word, word_token);
					ws->word_array[i].frequency = 1;
					ws->keyword_count++;
				}

			}
			ws->word_count++;
			word_token = strtok(NULL, delimiters);
		}
	}
	fclose(fp);
	return 0;

}

int save_to_file(char *filename, WORDSUMMARY *ws) {
// your implementation
	int i;
	FILE *fp = fopen(filename, "w");
	fprintf(fp, "line count:%d\n", ws->line_count);
	fprintf(fp, "word count:%d\n", ws->word_count);
	fprintf(fp, "non-common word count:%d\n", ws->keyword_count);
	for (i = 0; i < ws->keyword_count; i++) {
		fprintf(fp, "%s:%d\n", ws->word_array[i], ws->word_array[i].frequency);
	}
	fclose(fp);

}
