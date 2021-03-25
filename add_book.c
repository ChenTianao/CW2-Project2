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
	struct book data; //数据域
	struct Node* next; //指针域
};
//创建链表 

struct Node* createList(){
	struct Node* headNode,*last;
	headNode = (struct Node*)malloc(sizeof(struct Node)); //建立附加头结点 
	last = headNode;    //last始终指向当前最后一个结点 
	last->next = NULL;
	return last;
}
//添加图书 
void add(struct Node* lastx){
	system("cls");
	int pause;
	struct Node* newNode;
	struct Node* last;
	last = lastx;
	constant = lastx;    //固定指针位置 
	while(last->next!=NULL){
		last = last->next;   // 去循环到最后一个结点 
	}
	while(1){
		newNode = (struct Node*)malloc(sizeof(struct Node));
		data.title = (char*)malloc(sizeof(char));
		data.authors = (char*)malloc(sizeof(char));
		printf("Please enter book name,publish name,author and year");
		scanf("%s%s%d",newNode->data.title,newNode->data.authors,&newNode->data.year);    //scanf不允许空格，这里可能需要更改 
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
		last->next=NULL;  //这是一个地方 
		savebook(last);   //这里还有个保存图书文件的函数 
		
		printf("If you would like to continue,please enter any key,\
				otherwise enter 'Esc'");
		pause = getch();
		if(pause == 27) //这里面还有用getch来判断是否继续 
		{ 	
			last->next=NULL; //这是另一个地方，准备退出了，然后明确最后一个结点 
			break;
		} 
		else
			continue;
	}
}
