#include<stdio.h>>
#include<stdlib.h>
#include<string.h>
void register(){
	int student_number;
	char password[100];
	char ensure_password[100];
	int pause;
	int test_account;
	char test_password[100];
	FILE *fp;
	FILE *fp1;
	if(fopen('account.txt','r')==NULL){
		fp = fopen('account.txt','w');
		fclose(fp);
	}
	 system("cls"); //清空界面
	 fp = fopen('account.txt','a');
	for(;;){
		loop:
		printf("\nPlease enter the student number and password as the following example:\nstudent number(a string of integer) password\n");
		printf("Please enter:");
		scanf("%d %s",&student_number,password);
	//验证账号开始 
		fp1 = fopen('account.txt','r');
		if(fp1==NULL){
			printf("\nThe account is not registered\n");
	}
	else{
		for(;feof(fp1);){
			fscanf(fp,"%d %s",&test_account,test_password);
			if(test_account==student_number){
				printf("The account is registered,enter the 'Enter' to re-enter the account");
				pause = getch();
				if(pause==13){
					system("cls");
					goto loop;
				}	
			}
			else
				printf("\nThe account is not registered\n");
		}
	}
	//验证账号结束 
		printf("Please enter the password again:");
		scanf("%s",ensure_password);
		if(strcmp(password,ensure_password)==0){
			fprintf(fp,"%d %s",student_number,password);
			break;
		}
		else{
			printf("The password doesn't equal the confirmation password"\n);
			printf("If you would like to create account again,please enter the 'Enter'\n");
			printf("If you would like to exit the screen,please enter the 'Esc'");
			pause = getch();
			if(puase==27){
				system("cls");
				coremain();
			}
		}
		fclose(fp);
		printf("The account is created successfully.\n");
		printf("Please enter the 'Esc' to enter the main menu");
		pause = getch();
		if(pause==27)
			system("cls");
		coremain(); 
	}  
} 
