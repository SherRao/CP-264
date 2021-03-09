/*
 -------------------------------------------------------
 bst.c
 Linked version of the BST ADT.
 -------------------------------------------------------
 Author:  Heider Ali & David Brown
 ID:      999999999 & 999999999
 Email:   heali@wlu.ca & dbrown@wlu.ca
 Version: 2021-03-03
 -------------------------------------------------------
 */
#include "rm_library.h"
#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Macro for comparing node heights
#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)

/**
 * Local Variables
 */
static char string[DATA_STRING_SIZE];

/**
 * Local Functions
 */

/**
 * Initializes a new BST node with a copy of value.
 * @param tree pointer to a BST tree
 * @param value pointer to the value to assign to the node
 * @return a pointer to a new BST node
 */
static bst_node *bst_node_initialize(bst *tree, const data *value) {
	bst_node *node = malloc(sizeof *node);
	assert(node != NULL);
    node->value = tree->copy(value);
	node->height = 1;
	node->left = NULL;
	node->right = NULL;

	return node;

}

/**
 * Helper function to determine the height of node - handles empty node.
 * @param node The node to process.
 * @return The height of the current node.
 */
static int bst_node_height(const bst_node *node) {
	int height = 0;
	if(node != NULL)
		height = node->height;

	return height;

}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node The node to process.
 */
static void bst_update_height(bst_node *node) {
	int left_height = bst_node_height(node->left);
	int right_height = bst_node_height(node->right);
	node->height = MAX_HEIGHT(left_height, right_height) + 1;

	return;
}

/**
 * Destroys a node and its children.
 * @param tree Pointer to a BST.
 * @param node Pointer to the node to destroy.
 */
static void bst_destroy_aux(bst *tree, bst_node **node) {
	if(*node != NULL) {
        bst_destroy_aux(tree, &(*node)->left);
        bst_destroy_aux(tree, &(*node)->right);
        tree->destroy(&(*node)->value);
        
        (*node)->value = NULL;
        free(*node);
        *node = NULL;
	}
	
    return;
}

/**
 * Inserts value into a BST. Insertion must preserve the BST definition.
 * Only one of value may be in the tree.
 * @param tree Pointer to a BST.
 * @param node Pointer to the node to process.
 * @param value The value to insert.
 * @return 1 if the value is inserted, 0 otherwise.
 */
static int bst_insert_aux(bst *tree, bst_node **node, const data *value) {
	int inserted = FALSE;
	int comp;
    if(*node == NULL) { // Base case: Add a new node containing the value.
       *node = bst_node_initialize(tree, value);
       tree->count += 1;
       inserted = TRUE;
    
    } else { // Compare the node data against the new value.
        comp = tree->compare((*node)->value, value);
        if(comp < 0) 
    	    inserted = bst_insert_aux(tree, &(*node)->left, value); // General case: Check the left subtree.

        else if(comp > 0) 
            inserted = bst_insert_aux(tree, &(*node)->right, value); // General case: Check the right subtree.

        else                      
    	   inserted = FALSE; // Base case: Value is already in the BST.

    }

    // Update the node height if any of its children have been changed.
    if(inserted)
        bst_update_height( *node );

	return inserted;
}

/**
 * Finds a replacement node for a node to be removed from the tree.
 * (Called only by bst_remove_aux.)
 * @param parent Parent of possible replacment node.
 * @return The node to replace the node that is being removed.
 */
static bst_node *bst_delete_node(bst_node *parent) {
	bst_node *repl_node = NULL;
	//code here

	return repl_node;
}

/**
 * Attempts to find a value matching key in a BST node. Deletes the node
 * if found.
 * @param tree Pointer to a BST.
 * @param node The node to process.
 * @param key The key to look for.
 * @return data if the key is found and the value removed, NULL otherwise.
 */
static data *bst_remove_aux(bst *tree, bst_node **node, const data *key) {
	data *value = NULL;
	//code here

	return value;
}

/**
 * Prints the contents of the BST in inorder.
 * @param tree Pointer to a BST.
 * @param node The node to process.
 */
static void bst_inorder_aux(const bst *tree, const bst_node *node) {
    if(node != NULL) {
        bst_inorder_aux(tree, node->left);
        printf("%s\n", tree->to_string(string, DATA_STRING_SIZE, node->value));
		bst_inorder_aux(tree, node->right);
    }
	
    return;
}

/**
 * Prints the contents of the tree in preorder.
 * @param tree Pointer to a BST.
 * @param node The node to process.
 */
static void bst_preorder_aux(const bst *tree, const bst_node *node) {
	if(node != NULL) {
		printf("%s\n", tree->to_string(string, DATA_STRING_SIZE, node->value));
		bst_preorder_aux(tree, node->left);
		bst_preorder_aux(tree, node->right);

	}

	return;
}

