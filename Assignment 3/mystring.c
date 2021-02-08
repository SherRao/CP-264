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

#include "mystring.h"
#define NULL 0

int str_length(char *s) {
	// your implementation
	int length = 0, i = 0;
	while (s[i] != '\0') {
		i++;
		length++;
	}
	return length;
}

int word_count(char *s) {
// your implementation
	int words=0,i=0,prev=1;
	while(s[i]!='\0'){
		if(s[i]!=' ' && prev==1){
			prev=0;
			words++;
		}else if(s[i]==' '){
			prev=1;
		}
		i++;
	}
	return words;

}

void lower_case(char *s) {
// your implementation
	int i=0;
	while(s[i]!='\0'){
		if(s[i]>='A' && s[i]<='Z'){
			s[i] += 32;
		}
		i++;
	}
}

void trim(char *s) {
	// your implementation
	int i,j;
	for(i=j=0;s[i];i++){
		if(s[i]!=' ' || (i>0 && s[i-1]!=' ')){
			s[j++]=s[i];
		}
	}

	if(s[j-1]==' '){
		s[j-1]='\0';
	}
	s[j]='\0';

}
