#include"book_management.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern BookArray node;
void borrow(){
	system("cls");
	int x;
	int id;
	Book* constant = (Book*)malloc(sizeof(Book));
	Book* last;
	constant=node.array; 
	int allborrow = 1;  //1 means all books have been borrowed 
	int pause;
	
	system("cls");
	while(1){     					//Check if the book has been checked out. 
		constant = constant->next;	//If it has been returned, return to the main menu.
		if(constant->copies!=constant->brcopies) 
		{	
			allborrow = 0;
		}
		if(constant->next==NULL)
			break;
	}	
		if(allborrow == 1)
		{
			printf("All book have been borrowed.\n\n");
			printf("Please enter any key to return the main menu.");
			getch();
			return;
		}
	while(1)
	{	
		system("cls");
		x = go_through();  //Display all the book  
		printf("Id must in the range,otherwise will return the previous menu!\n");
		printf("\nIf you would like to borrow the book by searching the book \
id,please enter :\n");
		pause = scanf("%d",&id);
		fflush(stdin);
		if(pause != 1)
		{
			printf("Please enter the right format of book id!\n");
			return;
		}
		if(id>node.length||id <= 0)
		{
			printf("The number exceed the range!\n");
			printf("You have exited the borrow function successfully!\n");
			getch();
			return;
		}
		else
		{	
			last = node.array->next;
			while(1)
			{	
				if(last->id == id)
					break;
				last = last->next;
			}
			if(last->copies>last->brcopies)
				{
					last->brcopies += 1;
					printf("You have borrow a book successfully!\n");
					store_books("book.txt");
					getch();
					break;				
				}
			else
				{
					printf("The books have all been borrowed!\n");
					getch();
					return;
				}
		}
	}
}

