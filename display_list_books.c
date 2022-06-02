#include "headers.h"

int date_comparison(long borrow_date, int type_user, int* comparison){

	time_t seconds;
	seconds = time(NULL);
	
//	printf("%ld\n", seconds);
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
	int i, id_char;
	for(i=0; i<book_nb; i++){
		id_char=char_to_long(id_book);
		if(id_char==list_book[i].id){
			return list_book[i];
		}	
	}
}


void display_book(Id* list_id, char* login, Books* list_book, int id_nb, int book_nb, int* cursor_id){
	

	int i =0;
	int comparison =0;
	Books current_book;

	if(list_id[*cursor_id].nb_borrowed_books==0){
		printf("\nVous n'avez emprunté aucun livre.\n\n");
	}

	else{
		printf("\nVoici les livres que vous avez emprunté :\n\n");

		for(i=0;i<list_id[*cursor_id].nb_borrowed_books;i++){

			current_book =get_book_from_id (list_book, list_id[*cursor_id].books[i][0], book_nb);

			if(date_comparison(char_to_long(list_id[*cursor_id].books[i][1]), list_id[*cursor_id].role, &comparison)==1){
				printf("\"%s\" par %s\n", current_book.title, current_book.author);
				printf("Il vous reste %d secondes pour le rendre.\n\n", 120-(comparison));
			}
			else{
				printf(ANSI_COLOR_RED "\"%s\" de %s\n\n" ANSI_COLOR_RESET, current_book.title, current_book.author);
			}
		}
	}
}

void all_books(Books* list_book, int book_nb){
	int i;
	printf("Voici la liste des livres de notre bibliothèque\n\n");
	for(i=0;i<book_nb;i++){
		printf("\"%s\" par %s\n", list_book[i].title, list_book[i].author);
		if(list_book[i].taken==1){
		printf(ANSI_COLOR_RED "déjà emprunté\n\n" ANSI_COLOR_RESET);
		}
		else{
		printf(ANSI_COLOR_BLUE "disponible\n\n" ANSI_COLOR_RESET);
		}	
	}
}




/*
int main(){
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
