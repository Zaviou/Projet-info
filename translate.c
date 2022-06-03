#include "headers.h"

long int char_to_long(char* str){

	//Statement & Initialization :
	char *ptr=NULL;
	long int res =1000000000;

	res = strtol(str, NULL, 10);

	return res;
}

Books get_book_from_id (Books* list_book, char* id_book, int book_nb){

	//Statement & Initialization :
	int i=0, id_char=0;

	for(i=0; i<book_nb; i++){
		id_char =char_to_long(id_book);
		if(id_char==list_book[i].id){
			return list_book[i];
		}	
	}
}

int get_book_from_title (Books* list_book, char* title, int book_nb){

	//Statement & Initialization :
	int i=0;

	for(i=0; i<book_nb; i++){
		if(strcmp(title, list_book[i].title) ==0){
			return i;
		}	
	}
	return -1;
}

int get_book_from_author (Books* list_book, char* author, int book_nb){

	//Statement & Initialization :
	int i=0;

	for(i=0; i<book_nb; i++){
		if(strcmp(author, list_book[i].author) ==0){
			return i;
		}	
	}
	return -1;
}

/*
int main(){
	//Exemples of how to use all functions in this file.

	//Statement & Initialization :
	int id_nb =0;
	Id* list_id =NULL;
	long int test =1000000000;

	test =char_to_long("12345");

	return 0;
}
*/
