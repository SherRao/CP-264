/*
 -------------------------------------
 File:    tree.c
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
#include "tree.h"

/* this computes and returns TPROPS value containing the number of nodes and height
 * of tree passed by root.
 */
TPROPS get_props(TNODE *root) {
	TPROPS tree_data = { 0 };
	tree_data.count = get_count(root);   
	tree_data.height = get_height(root); 
	return tree_data;
}

int get_height(TNODE *node) {
	int left;
	int right;
	if(node == NULL)
		return 0;

	left = get_height(node->left);
	right = get_height(node->right);
	return (left > right ? left : right) + 1;
}

int get_count(TNODE *node) {
	int count = 1;
	if (node) {
		if(node->left) count += get_count(node->left);
		if(node->right) count += get_count(node->right);

	} else return 0;
	return count;
}

void display_preorder(TNODE *root) {
	if(root != NULL) {
		printf("%c ", root->data);
		display_preorder(root->left);
		display_preorder(root->right);

	}
}

void display_inorder(TNODE *root) {
	if(root != NULL) {
		display_inorder(root->left);
		printf("%c ", root->data);
		display_inorder(root->right);

	}
}

void display_postorder(TNODE *root) {
	if(root != NULL) {
		display_postorder(root->left);
		display_postorder(root->right);
		printf("%c ", root->data);

	}
}

TNODE* iterative_bf_search(TNODE *root, int val) {
	QUEUE queue = {0};
	TNODE *r = NULL, *tp = NULL;
	if(root == NULL)
		return r;

	enqueue(&queue, root);
	while(queue.front != NULL && r == NULL) {
		tp = dequeue(&queue);
		if (tp->data == val)
			r = tp;

		if(tp->left) enqueue(&queue, tp->left);
		if(tp->right) enqueue(&queue, tp->right);
	
    }

	clean_queue(&queue);
	return r;
}

TNODE* iterative_df_search(TNODE *root, int val) {
	STACK stack = {0};
	TNODE *r = NULL, *tp;
	if(root == NULL)
		return r;

	push(&stack, root);
	while(stack.top && r == NULL) {
		tp = peek(&stack);
		pop(&stack);
		if(tp->data == val) 
			r = tp;
		
		if(tp->left) push(&stack, tp->left);
		if(tp->right) push(&stack, tp->right);
	}

	clean_stack(&stack);
	return r;
}

TNODE* new_node(int value) {
	TNODE *np = (TNODE*) malloc(sizeof(TNODE));
	if (np == NULL) return NULL;
	np->data = value;
	np->left = NULL;
	np->right = NULL;
	
    return np;
}

void display_tree(TNODE *root, int prelen) {
	if(root) {
		int i;
		for(i = 0; i < prelen; i++)
			printf("%c", ' ');
		printf("%s", "|___");
		printf("%c\n", root->data);
		display_tree(root->right, prelen + 4);
		display_tree(root->left, prelen + 4);

	}
}

void clean_tree(TNODE **rootp) {
	TNODE *root = *rootp;
	if(root) {
		if(root->left) clean_tree(&root->left);
		if(root->right) clean_tree(&root->right);
		free(root);
	}
	
    *rootp = NULL;
}

void enqueue(QUEUE *qp, void *data) {
	QNODE *p = (QNODE*) malloc(sizeof(QNODE));
	if(p == NULL)
		return; 

	else {
		p->data = data;
		p->next = NULL;
		if (qp->front == NULL) {
			qp->front = p;
			qp->rear = p;

		} else {
			(qp->rear)->next = p;
			qp->rear = p;

		}
	}
}

void* dequeue(QUEUE *qp) {
	void *temp = NULL;
	if (qp->front) {
		QNODE *p = qp->front;
		temp = p->data;
		if (qp->front == qp->rear) {
			qp->front = NULL;
			qp->rear = NULL;

		} else qp->front = p->next;
		
		free(p);
		return temp;
	}

	return NULL;
}

void clean_queue(QUEUE *qp) {
	QNODE *temp, *p = qp->front;
	while(p != NULL) {
		temp = p;
		p = p->next;
		free(temp);
	}
}

void push(STACK *sp, void *data) {
	SNODE *node = (SNODE*) malloc(sizeof(SNODE));
	node->data = data;
	node->next = NULL;
	if(sp->top == NULL) 
		sp->top = node;

    else {
		node->next = sp->top;
		sp->top = node;
	}
}

void pop(STACK *sp) {
	if(sp->top != NULL) {
		SNODE *p = sp->top;
		sp->top = p->next;
		free(p);

	}
}

void* peek(STACK *sp) {
	if(sp->top != NULL) return sp->top->data;
	return NULL;
}

void clean_stack(STACK *sp) {
	SNODE *node, *p = sp->top;
	while(p) {
		node = p;
		p = p->next;
		free(node);
	}

	sp->top = NULL;
}
