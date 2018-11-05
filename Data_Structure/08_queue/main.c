#include "ADT_queue.h"
#include "chart.h"
#include <stdio.h>

#define REVERSE 0 // reverse

int main() {

	// new type definition
	typedef struct {
		char name[20];
		int score;
	} STD;

	// prepare 5 data
	STD student[5] = {
		{"James", 95},
		{"Yoosoo", 87},
		{"Paul", 93},
		{"Peter", 76},
		{"Park", 100}
	};

#ifndef REVERSE
	generate_chart_header();
	//                    me                my boss            my score
	generate_chart_node(student[0].name, student[0].name, student[0].score); 
	generate_chart_node(student[1].name, student[0].name, student[1].score); 
	generate_chart_node(student[2].name, student[1].name, student[2].score); 
	generate_chart_node(student[3].name, student[2].name, student[3].score); 
	generate_chart_node(student[4].name, student[3].name, student[4].score); 
	generate_chart_footer();
#else
	// start here, for homework
	//Stack Creation
	QUEUE* queue;
	queue=create_queue();
	int size = sizeof(student)/sizeof(student[0]);

	int i;
	for(i=0; i<size; i++){
		enqueue(queue,&student[i]);
	}

	//pop them
	STD* boss=NULL;//back up previous boss
	STD* std;
	generate_chart_header();
	while(!(queue->count==0)){
		std=(STD*)dequeue(queue);
		if(boss==NULL)
			generate_chart_node(std->name,std->name,std->score);
		else
			generate_chart_node(std->name,boss->name,std->score);
		
		boss=std;

	}
	generate_chart_footer();


#endif

    return 0;
}
