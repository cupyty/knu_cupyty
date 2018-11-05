typedef struct{
	int last;
	int size;
	int* array;
	int max_size;
}HEAP;

HEAP* create_heap(int max);
void reheapUp(HEAP* heap, int child);
void reheapDown(HEAP* heap, int root, int child);
bool insertHeap(HEAP* heap, int data);