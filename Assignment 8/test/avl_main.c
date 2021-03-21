/*
--------------------------------------------------
Project: CP264-a8q1
File:    avl_main.c
Description: test driver program
Author:  HBF  
Version: 2020-09-16 (update)
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char* args[])
{
  int n = 6;   // 1 < = n <= 26

  printf("AVL insertion\n", n);
  TNODE *root = NULL, *np;
  int i;
  char key[20];
  float value = 0;
  for (i = 0; i < n; i++) {
    key[0] = 'A' + i; 
	key[1] = 0; 
	value = i+1.0;
	printf("insert(&root, %s, %.1f):\n", key, value);
    insert(&root, key, value);  // use number i as score data
	display_tree(root, 0);
	printf("is_val(&root):%d\n\n", is_avl(root));
  }
  
  printf("AVL deletion\n", n);
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      key[0] = 'A' + i; 
	  key[1] = 0; 
	  printf("delete(&root, %s):\n", key);
      delete(&root, key);
	  display_tree(root, 0);
	  printf("is_val(&root):%d\n\n", is_avl(root));
    }
  }
  
  clean_tree(&root);
  return 0;
}

