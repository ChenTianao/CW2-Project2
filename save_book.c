void savebook(struct Node* last){
	struct Node* headNode;
	headNode = last;
	totalbook = 0;
	kindbook = 0;
	FILE *fp;
	fp = fopen("book.txt","w+");
	if(fp!=NULL){
		while(headNode->next!=NULL){
			headNode = headNode->next;
			fprintf(fp, "ID:%d\n", headNode->data.id);
			fprintf(fp, "Book Title:%s\n", headNode->data.title);
			fprintf(fp,"Author(s):%s\n",headNode->data.authors);
			fprintf(fp,"Year:%d\n",headNode->data.year);
			fprintf(fp,"Copies:%d\n",headNode->data.copies);
			fprintf(fp,"Borrow_Copies:%d\n",headNode->data.brcopies);
			totalbook += headNode->data.copies;
			kindbook += 1;
		}
		fclose(fp);
	}
	else
		{	
			printf("\t\tFailing to open the book.txt,please check it!\n\n");
			getch();
			coremain();
		}
}
