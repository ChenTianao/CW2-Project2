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
//创造俩玩意儿
	Ensure ensure_list[NODE];
	Unsure unsure_list[NODE-1];

void Gragh(long int nodestart){
	
	int m = 0;
	int i =0;
	int y =0;
	
	
	//对已确定点集合和未确定点集合进行初始化 
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

	int s1 = 0;  //新的已确定点的个数 
	while(1){
		int i = 0;
		//循环寻找所需顶点
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
			//寻找当前顶点 
			if(ensure_list[s1].ensure_nodeid == sum_list.vertex[i].topnode.node_id){
			//	printf("%ld",ensure_list[s1].ensure_nodeid);
			//	getch();
			//	printf("%ld\n",ensure_list[s1].ensure_nodeid);
				//先把不确定集合与该点相连的点的信息更新
				 while(updatelast != NULL){
				 	//printf("ttt");
				//	getch();
				 	int j;
				 	for(j = 0;j<NODE-1;j++){
						if(updatelast->nodelater.node_id == unsure_list[j].unsure_nodeid && unsure_list[j].x != 1){
						//	printf("%ld",updatelast->nodelater.node_id);
							//若新路径更小，则更新 
							if((updatelast->distance + ensure_list[s1].shortrst_distance < unsure_list[j].shortrst_distance) || 
								unsure_list[j].shortrst_distance == 0 )
				 			{	
				 			//	printf("gengxin");
								unsure_list[j].shortrst_distance = updatelast->distance + ensure_list[s1].shortrst_distance;
							//	printf("%lf",	unsure_list[j].shortrst_distance);
								//循环之前，先清空先前的路径
									int pop;
									for(pop = 0;pop<10000;pop++){
										unsure_list[j].all_nodeid[pop] = 0;
									} 
									//清空结束
								//储存路径经过的点的信息 
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
				//在未确定集合中找寻下一次离原始点最近的点
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
				//将已确定顶点放进已确定顶点集合中 
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
						//对路径进行赋值
						int k = 0;
						while(unsure_list[n].all_nodeid[k] != 0){
							ensure_list[s1].all_nodeid[k] = unsure_list[n].all_nodeid[k];
							//printf("ok");
							k += 1;
						}
						unsure_list[n].x = 1;  //对进入已确定集合进行标记
						break; 
					}
				}
				//printf("kongge\n");
				break;          //若已经找到了最短路径，就跳出循环 
			}
		}
		/*printf("%ld\n",ensure_list[s1].ensure_nodeid);
		y++;
		printf("%d\n",y);*/
		if(s1==NODE-1)
			break;                  //所有点都更新完成 
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

