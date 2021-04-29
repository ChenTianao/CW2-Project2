#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
extern struct adjacency_list sum_list;
int main(){
	long int startnode_id;
	long int endnode_id;
	read_data();
	//test1
	printf("read_data\n");
	//end
	convert();
	//test2
	printf("convert\n");
	//end
	printf("Please print the start node id and end node id:\n");
	scanf("%ld%ld",&startnode_id,&endnode_id);
	Gragh(startnode_id);
	//test3
	printf("Gragh\n");
	//end
	Output(endnode_id);
	//test4
	printf("Output\n");
	//end 
	return 0;
} 
