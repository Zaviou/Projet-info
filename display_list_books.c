#include "headers.h"

void affiche(char** tab, int taille1, int taille2){
	int i, j;

	printf("affiche :\n");
	for(i =0; i <taille1; i ++){
		for(j =0; j <taille2; j ++){
			printf("%c", tab[i][j]);
		}
		printf("\n");
	}
	printf("fin.\n\n");
}

void triSelection_all_title(Books* list_book, int book_nb, char** list_title_sorted, int TAILLE){
	//

	//Statement & Initialization :
	int i, j, cursor =0;
	char tempo[TAILLE];

	//Allocate memory for the new list of title (list_title_sorted)
	list_title_sorted =malloc (book_nb * sizeof(char*));
	if(list_title_sorted ==NULL){
		printf("Erreur d'allocation de mémoire. Impossible de créer une liste list_title_sorted.\n");
		exit(1);
	}

	for(i =0; i <book_nb; i++){
		//Allocate memory for the new list of title (list_title_sorted[i])
		list_title_sorted[i] =malloc (TAILLE * sizeof(char*));
		if(list_title_sorted ==NULL){
			printf("Erreur d'allocation de mémoire. Impossible de créer une liste list_title_sorted[i].\n");
			exit(1);
		}
	}

	//Merge
	for(i =0; i <book_nb; i++){
		copy_string(list_title_sorted[i], list_book[i].title, TAILLE);
	}

	//Sorting
	for (i =0; i <book_nb; i++){
		for (j =i +1; j <book_nb; j++){

			//See how many letters you have in common from left to right
			cursor =0;
			while(list_title_sorted[i][cursor] ==list_title_sorted[j][cursor]){
				cursor ++;
			}

			//Exchange values in list_title_sorted if needed
			if (list_title_sorted[i][cursor] >list_title_sorted[j][cursor]){
				copy_string(tempo, list_title_sorted[i], TAILLE);
				copy_string(list_title_sorted[i], list_title_sorted[j], TAILLE);
				copy_string(list_title_sorted[j], tempo, TAILLE);
			}
		}
	}

	all_books_title(list_book, book_nb, list_title_sorted);

	free(list_title_sorted);
}

void triSelection_all_author(Books* list_book, int book_nb, char** list_author_sorted, int TAILLE){
	//

	//Statement & Initialization :
	int i, j, cursor =0;
	char tempo[TAILLE];

	//Allocate memory for the new list of author (list_author_sorted)
	list_author_sorted =malloc (book_nb * sizeof(char*));
	if(list_author_sorted ==NULL){
		printf("Erreur d'allocation de mémoire. Impossible de créer une liste list_author_sorted.\n");
		exit(1);
	}

	for(i =0; i <book_nb; i++){
		//Allocate memory for the new list of author (list_author_sorted[i])
		list_author_sorted[i] =malloc (TAILLE * sizeof(char*));
		if(list_author_sorted ==NULL){
			printf("Erreur d'allocation de mémoire. Impossible de créer une liste list_author[i].\n");
			exit(1);
		}
	}

	//Merge
	for(i =0; i <book_nb; i++){
		copy_string(list_author_sorted[i], list_book[i].author, TAILLE);
	}

	//Sorting
	for (i =0; i <book_nb; i++){
		for (j =i +1; j <book_nb; j++){

			//See how many letters you have in common from left to right
			cursor =0;
			while(list_author_sorted[i][cursor] ==list_author_sorted[j][cursor]){
				cursor ++;
			}

			//Exchange values in list_title_sorted if needed
			if (list_author_sorted[i][cursor] >list_author_sorted[j][cursor]){
				copy_string(tempo, list_author_sorted[i], TAILLE);
				copy_string(list_author_sorted[i], list_author_sorted[j], TAILLE);
				copy_string(list_author_sorted[j], tempo, TAILLE);
			}
		}
	}

	all_books_author(list_book, book_nb, list_author_sorted);

	free(list_author_sorted);
}

