#include "headers.h"
/*
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
*/
void triSelection_all_title(Books* list_book, int book_nb, int TAILLE){
	//

	//Statement & Initialization :
	int i, j, cursor =0;
	char tempo[TAILLE];
	char** list_title_sorted;

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

	all_books_title(list_book,book_nb, list_title_sorted);
	free(list_title_sorted);
}

void triSelection_all_author(Books* list_book, int book_nb, int TAILLE){
	//

	//Statement & Initialization :
	int i, j, cursor =0;
	char tempo[TAILLE];
	char** list_author_sorted;

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

void triSelection_your_title(Books* list_book, Id* list_id, int book_nb, int id_cursor, int TAILLE){
	//

	//Statement & Initialization :
	int i, j, cursor =0;
	char tempo[TAILLE];
	Books bookt;
	char** list_title_sorted;

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

	if(list_id[id_cursor].nb_borrowed_books ==0){
		printf("Vous n'avez pas encore emprunter de livre\n");
	}else{
		your_books_title(list_id, list_book, id_cursor, book_nb, list_title_sorted);
	}

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

void look_for_by_title(Books* list_book, int book_nb){
	//

	//Statement & Initialization :
	char title[SIZE_MAX];
	int cursor_book =-1;

	scan_text("Vous avez choisi de rechercher un livre par son titre\nVeuillez indiquer le titre du lire que vous cherchez", title, SIZE_MAX);
	cursor_book =get_book_from_title (list_book, title, book_nb);

	//Show the users the result of the research
	if(cursor_book ==book_nb){
		printf("Il n'y a pas ce livre au sein de notre bibliothèque\n");
	} else {
		printf("Au sein de la bibliothèque vous pouvez trouver : \"%s\" par %s\n", list_book[cursor_book].title, list_book[cursor_book].author);
		if(list_book[cursor_book].taken==1){
			printf(ANSI_COLOR_RED "Mais il est déjà emprunté\n\n" ANSI_COLOR_RESET);
		}
		else{
			printf(ANSI_COLOR_BLUE "Vous avez de la chance, il est disponible !\n\n" ANSI_COLOR_RESET);
		}
	}
}


void look_for_by_author(Books* list_book, int book_nb){
	//

	//Statement & Initialization :
	char author[SIZE_MAX];
	int nb_book =0, i =-1;

	//Ask the user what author he wants to look for
	scan_text("Vous avez choisi de rechercher un livre par son auteur\nVeuillez indiquer l'auteur dont vous voulez chercher les livres", author, SIZE_MAX);

	//Finding books
	for(i =0; i <book_nb; i++){
		if(strcmp(author, list_book[i].author) ==0){
			nb_book ++;

			if(nb_book ==1){
				printf("\nVoici les livres écrit par " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET " au sein de la bibliothèque :\n\n", author);
			}

			//Show the users the result of the research
			printf("\"%s\"\n", list_book[i].title);
			if(list_book[i].taken==1){
				printf(ANSI_COLOR_RED "Mais il est déjà emprunté\n\n" ANSI_COLOR_RESET);
			}
			else{
				printf(ANSI_COLOR_BLUE "Vous avez de la chance, il est disponible !\n\n" ANSI_COLOR_RESET);
			}
		}
	}

	//Indicates if there is no books found
	if(nb_book ==0){
		printf("\nDésolée, il n'y a pas de livre dans la bibliothèque écrit par " ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, author);
	}
}

void look_for_by_genre(Books* list_book, int book_nb){
	//

	//Statement & Initialization :
	int nb_book =0, i =-1;
	int genre =-1;
	char* genre0 ="Action";
	char* genre1 ="Aventures";
	char* genre2 ="Comédie";
	char* genre3 ="Horreur";
	char* genre4 ="Romance";
	char* genre5 ="Science-fiction";
	char* genre6 ="Tragédie";
	char* genre7 ="Mystère";
	char* genre8 ="Didactique";
	char* genre9 ="Historique";
	char** genrex =NULL;

	//Genre
	genre =scan_int("Vous avez choisi de rechercher un livre par son genre\n\nVoici les genres de livres existants\n0. Action\n1. Aventures\n2. Comédie\n3. Horreur\n4. Romance\n5. Science-fiction\n6. Tragédie\n7. Mystère\n8. Didactique\n9. Historique\n\nVeuillez indiquer le genre de livres que vous voulez rechercher", 0, 9);
	switch (genre){
		case 0 :
			genrex =&genre0;
		break;
		case 1 :
			genrex =&genre1;
		break;
		case 2 :
			genrex =&genre2;
		break;
		case 3 :
			genrex =&genre3;
		break;
		case 4 :
			genrex =&genre4;
		break;
		case 5 :
			genrex =&genre5;
		break;
		case 6 :
			genrex =&genre6;
		break;
		case 7 :
			genrex =&genre7;
		break;
		case 8 :
			genrex =&genre8;
		break;
		default :
			genrex =&genre9;
	}

	//Finding books
	for(i =0; i <book_nb; i++){
		if(strcmp(*genrex, list_book[i].genre) ==0){
			nb_book ++;

			if(nb_book ==1){
				printf("\nVoici les livres de genre " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET " au sein de la bibliothèque :\n\n", *genrex);
			}

			//Show the users the result of the research
			printf("\"%s\" par \"%s\"\n", list_book[i].title, list_book[i].author);
			if(list_book[i].taken==1){
				printf(ANSI_COLOR_RED "Mais il est déjà emprunté\n\n" ANSI_COLOR_RESET);
			}
			else{
				printf(ANSI_COLOR_BLUE "Vous avez de la chance, il est disponible !\n\n" ANSI_COLOR_RESET);
			}
		}
	}

	//Indicates if there is no books found
	if(nb_book ==0){
		printf("\nDésolée, il n'y a pas de livre " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET " dans la bibliothèque\n", *genrex);
	}

}
/*
int main(){
	//Exemples of how to use all functions in this file.

	//Statement & Initialization :
	Books* list_book =NULL;
	Id* list_id =NULL;
	int id_nb =0, book_nb =0;

	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);

//	date_comparison(borrow_date, type_user);
//	triSelection_all_title(list_book, book_nb, SIZE_MAX);
//	triSelection_all_author(list_book, book_nb, SIZE_MAX);
//	triSelection_your_title(list_book, list_id, book_nb, 0, SIZE_MAX);
//	look_for_by_title(list_book, book_nb);
//	look_for_by_author(list_book, book_nb);
//	look_for_by_genre(list_book, book_nb);

	return 0;
}
*/
