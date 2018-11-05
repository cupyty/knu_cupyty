#include <stdlib.h>

#define LH +1
#define EH 0 
#define Rh -1

typedef struct node{
	int data;
	struct node* left;
	struct node * right;
	int balance;
}T_NODE;

typedef struct{
	int count;
	T_NODE* root;
}AVL_TREE;

AVL_TREE* create_avl();
T_NODE* rotate_left(T_NODE* root);
T_NODE* rotate_right(T_NODE* root);
T_NODE* insert_rotate(T_NODE* root, T_NODE* new_node,bool* taller);
bool AVL_insert(AVL_TREE* tree, int data);
