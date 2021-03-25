#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"book_management.h"

int totalbook;
int kindbook = 0;  //the kinds of book 
int line = 0;	//the text has how many lines  
BookArray node; //It's used to store information about all the books.Including adding, deleting, borrowing, reading and returning.
int main(void){
	node.array = (Book*)malloc(sizeof(Book));
	node.array->next = NULL;
	node.length = 0;
	load_books("book.txt");
	coremain(); //mainmenu 
	return 0;
}
