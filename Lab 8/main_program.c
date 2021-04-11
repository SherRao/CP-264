/*
-------------------------------------
File:    main_program.c
Project: Lab8_CP264
file description
-------------------------------------
Author:  Heider Ali & David Brown
ID:      9999999999
Email:   heali@wlu.ca & dbrown@wlu.ca
Version  2021-03-10
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#include "avl_linked.h"

#define SEP "-------------------------------\n"
#define SIZE 10

/**
 * Subrogram to test AVL tree.
 */
static void test_avl_linked();

/**
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);
	test_avl_linked();
}

static void test_avl_linked()
//===========================
{
	int found = 0;
		int n     = SIZE;
		int value;
		avl *tree;

		printf("::::: Test avl_linked :::::\n");
		printf("===========================\n\n");
		printf(SEP);
		printf(":::> Inserting\n\n");

		tree = avl_initialize();

		for (int i = 1; i <= n; i++) {
			printf("Insert: [%d]\n", i*4-1);

			avl_insert(tree, i*4-1);

			printf("Valid : [%d]\n", avl_valid(tree));

			avl_preorder(tree);
		}

		printf("\n");
		printf(SEP);
		printf("Max:\n\n");
		printf("%d\n", avl_max(tree));

		printf(SEP);
		printf(":::> Retrieving:\n\n");

		for (int i = 1; i <= n; i++) {
			found = avl_retrieve(tree, i*4-1, &value);
			printf("Retrieve: %3d - %d, %3d\n", i, found, value);
		}
		found = avl_retrieve(tree, 99, &value);
		printf("Retrieve: %3d - %d, %3d\n", 99, found, value);

		printf(SEP);
		printf("Done\n");

}