#ifndef READ_GUARD__H
#define READ_GUARD__H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��ȡ����

typedef struct readlink{
	long int linkid;
	long int node_id1;
	long int node_id2;
	double length;
	long int way;      //ûɶ�� 
	double veg;       //ûɶ�� 
	double arch;     //ûɶ�� 
	double land;    //ûɶ�� 
	long int POI;  //ûɶ�� 
}Readlink;

typedef struct readnode{
	long int nodeid;
	double nodelat;
	double nodelon;
}Readnode;

#endif
