void coremain(){
	mainmenu();
	int menu_number;
	void register();
	void facelogin()�� 
	void correct();
	scanf("%d",&menu_number);
	switch(menu_number){
		case 1:
			{
			facelogin()�� //�����˺ŵĽ��溯��
			break;
			}
		case 2:
			{
			register(); //ע����� 
			break;
			}
		case 3:
			{
			//������Ľ��溯��
			break;
			}
		case 4:
			exit(); 
	}
}
