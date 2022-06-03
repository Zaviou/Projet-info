#include "headers.h"

void start(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id){

	//Statement & Initialization :
	int answer =0;

	PRESENTATION
	printf("Bienvenue dans la bibliothèque de CY-TECH!\n\n");
	answer =scan_int("Que souhaitez-vous faire ?\n1. Se connecter\n2. S'identifier\n", 1, 2);

	//Connect
	if(answer==1){
		PRESENTATION
		connect(list_book, list_id, id_nb, book_nb, cursor_id);
		book_management (list_book, list_id,  id_nb, book_nb, cursor_id);
	}

	//Identification
	else if(answer==2){
		PRESENTATION
		create_id(list_id, &id_nb);
		*cursor_id =id_nb -1;
		book_management (list_book, list_id,  id_nb, book_nb, cursor_id);
	}
}

void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id){

	//Statement & Initialization :
	int answer=0, right =0;
	char title[SIZE_MAX] ={0};

	PRESENTATION

	triSelection_your_title( list_book, list_id, book_nb, *cursor_id, SIZE_MAX);
	printf("Quelle action souhaitez-vous réaliser ?\n");
	printf("1. Emprunter un nouveau livre\n"); 
	printf("2. Rendre un livre\n");

	//Dissociate the case : user is a student from the case : student is a teacher
	if(list_id[*cursor_id].role==1){
		printf("3. Se déconnecter.\n\n\n");
		answer=scan_int("", 1, 3);
	}else{
		printf("3. Ajouter un livre à la bibliothèque\n");
		printf("4. Se déconnecter.\n\n\n");
		answer=scan_int("", 1, 4);
	}

	//Borrow book
	if(answer==1){

		PRESENTATION
		triSelection_your_title(list_book, list_id, book_nb, *cursor_id, SIZE_MAX);
		scan_text("Appuyez sur 0 pour quitter,\n1 pour lancer une recherche par auteur,\n2 pour lancer une recherche par genre,\nou indiquer le titre du livre que vous souhaitez emprunter", title, SIZE_MAX);

		//Quit
		if(title[0]=='0'){
			book_management (list_book, list_id, id_nb, book_nb, cursor_id);
		}

		//Look by author
		else if(title[0]=='1'){
			PRESENTATION
			triSelection_all_author(list_book, book_nb, SIZE_MAX);
			look_for_by_author(list_book, book_nb);
		}

		//Look by genre
		else if(title[0]=='2'){
			PRESENTATION
			look_for_by_genre(list_book, book_nb);
		}

		//Borrow book
		else {
			right =right_to_borrow(list_id, list_book, book_nb, id_nb, *cursor_id, title);
			if(right ==0){
				get_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
				book_management(list_book, list_id, id_nb, book_nb, cursor_id);
			}else{
				book_management(list_book, list_id, id_nb, book_nb, cursor_id);
			}
		}
	}

	//Return book
	else if(answer==2){

		PRESENTATION
		triSelection_your_title(list_book, list_id, book_nb, *cursor_id, SIZE_MAX);
		scan_text("Quel livre souhaitez-vous rendre ?\n", title, SIZE_MAX);

		right =right_to_give_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
		if(right ==0){
			give_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
			book_management(list_book, list_id, id_nb, book_nb, cursor_id);
		}else{
			book_management(list_book, list_id, id_nb, book_nb, cursor_id);
		}

	}

	//Add book to the library
	else if(answer==3 && list_id[*cursor_id].role==2){
		create_book(list_book, book_nb);
		book_management (list_book, list_id, id_nb, book_nb, cursor_id);
	}

	//Add book to the library
	else if(answer==4 || (answer==3 && list_id[*cursor_id].role==1)){
		start(list_book, list_id, id_nb, book_nb, cursor_id);
	}
}
