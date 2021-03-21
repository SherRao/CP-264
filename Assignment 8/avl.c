/*
 -------------------------------------
 File:    avl.c
 Project: raox6250_a08

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-18
 -------------------------------------
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl.h"

// A utility functions
int max(int a, int b) {
    return (a > b)? a : b;

}

int height(TNODE *np) {
    if(np) 
        return np->height;

    else return 0;

}

int balance_factor(TNODE* np) {
    if(np)
        return height(np->left) - height(np->right);

    else return 0;

}

int is_avl(TNODE *root) {
	if(root == NULL)
		return 1;
	
    else {
		int left = height(root->left);
        int right = height(root->right);
		if(abs(left - right) < 2 && is_avl(root->left) && is_avl(root->right))
			return 1;

		else return 0;
    }
}

TNODE *rotate_right(TNODE *top) {
    TNODE *left = top->left;
    TNODE *leftright = top->left->right;

    left->right = top;
    top->left = leftright;
    top->height = max(height(top->left), height(top->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;
    
    return left;
}   

TNODE *rotate_left(TNODE *top) {
    TNODE *right = top->right;
    TNODE *rightleft = right->left;

    right->left = top;
    top->right = rightleft;
    top->height = max(height(top->left), height(top->right)) + 1;
    right->height = max(height(right->left), height(right->right)) + 1;
    
    return right;
}

TNODE *rotate_right_left(TNODE *node) {
    node->right = rotate_right(node->right);
    return rotate_left(node);

}

TNODE *rotate_left_right(TNODE *node) {
    node->left = rotate_left(node->left);
    return rotate_right(node);

}

void insert(TNODE **rootp, char *name, float score) {
    TNODE *np = (TNODE *) malloc(sizeof(TNODE));
    if(np == NULL)
        return;
    
    strcpy(np->data.name, name);
    np->data.score = score;
    np->height = 1;
    np->left = NULL;
    np->right = NULL;
  
    if(*rootp == NULL) {
        *rootp = np;
        return;

    }
  
    TNODE *root = *rootp;
    if(strcmp(name, root->data.name) < 0)
        insert(&root->left, name, score);
    
    else if (strcmp(name, root->data.name) > 0)
        insert(&root->right, name, score);
    
    else
        return;

    root->height = 1 + max(height(root->left), height(root->right));
    int factor = balance_factor(root);
    if(factor >= -1 && factor <= 1)
        return;

    else if(factor >= 2 && balance_factor(root->left) >= 0)
        *rootp = rotate_right(root);

    else if(factor >= 2 && balance_factor(root->left) < 0)
        *rootp = rotate_left_right(root);

    else if(factor <= -2 && balance_factor(root->left) <= 0)
        *rootp = rotate_left(root);

    else
        *rootp = rotate_right_left(root);
  
}

void delete(TNODE **rootp, char *name) {
    TNODE *root = *rootp;
    TNODE* np;
    if(root == NULL)
        return;

    if(strcmp(name, root->data.name) == 0) {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            *rootp = NULL;

        } else if (root->left != NULL && root->right == NULL) {
            np = root->left;
            free(root);
            *rootp = np;
    
        } else if (root->left == NULL && root->right != NULL) {
            np = root->right;
            free(root);
            *rootp = np;
        
        } else if (root->left != NULL && root->right != NULL) {
            np = extract_smallest_node(&root->right);
            np->left = root->left;
            np->right = root->right;
            free(root);
            *rootp = np;
        
        }
  
    } else {
        if(strcmp(name, root->data.name) < 0) 
            delete(&root->left, name);
    
        else 
            delete(&root->right, name);
    
    }

    if (*rootp == NULL)
        return;

    root = *rootp;
    root->height = 1 + max(height(root->left), height(root->right));
    int factor = balance_factor(root);
    if(factor >= -1 && factor <= 1)
        return;

    else if(factor >= 2 && balance_factor(root->left) >= 0)
        *rootp = rotate_right(root);

    else if(factor >= 2 && balance_factor(root->left) < 0)
        *rootp = rotate_left_right(root);

    else if(factor <= -2 && balance_factor(root->left) <= 0)
        *rootp = rotate_left(root);

    else
        *rootp = rotate_right_left(root);
}


// following functions are from bst.c of a7
TNODE *extract_smallest_node(TNODE **rootp) {
  TNODE *tnp = *rootp;
  TNODE *parent = NULL;
  if (tnp == NULL) {
    return NULL;
  } else {
    while (tnp->left) {
      parent = tnp;
      tnp = tnp->left;
    }
    if (parent == NULL)
      *rootp = tnp->right;
    else
      parent->left = tnp->right;
    tnp->left = NULL;
    tnp->right = NULL;
    return tnp;
  }
}

TNODE *search(TNODE *root, char *name) {
  TNODE *tp = root;
  while (tp) {
    if (strcmp(name, tp->data.name) == 0) {
       return tp;
    } else if (strcmp(name, tp->data.name) < 0) 
      tp = tp->left;
     else 
      tp = tp->right;
  }    
  return NULL;
}

void clean_tree(TNODE **rootp) {
  if (*rootp) {
    TNODE *np = *rootp;
    if (np->left)
      clean_tree(&np->left);
    if (np->right)
      clean_tree(&np->right);
    free(np);
  }
  *rootp = NULL;
}

void display_inorder(TNODE *root) {
  if (root) {
    if (root->left) display_inorder(root->left);
    printf("(%s %3.1f) ", root->data.name, root->data.score);
    if (root->right) display_inorder(root->right);
  }
}

void display_inorder_lines(TNODE *root) {
  if (root) {
    if (root->left) display_inorder_lines(root->left);
    printf("%-15s%.1f\n", root->data.name, root->data.score);
    if (root->right) display_inorder_lines(root->right);
  }
}

void display_tree(TNODE *root, int prelen) {
  if (root) {
    int i;
    for (i = 0; i < prelen; i++)
      printf("%c", ' ');
    printf("%s", "|___");
    printf("%s %.1f %d\n", root->data.name, root->data.score, root->height);
    display_tree(root->right, prelen + 4);    
    display_tree(root->left, prelen + 4);
  }
}