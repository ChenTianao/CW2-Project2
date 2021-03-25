#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node;
extern int kindbook;
extern int line;
//Add the book 
int add_book(Book book){
	system("cls");
	int pause;
	Book* newNode;
	Book* last = (Book*)malloc(sizeof(Book));
	last = node.array;
	while(last->next!=NULL){
		last = last->next;   //to circulate to the last node  
	}	
		newNode = (Book*)malloc(sizeof(Book));
		newNode->title = (char*)malloc(sizeof(char)*100);
		newNode->authors = (char*)malloc(sizeof(char)*100);
		newNode->id = book.id;
		newNode->title = book.title;
		newNode->authors = book.authors;
		newNode->year = book.year;
		newNode->copies = book.copies;
		newNode->brcopies = 0;
		newNode->next = NULL;
		last->next = newNode;
		store_books("book.txt");
		return 0;
	}

void add(){
	Book book;
	int x;
	int pause;
	kindbook += 1;
	line += 6;
	book.id = kindbook;
	system("cls");
	fflush(stdin);
	while(1){                 //the following lines while are test the input format
		book.title = (char*)malloc(sizeof(char)*100);
		printf("please enter the book title:\n");
		pause = scanf("%[^\n]",book.title);
		fflush(stdin);
		if(pause != 1||strlen(book.title)>40)
			printf("Please enter the right format\
or exceeding the range!\n");
		else
			break;
	}
	while(1){
		book.authors = (char*)malloc(sizeof(char)*100);
		printf("Please enter the book author(s):\n");
		pause = scanf("%[^\n]",book.authors);
		fflush(stdin);
		if(pause != 1||strlen(book.authors)>32)
			printf("Please enter the right format \
or exceeding the range!\n");
		else
			break;
	}
	while(1){
		printf("Please enter the book year:\n");
		pause = scanf("%d",&book.year);
		fflush(stdin);
		if(pause != 1)
			printf("Please enter the right format!\n");
		else
			break;
	}
	while(1){
		printf("Please enter the book copies:\n");
		pause = scanf("%d",&book.copies);
		fflush(stdin);
		if(pause != 1)
			printf("Please enter the right format!\n");
		else
			break;
	}
	book.brcopies = 0;
	node.length += book.copies;
	x = add_book(book);
	if(x == 0)
		printf("you have add a book successfully!\n");
	getch();
	system("cls");
}

