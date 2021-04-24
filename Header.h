#ifndef HEADER_GUARD__H
#define HEADER_GUARD__H

#include <stdio.h>




//������Ϣ 
typedef struct _Node{
	int node_id;
	double latitude;
	double longitude;
}Node_details;

//�߱�(���ں���ıߵ�) 
typedef struct _Link{
	int linkid;
	Node_details nodelater;   //��ñ����ӵ���һ�������Ϣ 
	double distance;
	struct _Link* next;
	//struct _Link* previous;
}Link;

//����(���ڿ�ͷ�Ķ���) 
typedef struct _node{
	Node_details topnode;		//��ͷ�������Ϣ���������� 
	Link *nodenext;				//ָ���򣨴ӿ�ͷ����ָ������ĵ㣩 
}Node; 

//�ڽӱ�
struct adjacency_list{
	Node vertex[100000];          //����ÿ��������ĵط�      //�������������������
	int number_vertex;       //��������� 
	int number_side;		//�ߵ����� 
};  









#endif
