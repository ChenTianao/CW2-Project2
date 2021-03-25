#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node;
BookArray find_book_by_author (const char *author){
	Book *last = (Book*)malloc(sizeof(Book));
	Book *passNode = (Book*)malloc(sizeof(Book));
	BookArray findauthors;				//Create new structure to store the search_book information  
	findauthors.length = 0;
	findauthors.array = (Book*)malloc(sizeof(Book));
	findauthors.array->next = NULL;

	system("cls");
	last = node.array->next;
	passNode = findauthors.array;
	while(1){
		if(last==NULL){
			return findauthors;
			break;
		}
		 
		if(strcmp(last->authors,author)==0)		//judge if they are equal  
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
			findauthors.length += last->copies;   
			passNode = newNode;      
		}
		last = last->next;
	}
} 
