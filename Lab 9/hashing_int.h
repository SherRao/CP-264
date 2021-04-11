/*
-------------------------------------
File:    hashing_int.h
Project: 202101_CP264_Lab09_Hashing
 Hashing Source Code
 -------------------------------------
 Author:  Heider Ali & Rick Magnotta
 ID:      999999999
 Email:   heali@wlu.ca & rmagnotta@wlu.ca
 Version: 2021-03-18
-------------------------------------
 */
#ifndef HASHING_INT_H_
#define HASHING_INT_H_

#include "My_Definitions.h"
                                //:::::::::::::: Function Prototypes
/**
 * Initializes the "hash_table" 1D-array of size HASH_TABLE_SIZE to (int)NULLs.
 * @param hash_table
 * @param HASH_TABLE_SIZE
 */
void initialize_hash_table(int hash_table[],
                           int MAX_HASH_TABLE_SIZE);

/**
 * Asks user to input an "integer" Key/Value and inserts its value into the "hash_table"
 * @param hash_table
 * @param HASH_TABLE_SIZE
 * @return TRUE if successful insertion, FALSE otherwise.
 */
bool insert_hash_table (int hash_table[],
                        int MAX_HASH_TABLE_SIZE);

/**
 * Displays the "current" contents of the "hash_table".
 * @param hash_table
 * @param HASH_TABLE_SIZE
 */
void display_hash_table(int hash_table[],
                        int MAX_HASH_TABLE_SIZE);

/**
 * Asks user to input an "integer" Key/Value and searches the "hash_table" for its value.
 * @param hash_table
 * @param HASH_TABLE_SIZE
 * @return TRUE if found, FALSE otherwise.
 */
bool search_hash_table (int hash_table[],
                        int MAX_HASH_TABLE_SIZE);

#endif /* HASHING_INT_H_ */
