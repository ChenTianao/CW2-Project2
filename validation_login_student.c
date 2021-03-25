void match(int account_user,char password_user[100]){
	FILE *fp;
	int pause;
	int account;
	char password[100];
	fp = fopen('account.txt','r');
	if(fp==NULL){
		printf("\nThe file does not exist.Please enter any key to register the account");
		getch();
		register();
	}
	else{
		for(;feof(fp);){
			fscanf(fp,"%d %s",&account,password);
			if(account_user==account){
				if(strcmp(password_user,password)==0){
					return 0;
				}
				else
					return 1;
			}
			else
				return -1;
		}
	}
	fclose(fp);//暂且不知道是否要关闭 
}
