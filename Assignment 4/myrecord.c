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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

char letter_grade(float s) {
	char grade[] = {'S', 'A', 'B', 'C', 'D', 'F'};
	float score[] = {90, 80, 70, 60, 50, 0};
	int left = 0;
	int right = sizeof(score) / sizeof(float) - 1;
	int mid;

	while(left <= right) {
		mid = (right - left) / 2 + left;
		if(score[mid] == s) 
			return grade[mid];

		else if(s > score[mid]) 
			right = mid - 1;

		else 
			left = mid + 1;	
	}
	
	return grade[left];
}

int import_data(RECORD dataset[], char *filename) {
	const char delims[] = ",\n\r";
	FILE *file = fopen(filename, "r");
	char line[100];
	char *word_token;
	int i = 0;

	while(fgets(line, sizeof(line), file) != NULL) {
		word_token = strtok(line, delims);
		strcpy(dataset[i].name, word_token);
		word_token = strtok(NULL, delims);
		dataset[i].score = atof(word_token);
		i++;
	}

	fclose(file);
	return i;
}

REPORT report_data(RECORD dataset[], int n, char *filename) {
	REPORT report = {};
	if(n < 1)
		return report;

	int i;
	FILE *fp = fopen(filename, "w");
	for(i = 0; i < n; i++) {
		report.mean += dataset[i].score;
		report.count++;
		fprintf(fp, "%s,%c\n", dataset[i].name, letter_grade(dataset[i].score));
	}

	fclose(fp);
	report.mean /= n;
	for(i = 0; i < n; i++)
		report.stddev += (dataset[i].score - report.mean) * (dataset[i].score - report.mean);
	
	report.stddev = sqrt(report.stddev / n);
	return report;
}
