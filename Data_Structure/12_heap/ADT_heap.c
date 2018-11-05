#include "ADT_heap.h"
#include <stdlib.h>

HEAP* create_heap(int max){
	HEAP* heap=(HEAP*)malloc(sizeof(HEAP));
	if(heap){
		heap->last=-1;
		heap->size=0;
		heap->max_size=max;
		heap->array=(int*)malloc(sizeof(int)*max);
		return heap;
	}
}

void reheapUp(HEAP* heap, int child){
	int parent=(child-1)/2;
	int back;
	if(child){
		if(heap->array[parent]<heap->array[child]){
			back=heap->array[parent];
			heap->array[parent]=heap->array[child];
			heap->array[child]=back;
		reheapUp(heap,parent);
		}
	}
}
void reheapDown(HEAP* heap, int root){
	int hold;
	int leftdata;
	int rightdata;
	int largekey;
	int last;

	last=heap->last;
	if((root*2+1)<=last)
	{
		leftdata=heap->array[root*2+1];
		if((root*2+2)<=last)
			rightdata=heap->array[root*2+2];
		else
			rightdata=0;

		if(!rightdata)
			largekey=root*2+1;
		else{
			if(leftdata>rightdata)
				largekey=root*2+1;
			else
				largekey=root*2+2;
		}
		if(heap->array[root]<heap->array[largekey]){
			hold=heap->array[root];
			heap->array[root]=heap->array[largekey];
			heap->array[largekey]=hold;
			reheapDown(heap,largekey);
		}

	}
}
bool insertHeap(HEAP* heap, int data){
	if(heap->size==0)
	{
		heap->size=1;
		heap->last=0;
		heap->array[heap->last]=data;
		return true;
	}
	if(heap->last==heap->max_size-1)
		return false;
	(heap->last)++;
	(heap->size)++;
	heap->array[heap->last]=data;
	reheapUp(heap,heap->last);
	return true;
}