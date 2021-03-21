/*
 -------------------------------------
 File:    bst.h
 Project: raox6250_a07

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */

#ifndef BST_H_
#define BST_H_


typedef struct rec {
  char name[40];
  float score;
} RECORD;

typedef struct node {
    RECORD data;
    struct node *left;
    struct node *right;
} TNODE;

/* search bst by data.name */
TNODE *search(TNODE *root, char *name); 

/* insert record (name, score) into bst using data.name as key */
void insert(TNODE **rootp, char *name, float score); 

/* delete node of data.name from bst */
void delete(TNODE **rootp, char *name);  

/* get and return and delete the node of the smallest data.name node from the bst */
TNODE *extract_smallest_node(TNODE **rootp); 

/* display bst tree data by in-order */
void display_inorder(TNODE *root); 

/* clean the tree */
void clean_tree(TNODE **rootp); 


#endif /* BST_H_ */
