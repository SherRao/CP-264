/*
-------------------------------------
File:    avl_linked.h
Project: Lab8_CP264
file description
-------------------------------------
Author:  Heider Ali & David Brown
ID:      9999999999
Email:   heali@wlu.ca & dbrown@wlu.ca
Version  2021-03-10
-------------------------------------
 */

#ifndef AVL_LINKED_H_
#define AVL_LINKED_H_

#include <assert.h>

// Structures

typedef struct avl_node {
	int    height;               ///< Height of the current node.
	int    data;                 ///< Data stored in the node.
	struct avl_node *left;       ///< Pointer to the left child.
	struct avl_node *right;      ///< Pointer to the right child.
} avl_node;

typedef struct avl {
	int      count;              ///< Number of nodes in the AVL.
	avl_node *root;              ///< Pointer to the root node of the AVL.
} avl;

// Prototypes

/**
 * Allocates memory and initializes a AVL structure.
 * @return a pointer to the avl structure.
 */
avl *avl_initialize();

/**
 * Deallocates memory for a AVL.
 * @param tree Pointer to a AVL.
 */
void avl_destroy(avl **tree);

/**
 * Determines if a AVL is empty.
 * @param tree Pointer to a AVL.
 * @return 1 if the AVL is empty, 0 otherwise.
 */
int avl_empty(const avl *tree);

/**
 * Determines if a AVL if full.
 * @param tree Pointer to a AVL.
 * @return 1 if the AVL if full, 0 otherwise.
 */
int avl_full(const avl *tree);

/**
 * Returns the number of elements in a AVL.
 * @param tree Pointer to a AVL.
 * @return The number of vales stored in the AVL.
 */
int avl_count(const avl *tree);

/**
 * Inserts data into a AVL.
 * @param tree Pointer to a AVL. Pointer to a AVL.
 * @param value Value to insert into the tree.
 * @return 1 if value is successfully inserted into the tree, 0 otherwise.
 */
int avl_insert(avl *tree, int value);

/**
 * Retrieves a copy of a value matching key in a AVL. (Iterative)
 * @param tree Pointer to a AVL.
 * @param key Key value to search for.
 * @param value The value found, if in AVL.
 * @return 1 if the key is found in the AVL, 0 otherwise.
 */
int avl_retrieve(const avl *tree, int key, int *value);

/**
 * Removes a node with a value matching key from the avl.
 * @param tree Pointer to a AVL.
 * @param key Key value to search for.
 * @param value The value found, if in AVL.
 * @return 1 if the key is found in the AVL, 0 otherwise.
 */
int avl_remove(avl *tree, int key, int *value);

/**
 * Prints the contents of the tree in order.
 * @param tree Pointer to a AVL.
 */
void avl_inorder(const avl *tree);

/**
 * Prints the contents of the tree in preorder.
 * @param tree Pointer to a AVL.
 */
void avl_preorder(const avl *tree);

/**
 * Find the maximum value in the tree.
 * @param tree Pointer to a AVL.
 * @return Maximum value in AVL.
 */
int avl_max(const avl *tree);

/**
 * Finds the number of leaf nodes in a tree.
 * @param tree Pointer to a AVL.
 * @return Number of nodes with no children.
 */
int avl_leaf_count(const avl *tree);

/**
 * Finds the number of nodes with one child in a tree.
 * @param tree Pointer to a AVL.
 * @return Number of nodes with one child.
 */
int avl_one_child_count(const avl *tree);

/**
 * Finds the number of nodes with two children in a tree.
 * @param tree Pointer to a AVL.
 * @return Number of nodes with two children.
 */
int avl_two_child_count(const avl *tree);

/**
 * Determines the number of nodes with zero, one, and two children.
 * @param tree Pointer to a AVL.
 * @param zero Number of leaf nodes (no children).
 * @param one Number of nodes with one child.
 * @param two Number of nodes with two children.
 */
void avl_node_counts(const avl *tree, int *zero, int *one, int *two);

/**
 * Determines whether or not a tree is a balanced tree.
 * All node heights are no more than one greater than any child heights.
 * @param tree Pointer to a AVL.
 * @return
 */
int avl_balanced(const avl *tree);

/**
 * Determines whether or not a tree is a valid AVL.
 * @param tree Pointer to a AVL.
 * @return 1 if the tree is a valid AVL, 0 otherwise.
 */
int avl_valid(const avl *tree);

/**
 * Determines if two trees contain same data in same configuration.
 * @param tree1 Pointer to an AVL.
 * @param tree2 Pointer to an AVL.
 * @return 1 if trees are identical, 0 otherwise.
 */
int avl_identical(const avl *tree1, const avl *tree2);

#endif /* AVL_LINKED_H_ */
