/*
 -------------------------------------
 File:    tree_main.c
 Project: raox6250_a07

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#include <stdio.h>
#include "tree.h"

void search_info(char *sf, char key, TNODE *tnp) {
	if (tnp)
		printf("\n%s(%c):%c", sf, key, tnp->data);
	else
		printf("\n%s(%c):NULL", sf, key);
}

int main() {
	// create nodes
	TNODE *a = new_node('A');
	TNODE *b = new_node('B');
	TNODE *c = new_node('C');
	TNODE *d = new_node('D');
	TNODE *e = new_node('E');
	TNODE *f = new_node('F');
	TNODE *g = new_node('G');

	// do linking
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	// set root
	TNODE *root = a;

	printf("display_tree():\n");
	display_tree(root, 0);
	printf("%s:%d\n", "get_props().count", get_props(root).count);
	printf("%s:%d\n", "get_props().height", get_props(root).height);

	printf("%s:", "display_preorder()");
	display_preorder(root);

	printf("\n%s:", "display_postorde()");
	display_postorder(root);

	printf("\n%s:", "display_inorder()");
	display_inorder(root);

	// testing iterative_bf_search function
	char key = 'F';
	TNODE *tnp = iterative_bf_search(root, key);
	search_info("iterative_bf_search", key, tnp);

	key = 'H';
	tnp = iterative_bf_search(root, key);
	search_info("iterative_bf_search", key, tnp);

	// testing iterative_bf_search function
	key = 'F';
	tnp = iterative_df_search(root, key);
	search_info("iterative_df_search", key, tnp);

	key = 'H';
	tnp = iterative_df_search(root, key);
	search_info("iterative_df_search", key, tnp);

	clean_tree(&root);
	printf("\n%s:%d\n", "clean get_props().count", get_props(root).count);

	return 0;
}
