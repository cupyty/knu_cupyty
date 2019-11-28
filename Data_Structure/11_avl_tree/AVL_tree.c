#include <stdlib.h>
#include <stdio.h>
#include "AVL_tree.h"

AVL_TREE* create_avl(){
	AVL_TREE* tree;
	tree =(AVL_TREE*)malloc(sizeof(AVL_TREE));
		tree->root=NULL;
		tree->count=0;

	return tree;
}

T_NODE* search_avl(T_NODE* root, int data){
	if(root==NULL)return NULL;

	if(data<(root->data))
		return search_avl(root->left,data);
	else if(data>(root->data))
		return search_avl(root->right,data);
	else
		return root;
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
				case EH:root->balance=LH;
					break;
				case RH: root->balance=EH;
						*taller=false;
						break;
			}
		}
		return root;
	}
	else{
		root->right=insert_rotate(root->right,new_node,taller);
		if(*taller){
			switch(root->balance){
				case LH:root->balance=EH;
					*taller =false;
					break;
				case EH:root->balance=RH;
					break;
				case RH:root=balance_right(root,taller);
					break;
			}
		}
		return root;
	}
	return root;
}

T_NODE* balance_left(T_NODE* root, bool* taller){
	T_NODE* right_tree;
	T_NODE* left_tree;

	left_tree=root->left;
	switch(left_tree->balance){
		case LH:
			root->balance=EH;
			left_tree->balance=EH;
			root=rotate_right(root);
			*taller=false;
			break;
		case EH:exit(0);
		case RH:
			right_tree=left_tree->right;
			switch(right_tree->balance){
				case LH:
					root->balance=RH;
					left_tree->balance=EH;
					break;
				case EH:
					root->balance=EH;
					left_tree->balance=EH;
					break;
				case RH:
					root->balance=EH;
					left_tree->balance=LH;
					break;

			}
			right_tree->balance=EH;
			root->left=rotate_left(left_tree);
			root=rotate_right(root);
			*taller=false;
	}
	return root;
}

T_NODE* balance_right(T_NODE* root, bool* taller){
	T_NODE* right_tree;
	T_NODE* left_tree;

	right_tree=root->right;

	switch(right_tree->balance){
		case RH:
			root->balance=EH;
			right_tree->balance=EH;
			root=rotate_left(root);
			*taller=false;
			break;
		case EH:exit(0);
		case LH:
			left_tree=right_tree->left;
			switch(left_tree->balance){
				case RH:
					root->balance=LH;
					right_tree->balance=EH;
					break;
				case EH:
					root->balance=EH;
					right_tree->balance=EH;
					break;
				case LH:
					root->balance =EH;
					right_tree->balance=RH;
					break;
			}
			left_tree->balance=EH;
			root->right=rotate_right(right_tree);
			root=rotate_left(root);
			*taller = false;
	}
	return root;

}

bool AVL_delete(AVL_TREE* tree, int data)
{
	bool shorter;
	bool success;
	T_NODE* new_node = delete_rotate(tree->root, data, &shorter,&success);
	if(success)
	{
		tree->root = new_node;
		(tree->count)--;
		return true;
	}
}

T_NODE* delete_rotate(T_NODE* root, int data, bool* shorter, bool* success)
{	

	T_NODE* delete_node;
	T_NODE* new_node;
	T_NODE* search;

	if(root==NULL){
		*success=false;
		return NULL;
	}
	
	if(data <(root->data)){
		root->left=delete_rotate(root->left, data, shorter, success);
		if(*shorter)
			root=del_balance_right(root,shorter);
	}

	else if(data>(root->data))
	{
		root->right=delete_rotate(root->right,data,shorter,success);
		/*if(*shorter)
			root=del_balance_left(root,shorter);*/
	}

	else
	{	
		delete_node=root;

		if(!root->right){
			new_node=root->left;
			*success=true;
			*shorter=true;
			free(delete_node);
			return new_node;
		}

		else{
			if(!root->left){
				new_node = root->right;
				*success=true;
				*shorter=true;
				free(delete_node);
				return new_node;
			}

			else
			{
				search=root->left;
				while(search->right!=NULL)
					search=search->right;

				root->data=search->data;
				root->left=delete_rotate(root->left, search->data,shorter,success);
				if(*shorter)
					root=del_balance_right(root, shorter);
			}
		}

	}

	return root;

}

T_NODE* del_balance_right(T_NODE* root, bool* shorter)
{
	T_NODE* left_tree;
	T_NODE* right_tree;

	switch(root->balance)
	{
		case LH:
			root->balance = EH;
			break;

		case EH:
			root->balance=RH;
			*shorter = false;
			break;

		case RH:
			right_tree = root->right;
			if(right_tree->balance == LH)
			{
				left_tree = right_tree->left;
				switch(left_tree->balance)
					{
						case LH:right_tree->balance = RH;
								root->balance = EH;
								break;

						case EH:root->balance = EH;
								right_tree->balance = EH;
								break;

						case RH:root->balance = LH;
								right_tree-> balance =EH;
								break;
					}

					left_tree->balance = EH;

					root->right = rotate_right(right_tree);
					root = rotate_left(root);
			}

			else
				{
					switch (right_tree->balance)
					{
						case LH:
						case RH:root->balance = EH;
								right_tree->balance = EH;
								break;

						case EH:root->balance = RH;
								right_tree->balance = LH;
								*shorter = false;
								break;
					}
					root = rotate_left(root);
				}

	}

	return root;
}


void traverse_preorder(T_NODE* root){
	if(root !=NULL){
		printf("%d ",root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void AVL_print(AVL_TREE* tree){
	printf("AVL_TREE\n");
	printf("size : %d\n",tree->count);
	printf("data: ");
	traverse_preorder(tree->root);

	printf("\n");
}