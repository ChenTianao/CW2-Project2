#include"book_management.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern BookArray node;
void back(){
	system("cls");
	Book* constant = (Book*)malloc(sizeof(Book));
	Book* last;
	constant=node.array; 
	int allreturn= 1 ;
	int id;
	int x;
	int pause;
	
	system("cls");
	while(1){                                        //Check if the book has been all returned.
		constant = constant->next;					//If so, return to the main menu.
		if(constant->copies!=constant->brcopies) 
		{
			allreturn = 0;
		}
		if(constant->next==NULL)
			break;
	}
		if(allreturn == 1)
		{
			printf("\t\tAll book have been returned.\n\n");
			printf("\t\tPlease enter any key to return the main menu.");
			getch();
			return;
		}
	while(1){
		system("cls");
		x = go_through();  //Display all books  
		printf("Id must in the range,otherwise will return the previous menu!\n");
		printf("If you would like to return the book by searching the book \
id,please enter the book id:\n");
		pause = scanf("%d",&id);
		fflush(stdin);
		if(pause != 1)		//format validation  
			{
				printf("Please enter the right format of book id!\n");
				return;
			}
		if(id>node.length||id <= 0)		//Unreasonable value
		{
			printf("The number exceed the range!\n");
			printf("You have exited the borrow function successfully!\n");
			getch();
			return;
		}
		else{
			last = node.array->next;
			while(1)
			{	
				if(last->id == id)
					break;
				last = last->next;
			}
			if(last->brcopies<=0)		//this kind of book has been all returned  
			{
				printf("This kind of book has been all returned,\
please check if you write the wrong id\n");
				getch();
				return;
			}
			else
			{
				last->brcopies -= 1;
				printf("You have return a book successfully!\n");
				store_books("book.txt");
				getch();
				break;
			}
		}
	}
}
	

