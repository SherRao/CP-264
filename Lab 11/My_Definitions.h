/*
 -------------------------------------
 File:    My_Definitions.c
 Project: raox6250_l11

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-04-03
 -------------------------------------
 */
#ifndef MY_DEFINITIONS_H_
#define MY_DEFINITIONS_H_

#ifdef TRUE
   #undef TRUE
   #undef FALSE
   
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

typedef unsigned int bool;

#define SUCCESS TRUE
#define FAILURE FALSE

//#define DEBUG_LEVEL_01
//#define DEBUG_LEVEL_02

#endif /* MY_DEFINITIONS_H_ */
