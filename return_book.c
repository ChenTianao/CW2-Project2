void back(struct Node* lastx){
	system("cls");
	FILE *fp;
	struct Node* constant;
	struct Node* constant_1;
	struct Node* previous;
	struct Node* last;
	constant=lastx;     //�̶�ָ�룬Ϊ�˷��� 
	constant_1=lastx;   //�̶�ָ�룬Ϊ�˷���+1 
	last = lastx;
	char namebr[100];
	int pause;
	int allreturn= 1 ;
	while(1){                                      // �ж��鱻������������������ˣ��ͷ������˵� 
		constant_1 = constant_1->next;
		if(constant_1->data.copies!=contant_1->data.brcopies) 
		{
			allreturn = 0;
		}
		if(allreturn==1)
		{
			printf("\t\tAll book have been returned.\n\n");
			printf("\t\tPlease enter any key to return the main menu.");
			getch();
			coreshowmenu();
		}
	}
	printf("\t\tIf you would like to return the book by searching the book name,please enter the book name\n\n");
	scanf("%s",namebr);
	while(last->next=NULL)
	{		
		previous=last;
		last = last->next;
		if(strcmp(last->data.title,namebr)==0)
			break;
	}
	if(last->next=NULL)
		{
			printf("\t\tPlease re-enter the book name, the system could not find it.\n\n");
			getch();   //�Ҿ��ÿ��Լ�һ��
			back(constant);
		}
	else	
	{
		if(last->data.copies>last->data.brcopies) 
		{
			last->data.brcopies+=1;
			printf("\t\tYou have return it successfully!\n\n");
			//�����һ��sava������ÿ�ɹ�����һ�ξ����´����ļ� 
		}
		else
			{
				printf("\t\tThe book has been all returned,please check if you type the wrong book name.\n\n");
				getch();   //�Ҿ��ÿ��Լ�һ��
				back(constant);
			}
	}
	printf("\t\tIf you would like to continue to borrow the book,please enter the any key except 'Esc'\n\n");
	printf("\t\tIf you would like to return the main menu,please enter the 'Esc'\n\n")
	pause=getch();
	if(pause==27){
		fclose(fp);
		coreshowmenu();
	}
	else
		back(constant);
	//�����Ϊ������ һ��ѭ���ҵ�ͼ��Ȼ��ɾȥ�� ������������һ�������ļ��� 
	
}
