/*
 -------------------------------------
 File:    myrecord.c
 Project: cp264_a4_koha5160
 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-02-12
 -------------------------------------
 */

#ifndef MYRECORD_H_
#define MYRECORD_H_

typedef struct {
	char name[20];
	float score;

} RECORD;

typedef struct {
	int count;
	float mean;
	float stddev;

} REPORT;

char letter_grade(float score);
int import_data(RECORD dataset[], char *filename);
REPORT report_data(RECORD dataset[], int n, char *filename);

#endif
