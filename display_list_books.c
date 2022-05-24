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

int date_comparison(long borrow_date, int type_user){
	time_t seconds;
	seconds = time(NULL);
	int comparison;
	comparison=seconds-borrow_date;
	printf("\nSeconds since january 1, 1970 = %ld\n", seconds);
	printf("borrow_date = %ld\n", borrow_date); 
	printf("Seconds since you borrowed the book = %ld\n", comparison); 
	if(type_user==1){
		if(comparison<=120){
			printf("Vous êtes dans les temps pour rendre votre livre. Gros naze\n");
		}
		else{
			printf("Vous êtes en retard pour rendre votre livre. Gros naze.\n");
		}
	}
	else{
		if(comparison<=180){
			printf("Vous êtes dans les temps pour rendre votre livre. Porofessor.\n");
		}
		else{
			printf("Vous êtes en retard pour rendre votre livre. Porofessor\n");
		}
	}
		return 0;
}

Books get_book_from_id (Books* list_book, long id_book, int book_nb){
	int i;
	for(i=0; i<book_nb; i++){
		if(id_book==list_book[i].id){
			return list_book[i];
		}	
	}
}


Books display_book(Id* list_id,char* login ,Books* list_book, int id_nb){
	int i =0,cursor_id =0;
	for(i=0;i<id_nb; i++){
		if(strcmp(login, list_id[i].login) ==0){
			cursor_id=i;
		}
	}
	printf("list_id[%d].nb_borrowed_books :%d\n", cursor_id, list_id[cursor_id].nb_borrowed_books);
	printf("Voici les livres que vous avez emprunté :\n");
	for(i=0;i<list_id[cursor_id].nb_borrowed_books;i++){
		printf("livre emprunté n°%d: %s\n", i+1, list_id[cursor_id].books[i][0]);
	}
}







int main(){
	//tmp
	long id_book=123;	
	long borrow_date=123455;
	int type_user=2;
	char* login = "aze";
	//Statement & Initialization :
	Books current_book;
	char* username;
	int id_nb =0;
	Books* list_book =NULL;
	int book_nb =0;
	list_book =read_book(&book_nb);
	Id* list_id =NULL;

//	current_book=get_book_from_id (list_book, id_book, book_nb);
//	printf("titre: %s\n", current_book);
//	date_comparison(borrow_date, type_user);
	list_id =read_id(&id_nb);
	display_book(list_id,login ,list_book, id_nb);
//	display(list_id, id_nb, "zaviou");
//	create_id(list_id, id_nb);
//	date_comparison(1, "Thu May 19 15:52:30 2022");
	return 0;
}
