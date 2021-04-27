#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define LINK 2344
#define NODE 3941
#include"Header.h"
#include"Read.h"
extern Readlink Readlinkarray[1000000];
extern Readnode Readnodearray[1000000];
struct adjacency_list sum_list;
void convert(){
	int i = 0;
	for(i = 0;i<NODE;i++){
		//顶点起点信息赋值 
		sum_list.vertex[i].topnode.node_id = Readnodearray[i].nodeid;
		sum_list.vertex[i].topnode.latitude = Readnodearray[i].nodelat;
		sum_list.vertex[i].topnode.longitude = Readnodearray[i].nodelon;
		sum_list.vertex[i].nodenext = NULL;
		
		
		//边表开始 
		int j = 0;
		for(j = 0;j<LINK;j++){
			
			if(sum_list.vertex[i].nodenext == NULL){
				//起点的指针指向边表第一个 
				if(Readnodearray[i].nodeid == Readlinkarray[j].node_id1){	
					Link *startlink = (Link*)malloc(sizeof(Link)*1000);
					startlink->nodelater.node_id = Readlinkarray[j].node_id2;
					startlink->distance = Readlinkarray[j].length;
					startlink->linkid = Readlinkarray[j].linkid;
					sum_list.vertex[i].nodenext = startlink;
					
				}
				else if(Readnodearray[i].nodeid == Readlinkarray[j].node_id2){
					Link *startlink = (Link*)malloc(sizeof(Link)*1000);
					startlink->nodelater.node_id = Readlinkarray[j].node_id1;
					startlink->distance = Readlinkarray[j].length;
					startlink->linkid = Readlinkarray[j].linkid;
					sum_list.vertex[i].nodenext = startlink;
				
				}
			}
			//边表中的链表(前插法)
			else{
				if(Readnodearray[i].nodeid == Readlinkarray[j].node_id1){	
					Link *newlink = (Link*)malloc(sizeof(Link)*1000);
					newlink->nodelater.node_id = Readlinkarray[j].node_id2;
					newlink->distance = Readlinkarray[j].length;
					newlink->linkid = Readlinkarray[j].linkid;
					newlink->next = NULL;
					newlink->next = sum_list.vertex[i].nodenext;
					sum_list.vertex[i].nodenext = newlink;
				}
				else if(Readnodearray[i].nodeid == Readlinkarray[j].node_id2){
					Link *newlink = (Link*)malloc(sizeof(Link)*1000);
					newlink->nodelater.node_id = Readlinkarray[j].node_id1;
					newlink->distance = Readlinkarray[j].length;
					newlink->linkid = Readlinkarray[j].linkid;
					newlink->next = NULL;
					newlink->next = sum_list.vertex[i].nodenext;
					sum_list.vertex[i].nodenext = newlink;
					
				}
			}
		}
	}
}
