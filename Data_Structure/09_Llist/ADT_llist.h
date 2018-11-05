#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	void* data_ptr;
	struct node* next;
}NODE;

typedef struct{
	int count;
	NODE* front;
	NODE* rear;
	NODE* pos;
	int(*cmp_func)(void* x, void* y);
}LLIST;

LLIST* create_list(int (*func)(void* x, void* y));
bool add_node_at(LLIST* list, unsigned int index, void* data);
bool del_node_at(LLIST* list, unsigned int index);
void* get_data_at(LLIST* list, unsigned int index);
int find_data(LLIST* list, void* search_data);