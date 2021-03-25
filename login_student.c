void facelogin(){
	int account;
	int n;
	char password[100];
	void match();
	printf("\n\nPlease enter the Student number \n");
	scanf("%d",&account);
	loop:
	printf("\nPlease enter the Password\n");
	scanf("%s",password);
	n = match(account,password);
	if(n==0)
	{
		printf("You enter the system successfully!\nEnter any key to continue!");
		getch();
		showmenu();
	}
	else if(n==1){
		printf("The password is wrong");
		getch();
		goto loop;
	}
	else{
		printf("The account does not exist");
		getch();
		system("cls");
		facelogin();
	}
	
}
