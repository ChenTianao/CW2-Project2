int search_through(BookArray go){
	int loop;
	if(go.length==0){
		return -1;
	}
	Book* loop = (Book*)malloc(sizeof(Book));
	loop = go.array->next;
	printf("The details in Books of the library are follows:\n\
			Id\tTitle\tAuthor(s)\tCopies\tBorrow_copies\n");
	for(;;){
		if(loop=NULL)
			break;
		printf("%-d %-s %-s %d %d\n",loop->id,loop->title,loop->authors,
		loop->copies,loop->brcopies);
		loop = loop->next;
	}
	return 0;
}
