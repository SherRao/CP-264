/*
 -------------------------------------
 File:    bst.c
 Project: raox6250_a07

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bst.h"

TNODE* search(TNODE *root, char *name) {
	TNODE *ptr = root;
	int found = 0;
	while(ptr && found == 0) {
		if(strcmp(ptr->data.name, name) == 0)
			found = 1;
		else if(strcmp(ptr->data.name, name) > 0)
			ptr = ptr->left;

		else ptr = ptr->right;
	}

	return ptr;
}

void insert(TNODE **rootp, char *name, float score) {
	if (*name == '\0')
		return;

	TNODE *new = (TNODE*) malloc(sizeof(TNODE));
	strncpy(new->data.name, name, 39);
	new->data.score = score;
	new->left = NULL;
	new->right = NULL;
	if(*rootp == NULL)
		*rootp = new;

	else {
		TNODE *prev = NULL, *curr = *rootp;
		while(curr) {
			prev = curr;
			if(strcmp(curr->data.name, name) == 0) {
				printf("this person is already in the table");
				return;

			} else if(strcmp(curr->data.name, name) < 0)
				curr = curr->right;

			else curr = curr->left;

		}

		if (strcmp(prev->data.name, name) < 0)
			prev->right = new;

		else prev->left = new;
	}

	return;
}

void delete(TNODE **rootp, char *name) {
	TNODE *curr = *rootp, *prev = NULL, *smallest_node;
	while(curr != NULL && strcmp(curr->data.name, name) != 0) {
		prev = curr;
		curr = (strcmp(curr->data.name, name) < 0 ? curr->right : curr->left);

	}

	if (curr != NULL) {
		if(curr->left == NULL) {
			if(prev == NULL)
				*rootp = curr->right;

			else {
				if (prev->left == curr)
					prev->left = curr->right;
				else
					prev->right = curr->right;
			}

		} else if (curr->right == NULL) {
			if (prev == NULL)
				*rootp = curr->left;

			else {
				if (prev->left == curr)
					prev->left = curr->left;
				else
					prev->right = curr->left;
			}

		} else {
			smallest_node = extract_smallest_node(&curr->right);
			if(prev == NULL)
				*rootp = smallest_node;

			else {
				if (prev->left == curr)
					prev->left = smallest_node;

				else prev->right = smallest_node;
			}

			smallest_node->left = curr->left;
			smallest_node->right = curr->right;

		}

		free(curr);
	}

}

TNODE* extract_smallest_node(TNODE **rootp) {
	TNODE *prev = NULL;
    TNODE *curr = *rootp;
	if(*rootp != NULL) {
		prev = curr;
		while(curr->left != NULL) {
			prev = curr;
			curr = curr->left;

		}

		if(prev == NULL)
			*rootp = curr->right;

		else prev->left = curr->right;
	}

	return curr;
}

void display_inorder(TNODE *root) {
	if(root) {
		if(root->left) display_inorder(root->left);
		printf("%-15s%3.1f\n", root->data.name, root->data.score);
		if(root->right) display_inorder(root->right);

	}
}

void clean_tree(TNODE **rootp) {
	TNODE *root = *rootp;
	if (root) {
		if(root->left) clean_tree(&root->left);
		if(root->right) clean_tree(&root->right);
		free(root);

	}
    
	*rootp = NULL;
}
