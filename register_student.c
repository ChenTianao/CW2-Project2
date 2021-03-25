#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"user_management.h"
void register1(){
	int student_number;   //the account number(a string of number) 
	char password[100];   
	char ensure_password[100];   //to let user ensure what exaclty is the password
	int pause;
	int test_account;
	char test_password[100];
	FILE *fp;
	
	system("cls"); 			//clear the interface  
	while(1){	   			//the loop concerns account(a,b) 
		while(1){			//Account Format Verification(a) 
			printf("\nPlease enter the student number(a string of integer):\n");
			printf("Please enter:");
			pause = scanf("%d",&student_number);
			fflush(stdin);
			if(pause != 1)
				printf("You have enter the wrong student number\
please notice the format!\n");
			else
				break;
			}
		//judge if the account is registered(b)
		fp = fopen("account.txt","a+"); 
		if(fp==NULL){
			printf("\nThe account is not registered\n");
		fclose(fp);
		}
		else{
			for(;!feof(fp);){
				fscanf(fp,"%d %s ",&test_account,test_password);
				if(test_account==student_number){
					printf("The account is registered\n");
					getch();
					return;
				}
			}
			printf("The account is not registered\n");
			fclose(fp);
			break;
		}
	} 
	//the loop concerns account ends
	//Password Format Verification
	while(1){
		printf("\nPlease enter the password:\n");
		printf("Please enter:");
		pause = scanf("%s",password);
		fflush(stdin);
		if(pause != 1)
			printf("You have enter the wrong password\
please notice the format!\n");
		else
			break;
		}
	while(1){
		printf("Please enter the password again:");
		scanf("%s",ensure_password);
		fflush(stdin);
		if(strcmp(password,ensure_password)==0){
			fp = fopen("account.txt","a+");
			fprintf(fp,"%d %s ",student_number,password);
			fclose(fp);
			break;
		}
		else{
			printf("The password doesn't equal the confirmation password\n");
			getch();
		}
	}
		printf("The account is created successfully.\n");
		getch();
} 
