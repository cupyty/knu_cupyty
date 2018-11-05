#include <stdlib.h>
#include "ADT_atree.h"

AVL_TREE* create_avl(){
	AVL_TREE* tree;
	tree=(AVL_TREE*)malloc(sizeof(AVL_TREE));
	if(tree)
	{
		tree->root=NULL;
		tree->count=0;
	}

	return tree;
}

T_NODE* rotate_left(T_NODE* root){
	T_NODE* new_root;
	new_root=root->right;
	root->right=new_root->left;
	new_root->left=root;
	return new_root;
}

T_NODE* rotate_right(T_NODE* root){
	T_NODE* new_root;
	new_root=root->left;
	root->left=new_root->right;
	new_root->right=root;
	return new_root;
}

bool AVL_insert(AVL_TREE* tree, int data){
	T_NODE* new_node;
	bool taller;
	new_node=(T_NODE*)malloc(sizeof(T_NODE));
	if(!new_node)return false;
	new_node->balance=EH;
	new_node->right=NULL;
	new_node->left=NULL;
	new_node->data=data;

	tree->root=insert_rotate(tree->root,new_node,&taller);
	(tree->count)++;
	return true;
}

T_NODE* insert_rotate(T_NODE* root, T_NODE* new_node, bool* taller){
	if(root==NULL)
	{
		root=new_node;
		*taller=true;
		return root;
	}
	if((new_node->data)<(root->data)){
		root->left=insert_rotate(root->left,new_node,taller);
		if(*taller){
			switch(root->balance){
				case LH:root=balance_left(root,taller);
						break;
				case EH:root->balance=LH;break;
				case RH:root->balance=EH;
						*taller=false;break;
			}
		}
		return root;
	}
}