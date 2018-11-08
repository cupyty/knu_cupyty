#include <stdio.h>
#include "AVL_tree.h"

int main(void)
{
	AVL_TREE* tree = create_avl();
	AVL_insert(tree,18);
	AVL_insert(tree,12);
	AVL_insert(tree,20);
	AVL_insert(tree,8);
	AVL_insert(tree,14);

	AVL_print(tree);

	AVL_insert(tree,4);

	AVL_print(tree);

	AVL_insert(tree,21);
	AVL_insert(tree,23);
	AVL_insert(tree,24);
	AVL_insert(tree,26);
	AVL_print(tree);

	return 0;
}