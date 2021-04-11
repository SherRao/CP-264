/*
 -------------------------------------------------------
 bst.h
 Linked version of the BST ADT.
 -------------------------------------------------------
 Author:  Heider Ali & David Brown
 ID:      999999999 & 999999999
 Email:   heali@wlu.ca & dbrown@wlu.ca
 Version: 2021-03-03
 -------------------------------------------------------
 */

#ifndef BST_H_
#define BST_H_
                                            // define and declare the data type
#include "data.h"
                                            // Structures
typedef struct bst_node {
	data            *value;                 ///< Data stored in the node.
	int              height;                ///< Height of the current node.
	struct bst_node *left;                  ///< Pointer to the left child.
	struct bst_node *right;                 ///< Pointer to the right child.
} bst_node;

typedef struct {
	int            count;                   ///< Number of nodes in the BST.
	bst_node       *root;                   ///< Pointer to the root node of the BST.
	data_destroy   destroy;                 ///< Pointer to data destroy function.
	data_copy      copy;                    ///< Pointer to data copy function.
	data_to_string to_string;               ///< Pointer to data to string function.
	data_compare   compare;                 ///< Pointer to data comparison function.
} bst;

                                            // Prototypes
/**
 * Allocates memory and initializes a BST structure.
 * @param destroy The destroy function for the bst data.
 * @param copy The copy function for the bst data.
 * @param to_string The to string function for the bst data.
 * @param data_compare The comparison function for the bst data.
 * @return A pointer to a new bst.
 */
bst *bst_initialize(data_destroy   destroy,
		            data_copy      copy,
	             	data_to_string to_string,
					data_compare   compare);
/**
 * Deallocates memory for a BST.
 * @param tree A BST handle.
 */
void bst_destroy(bst **tree);

/**
 * Determines if a BST is empty.
 * @param tree Pointer to a BST.
 * @return 1 if the BST is empty, 0 otherwise.
 */
int bst_empty(const bst *tree);

/**
 * Determines if a BST if full.
 * @param tree Pointer to a BST.
 * @return 1 if the BST if full, 0 otherwise.
 */
int bst_full(const bst *tree);

/**
 * Returns the number of elements in a BST.
 * @param tree Pointer to a BST.
 * @return The number of vales stored in the BST.
 */
int bst_count(const bst *tree);

/**
 * Inserts data into a BST.
 * @param tree Pointer to a BST. Pointer to a BST.
 * @param value Value to insert into the tree.
 * @return 1 if value is successfully inserted into the tree, 0 otherwise.
 */
int bst_insert(      bst  *tree,
		       const data *value);
/**
 * Retrieves a copy of a value matching key in a BST. (Iterative)
 * @param tree Pointer to a BST.
 * @param key Key value to search for.
 * @return copy of data if the key is found in the BST, NULL otherwise.
 */
data *bst_retrieve(const bst *tree,
		           const data *key);
/**
 * Removes a node with a value matching key from the bst.
 * @param tree Pointer to a BST.
 * @param key Key value to search for.
 * @return pointer to dat if the key is found in the BST, NULL otherwise.
 */
data *bst_remove(      bst  *tree,
		         const data *key);
/**
 * Prints the contents of the tree in order.
 * @param tree Pointer to a BST.
 */
void bst_inorder(const bst *tree);

/**
 * Prints the contents of the tree in preorder.
 * @param tree Pointer to a BST.
 */
void bst_preorder(const bst *tree);

/**
 * Prints the contents of the tree in postorder.
 * @param tree Pointer to a BST.
 */
void bst_postorder(const bst *tree);

/**
 * Returns a copy of the maximum value in the tree.
 * @param tree Pointer to a BST.
 * @return Copy of maximum value in BST.
 */
data *bst_max(const bst *tree);

/**
 * Returns a copy of the minimum value in the tree.
 * @param tree Pointer to a BST.
 * @return Copy of minimum value in BST.
 */
data *bst_min(const bst *tree);

/**
 * Finds the number of leaf nodes in a tree.
 * @param tree Pointer to a BST.
 * @return Number of nodes with no children.
 */
int bst_leaf_count(const bst *tree);

/**
 * Finds the number of nodes with one child in a tree.
 * @param tree Pointer to a BST.
 * @return Number of nodes with one child.
 */
int bst_one_child_count(const bst *tree);

/**
 * Finds the number of nodes with two children in a tree.
 * @param tree Pointer to a BST.
 * @return Number of nodes with two children.
 */
int bst_two_child_count(const bst *tree);

/**
 * Determines the number of nodes with zero, one, and two children.
 * @param tree Pointer to a BST.
 * @param zero Number of leaf nodes (no children).
 * @param one Number of nodes with one child.
 * @param two Number of nodes with two children.
 */
void bst_node_counts(const bst *tree,
		                   int *zero,
						   int *one,
						   int *two);
/**
 * Determines whether or not a tree is a balanced tree.
 * All node heights are no more than one greater than any child heights.
 * @param tree Pointer to a BST.
 * @return
 */
int bst_balanced(const bst *tree);

/**
 * Determines whether or not a tree is a valid BST.
 * @param tree Pointer to a BST.
 * @return 1 if the tree is a valid BST, 0 otherwise.
 */
int bst_valid(const bst *tree);

#endif /* BST_H_ */
