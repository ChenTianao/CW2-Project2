#include<stdio.h>
#include<stdlib.h>
#define LINK 2344
#define NODE 3941
#include"Header.h"
#include"Read.h"
#include"List.h"
extern struct adjacency_list sum_list;
extern Readlink Readlinkarray[1000000];
extern Readnode Readnodearray[1000000];
//�����������
	Ensure ensure_list[NODE];
	Unsure unsure_list[NODE-1];

void Gragh(long int nodestart){
	
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
			ensure_list[0].all_nodeid[0] = nodestart;
		}
		else{
			unsure_list[m].unsure_nodeid = sum_list.vertex[i].topnode.node_id;
			unsure_list[m].shortrst_distance = 0;
			unsure_list[m].unsure_nodelat = sum_list.vertex[i].topnode.latitude;
			unsure_list[m].unsure_nodelon = sum_list.vertex[i].topnode.longitude;
			unsure_list[m].all_nodeid[0] = nodestart;
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
			//	printf("%ld",ensure_list[s1].ensure_nodeid);
			//	getch();
			//	printf("%ld\n",ensure_list[s1].ensure_nodeid);
				//�ȰѲ�ȷ��������õ������ĵ����Ϣ����
				 while(updatelast != NULL){
				 	//printf("ttt");
				//	getch();
				 	int j;
				 	for(j = 0;j<NODE-1;j++){
						if(updatelast->nodelater.node_id == unsure_list[j].unsure_nodeid && unsure_list[j].x != 1){
						//	printf("%ld",updatelast->nodelater.node_id);
							//����·����С������� 
							if((updatelast->distance + ensure_list[s1].shortrst_distance < unsure_list[j].shortrst_distance) || 
								unsure_list[j].shortrst_distance == 0 )
				 			{	
				 			//	printf("gengxin");
								unsure_list[j].shortrst_distance = updatelast->distance + ensure_list[s1].shortrst_distance;
							//	printf("%lf",	unsure_list[j].shortrst_distance);
								//ѭ��֮ǰ���������ǰ��·��
									int pop;
									for(pop = 0;pop<10000;pop++){
										unsure_list[j].all_nodeid[pop] = 0;
									} 
									//��ս���
								//����·�������ĵ����Ϣ 
								int t;
								for(t = 0;t<10000;t++){
									if(ensure_list[s1].all_nodeid[t] == 0){
										unsure_list[j].all_nodeid[t] = unsure_list[j].unsure_nodeid;
									//	printf("%ld",unsure_list[j].all_nodeid[t]);
									//	printf("%d",t);
										//if(ensure_list[s1].ensure_nodeid == 288976339)
											/*{
											printf("ok");
											printf("%ld",ensure_list[s1].ensure_nodeid);
											getch();
											}*/
										break;
										
									}
									else{
										unsure_list[j].all_nodeid[t] = ensure_list[s1].all_nodeid[t];
									//	printf("%ld",unsure_list[j].all_nodeid[t]);
									//	printf("%d",t);
									}
								}
								//	printf("\n%ld\n",unsure_list[j].all_nodeid[0]);
							}
				 			break;
						}
					}
					updatelast = updatelast->next;
				 }
				//printf("3");
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
						//	printf("%lf",min_distance);
							//getch();
						}
					}
				}
				//����ȷ������Ž���ȷ�����㼯���� 
				int n;
				for(n = 0;n<NODE-1;n++){
				//	printf("\nnaru");
					if(min_distance == unsure_list[n].shortrst_distance && unsure_list[n].x != 1){
					//	printf("%ld\n\n",unsure_list[n].unsure_nodeid);
					//	printf("%ld\n\n",unsure_list[n].all_nodeid[0]);
					//	printf("%d",n);
						
						s1 += 1;
						ensure_list[s1].ensure_nodeid = unsure_list[n].unsure_nodeid;
						
						ensure_list[s1].ensure_nodelat = unsure_list[n].unsure_nodelat;
						ensure_list[s1].ensure_nodelon = unsure_list[n].unsure_nodelon;
						ensure_list[s1].shortrst_distance = min_distance;
						//��·�����и�ֵ
						int k = 0;
						while(unsure_list[n].all_nodeid[k] != 0){
							ensure_list[s1].all_nodeid[k] = unsure_list[n].all_nodeid[k];
							//printf("ok");
							k += 1;
						}
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

void Output(long int nodestart,long int nodeend){
	FILE *fp;
	FILE *fp1;
	fp = fopen("all.txt","wt");
	int i = 0;
	while(Readlinkarray[i].linkid != 0){
		int x = 0;
		int j = 0;
		for(j = 0;j<100000;j++){
			if(Readlinkarray[i].node_id1 == Readnodearray[j].nodeid){
				fprintf(fp,"%lf ",Readnodearray[j].nodelon);
				fprintf(fp,"%lf\n",Readnodearray[j].nodelat);
				x++;
			}
			if(Readlinkarray[i].node_id2 == Readnodearray[j].nodeid){
				fprintf(fp,"%lf ",Readnodearray[j].nodelon);
				fprintf(fp,"%lf\n",Readnodearray[j].nodelat);
				x++;
			}
			
			if(x == 2){
				fprintf(fp,"\n");
				break;
			}
		}
		i++;
	}
	fclose(fp);
	fp1 = fopen("short.txt","wt");
	int m = 0;
	for(m=0;m<NODE;m++){
		if(ensure_list[m].ensure_nodeid == nodeend){
			int n = 1;
			while(ensure_list[m].all_nodeid[n] != 0){
				
				int x = 0;
				int j = 0;
				for(j = 0;j<10000;j++){
					if(Readnodearray[j].nodeid == ensure_list[m].all_nodeid[n-1]){
						fprintf(fp,"%lf ",Readnodearray[j].nodelon);
						fprintf(fp,"%lf\n",Readnodearray[j].nodelat);
						x++;
					}
					if(Readnodearray[j].nodeid == ensure_list[m].all_nodeid[n]){
						fprintf(fp,"%lf ",Readnodearray[j].nodelon);
						fprintf(fp,"%lf\n",Readnodearray[j].nodelat);
						x++;
					}
					if(x == 2){
						fprintf(fp,"\n");
						break;
					}
				}
				n++;
			}
		}
	}
	
	
}

