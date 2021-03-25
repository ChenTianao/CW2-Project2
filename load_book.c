#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node; 
extern int kindbook;
extern int line;
int load_books(FILE *file){
	Book* newNode = (Book*)malloc(sizeof(Book));
	Book* last = (Book*)malloc(sizeof(Book));
	char buf[300];  //to store the each line's information  
	int n = 0;     //used to judge loop if is ended  
	last = node.array;     
	FILE *fp;
	fp = fopen(file,"rt");
	if(fp!=NULL)
	{	
		fgets(buf,200,fp);
		sscanf(buf,"The total amount of the book is %d\n",&node.length);
		fgets(buf,200,fp);
		sscanf(buf,"The kinds of book are %d\n",&kindbook);
		fgets(buf,200,fp);
		sscanf(buf,"The following lines are %d\n",&line);
		while(n<line)
		{	
			newNode = (Book*)malloc(sizeof(Book)); //Creates a node to accept information loaded 
			newNode->title = (char*)malloc(sizeof(char));
			newNode->authors = (char*)malloc(sizeof(char));   //Allocates space for Pointers 
			fgets(buf, 200, fp);
			sscanf(buf,"ID:%d\n", &newNode->id);
			fgets(buf, 200, fp);
			sscanf(buf, "Book Title:%s\n",newNode->title);
			fgets(buf, 200, fp);
			sscanf(buf,"Author(s):%s\n",newNode->authors);
			fgets(buf, 200, fp);
			sscanf(buf,"Year:%d\n", &newNode->year);
			fgets(buf, 200, fp);
			sscanf(buf,"Copies:%d\n", &newNode->copies);
			fgets(buf, 200, fp);
			sscanf(buf,"Borrow_Copies:%d\n", &newNode->brcopies);
      		last->next = newNode;
			newNode = newNode->next;
			last = last->next;
			n += 6;
		}
		last->next = NULL;
		fclose(fp);
		return 0;
  	}
  	else 
	{
   		printf("\t\tFailing to load the book.txt,\
maybe it's the first time to use the system!\n\n");
		getch();
		fclose(fp);
		return -1;
  	}
}
