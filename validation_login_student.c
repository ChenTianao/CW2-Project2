#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"user_management.h"
int match(int account_user,char password_user[100]){
	FILE* fp;
	int pause;
	int account;
	char password[100];
	fp = fopen("account.txt","r+");
	if(fp==NULL){
		printf("\nThe file does not exist.\
Please enter any key to register the account\n");
		getch();
		return -2;
	}
	else{
		for(;!feof(fp);){
			fscanf(fp,"%d %s ",&account,password); 
			if(account_user==account){
				if(strcmp(password_user,password)==0){
					return 0;   //all right
				}
				else
					return 1;  //password is not right
			}

		}
		return -1;  // username are not rigt
	}
	fclose(fp);
}