static void bst_postorder_aux(const bst *tree, const bst_node *node) {
	if(node != NULL) {
		bst_postorder_aux(tree, node->left);
		bst_postorder_aux(tree, node->right);
		printf("%s\n", tree->to_string(string, DATA_STRING_SIZE, node->value));
	
    }
	
    return;
}

/**
 * Returns the number of leaves (nodes with no children) in node.
 * @param node The node to process.
 * @return The number of leaves for node and its children.
 */
static int bst_leaf_count_aux(const bst_node *node) {
	int count = 0;
	//code here

	return count;
}

/**
 * Returns the number of one child nodes in a BST node.
 * @param node The node to process.
 * @return The number of one child nodes for node and its children.
 */
static int bst_one_child_count_aux(const bst_node *node) {
	int count = 0;
	//code here

	return count;
}

/**
 * Returns the number of types of nodes in a BST node.
 * @param node The node to process.
 * @return The number of two children nodes for node and its children.
 */
static int bst_two_child_count_aux(bst_node *node) {
	int count = 0;
	//code here

	return count;
}

/**
 * Determines the number of zero, one, and two children nodes in a tree.
 * @param node The node to process.
 * @param zero The number of zero children nodes for node and its children.
 * @param one The number of one child nodes for node and its children.
 * @param two The number of two children nodes for node and its children.
 */
static void bst_node_counts_aux(bst_node *node, int *zero, int *one, int *two) {
	//code here

	return;
}

/**
 * Determines whether the BST is balanced.
 * @param node The node to process.
 * @return 1 if the node and its children are balanced, 0 otherwise.
 */
static int bst_balanced_aux(const bst_node *node) {
	int balanced = 0;
	//code here

	return balanced;
}

/**
 * Determines if a tree is a valid BST.
 * @param tree Pointer to a BST.
 * @param node The node to process.
 * @return 1 if the node and its children are valid, 0 otherwise.
 */
static int bst_valid_aux(const bst *tree, const bst_node *node) {
	int valid = 0;
	//code here

	return valid;
}

/**
 * Functions
 */

bst *bst_initialize(data_destroy destroy, data_copy copy, data_to_string to_string, data_compare compare) {
	bst *tree = malloc(sizeof(*tree));
	assert(tree != NULL);
    tree->count = 0;
    tree->root = NULL;

    tree->copy = copy;
    tree->compare = compare;
    tree->to_string = to_string;
    tree->destroy = destroy;

	return tree;
}

void bst_destroy(bst **tree) { 
    if(*tree != NULL) {
        bst_destroy_aux(*tree, &(*tree)->root);
        free(*tree);
        *tree = NULL;
    }

	return;
}

int bst_empty(const bst *tree) {
	return tree->root == NULL;

}

int bst_full(const bst *tree) {
	return FALSE; // Tree will NEVER be full

}

int bst_count(const bst *tree) {
	return tree->count;

}

void bst_inorder(const bst *tree) {
    bst_inorder_aux(tree, tree->root);
    printf(NL);
    return;

}

void bst_preorder(const bst *tree) {
	bst_preorder_aux(tree, tree->root);
	printf(NL);
	return;

}

void bst_postorder(const bst *tree) {
	bst_postorder_aux(tree, tree->root);
	printf(NL);
	return;

}

int bst_insert(bst *tree, const data *value) {
	return bst_insert_aux(tree, &(tree->root), value);

}

data *bst_retrieve(const bst *tree, const data *key) {
	bst_node *node = tree->root;
	data *value = NULL;
	int comparison = 0;
    while(node && !value) {
        comparison = tree->compare(node->value, key);
        if(comparison == 0) 
            value = tree->copy(node->value);

        else if(comparison == 1)
            node = node->right;

        else 
            node = node->left;
    }

	return value;
}

data *bst_remove(bst *tree, const data *key) {
	return bst_remove_aux(tree, &(tree->root), key);

}

data *bst_max(const bst *tree) {
	assert(tree->root != NULL);
	bst_node *node = tree->root;
	//code here

	return tree->copy(node->value);
}

data *bst_min(const bst *tree) {
	(tree->root != NULL);
	bst_node *node = tree->root;
    //code here

	return tree->copy(node->value);
}

void bst_node_counts(const bst *tree, int *zero, int *one, int *two) {
	bst_node_counts_aux(tree->root, zero, one, two);
	return;

}

int bst_leaf_count(const bst *tree) {
	return bst_leaf_count_aux(tree->root);

}

int bst_one_child_count(const bst *tree) {
	return bst_one_child_count_aux(tree->root);

}

int bst_two_child_count(const bst *tree) {
	return bst_two_child_count_aux(tree->root);

}

int bst_balanced(const bst *tree) {
	return bst_balanced_aux(tree->root);

}

int bst_valid(const bst *tree) {
	return bst_valid_aux(tree, tree->root);

}

