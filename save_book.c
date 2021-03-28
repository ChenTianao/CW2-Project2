#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node;
extern int kindbook;
extern int line;
int store_books(FILE *file){
	Book* headNode;
	headNode = node.array;
	FILE *fp;
	fp = fopen(file,"wt");
		fprintf(fp,"The total amount of the book is %d\n",node.length);
		fprintf(fp,"The kinds of book are %d\n",kindbook);
		fprintf(fp,"The following lines are %d\n",line);
		while(headNode->next!=NULL){
			headNode = headNode->next;
			fprintf(fp, "ID:%d\n", headNode->id);
			fprintf(fp, "Book Title:%s\n",headNode->title);
			fprintf(fp,"Author(s):%s\n",headNode->authors);
			fprintf(fp,"Year:%d\n",headNode->year);
			fprintf(fp,"Copies:%d\n",headNode->copies);
			fprintf(fp,"Borrow_Copies:%d\n",headNode->brcopies);
		}
		fclose(fp);
		return 0;

}
