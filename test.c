#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINK 2344
#define NODE 3941

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

Readlink Readlinkarray[1000000];

typedef struct readnode{
	long int nodeid;
	double nodelat;
	double nodelon;
}Readnode;

Readnode Readnodearray[1000000];

int main(void){

FILE *fp ;
fp = fopen("Final_Map(1).map","r"); 
char line[20000] ;
fgets(line,10000,fp);


//Loop begin 
int i =0;
for(i =0;i<LINK;i++){
	char line[10000] ;
	fgets(line,10000,fp);
	sscanf(line,"<link id=%ld node=%ld node=%ld way=%ld length=%lf veg=%lf arch=%lf land=%lf POI=%ld;/link>\n",
	&Readlinkarray[i].linkid, &Readlinkarray[i].node_id1,&Readlinkarray[i].node_id2,&Readlinkarray[i].way,
	&Readlinkarray[i].length,&Readlinkarray[i].veg,&Readlinkarray[i].arch,&Readlinkarray[i].land,&Readlinkarray[i].POI);
}

char line1[10000];
int j = 0;
for(j=0;i<NODE;i++){
	fgets(line1,10000,fp);
	sscanf(line1,"<node id=%d lat=%lf lon=%lf /node>\n",&Readnodearray[j].nodeid,&Readnodearray[j].nodelat,&Readnodearray[j].nodelon);
}
printf("%ld",Readlinkarray[2342].linkid);
return 0;
}
