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

//===================== GLOBAL MACRO DEFINITIONS ==========================================================

#define cNUL '\0' // NULL character
#define sNUL "\0" // NULL String
#define cBlank ' ' // Blank character
#define sBlank " " // Blank String
#define cUScore '_' // Underscore character
#define sUScore "_" // Underscore string.

#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)
                                // ======================== Statement Function Definitions.
#define  F_MIN(v1,v2) (((v1) <  (v2))? (v1):(v2))        // Return the less    of v1 and v2
#define  F_MAX(v1,v2) (((v1) >  (v2))? (v1):(v2))        // Return the greater of v1 and v2
#define ZF_MIN(v1,v2) (F_MAX(0, (F_MIN((v1),(v2)))))     // Like F_MIN, but lower bounds the result at ZERO
#define ZF(v)         (F_MAX(0, (v)))                    // Lower bounds the value "v" at ZERO.
#define  F_NOT(v)     (((v) == TRUE)? FALSE:TRUE)        // Logical Negation.
#define  F_ABS(v)     (((v) >= 0   )? (v):(-(v)))        // Absolute value

#define MAX_NUM_ROWS 5 
#define MAX_NUM_COLS 6 
#define MAX_KEY_PAIRS 15 

char blank = ' ';

int main(int argc, char *argv[]) {
   setbuf(stdout, NULL);

   char scrambled[MAX_NUM_ROWS][MAX_NUM_COLS] = {{"zd_k83"}, {"Ju9_Tn"}, {"bgm7If"}, {"ax0DLU"}, {"p_QoiR"}};
   int key[MAX_KEY_PAIRS][2] = {{3,5}, {5,2}, {4,1}, {3, 3}, {1,3}, {1, 2}, {5,4}, {5,5}, {2, 6}, {3,2}, {2,4}, {4, 5}, {4,1}, {3, 1}, {1,6} };
   char result[MAX_KEY_PAIRS];
   
   for(int i = 0; i < MAX_KEY_PAIRS; i++) {
      int x = key[i][0];
      int y = key[i][1];
      char c = scrambled[x - 1][y - 1];
      if(c == cUScore)
         strncat(result, &blank, 1);

      else strncat(result, &c, 1);

   }

   printf("Result: %s", result);
   return 0;
}
	