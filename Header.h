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
	Node_details nodelater;   //��ñ����ӵ���һ�������Ϣ 
	double distance;
	struct _Link* next;
	//struct _Link* previous;
}Link;

//the start node 
typedef struct _node{
	Node_details topnode;		//��ͷ�������Ϣ���������� 
	Link *nodenext;				//ָ���򣨴ӿ�ͷ����ָ������ĵ㣩 
}Node; 

//adjacency list 
struct adjacency_list{
	Node vertex[100000];          //����ÿ��������ĵط�      //�������������������
	int number_vertex;       //��������� 
	int number_side;		//�ߵ����� 
};  









#endif
