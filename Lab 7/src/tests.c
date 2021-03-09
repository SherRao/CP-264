/*
 -------------------------------------
 File:    tests.c
 -------------------------------------
 Author:  Heider Ali & David Brown
 ID:      999999999
 Email:   dbrown@wlu.ca
 Version: 2021-03-03
 -------------------------------------
 */
#include <assert.h>
#include "tests.h"

#define STRING_SIZE 256

static char string[STRING_SIZE];

void bst_test()
//=============
{
	int   i;
	int   size;
	int   zero, one, two;
	bst  *tree1;
	bst  *tree2;
	bst  *tree3;
	data *value;
	data  values[] = { 5, 12, 9, 22, 11, 6, 31, 8};
	data  keys[] = { 16 };

	value = NULL;

	printf(SEP);
	printf("\nTesting: BST\n");
	printf(SEP);

	printf("Test: bst_initialize\n");
	tree1 = bst_initialize(int_destroy, int_copy, int_to_string, int_compare);
	tree2 = bst_initialize(int_destroy, int_copy, int_to_string, int_compare);
	tree3 = bst_initialize(int_destroy, int_copy, int_to_string, int_compare);

	i = 0;
	size = sizeof(values) / sizeof(*values);         // Determine number of values in values[] array.

	for (i = 0; i < size; i++) {
		bst_insert(tree1, &values[i]);
	}
	printf(":::> Inorder\n");
	bst_inorder(tree1);

	printf(SEP);
	printf("Leaf count     : %d\n", bst_leaf_count(tree1));
	printf("One child count: %d\n", bst_one_child_count(tree1));
	printf("Two child count: %d\n", bst_two_child_count(tree1));

	zero = 0;
	one = 0;
	two = 0;
	bst_node_counts(tree1, &zero, &one, &two);
	printf("Zero: %d, One: %d, Two: %d\n", zero, one, two);

	printf(SEP);
	printf(":::> Valid   : %d\n", bst_valid(tree1));
	printf(":::> Balanced: %d\n", bst_balanced(tree1));

	printf(SEP);
	printf(":::> Retrieve:\n");
	value = bst_retrieve(tree1, &values[4]);

	if (value != NULL) {
		printf("key: %d, value: %d\n", values[4], *value);
		int_destroy(&value);
	} else {
		printf("key: %d, value: not found\n", values[4]);
	}

	value = bst_retrieve(tree1, &keys[0]);

	if (value != NULL) {
		printf("key: %d, value: %d\n", keys[0], *value);
		int_destroy(&value);
	} else {
		printf("key: %d, value: not found\n", keys[0]);
	}
	printf(SEP);
	printf("Remove:\n");
	value = bst_remove(tree1, &values[4]);
	if (value != NULL) {
		printf("key: %d, value: %d\n", values[4], *value);
		int_destroy(&value);
	} else {
		printf("key: %d, value: not found\n", values[4]);
	}

	printf("Inorder\n");
	bst_inorder(tree1);

	printf(SEP);
	printf(":::> Clean Up\n");
	printf("Destroy tree1:\n");
	bst_destroy(&tree1);

	printf("Destroy tree2:\n");
	bst_destroy(&tree2);

	printf("Destroy tree3:\n");
	bst_destroy(&tree3);

	printf("Done\n");
	return;
}
