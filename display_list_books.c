#include "headers.h"

int date_comparison(long borrow_date, int type_user, long int* comparison){
	/*
	This function calculates if the user is late or not to return the books he borrowed. The time allowed to keep the book is 120 seconds for a student and 180 seconds for a teacher. It returns 1 if the user is not late and 0 if he is.
	*/
	time_t seconds;
	seconds = time(NULL);
	(*comparison)=seconds-borrow_date;
	if(type_user==1){
		if(*comparison<=120 && *comparison>0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if(*comparison<=180 && *comparison>0){
			return 1;
		}
		else{
			return 0;
		}
	}
}

Books get_book_from_id (Books* list_book, char* id_book, int book_nb){
	/*
	This function uses an ID of a book and returns the book's information after recognizing the ID.
	*/
	int i, id_char;
	for(i=0; i<book_nb; i++){
		id_char=char_to_long(id_book);
		if(id_char==list_book[i].id){
			return list_book[i];
		}	
	}
}


void display_book(Id* list_id ,char* login ,Books* list_book ,int id_nb, int book_nb){
	/*
	This function prints the list of the books borrowed with the name and the author. It also prints the time remaining to return it, if the time has passed the name and author of the book are written in red.
	
	list_id: list of ids contained in the ID's file (id.txt).
	login: login of the user ~~~~~
	id_nb: 
	book_nb:
	*/
	int i =0, cursor_id =0;
	long int* comparison;
	Books current_book;
	for(i=0;i<id_nb; i++){
		if(strcmp(login, list_id[i].login) ==0){
			cursor_id=i;
		}
	}
	if(list_id[cursor_id].nb_borrowed_books==0){
		printf("Vous n'avez emprunté aucun livre.\n\n");
	}
	else{
		printf("\nVoici les livres que vous avez emprunté :\n\n\n");
		for(i=0;i<list_id[cursor_id].nb_borrowed_books;i++){
			current_book =get_book_from_id (list_book, list_id[cursor_id].books[i][0], book_nb);
			if(date_comparison(char_to_long(list_id[cursor_id].books[i][1]), list_id[cursor_id].role, comparison)==1){
				printf("\"%s\" par %s\n", current_book.title, current_book.author);
				printf("Il vous reste %d de secondes pour le rendre.\n\n", 120-(*comparison));
			}
			else{
				printf(ANSI_COLOR_RED "\"%s\" par %s\n\n" ANSI_COLOR_RESET, current_book.title, current_book.author);
			}
		}
	}
}







/*int main(){
	//tmp
	long id_book=123;
	int type_user=2;
	char* login = "Zaviou";
	//Statement & Initialization :
	Books current_book;
	int id_nb =0;
	Books* list_book =NULL;
	int book_nb =0;
	Id* list_id =NULL;

//	current_book=get_book_from_id (list_book, id_book, book_nb);
//	printf("titre: %s\n", current_book);
//	date_comparison(borrow_date, type_user);
	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);
	display_book(list_id,login ,list_book, id_nb, book_nb);
//	display(list_id, id_nb, "zaviou");
//	create_id(list_id, id_nb);
//	date_comparison(1, "Thu May 19 15:52:30 2022");
	return 0;
}
*/
