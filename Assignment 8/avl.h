/*
 -------------------------------------
 File:    avl.h
 Project: raox6250_a08

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-18
 -------------------------------------
 */ 
#ifndef AVL_H
#define AVL_H

typedef struct rec {
  char name[40];
  float score;
} RECORD;

typedef struct node {
    RECORD data;
    int height;
    struct node *left;
    struct node *right;

} TNODE;

/* check if the tree is AVL tree, return 1 if true, 0 otherwise */
int is_avl(TNODE *root);

/* do left rotation  */
TNODE *rotate_left(TNODE *root);  
TNODE *rotate_right(TNODE *root);
TNODE *rotate_left_right(TNODE *root);
TNODE *rotate_right_left(TNODE *root);

/* insert record (name, score) into the AVL using name as key */
void insert(TNODE **rootp, char *name, float score);

/* delete node of data.name from the AVL */ 
void delete(TNODE **rootp, char *name);  // 

// following functions are from a7
TNODE *extract_smallest_node(TNODE **rootp); 
void display_inorder(TNODE *root);
void display_inorder_lines(TNODE *root);
void display_tree(TNODE *root, int prelen);
TNODE *search(TNODE *root, char *name);
void clean_tree(TNODE **rootp); 

#endif