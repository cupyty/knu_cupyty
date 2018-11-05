#include <stdio.h>
#include "ADT_llist.h"

int compare1(void* x, void*y);

int main()
{
	LLIST* list;
	int i=100;
	list=create_list(compare1);

	if(add_node_at(list,0,&i))
		printf("good\n");
	printf("hello");

	return 0;
}

int compare1(void* x, void* y){
	int* xp=(int*)x;
	int* yp=(int*)y;
	return *xp-*yp;
}