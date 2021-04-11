/*
 -------------------------------------
 File:    hashing_int.c
 Project: 202101_CP264_Lab09_Hashing
 Hashing Source Code
 -------------------------------------
 Author:  Heider Ali & Rick Magnotta
 ID:      999999999
 Email:   heali@wlu.ca & rmagnotta@wlu.ca
 Version: 2021-03-18
 ------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "hashing_int.h"

void initialize_hash_table(int hash_table[], // The integer 1D array implementing the Hash Table.
		int MAX_HASH_TABLE_SIZE) // Max. number of slots defined for the Hash Table.
//=================================================
// Fill the hash table array with NULLS casted to "int"!
{
	for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
		hash_table[i] = (int) NULL;
	}
	return;
}

/**
 *
 * @param hash_table
 * @param MAX_HASH_TABLE_SIZE
 * @return
 */

bool insert_hash_table(int hash_table[], // The integer 1D array implementing the Hash Table.
		int MAX_HASH_TABLE_SIZE) // Max. number of slots defined for the Hash Table.
//=============================================
{
	bool INSERTED;            // TRUE if key/value is inserted, FALSE otherwise.
	int key;   // The input Key/Value to insert/store into the Hash Table/Array.

	//Step 1: Read the key/value to be inserted.
	printf("Enter an integer key/value to insert into Hash table: \n");
	scanf("%d", &key);
	while (getchar() != '\n')
		//get input from user and assure its not empty character
		;

	printf("\n");
	printf("Slot  Collision?  Value Inserted\n");
	printf("====  ==========  ==============\n");

	INSERTED = FALSE;
	int max = MAX_HASH_TABLE_SIZE;   //i didnt wanna type this that much
	//Step 2: Let i = 0
	int i = 0, index;//i is a counter to go until table size, index is hash table index

	while (!INSERTED && i < max) {   //Step 6
		//Step 3: Compute the index at which the key/value has to be inserted in hash table
		index = ((key % max) + i) % max;
		//Step 4: If there is no element at that index, then insert the key/value at index and STOP!
		if (hash_table[index] == NULL) {
			hash_table[index] = key;
			INSERTED = TRUE;
			printf("%4d      no      %14d\n", index, key);
		}
		//Step 5: If there is already an element at that index, then re-hash with "i+1" (repeat step 3)
		else
			printf("%4d      Yes\n", index);
		i++;
	}//Step 6: Repeat Step-3, 4, and 5 as long as (i < HASH_TABLE_SIZE) or an empty slot hasn't been found

	if (!INSERTED)
		printf("Element [%d] cannot be inserted.\n", key);

	return (INSERTED);
}

bool search_hash_table(int hash_table[], // The integer 1D array implementing the Hash Table.
		int MAX_HASH_TABLE_SIZE) // Max. number of slots defined for the Hash Table.
//=============================================
// Ask user to input the "key" value of interest, and use it's hash value
// to search for its presence/absence from the "hash_table".
// Prints appropriate search-result message, and
// returns TRUE if key is found in hash_table, FALSE otherwise.
{
	bool FOUND = FALSE; // TRUE if input key is found in hash_table, false otherwise.
	int key;                              // Input key value to search!

	printf("\n");
	//Step 1: Read the key/value to be inserted.
	printf("Enter integer key/value to search:\n");
	scanf("%d", &key);
	while (getchar() != '\n')
		;

	int max = MAX_HASH_TABLE_SIZE;
	//Step 2: Let i = 0
	int i = 0, index;

	//Step 6
	while (!FOUND && i < max) {
		//Step 3: Compute the index at which the key/value has to be inserted in hash table
		index = ((key % max) + i) % max;
		//Step 4: If  element at that index matches key, then value is found, STOP!
		if (hash_table[index] == key) {
			FOUND = TRUE;
			printf("Key/Value [%d] is found at index/slot [%d]\n", key, index);
		}
		//Step 5: If element is not at that index, then re-hash with "i+1" (repeat step 3)
		else
			i++;
	} //Step 6: Repeat Step-3, 4, and 5 as long as (i < HASH_TABLE_SIZE) or an value hasn't been found

	if (!FOUND)
		printf("Key/Value [%d] is not found!\n", key);

	return (FOUND);
}

void display_hash_table(int hash_table[], // The integer 1D array implementing the Hash Table.
		int MAX_HASH_TABLE_SIZE) // Max. number of slots defined for the Hash Table.
//==============================================
// Print the contents of the "hash_table".
{
	printf("\n");
	printf("Contents of Hash Table:\n");
	printf("====================== \n");
	printf("Index/Slot   Key/Value \n");
	printf("==========   ========= \n");

	for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
		if (hash_table[i] == (int) NULL)
			printf("%10d   %9s\n", i, "empty");
		else
			printf("%10d   %9d\n", i, hash_table[i]);
	}
	printf("\n");
	return;
}
