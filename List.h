#ifndef LIST_GUARD__H
#define LIST_GUARD__H

//��ȷ�����·���ĵ�ļ��� 
	typedef struct gather_ensure{
		long int ensure_nodeid;
		double shortrst_distance;
		double ensure_nodelat;
		double ensure_nodelon;
		long int all_nodeid[10000];
	}Ensure;
	
	//δȷ�����·���ĵ�ļ��� 
	typedef struct gather_unsure{
		long int unsure_nodeid;
		double shortrst_distance;
		double unsure_nodelat;
		double unsure_nodelon;
		long int all_nodeid[10000];
		int x;  //�����Ƿ�������·���ĵ�ı�� 
	}Unsure;

#endif
