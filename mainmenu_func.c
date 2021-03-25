void coremain(){
	mainmenu();
	int menu_number;
	void register();
	void facelogin()； 
	void correct();
	scanf("%d",&menu_number);
	switch(menu_number){
		case 1:
			{
			facelogin()； //输入账号的界面函数
			break;
			}
		case 2:
			{
			register(); //注册界面 
			break;
			}
		case 3:
			{
			//改密码的界面函数
			break;
			}
		case 4:
			exit(); 
	}
}
