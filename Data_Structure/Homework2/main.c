#include "ADT_llist.h"

#define SORT 0 //sort

#define D_SIZE 8


void print1(void* x)
{
    double* xp = (double*)x;
    printf(" - double data %.6lf\n", *xp);
}

typedef struct point{
    double x;
    double y;
} POINT;

int compare1(void* x, void* y) {
    double a= ((double*)x) - ((double*)y);
    if(a>0)
    	return 1;
    else if(a<0)
    	return -1;
    else
    	return 0;

}

void sort_list(LLIST* list, void* data);

int main() {
    FILE* fnode = fopen("node.in", "w");
    FILE* flink = fopen("link.in", "w");

    LLIST* list = create_list(compare1, print1);
    int i;

    POINT path[D_SIZE] = {
        {35.885663, 128.6142},
        {35.888741, 128.609344},
        {35.887057, 128.610213},
        {35.886988, 128.611832},
        {35.890204, 128.609753},
        {35.892413, 128.609242},
        {35.891764, 128.609924},
        {35.887085, 128.609089},
    };

#ifndef SORT

    for(i = 0; i < D_SIZE; i++) {
        fprintf(fnode, "%lf %lf\n", path[i].x, path[i].y);
    }
    for(i = 0; i < D_SIZE-1; i++) {
        fprintf(flink, "%lf %lf %lf %lf\n", path[i].x, path[i].y, path[i+1].x, path[i+1].y);
    }

#else

    for(i=0; i<D_SIZE; i++){
    	if(!add_node_at(list,list->count,&path[i]))
    		printf("data insertion fatiled on list!\n");
    	else
    		printf("data insertion ok on list!\n");
    }

    sort_list(list,path);
    
    POINT* a;
    POINT* b;

    for(i=0; i<D_SIZE; i++){
    	a=(POINT*)get_data_at(list,i);
    	fprintf(fnode, "%lf %lf\n",a->x,a->y); 
    }
    for(i=0; i<D_SIZE-1;i++){
    	a=(POINT*)get_data_at(list,i);
    	b=(POINT*)get_data_at(list,i+1);
    	fprintf(flink, "%lf %lf %lf %lf\n",a->x,a->y,b->x,b->y); 
    }


#endif

   return 0;
}

/*void sort_list(LLIST* list, void* data) {
	int i,j;
	void* stand;
	void* walk;
	void* tmp;

	POINT* path = (POINT*)data;

	for(i=0; i<(list-> count)-1;i++){
		for(j=i+1; j<(list->count); j++){
			stand=get_data_at(list,i);
			walk=get_data_at(list,j);

			if(((POINT*)stand)->x>((POINT*)walk)->x){
				del_node_at(list,i);
				add_node_at(list,i,walk);
				del_node_at(list,j);
				add_node_at(list,j,stand);
			}
			
			
			printf("stand: %.6lf\n",((POINT*)stand)->x);
		}
		
	}


}*/

void sort_list(LLIST* list, void* data) {
	int i,j;
	void* stand;
	void* walk;
	void* tmp;

	POINT* path = (POINT*)data;

	for(i=0; i<(list->count)-1; i++){
		for(j=i+1; j<(list->count); j++){
			stand = &path[i];
			walk = &path[j];
			tmp=(POINT*)malloc(sizeof(POINT));
			if(((POINT*)stand)->x > ((POINT*)walk)->x){
				((POINT*)tmp)->x=((POINT*)stand)->x;
				((POINT*)tmp)->y=((POINT*)stand)->y;
				((POINT*)stand)->x=((POINT*)walk)->x;
				((POINT*)stand)->y=((POINT*)walk)->y;
				((POINT*)walk)->x=((POINT*)tmp)->x;
				((POINT*)walk)->y=((POINT*)tmp)->y;
				del_node_at(list,i);
				add_node_at(list,i,stand);
				del_node_at(list,j);
				add_node_at(list,j,walk);
			}
				
			
		}
	}

	free(tmp);
}


