#ifndef HEADER_GUARD__H
#define HEADER_GUARD__H

#include <stdio.h>




//顶点信息 
typedef struct _Node{
	int node_id;
	double latitude;
	double longitude;
}Node_details;

//边表(关于后面的边点) 
typedef struct _Link{
	int linkid;
	Node_details nodelater;   //与该边连接的另一个点的信息 
	double distance;
	struct _Link* next;
	//struct _Link* previous;
}Link;

//链表(关于开头的顶点) 
typedef struct _node{
	Node_details topnode;		//开头顶点的信息（即数据域） 
	Link *nodenext;				//指针域（从开头定点指向下面的点） 
}Node; 

//邻接表
struct adjacency_list{
	Node vertex[100000];          //储存每个点的链的地方      //这里可以用链表来储存
	int number_vertex;       //顶点的数量 
	int number_side;		//边的数量 
};  









#endif
