void delete(struct Node* lastx){
	system("cls");
	struct Node* previous;
	struct Node* last;
	struct Node* constant;
	constant = lastx ;  //临时结点，一直指向头结点（或者说一直指向那个地址）
	last = lastx; 
	char namepy[100];
	int pause; 
	int choice;
	if(last->next=NULL)  //先判断书被删除完了吗，若有就返回主菜单了 
		{
			printf("\t\tAll book have been borrowed or delete.\n\n");
			printf("\t\tPlease enter any key to return the main menu.");
			getch();
			coreshowmenu();
		}
	printf("\t\tIf you would like to delete the book by searching the book name,please enter the book name.\n\n");
	scanf("%s",namepy);
	while(last->next=NULL)
	{		
		previous=last;
		last = last->next;
		if(strcmp(last->data.title,namepy)==0)
			break;
	}
	if(last->next=NULL)
		{
			printf("\t\tPlease re-enter the book name, the system could not find it.\n\n");
			delete(constant);
		}
	else
		{
			printf("Do you want to delete one of them or all of them?\n 1. ONE \n 2. ALL\n\n");
			scanf("%d",&choice);
			if(choice==2)
			{
				previous->next=last->next;
				free(last);
			}
			else
			{
				if(last->data.copies==1)
				{
					previous->next=last->next;
					free(last);
				}
				last->data.copies -= 1;
			}
			
			printf("\t\tYou have delete it successfully!\n\n");
		}
	printf("\t\tIf you would like to continue to delete the book,please enter the any key except 'Esc'\n\n");
	printf("\t\tIf you would like to return the main menu,please enter the 'Esc'\n\n")
	pause=getch();
	if(pause==27){
		coreshowmenu();
	}
	else
		delete(constant);
} 
