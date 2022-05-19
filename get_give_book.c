#include "headers.h"

void get_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title){
	//

	//Statement & Initialization :
	int i =0, book_cursor =0;

	//Find the id's book
	for(i =0; i <book_nb; i++){
		if(strcmp(title, list_book[0].title) ==0){
			printf("list_book[%d].title :%s !\n", i, list_book[0].title);
			book_cursor =i;
		}
	}

	//Find the date

	//Add the book in the id's list (list_id.books)
}

void give_book();

int main(){
	//

	//Statement & Initialization :
	Books* list_book=NULL;
	int book_nb =0;
	Id* list_id =NULL;
	int id_nb =0;

	list_book =read_book(&book_nb);
	list_id =read_id(&id_nb);

	get_book(list_id, list_book, book_nb, id_nb, 0, "aze");

	return 0;
}
