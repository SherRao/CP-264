/*
 -------------------------------------
 File:    marks_avl.h
 Project: raox6250_a08

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-18
 -------------------------------------
 */
#ifndef MARSAVL_H
#define MARSAVL_H

#include "avl.h"

typedef struct mark_stats {
    TNODE *bst;
    int count;
    float mean;
    float stddev;
} MARKS;

/* merge tree rootp2 into tree rootp1 */
void merge_tree(TNODE **rootp1, TNODE **rootp2); 

/* merget two MARKS dataset and aggregate stats info */
void merge_data(MARKS  *ds1, MARKS *ds2);

// the following functions are from a7q2
void display_stats(MARKS *dsp); 
void add_data(MARKS *dsp, char *name, float score);
void remove_data(MARKS *dsp, char *name);
void import_data(MARKS *dsp, char *filename);
void report_data(MARKS *dsp, char *filename);
void print_to_file_inorder(TNODE *root, FILE *filename);
void display_marks(MARKS *dsp);
void clean_marks(MARKS *dsp);
char letter_grade(float score);

#endif