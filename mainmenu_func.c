#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"user_management.h"
void coremain(){
	int menu_number;  //to store the choice
	int a;  //to store return number
	void register1();
	int facelogin();
	int pause;
	
	system("cls");
	while(1){
		mainmenu();
		pause = scanf("%d",&menu_number);
		fflush(stdin);
		if(pause != 1)
			{
				printf("You have exit the system successfully!\n");
				exit(0);
			}
		switch(menu_number){
			case 1:
				{
					a = facelogin(); //login function for user  
					if(a == 0){
						coreshowmenu();  //book management system for user  
					}
					break;
				}
			case 2:
				{
					register1(); //register function  
					break;
				}
			case 3:
				{
					a = adlogin();    //login function for administrator  
					if(a == 0){
						adcoreshowmenu();   //book management system for administrator  
					}
					break;
				}
			default:{
				printf("You have exit the system successfully!\n");
				exit(0);   //to exit the register system
			}
		}
	}
}
