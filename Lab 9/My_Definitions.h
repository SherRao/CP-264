/*
-------------------------------------
File:    My_Definitions.h
Project: 202101_CP264_Lab09_Hashing
 Hashing Source Code
 -------------------------------------
 Author:  Heider Ali & Rick Magnotta
 ID:      999999999
 Email:   heali@wlu.ca & rmagnotta@wlu.ca
 Version: 2021-03-18
-------------------------------------
 */
#ifndef MY_DEFINITIONS_H_
#define MY_DEFINITIONS_H_

//#define DEBUG_LEVEL_01  1
//#define DEBUG_LEVEL_02  1

#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

#define SUCCESS TRUE
#define FAILURE FALSE

typedef unsigned bool;

#endif /* MY_DEFINITIONS_H_ */
