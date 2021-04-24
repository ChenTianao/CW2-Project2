#ifndef READ_GUARD__H
#define READ_GUARD__H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//读取部分

typedef struct readlink{
	long int linkid;
	long int node_id1;
	long int node_id2;
	double length;
	long int way;      //没啥用 
	double veg;       //没啥用 
	double arch;     //没啥用 
	double land;    //没啥用 
	long int POI;  //没啥用 
}Readlink;

typedef struct readnode{
	long int nodeid;
	double nodelat;
	double nodelon;
}Readnode;

#endif
