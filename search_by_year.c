#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node;
BookArray find_book_by_year (unsigned int year){
	Book *last = (Book*)malloc(sizeof(Book));
	Book *passNode = (Book*)malloc(sizeof(Book));
	BookArray findyear;					//Create new structure to store the search_book information
	findyear.length = 0;
	findyear.array = (Book*)malloc(sizeof(Book));
	findyear.array->next = NULL;

	system("cls");
	last = node.array->next;
	passNode = findyear.array;
	while(1){
		if(last==NULL){
			return findyear;
			break;
		}
		 
		if(last->year==year)		//judge if they are equal
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
			findyear.length += last->copies;
			passNode = newNode;
		}
		last = last->next;
	}
} 

