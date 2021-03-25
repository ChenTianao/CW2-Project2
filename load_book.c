//这时last 将会变为头结点 
void readbook(struct Node* lastx){
	struct Node* newNode;
	struct Node* last;
	int i = 0;
	char buf[300];
	last = lastx;     
	FILE *fp;
	fp = fopen("book.txt","r+");
	if(fp!=NULL)
	{
		while(i<kindbook)
		{	
			fgets(buf, 300, fp);
			sscanf(buf,"ID:%d\n", &newNode->data.id);
			fgets(buf, 300, fp);
			sscanf(buf, "Book Title:\%[^\n]",newNode->data.title);
			fgets(buf, 300, fp);
			sscanf(buf,"Author(s):\%[^\n]",newNode->data.authors);
			fgets(buf, 300, fp);
			sscanf(buf,"Year:%d\n", &newNode->data.year);
			fgets(buf, 300, fp);
			sscanf(buf,"Copies:%d\n", &newNode->data.copies);
			fgets(buf, 300, fp);
			sscanf(buf,"Borrow_Copies:%d\n", &newNode->data.brcopies);
			newNode = (struct Node*)malloc(sizeof(struct Node)); //创立结点，以便接受读取的信息 
      		newNode->next = last;
			last->next = NULL;
			i++;
		}
		fclose(fp);
  	}
  	else 
	{
   		printf("\t\tFailing to load the book.txt,please check it!\n\n");
		getch();
		coremain();
  	}
}
