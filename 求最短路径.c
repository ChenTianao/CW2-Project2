#include<stdio.h>
#include<stdlib.h>
#define LINK 2344
#define NODE 3941
#include"Header.h"
#include"Read.h"
#include"List.h"
extern struct adjacency_list sum_list;
//�����������
	Ensure ensure_list[NODE];
	Unsure unsure_list[NODE-1];

void Gragh(long int nodestart,long int nodeend){
	
	int m = 0;
	int i =0;
	int y =0;
	
	
	//����ȷ���㼯�Ϻ�δȷ���㼯�Ͻ��г�ʼ�� 
	for(i =0;i<NODE;i++){
		if(sum_list.vertex[i].topnode.node_id == nodestart){
			ensure_list[0].ensure_nodeid =  nodestart;
			ensure_list[0].shortrst_distance = 0;
			ensure_list[0].ensure_nodelat = sum_list.vertex[i].topnode.latitude;
			ensure_list[0].ensure_nodelon = sum_list.vertex[i].topnode.longitude;
		}
		else{
			unsure_list[m].unsure_nodeid = sum_list.vertex[i].topnode.node_id;
			unsure_list[m].shortrst_distance = 0;
			unsure_list[m].unsure_nodelat = sum_list.vertex[i].topnode.latitude;
			unsure_list[m].unsure_nodelon = sum_list.vertex[i].topnode.longitude;
			unsure_list[m].x = 0;
			m += 1;
		}
	}

	int s1 = 0;  //�µ���ȷ����ĸ��� 
	while(1){
		int i = 0;
		//ѭ��Ѱ�����趥��
		for(i = 0;i<NODE;i++){
			double min_distance = 0;
			/*Link *last;
			last = (Link*)malloc(sizeof(Link));
			Link *constant;
			constant = (Link*)malloc(sizeof(Link));
			last = sum_list.vertex[i].nodenext;*/
			Link *updatelast;
			updatelast = (Link*)malloc(sizeof(Link)*30);
			updatelast = sum_list.vertex[i].nodenext;
			//Ѱ�ҵ�ǰ���� 
			if(ensure_list[s1].ensure_nodeid == sum_list.vertex[i].topnode.node_id){
				//printf("%ld\n",ensure_list[s1].ensure_nodeid);
				//�ȰѲ�ȷ��������õ������ĵ����Ϣ����
				 while(updatelast != NULL){
				 	int j;
				 	for(j = 0;j<NODE-1;j++){
						if(updatelast->nodelater.node_id == unsure_list[j].unsure_nodeid){
							//����·����С������� 
							if(updatelast->distance + ensure_list[s1].shortrst_distance < unsure_list[j].shortrst_distance || 
								unsure_list[j].shortrst_distance == 0 )
				 			{	
								unsure_list[j].shortrst_distance = updatelast->distance + ensure_list[s1].shortrst_distance;
								//����·�������ĵ����Ϣ 
								int t;
								for(t = 0;t<10000;t++){
									//ѭ��֮ǰ���������ǰ��·��
									int pop;
									for(pop = 0;pop<10000;pop++){
										unsure_list[j].all_nodeid[pop] = 0;
									} 
									//��ս��� 
									if(ensure_list[s1].all_nodeid[t] == 0){
										unsure_list[j].all_nodeid[t] = unsure_list[j].unsure_nodeid;
										break;
									}
									else{
										unsure_list[j].all_nodeid[t] = ensure_list[s1].all_nodeid[t];
									}
								}
							}
				 			break;
						}
					}
					updatelast = updatelast->next;
				 }
				//��δȷ����������Ѱ��һ����ԭʼ������ĵ�
				int m;
				for(m = 0;m<NODE-1;m++){
					if(unsure_list[m].x != 1 && unsure_list[m].shortrst_distance != 0){
						//test
						/*printf("%lf",unsure_list[m].shortrst_distance);
						getch();*/
						if(min_distance == 0){
							min_distance = unsure_list[m].shortrst_distance;
						}
						else if(unsure_list[m].shortrst_distance < min_distance)
						{
							min_distance = unsure_list[m].shortrst_distance;
							//test
							//printf("%lf",min_distance);
							//getch();
						}
					}
				}
				//����ȷ������Ž���ȷ�����㼯���� 
				int n;
				for(n = 0;n<NODE-1;n++){
					if(min_distance == unsure_list[n].shortrst_distance && unsure_list[n].x != 1){
						s1 += 1;
						ensure_list[s1].ensure_nodeid = unsure_list[n].unsure_nodeid;
						ensure_list[s1].ensure_nodelat = unsure_list[n].unsure_nodelat;
						ensure_list[s1].ensure_nodelon = unsure_list[n].unsure_nodelon;
						ensure_list[s1].shortrst_distance = min_distance;
						unsure_list[n].x = 1;  //�Խ�����ȷ�����Ͻ��б��
						break; 
					}
				}
				//printf("kongge\n");
				
				break;          //���Ѿ��ҵ������·����������ѭ�� 
			}
			
			
		}
		/*printf("%ld\n",ensure_list[s1].ensure_nodeid);
		y++;
		printf("%d\n",y);*/
		if(s1==NODE-1)
			break;                  //���е㶼������� 
	}
	
}

