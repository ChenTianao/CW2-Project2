#include<stdio.h>>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
struct book{	
	unsigned int id; //Book ID
	char *title; //book title
	char *authors; //comma separated list of authors
	unsigned int year; // year of publication
	unsigned int copies; //number of copies the library has
	int brcopies=0;  //0 stands for not be returned
}; 
struct Node{
	struct book data; //������
	struct Node* next; //ָ����
};
//�������� 

struct Node* createList(){
	struct Node* headNode,*last;
	headNode = (struct Node*)malloc(sizeof(struct Node)); //��������ͷ��� 
	last = headNode;    //lastʼ��ָ��ǰ���һ����� 
	last->next = NULL;
	return last;
}
//���ͼ�� 
void add(struct Node* lastx){
	system("cls");
	int pause;
	struct Node* newNode;
	struct Node* last;
	last = lastx;
	constant = lastx;    //�̶�ָ��λ�� 
	while(last->next!=NULL){
		last = last->next;   // ȥѭ�������һ����� 
	}
	while(1){
		newNode = (struct Node*)malloc(sizeof(struct Node));
		data.title = (char*)malloc(sizeof(char));
		data.authors = (char*)malloc(sizeof(char));
		printf("Please enter book name,publish name,author and year");
		scanf("%s%s%d",newNode->data.title,newNode->data.authors,&newNode->data.year);    //scanf������ո����������Ҫ���� 
		while(1){
			contant = constant->next;
			if(strcmp(constant->data.title,newNode->data.title)==0)
			{
				if(contant==newNode)
					{
						newNode->data.id+=1;
						newNode->data.copies=1;
						break;
					}
				newNode->data.copies+=1;
				break;
				}
			}
		}
		last->next = newNode;
		last = newNode;
		last->next=NULL;  //����һ���ط� 
		savebook(last);   //���ﻹ�и�����ͼ���ļ��ĺ��� 
		
		printf("If you would like to continue,please enter any key,\
				otherwise enter 'Esc'");
		pause = getch();
		if(pause == 27) //�����滹����getch���ж��Ƿ���� 
		{ 	
			last->next=NULL; //������һ���ط���׼���˳��ˣ�Ȼ����ȷ���һ����� 
			break;
		} 
		else
			continue;
	}
}
