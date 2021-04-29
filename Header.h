#ifndef HEADER_GUARD__H
#define HEADER_GUARD__H

#include <stdio.h>




//the information of the node 
typedef struct _Node{
	long int node_id;
	double latitude;
	double longitude;
}Node_details;

//side table 
typedef struct _Link{
	long int linkid;
	Node_details nodelater;   //与该边连接的另一个点的信息 
	double distance;
	struct _Link* next;
	//struct _Link* previous;
}Link;

//the start node 
typedef struct _node{
	Node_details topnode;		//开头顶点的信息（即数据域） 
	Link *nodenext;				//指针域（从开头定点指向下面的点） 
}Node; 

//adjacency list 
struct adjacency_list{
	Node vertex[100000];          //储存每个点的链的地方      //这里可以用链表来储存
	int number_vertex;       //顶点的数量 
	int number_side;		//边的数量 
};  









#endif
