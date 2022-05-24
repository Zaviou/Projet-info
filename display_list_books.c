#include "headers.h"

void display(Id* list_id, int id_nb, char* login){
	int i,cursor;
	for(i=0;i<id_nb; i++){
		if(strcmp(login, list_id[i].login) ==0){
			cursor=i;
		}
	}

	printf("list_id[cursor].nb_borrowed_books : %d !\n", list_id[cursor].nb_borrowed_books);
	printf("Vous avez emprunté les livres suivant :\n");
	for(i=0;i<list_id[cursor].nb_borrowed_books; i++){
		printf("%s\n",list_id[cursor].books[i][0]);
		printf("%s\n",list_id[cursor].books[i][1]);
	}
}

int date_comparison(long borrow_date, int type_user, long int* comparison){
	time_t seconds;
	seconds = time(NULL);
	printf("seconds %ld\n", seconds);
	printf("borrow_date %ld\n", borrow_date);
	(*comparison)=seconds-borrow_date;
	printf("comparison %ld\n", *comparison);
	if(type_user==1){
		if(*comparison<=120){
//			printf("c'est bon\n");
			return 1;
		}
		else{
//			printf("c'est pas bon\n");
			return 0;
		}
	}
	else{
		if(*comparison<=180){
//			printf("c'est bon\n");
			return 1;
		}
		else{
//			printf("c'est pas bon\n");
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


void display_book(Id* list_id ,char* login ,Books* list_book ,int id_nb, int book_nb){
	int i =0,cursor_id =0;
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
			printf("\"%s\" par %s\n", current_book.title, current_book.author);
//			printf("retourné :%d\n", date_comparison(char_to_long(list_id[cursor_id].books[i][1]), list_id[cursor_id].role, comparison));
			if(date_comparison(char_to_long(list_id[cursor_id].books[i][1]), list_id[cursor_id].role, comparison)==1){
				printf("Vous êtes dans les temps pour rendre votre livre, il vous reste %d de secondes pour le rendre.\n\n", 120-(*comparison));
			}
			else{
				printf("Vous êtes en retard pour rendre votre livre.\n\n");
			}
		}
	}
}







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
