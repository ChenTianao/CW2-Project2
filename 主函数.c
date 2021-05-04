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
	convert();
	printf("Please print the start node id and end node id:\n");
	scanf("%ld%ld",&startnode_id,&endnode_id);
	Gragh(startnode_id);
	Output(startnode_id,endnode_id);
	return 0;
} 
