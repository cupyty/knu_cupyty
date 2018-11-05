#include <stdio.h>
#include <stdlib.h>
#include "ADT_heap.h"

int main(void)
{

	HEAP* heap=create_heap(10);
	insertHeap(heap,15);
	insertHeap(heap,91);
	insertHeap(heap,53);
	insertHeap(heap,19);
	insertHeap(heap,31);
	insertHeap(heap,46);
	insertHeap(heap,73);
	insertHeap(heap,64);

	for(int i=0;i<(heap->size);i++){
		printf("data:%d\n",heap->array[i]);
	}

	return 0;

}