void triSelection_your_title(Books* list_book, Id* list_id, int book_nb, int id_cursor, char** list_title_sorted, int TAILLE){
	//

	//Statement & Initialization :
	int i, j, cursor =0;
	char tempo[TAILLE];
	Books bookt;

	//Allocate memory for the new list of title (list_title_sorted)
	list_title_sorted =malloc (book_nb * sizeof(char*));
	if(list_title_sorted ==NULL){
		printf("Erreur d'allocation de mémoire. Impossible de créer une liste list_title_sorted.\n");
		exit(1);
	}

	for(i =0; i <list_id[id_cursor].nb_borrowed_books; i++){
		//Allocate memory for the new list of title (list_title_sorted[i])
		list_title_sorted[i] =malloc (TAILLE * sizeof(char*));
		if(list_title_sorted ==NULL){
			printf("Erreur d'allocation de mémoire. Impossible de créer une liste list_title_sorted[i].\n");
			exit(1);
		}
	}

	//Merge
	for(i =0; i <list_id[id_cursor].nb_borrowed_books; i++){
		bookt =get_book_from_id (list_book, list_id[id_cursor].books[i][0], book_nb);
		copy_string(list_title_sorted[i], bookt.title, TAILLE);
	}

	//Sorting
	for (i =0; i <list_id[id_cursor].nb_borrowed_books; i++){
		for (j =i +1; j <list_id[id_cursor].nb_borrowed_books; j++){

			//See how many letters you have in common from left to right
			cursor =0;
			while(list_title_sorted[i][cursor] ==list_title_sorted[j][cursor]){
				cursor ++;
			}

			//Exchange values in list_title_sorted if needed
			if (list_title_sorted[i][cursor] >list_title_sorted[j][cursor]){
				copy_string(tempo, list_title_sorted[i], TAILLE);
				copy_string(list_title_sorted[i], list_title_sorted[j], TAILLE);
				copy_string(list_title_sorted[j], tempo, TAILLE);
			}
		}
	}

	your_books_title(list_id, list_book, id_cursor, book_nb, list_title_sorted);

	free(list_title_sorted);
}

int date_comparison(long borrow_date, int type_user, int* comparison){
	//

	//Statement & Initialization :
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

void all_books_title(Books* list_book, int book_nb, char** title){
	//

	//Statement & Initialization :
	int i, cursor =-1;

	printf("Voici la liste des livres de notre bibliothèque\n\n");
	for(i=0;i <book_nb;i++){
		cursor =get_book_from_title(list_book, title[i], book_nb);
		printf("\"%s\" par %s\n", title[i], list_book[cursor].author);
		if(list_book[cursor].taken==1){
			printf(ANSI_COLOR_RED "déjà emprunté\n\n" ANSI_COLOR_RESET);
		}
		else{
			printf(ANSI_COLOR_BLUE "disponible\n\n" ANSI_COLOR_RESET);
		}
	}
}

void all_books_author(Books* list_book, int book_nb, char** author){
	//

	//Statement & Initialization :
	int i, cursor =-1;

	printf("Voici la liste des livres de notre bibliothèque\n\n");
	for(i=0;i <book_nb;i++){
		cursor =get_book_from_author(list_book, author[i], book_nb);
		printf("\"%s\" par %s\n", list_book[cursor].title, author[i]);
		if(list_book[cursor].taken==1){
			printf(ANSI_COLOR_RED "déjà emprunté\n\n" ANSI_COLOR_RESET);
		}
		else{
			printf(ANSI_COLOR_BLUE "disponible\n\n" ANSI_COLOR_RESET);
		}
	}
}

void your_books_title(Id* list_id, Books* list_book, int id_cursor, int book_nb, char** title){
	//

	//Statement & Initialization :
	int i, cursor =-1;

	printf("Voici les livres que vous avez emprunté :\n\n");
	for(i=0;i <list_id[id_cursor].nb_borrowed_books; i++){
		cursor =get_book_from_title(list_book, title[i], book_nb);
		printf("\"%s\" par %s\n", title[i], list_book[cursor].author);
		if(list_book[cursor].taken==1){
			printf(ANSI_COLOR_RED "déjà emprunté\n\n" ANSI_COLOR_RESET);
		}
		else{
			printf(ANSI_COLOR_BLUE "disponible\n\n" ANSI_COLOR_RESET);
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
	char** list_title_sorted;
	char** list_author;

//	printf("titre: %s\n", current_book);
//	date_comparison(borrow_date, type_user);

	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);

//	display_book(list_id,login ,list_book, id_nb, book_nb);
//	display(list_id, id_nb, "zaviou");
//	triSelection_all_title(list_book, book_nb, list_title_sorted, SIZE_MAX);
//	triSelection_all_author(list_book, book_nb, list_author, SIZE_MAX);
	triSelection_your_title(list_book, list_id, book_nb, 0, list_title_sorted, SIZE_MAX);

	return 0;
}

