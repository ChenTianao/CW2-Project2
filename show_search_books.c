#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
int search_through(BookArray go){
	

	if(go.length==0){		//length == 0 means no matched book 
		printf("No matched books or enter the wrong book information!\n");
		getch();
		return -1;
	}

	Book* loop = (Book*)malloc(sizeof(Book));

	loop = go.array->next;
	printf("The details in Books of the library are follows:\n\
Id\tTitle\t\t\t\t\tAuthor(s)\t\t\tYear\tCopies\tBorrow_copies\n");
	for(;;){			//the loop to print the TXT file information 
		if(loop==NULL)
			break;
		printf("%-8d%-40s%-32s%-8d%-8d%-8d\n",loop->id,loop->title,
		loop->authors,loop->year,loop->copies,loop->brcopies);
		loop = loop->next;
	}
	getch();
	return 0;
}
