#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void adcoreshowmenu(){
	int showmenu_number;  //to choose which function
	int partnumber;       //to choose which search function
	int n; //to store the go_through() 
	int m; //to store the search_through()
	BookArray structure;  //the search function return thing
	const char *title;
	const char *author;
	unsigned int year;
	int pause;
	while(1){
		adshowmenu();
		pause = scanf("%d",&showmenu_number);
		fflush(stdin);
		if(pause != 1)
			{
				printf("You have exit the system successfully!\n");
				exit(0);
			}
		switch(showmenu_number){		//administrator menu choice  
			case 1:
				{	
					add();
					//add book function  
					break;
				}
			case 2:
				{	
					delete1();
					//return book function  
					break;
				}
			case 3:    //search book function  
				{	
					while(1){
						system("cls");
						go_through();    //display all book  
						printf("You have entered the search system!\n");
						printf("1.Search by title\n");
						printf("2.Search by authors\n");
						printf("3.Search by year\n");
						printf("4.Return the previous menu\n");
						while(1)
						{
							pause = scanf("%d",&partnumber);
							fflush(stdin);
							if(pause != 1)  //format verification 
								printf("Please enter the right number!\n");
							else
								break;
						}
						switch(partnumber){
							case 1:
								{	//search function type choices  
									printf("Please enter the book title:\n");
									title = (char*)malloc(sizeof(char)*100);
									pause = scanf("%[^\n]",title);
									fflush(stdin);
									if(pause != 1)	//format verification
										{
											printf("Please enter the right format value!\n");
											getch();
											break;
										}
									structure =find_book_by_title (title);
									m = search_through(structure);
									break;
								}
							case 2:
								{	
									printf("Please enter the book author(s):\n");
									author = (char*)malloc(sizeof(char)*100);
									pause = scanf("%[^\n]",author);
									fflush(stdin);
									if(pause != 1)	//format verification
										{
											printf("Please enter the right format value!\n");
											getch();
											break;
										}
									structure =find_book_by_author (author);
									m = search_through(structure);
									break;
								}
							case 3:
								{	
									printf("Please enter the published year:\n");
									pause = scanf("%d",&year);
									fflush(stdin);
									if(pause != 1)	//format verification
										{
											printf("Please enter the right format value!\n");
											getch();
											break;
										}
									structure =find_book_by_year (year);
									m = search_through(structure);
									break;
								}
							case 4:
								{
									adcoreshowmenu();
									break;
								}
							default:
							{
								printf("Please enter the right number!\n");
								getch();
							}
						}
					}
					break; 
				}
			case 4:{
				n = go_through();
					//显示所有的图书 
				break;
			}
			case 5:
			{	
				coremain();
				break;
			}
			default:{
				printf("You have exit the system successfully!\n");
				exit(0);
			}
		}
	}
} 
