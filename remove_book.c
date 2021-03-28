#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
extern BookArray node;
extern int kindbook;
extern int line;
int remove_book(Book book){
	system("cls");
	int x;    //to judge if the library has no book
	Book* previous;
	Book* last;
	char choice;
	int pause;     //to judge if the scanf format is right
	
	system("cls");

		previous = (Book*)malloc(sizeof(Book));
		last = (Book*)malloc(sizeof(Book));
		previous = node.array;
		last = node.array->next;
		while(1){		//judge if there existing this kind of book  
			if(last->id==book.id&&
			strcmp(last->title,book.title)==0
			&&strcmp(last->authors,book.authors)==0&&
			last->copies==book.copies&&
			last->year==book.year&&
			last->brcopies==book.brcopies)  
			{	
				break;
			}
			else
			{
				previous = last;
				last = last->next;
			}
			if(last==NULL)
				{
					printf("You have enter the wrong \
information of the book!\n");
					getch();
					return -1;
				}
		}
		//Remove one or all (begin) 
		printf("Do you want to delete all this kind of\
book or one of them(y/n)?\n");
		while(1){
			pause = scanf("%c",&choice);
			fflush(stdin);
			if(pause != 1)		//format validation  
				printf("Please enter the right format!\n");
			else
				break;
		}
		if(choice=='y')  //all this kind of book  
		{	
			if(last->brcopies == 0)
			{	
				if(last->next==NULL)
					{	
						previous->next=NULL;
					}
				else
					previous->next = last->next;
				node.length -= last->copies;
				kindbook -= 1;
				line -= 6;
				free(last);
				store_books("book.txt");
				return 0;
			}
			else		//existing borrowed book  
				{
					printf("The books are on loan!Fail to delete them!\n");
					getch();
					return -1;
				}
		}
		//one kind of this book  
		else
			{	
				if(last->copies>last->brcopies)
					{	
						if(last->copies==1&&last->brcopies==0)
							{
								previous->next = last->next;
								node.length -= last->copies;
								kindbook -= 1;
								line -= 6;
								free(last);
								store_books("book.txt");
								return 0;
							}
						else
							{
								last->copies -= 1;
								node.length -= 1;
								store_books("book.txt");
								return 0;
						}		
					}
				else		//existing borrowed book  
					printf("The books are on loan!Fail to delete it!\n");
			}
}

void delete1(){
	Book book;
	int x;
	system("cls");
	x = go_through();
	if(x == -1)  //Check if the book has been deleted. 
		{		//If so, return to the main menu.
			printf("\t\tThe library has not exist any book,\
please add some books firstly!\n");
			printf("\t\tPlease enter any key to return the main menu.\n");
			getch();
			system("cls");
			return;
		}
	printf("\n\n");
	printf("Please enter the book id:\n");
	scanf("%d",&book.id);
	fflush(stdin);
	book.title = (char*)malloc(sizeof(char)*100);
	printf("Please enter the book title:\n");
	scanf("%[^\n]",book.title);
	fflush(stdin);
	book.authors = (char*)malloc(sizeof(char)*100);
	printf("Please enter the book author(s):\n");
	scanf("%[^\n]",book.authors);
	fflush(stdin);
	printf("Please enter the book year:\n");
	scanf("%d",&book.year);
	fflush(stdin);
	printf("Please enter the book copies:\n");
	scanf("%d",&book.copies);
	fflush(stdin);
	printf("Please enter the book borrow copies:\n");
	scanf("%d",&book.brcopies);
	fflush(stdin);
	x = remove_book(book);
	if(x == 0){
		printf("You have remove the book successfully!\n");
		getch();
	}
}


