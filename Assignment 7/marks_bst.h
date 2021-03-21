/*
 -------------------------------------
 File:    marks_bst.h
 Project: raox6250_a07

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#ifndef MARKS_BST_H
#define MARKS_BST_H

#include "bst.h"

typedef struct marks_stats {
    TNODE *bst;
    int count;
    float mean;
    float stddev;
    
} MARKS;

void add_data(MARKS *dsp, char *name, float score);
void remove_data(MARKS *dsp, char *name);

char letter_grade(float score);
void import_data(MARKS *dsp, char *filename);
void report_data(MARKS *dsp, char *filename);
void print_to_file_inorder(TNODE *root, FILE *filename);
void display_marks(MARKS *dsp);
void clean_marks(MARKS *dsp);

#endif /* MARKS_BST_H_ */
