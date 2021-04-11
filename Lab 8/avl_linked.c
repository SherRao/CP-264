/*
-------------------------------------
File:    avl_linked.c
Project: Lab8_CP264
file description
-------------------------------------
Author:  Heider Ali & David Brown
ID:      9999999999
Email:   heali@wlu.ca & dbrown@wlu.ca
Version  2021-03-10
-------------------------------------
 */


// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "avl_linked.h"


                                   // Macro for comparing node heights
#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)

// Local Functions

/**
 * USE FOR TESTING ONLY
 * Prints node height and value.
 * @param node The node to process.
 */
/*
static void avl_print_node(const avl_node *node)
//==============================================
{
	printf("h: %d, v: %d\n", node->height, node->data);
	return;
}
*/

/**
 * Helper function to determine the height of node - handles empty node.
 * @param node The node to process.
 * @return The height of the current node.
 */
static int avl_node_height(const avl_node *node)
//==============================================
{
	int height;

	height = 0;
	if (node != NULL) height = node->height;

	return (height);
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node The node to process.
 */
static void avl_update_height(avl_node *node)
//===========================================
{
	int left_height;
	int right_height;

	left_height  = avl_node_height(node->left);
	right_height = avl_node_height(node->right);

	if (left_height >= right_height) {
		node->height = left_height + 1;
	} else {
		node->height = right_height + 1;
	}
	return;
}

/**
 * Destroys a node and its children.
 * @param tree Pointer to a AVL.
 * @param node The node to process.
 */
static void avl_destroy_aux(avl       *tree,
		                    avl_node **node)
//==========================================
{
	if (*node != NULL) {
	   avl_destroy_aux(tree, &(*node)->left );
	   avl_destroy_aux(tree, &(*node)->right);
	   free(*node);
	   *node = NUw
	return;
}

/**
 * Determines whether the AVL is balanced.
 * @param node The node to process.
 * @return 1 if the node and its children are balanced, 0 otherwise.
 */
static int avl_balance(const avl_node *node)
//==========================================
{
	return ( avl_node_height(node->left) - avl_node_height(node->right) );
}

/**
 * Performs a left rotation around node.
 * @param node Pointer to the root of a subtree.
 * @return Pointer to new root of subtree.
 */
static avl_node *avl_rotate_left(avl_node *node)
//==============================================
{
	avl_node *temp;
	temp = NULL;
	                            // Rearrange the nodes.

	// < your code here >

	                            // Return new root.
	return (temp);
}

/**
 * Performs a right rotation around node.
 * @param node Pointer to the root of a subtree.
 * @return Pointer to new root of subtree.
 */
static avl_node *avl_rotate_right(avl_node *node)
//===============================================
{
	avl_node *temp;
	temp = NULL;
	                           // Rearrange the nodes.

	// <your code here >

	                           // Return new root.
	return (temp);
}

/**
 * Rebalances a node according to AVL rules.
 * @param node Pointer to the node to rebalance.
 */
static void avl_rebalance(avl_node **node)
//========================================
{
	int balance;
	                             // Update the node height if any of its children have been changed.
	avl_update_height(*node);
	                             // Get the balance factor of this ancestor node to check whether
	                             // this node became unbalanced
	balance = avl_balance(*node);
	                             // If this node is unbalanced, then there are 4 cases

	if (balance > 1 && avl_balance((*node)->left) >= 0) {
		                         // Left Left Case - single rotation
		*node = avl_rotate_right(*node);

	} else if (balance < -1 && avl_balance((*node)->right) <= 0) {
		                         // Right Right Case - single rotation
		*node = avl_rotate_left(*node);

	} else if (balance > 1 && avl_balance((*node)->left) < 0) {
		                         // Left Right Case - double rotation
		(*node)->left = avl_rotate_left((*node)->left);
		*node         = avl_rotate_right(*node);

	} else if (balance < -1 && avl_balance((*node)->right) > 0) {
		                         // Right Left Case - double rotation
		(*node)->right = avl_rotate_right((*node)->right);
		*node          = avl_rotate_left(*node);
	}
	return;
}

/**
 * Inserts value into a AVL. Insertion must preserve the AVL definition.
 * Only one of value may be in the tree.
 * @param tree Pointer to a AVL.
 * @param node The node to process.
 * @param value The value to insert.
 * @return 1 if the value is inserted, 0 otherwise.
 */
static int avl_insert_aux(avl       *tree,
		                  avl_node **node,
						  int        value)
//=========================================
{
	int inserted;

	inserted = 0;
	if (*node == NULL) {
		                            // Base case: add a new node containing the value.
		                            // NOTE: The (*node)->height is initialized/set/updated
				                    //       by the "avl_rebalance(...)" routine, below.
		*node = malloc(sizeof **node);
		assert(node != NULL);

		(*node)->left  = NULL;
		(*node)->right = NULL;
		(*node)->data  = value;
		tree->count   += 1;
		inserted       = 1;

	} else if ((*node)->data > value) {
		                            // General case: check the left subtree.
		inserted = avl_insert_aux(tree, &(*node)->left, value);

	} else if ((*node)->data < value) {
		                            // General case: check the right subtree.
		inserted = avl_insert_aux(tree, &(*node)->right, value);
	} else {
		                            // Base case: value is already in the AVL.
		inserted = 0;
	}
	if (inserted) {
		                            // Rebalance if any of its children have been changed.
		avl_rebalance(node);
	}
	return (inserted);
}

/**
 * Finds a replacement node for a node to be removed from the tree.
 * (Called only by avl_remove_aux.)
 * @param parent Parent of possible replacement node.
 * @return The node to replace the node that is being removed.
 */
/*
static avl_node *avl_delete_node_left(avl_node **parent)
//======================================================
{
	avl_node *repl;
	repl = NULL;

	// < your code here >

	return (repl);
}
*/

/**
 * Attempts to find a value matching key in a AVL node. Deletes the node
 * if found.
 * @param tree Pointer to a AVL.
 * @param node The node to process.
 * @param key The key to look for.
 * @param value If key is found, the value being removed.
 * @return 1 if the key is found and the value removed, 0 otherwise.
 */
static int avl_remove_aux(avl       *tree,
		                  avl_node **node,
						  int        key,
						  int       *value)
//=========================================
{
int removed;                     // True(1) if node is removed. False(0) otherwise.
avl_node *repl;                  // Pointer to replacement node.
avl_node *temp;                  // Temporary pointer to the given node.

	                                 // Initialize local variables.
	removed = 0;
	repl    = NULL;
	temp    = NULL;
	value   = NULL;

	if (*node == NULL) {
		                             // Base Case: the key is not in the tree.
		removed = 0;

	} else if (key < (*node)->data) {
		                             // Search the left subtree.
		removed = avl_remove_aux(tree, &((*node)->left), key, value);

	} else if (key > (*node)->data) {
		                             // Search the right subtree.
		removed = avl_remove_aux(tree, &((*node)->right), key, value);

	} else {
		                             // Value has been found.
		temp   = *node;
		*value = (*node)->data;
		tree->count--;
		removed = 1;
		// Replace this node with another node.

 	    // <your code here>

		// Replace the removed node.
			*node = repl;

	    free(temp);
		temp = NULL;
	}
	if (removed && *node != NULL) {
		                             // If the value was found, update the ancestor heights.
		avl_rebalance(node);
	}
	return (removed);
}

/**
 * Prints the contents of the AVL in inorder.
 * @param node The node to process.
 */
static void avl_inorder_aux(const avl_node *node)
//===============================================
{

	if (node != NULL) {
		avl_inorder_aux(node->left);
		printf("%d  ",  node->data);
		avl_inorder_aux(node->right);
	}
	return;
}

/**
 * Prints the contents of the tree in preorder.
 * @param node The node to process.
 */
static void avl_preorder_aux(const avl_node *node)
//================================================
{
	if (node != NULL) {
		printf("%d  ",   node->data);
		avl_preorder_aux(node->left);
		avl_preorder_aux(node->right);
	}
	return;
}

/**
 * Returns the number of leaves (nodes with no children) in node.
 * @param node The node to process.
 * @return The number of leaves for node and its children.
 */
static int avl_leaf_count_aux(const avl_node *node)
//=================================================
{
	int count = 0;

	if (node == NULL) {
		                                   // Base case: no node.
		count = 0;
	} else if (node->left == NULL && node->right == NULL) {
		                                   // Base case: node has no children.
		count = 1;
	} else {
		count = avl_leaf_count_aux(node->left) +
				avl_leaf_count_aux(node->right);
	}
	return (count);
}

/**
 * Returns the number of one child nodes in a AVL node.
 * @param node The node to process.
 * @return The number of one child nodes for node and its children.
 */
static int avl_one_child_count_aux(const avl_node *node)
//======================================================
{
	int count = 0;

	if (node == NULL) {
		                          // Base case: empty node..
		count = 0;
	} else if (node->left == NULL && node->right != NULL) {
		                          // General case: node has one child.
		count = 1 + avl_one_child_count_aux(node->right);

	} else if (node->left != NULL && node->right == NULL) {
		                          // General case: node has one child.
		count = 1 + avl_one_child_count_aux(node->left);
	} else {
		                          // General case: node has two children.
		count = avl_one_child_count_aux(node->left) +
				avl_one_child_count_aux(node->right);
	}
	return (count);
}

/**
 * Returns the number of types of nodes in a AVL node.
 * @param node The node to process.
 * @return The number of two children nodes for node and its children.
 */
static int avl_two_child_count_aux(const avl_node *node)
//======================================================
{
	int count = 0;

	if (node == NULL) {
		                          // Base case: no node.
		count = 0;
	} else if (node->left != NULL && node->right != NULL) {
		                         // General case: node has two children.
		count = 1 + avl_two_child_count_aux(node->left)
				  + avl_two_child_count_aux(node->right);
	} else {
		                         // General case: node has one child.
		count = avl_two_child_count_aux(node->left) +
				avl_two_child_count_aux(node->right);
	}
	return (count);
}

/**
 * Determines the number of zero, one, and two children nodes in a tree.
 * @param node The node to process.
 * @param zero The number of zero children nodes for node and its children.
 * @param one The number of one child nodes for node and its children.
 * @param two The number of two children nodes for node and its children.
 */
static void avl_node_counts_aux(const avl_node *node,
		                              int      *zero,
									  int      *one,
		                              int      *two )
//===================================================
{
	if (node != NULL) {

		if (node->left == NULL && node->right == NULL) {
 			                                  // Base case: leaf node
			(*zero)++;

		} else if (node->left == NULL && node->right != NULL) {
			                                  // One child - right
			(*one)++;
			avl_node_counts_aux(node->right, zero, one, two);

		} else if (node->left != NULL && node->right == NULL) {
			                                  // One child - left
			(*one)++;
			avl_node_counts_aux(node->left, zero, one, two);

		} else {
			                                  // two children
			(*two)++;
			avl_node_counts_aux(node->left, zero, one, two);
			avl_node_counts_aux(node->right, zero, one, two);
		}
	}
	return;
}

/**
 * Determines whether the AVL is balanced.
 * @param node The node to process.
 * @return 1 if the node and its children are balanced, 0 otherwise.
 */
static int avl_balanced_aux(const avl_node *node)
//===============================================
{
	int is_balanced = 0;

	if (node == NULL || node->height == 1) {
		                                    // Base case: no node or a leaf, so no children.
		is_balanced = 1;
	} else if (abs(avl_node_height(node->left) -
			       avl_node_height(node->right) ) > 1) {
		                                    // Base case: left or right subtree is too deep.
		is_balanced = 0;
	} else {
		                                    // General case: check the children of node.
		is_balanced = avl_balanced_aux(node->left) && avl_balanced_aux(node->right);
	}
	return (is_balanced);
}

/**
 * Determines if a tree is a valid AVL.
 * @param node The node to process.
 * @return 1 if the node and its children are valid, 0 otherwise.
 */

static int avl_valid_aux(const avl      *tree,
                         const avl_node *node,
                         const avl_node *min_node,
                         const avl_node *max_node)
//================================================
{
	int is_valid = 0;
    if(node != NULL) {
        int left = avl_node_height(node->left);
        int right = avl_node_height(node->right);
        if(node->left->data < node->data && node->right->data > node->data && fabs(left-right) <= 1 && avl_valid_aux(tree, node->left, min_node, max_node) && avl_valid_aux(tree, node->right, min_node, max_node))
            is_valid = 1;

        else is_valid = 0;

    } else
        is_valid = 1;

	return is_valid;
}

/**
 * Determines if two trees are identical.
 * @param node1 Pointer to an AVL node.
 * @param node2 Pointer to an AVL node.
 * @return 1 if trees are identical, 0 otherwise.
 */
static int avl_identical_aux(const avl_node *node1,
		                     const avl_node *node2)
//=================================================
{
	int is_identical = 0;

	if (node1 == NULL && node2 == NULL) {
		                                   // Base case: Trees are identical so far.
		is_identical = 1;
	}else if ( (node1 == NULL && node2 != NULL) ||
			   (node1 != NULL && node2 == NULL) ||
			   (node1->data != node2->data)       ) {
		                                   // Base case: tree elements are not equal.
		is_identical = 0;
	}else {
		                                   // General case: search rest of trees.
		is_identical = avl_identical_aux(node1->left, node2->left) &&
				       avl_identical_aux(node1->right, node2->right);
	}
	return (is_identical);
}

//--------------------------------------------------------------------
// Functions

avl *avl_initialize()
//===================
{
	avl *tree    = malloc(sizeof *tree);
	assert(tree != NULL);

	tree->root  = NULL;
	tree->count = 0;
	return (tree);
}

void avl_destroy(avl **tree)
//==========================
{
	avl_destroy_aux(*tree, &(*tree)->root);
	free(*tree);
	*tree = NULL;
	return;
}

int avl_empty(const avl *tree)
//============================
{
	return (tree->root == NULL);
}

int avl_full(const avl *tree)
//===========================
{
	return 0;
}

int avl_count(const avl *tree)
//============================
{
	return tree->count;
}

void avl_inorder(const avl *tree)
//===============================
{
	assert(tree != NULL);

	avl_inorder_aux(tree->root);
	printf("\n");
	return;
}

void avl_preorder(const avl *tree)
//================================
{
	assert(tree != NULL);

	avl_preorder_aux(tree->root);
	printf("\n");
	return;
}

int avl_insert(avl *tree, int value)
//==================================
{
	assert(tree != NULL);

	return (avl_insert_aux(tree, &(tree->root), value));
}

int avl_retrieve(const avl *tree,
		               int  key,
					   int *value)
//================================
{
	int found;
	avl_node *node;

	found = 0;
	node  = tree->root;

	while (node != NULL && !found) {

		if (node->data > key) {
			node = node->left;
		} else if (node->data < key) {
			node = node->right;
		} else {
			*value = node->data;
			found = 1;
		}
	}
	return (found);
}

int avl_remove(avl *tree,
		       int  key,
			   int *value)
//========================
{
	return (avl_remove_aux(tree, &(tree->root), key, value));
}

int avl_max(const avl *tree)
//==========================
{
	avl_node *node;
	assert(tree->root != NULL);
		                         // Find the node containing the largest data.
		                         // (It is the right-most node.)
	node = tree->root;

	while (node->right != NULL) {
		node = node->right;
	}
	return (node->data);
}

void avl_node_counts(const avl *tree,
		                   int *zero,
						   int *one,
						   int *two )
//===================================
{
	*zero = *one = *two = 0;
	avl_node_counts_aux(tree->root, zero, one, two);
	return;
}

int avl_leaf_count(const avl *tree)
//=================================
{
	return (avl_leaf_count_aux(tree->root));
}

int avl_one_child_count(const avl *tree)
//======================================
{
	return (avl_one_child_count_aux(tree->root));
}

int avl_two_child_count(const avl *tree)
//======================================
{
	return (avl_two_child_count_aux(tree->root));
}

int avl_balanced(const avl *tree)
//===============================
{
	return (avl_balanced_aux(tree->root));
}

int avl_valid(const avl *tree)
//============================
{
	return avl_valid_aux(tree, tree->root, NULL, NULL);
}

int avl_identical(const avl *tree1,
		          const avl *tree2)
//=================================
{
	return (avl_identical_aux(tree1->root, tree2->root));
}
