/*
 -------------------------------------
 File:    tree.h
 Project: raox6250_a07

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-01
 -------------------------------------
 */
#ifndef TREE_H_
#define TREE_H_

typedef struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;

} TNODE;

typedef struct tree_props {
	int count;
	int height;

} TPROPS;

TNODE* new_node(int value);
void display_tree(TNODE *root, int prelen);
void clean_tree(TNODE **rootp);

TPROPS get_props(TNODE *root);
int get_height(TNODE *rnode);
int get_count(TNODE *rnode);
void display_preorder(TNODE *root);
void display_inorder(TNODE *root);
void display_postorder(TNODE *root);
TNODE* iterative_bf_search(TNODE *root, int val);
TNODE* iterative_df_search(TNODE *root, int val);

typedef struct queue_node {
	void *data;
	struct queue_node *next;

} QNODE;

typedef struct queue {
	QNODE *front, *rear;

} QUEUE;

void enqueue(QUEUE *qp, void *data);
void* dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

typedef struct stack_node {
	void *data;
	struct stack_node *next;

} SNODE;

typedef struct stack {
	SNODE *top;

} STACK;

void push(STACK *sp, void *data);
void pop(STACK *sp);
void* peek(STACK *sp);
void clean_stack(STACK *sp);
#endif /* TREE_H_ */
