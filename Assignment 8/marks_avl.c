/*
 -------------------------------------
 File:    marks_avl.c
 Project: raox6250_a08

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-18
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avl.h"
#include "marks_avl.h"

void merge_tree(TNODE **rootp1, TNODE **rootp2) {
    if(rootp2 == NULL)
        return;

    insert(rootp1, (*rootp2)->data.name, (*rootp2)->data.score);
    if((*rootp2)->left != NULL)
        merge_tree(rootp1, &(*rootp2)->left);

    if((*rootp2)->right != NULL)
        merge_tree(rootp1, &(*rootp2)->right);

}

void merge_data(MARKS *ds1, MARKS *ds2) {
    merge_tree(&ds1->bst, &ds2->bst);
    float mean1 = ds1->mean;
    int count1 = ds1->count;
    float stdev1 = ds1->stddev;

    float mean2 = ds2->mean;
    int count2 = ds2->count;
    float stdev2 = ds2->stddev;

    ds1->count += ds2->count;
    ds1->mean = ((mean1 * count1) + (mean2 * count2)) / ds1->count;
    ds1->stddev = sqrt( ((count1 * (pow(stdev1, 2) + pow(mean1, 2))) + (count2 * (pow(stdev2, 2) + pow(mean2, 2))) )/ds1->count - pow(ds1->mean, 2));
}


// the following are adapted from marks_bst.c of A7Q2


void display_stats(MARKS *sd) {
  printf("\nStatistics summary\n");
  printf("%s:%d\n", "count", sd->count);
  printf("%s:%.1f\n", "mean", sd->mean);
  printf("%s:%.1f\n", "stddev", sd->stddev);
}

void add_data(MARKS *sd, char *name, float score) {
    if (search(sd->bst, name) == NULL) {
      insert(&sd->bst, name, score);
     
    //recompute statistics summary by adding new one  
    int count = sd->count;
    float mean = sd->mean;
    float stddev = sd->stddev;
    sd->count = count + 1;
    sd->mean =  (mean*count + score) / (count+1);
    sd->stddev = sqrt(score*score/(count+1.0) + (stddev * stddev + mean * mean) * (count/(count+1.0)) - sd->mean * sd->mean );
     
  } else
    printf("record exit");  

}

void remove_data(MARKS *sd, char *name) {
    TNODE *np = NULL;
    if ( (np = search(sd->bst, name)) != NULL) {
    float score = np->data.score;
    delete(&sd->bst, name);
        
    //recompute statistics summary by removing an old one  
    int count = sd->count;
    float mean = sd->mean;
    float stddev = sd->stddev;
    sd->count = count - 1;
    sd->mean =  (mean*count - score) / (count-1.0);
    sd->stddev = sqrt( (stddev * stddev + mean * mean) * (count/(count-1.0)) - score*score/(count-1.0) - sd->mean * sd->mean );

  } else
    printf("record not exit");     
}

void display_marks(MARKS *dsp) { 
  display_inorder_lines(dsp->bst);  
  printf("\nstatistics summary\n");
  printf("%s:%d\n", "count", dsp->count);
  printf("%s:%.1f\n", "mean", dsp->mean);
  printf("%s:%.1f\n", "stddev", dsp->stddev);
}

void clean_marks(MARKS *dsp) {
  clean_tree(&dsp->bst);
  dsp->count = 0;
  dsp->mean = 0;
  dsp->stddev = 0;
}


void import_data(MARKS *ds, char *filename) {
  char line[40], name[20];
  FILE *fp = fopen(filename, "r");
  char *result = NULL;
  char delimiters[] = ",\n";
  float score = 0;
  int count = 0;
  float mean =0, stddev = 0;

  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    result = strtok(line, delimiters);
    if (result) {
      strcpy(name, result);
      result = strtok(NULL, delimiters);
      score = atof(result);
      count++;
      mean += score;
      stddev += score * score;
      insert(&ds->bst, name, score);
    }
  }
  
  ds->count = count;
  mean /= count; 
  ds->mean = mean;
  ds->stddev = sqrt(stddev/count - mean*mean); 
  
  fclose(fp);
}

void report_data(MARKS *sd, char *filename) {
  FILE *fp = fopen(filename, "w");
 
  print_to_file_inorder(sd->bst, fp);
  
  fprintf(fp, "\nStatistics summary\n");
  fprintf(fp, "%s:%d\n", "count", sd->count);
  fprintf(fp, "%s:%.1f\n", "mean", sd->mean);
  fprintf(fp, "%s:%.1f\n", "stddev", sd->stddev);
  fclose(fp);
}

void print_to_file_inorder(TNODE *root, FILE *fp) {
  if (root) {
    if (root->left) print_to_file_inorder(root->left, fp);
    fprintf(fp, "%s,%.1f,%c\n", root->data.name, root->data.score, letter_grade(root->data.score));
    if (root->right) print_to_file_inorder(root->right, fp);
  }
}

char letter_grade(float s){
  char r = 'F';
  if (s >= 90) r = 'S';
  else if (s >= 80) r = 'A';
  else if (s >= 70) r = 'B';
  else if (s >= 60) r = 'C';
  else if (s >= 50) r = 'D';  
  else r = 'F';
  return r;
}