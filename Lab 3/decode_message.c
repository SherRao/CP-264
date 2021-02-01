/*
-------------------------------------
File:    decode_message.c
Project: Lab3_cp264
-------------------------------------
Author:  Nausher Rao
ID:      190906250
Email:   raox6250@mylaurier.ca
Version  2021-01-31
-------------------------------------

Program Description:
===================
   Given a 2D character array, called "scrambled", filled with ad hoc characters, this program uses the [row, col]
pair values stored in the 2D integer array, called "key", to retrieve characters from the "scrambled" array.
The retrieved individual characters are concatenated, left to right, and in the order that they are retrieved, to
form the complete decoded message. The message is then output.
------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM_ROWS 5 
#define MAX_NUM_COLS 6 
#define MAX_KEY_PAIRS 15 

const char underscore = '_';
const char blank = ' ';

int main(int argc, char *argv[]) {
   setbuf(stdout, NULL);

   char scrambled[MAX_NUM_ROWS][MAX_NUM_COLS] = {{"zd_k83"}, {"Ju9_Tn"}, {"bgm7If"}, {"ax0DLU"}, {"p_QoiR"}};
   int key[MAX_KEY_PAIRS][2] = {{3,5}, {5,2}, {4,1}, {3, 3}, {1,3}, {1, 2}, {5,4}, {5,5}, {2, 6}, {3,2}, {2,4}, {4, 5}, {4,1}, {3, 1}, {1,6} };
   char result[MAX_KEY_PAIRS];
   
   for(int i = 0; i < MAX_KEY_PAIRS; i++) {
      int x = key[i][0];
      int y = key[i][1];
      char c = scrambled[x - 1][y - 1];
      if(c == underscore)
         strncat(result, &blank, 1);

      else strncat(result, &c, 1);

   }

   printf("Result: %s", result);
   return 0;
   
}
	