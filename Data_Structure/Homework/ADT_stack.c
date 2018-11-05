#include "ADT_stack.h"
#include <stdlib.h>

STACK* create_stack(){
	STACK* stack= (STACK*)malloc(sizeof(STACK));
	if(!stack)
		return NULL;

	stack->count=0;
	stack->top=NULL;

	return stack;
}

bool push(STACK* stack, void* in){
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(node == NULL)
		return false;

	node->data_ptr=in;
	node->link=stack->top; // new node's next is previous top
	stack->top=node;
	(stack->count)++;

	return true;
}

void* pop(STACK* stack)
{
	void* dataoutptr;
	STACK_NODE* temp;

	if(stack->count == 0)
		dataoutptr = NULL;
	else
	{
		temp = stack->top;
		dataoutptr=stack->top->data_ptr;
		stack->top=stack->top->link;
		free(temp);
		(stack->count)--;
	}

	return dataoutptr;
}