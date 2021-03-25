#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node;
BookArray find_book_by_title (const char *title){
	Book* last = (Book*)malloc(sizeof(Book));
	Book* passNode = (Book*)malloc(sizeof(Book));
	BookArray findtitle;				//Create new structure to store the search_book information  
	findtitle.length = 0;
	findtitle.array = (Book*)malloc(sizeof(Book));
	findtitle.array->next = NULL;
	
	system("cls");
	last = node.array->next;
	passNode = findtitle.array;
	while(1){
		if(last==NULL){
			return findtitle;
			break;
		}
		if(strcmp(last->title,title)==0)		//judge if they are equal
		{
			Book *newNode = (Book*)malloc(sizeof(Book));
			newNode->title = (char*)malloc(sizeof(char)*100);
			newNode->authors = (char*)malloc(sizeof(char)*100);
			newNode->id = last->id;
			newNode->title = last->title;
			newNode->authors = last->authors;
			newNode->year = last->year;
			newNode->copies = last->copies;
			newNode->brcopies = last->brcopies;
			newNode->next = NULL;
			passNode->next = newNode;		//insert node and add new node	
			findtitle.length += last->copies;
			passNode = newNode;
		}
		last = last->next;
	}
}
