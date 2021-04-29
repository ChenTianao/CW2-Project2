#ifndef LIST_GUARD__H
#define LIST_GUARD__H

//已确定最短路径的点的集合 
	typedef struct gather_ensure{
		long int ensure_nodeid;
		double shortrst_distance;
		double ensure_nodelat;
		double ensure_nodelon;
		long int all_nodeid[10000];
	}Ensure;
	
	//未确定最短路径的点的集合 
	typedef struct gather_unsure{
		long int unsure_nodeid;
		double shortrst_distance;
		double unsure_nodelat;
		double unsure_nodelon;
		long int all_nodeid[10000];
		int x;  //对于是否进入最短路径的点的标记 
	}Unsure;

#endif
