#include "headers.h"

char* get_date(){
	//

	//Statement & Initialization :
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo =localtime(&rawtime);

	return asctime(timeinfo);
}

void delete_book_from_file(int book_cursor){

}

void get_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title){
	//

	//Statement & Initialization :
	int i =0, book_cursor =0;
	char* date =NULL;
	char** tmp =NULL;

	//Find the id's book
	for(i =0; i <book_nb; i++){
		if(strcmp(title, list_book[i].title) ==0){
			book_cursor =i;
		}
	}

	//Get the date
	date =get_date();
	date[24] ='\0';

		//Add the book in the id's list (list_id[id_cursor].books)
	//Increase the lenght of the book list (list_id[id_cursor].books) of 1
	tmp =realloc(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books -1], (list_id[id_cursor].nb_borrowed_books) *sizeof(char**));
	if(tmp ==NULL){
		printf("Impossible d'augmenter la taille de la list (list_id[%d].books).\n", id_cursor);
		exit(1);
	}
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books] =tmp;

	//Add the values
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][0] =list_book[book_cursor].id;
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][1] =date;

	//Change the book's status in the book list (list_book[book_cursor].taken)
	list_book[book_cursor].taken =0;

	//Write in the files (book.txt and id.txt)

	free(tmp);
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

	get_book(list_id, list_book, book_nb, id_nb, 0, "ert");

	return 0;
}
