#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include"Header.h"
extern struct adjacency_list sum_list;
long int startnode_id;
long int endnode_id;
int main(){
	read_data();
	convert();
	//test_code3();
	//test_code4();
	//test_code5();
	while(1){
		int x = 0;
		printf("Please print the start node id and end node id:\n");
		scanf("%ld%ld",&startnode_id,&endnode_id);
		//test_code1();
		fflush(stdin);
		if(isdigit(startnode_id)==1 && isdigit(endnode_id)==1){
			printf("Please wrtie the right format!\n");
		}
		else{
			int i = 0;
			for(i = 0;i<10000;i++){
				if(sum_list.vertex[i].topnode.node_id == startnode_id || sum_list.vertex[i].topnode.node_id == endnode_id)
					x++;
			}
			if(x == 2){
				break;
				}
			else
				{
					printf("The node is out the range of the data set!\n");
				}
		}
	}
	//test_code2();
	Gragh(startnode_id);
	Output(startnode_id,endnode_id);
	//test_code6();
	//test_code7();
	return 0;
} 
