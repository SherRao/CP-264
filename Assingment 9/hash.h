/*
 -------------------------------------
 File:    hash.h
 Project: raox6250_a09

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-31
 -------------------------------------
 */
#ifndef HASH_H
#define HASH_H

extern int htsize;

typedef struct hashnode {
  char name[10];
  int value;
  struct hashnode *next; 
  
} HTNODE;

typedef struct hashtable {
  HTNODE **hnp;
  int size;
  int count;

} HASHTABLE;

/* hash function that hash name string to an integer of modular htsize */
int hash(char *name); 

/* create dynamically a hash node and set name and value and return the point */
HTNODE *new_hashnode(char *name, int vale); 

/* create dynamically a chained hash table of the size */
HASHTABLE *new_hashtable(int size); 

/* search the hash table and return the pointer of found hashnode */
HTNODE *search(HASHTABLE *ht, char *name);

/* insert hashnode np to hash table
 * when the named hashnode exists, update the hashnode's value by np->value, free np, return 0;
 * otherwise insert into the hash table, return 1 
 */
int insert(HASHTABLE *ht, HTNODE *np);

/* delete hashnode by name. If the named hash node exists, delete it and return 1; 
 * otherwise return 0
 */
int delete(HASHTABLE *ht, char *name);


void clean_hash(HASHTABLE **htp);

void display_hashtable(HASHTABLE *ht, int option);

#endif