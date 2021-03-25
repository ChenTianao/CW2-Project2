#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node;
int go_through(){
	system("cls");
	if(node.length==0){
		printf("The library has no book!\n");
		getch();
		return -1;
	}
	Book* loop = (Book*)malloc(sizeof(Book));
	loop = node.array->next;
	printf("The details in Books of the library are follows:\n\
Id\tTitle\t\t\t\t\tAuthor(s)\t\t\tYear\tCopies\tBorrow_copies\n");

	for(;;){				//the loop to print the TXT file information 
		if(loop == NULL)
			break;
		printf("%-8d%-40s%-32s%-8d%-8d%-8d\n",loop->id,loop->title,
		loop->authors,loop->year,loop->copies,loop->brcopies);
		loop = loop->next;
	}
	printf("Please enter any key to continue\n");
	getch();
	return 0;
}
