#include "headers.h"

void start(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id){
	int answer;
	PRESENTATION
	printf("Bienvenue dans la bibliothèque de CY-TECH!\n\n");
	printf("cursor_id=%d!\n\n", *cursor_id);

	do{
		printf("Que souhaitez-vous faire ?\n");
		printf("1. Se connecter \n"); 
		printf("2. S'identifier\n\n\n\n");
		scanf("%d",&answer);
		if(answer==1){
			PRESENTATION
			connect(list_book, list_id, id_nb, book_nb, cursor_id);
			printf("in start cursor_id=%d!\n");
			book_management (list_book, list_id,  id_nb, book_nb, cursor_id);
		}
		else if(answer==2){
			PRESENTATION
			create_id(list_id, &id_nb);
			*cursor_id =id_nb -1;
			book_management (list_book, list_id,  id_nb, book_nb, cursor_id);
		}
	}while(answer!=1 && answer !=2);
}



void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id){
	*cursor_id =id_nb -1;
	int answer=0, come_back=0;
	char title[SIZE_MAX] ={0};
	PRESENTATION
	display_book(list_id ,list_id[*cursor_id].login ,list_book ,id_nb , book_nb, cursor_id);
	do{
		printf("Quelle action souhaitez-vous réaliser ?\n");
		printf("1. Emprunter un nouveau livre\n"); 
		printf("2. Rendre un livre\n");
		printf("3. Se déconnecter.\n\n\n");
		scanf("%d",&answer);

		if(answer==1){
			PRESENTATION
			all_books(list_book, book_nb);

			printf("cursor_id=%d!\n");

			scan_text("Quel livre souhaitez-vous emprunter ? Appuyez sur 0 pour quitter", title, SIZE_MAX);
			if(title[0]==0){
				book_management (list_book, list_id, id_nb, book_nb, cursor_id);
			}
			else{
				PRESENTATION	
				all_books(list_book, book_nb);
				get_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
		//		book_management (list_book, list_id, id_nb, book_nb, cursor_id);
			}
		}
		else if(answer==2){
			if(list_id[*cursor_id].nb_borrowed_books==0){
				come_back=scan_int("Vous n'avez aucun livre à rendre, appuyez sur 0 pour revenir en arrière", 0, 1);
				if(come_back==0){
					book_management (list_book, list_id, id_nb, book_nb, cursor_id);
				}
			}
			else{
				PRESENTATION
				display_book(list_id ,list_id[*cursor_id].login ,list_book ,id_nb , book_nb, cursor_id);
				scan_text("Quel livre souhaitez-vous rendre ?", title, SIZE_MAX);
				give_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
				book_management (list_book, list_id, id_nb, book_nb, cursor_id);
			}
		}
		else if(answer==3){
			start(list_book, list_id, id_nb, book_nb, cursor_id);
		}
	}while(answer!=1 && answer !=2 && answer!=3);
}














int main(){
	int id_nb =0;
	int book_nb =0;
	Books* list_book =NULL;
	Id* list_id =NULL;
	int cursor_id;
	int id_cursor;

	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);

	start(list_book, list_id, id_nb, book_nb, &cursor_id);
//	book_management ();
	return 0;
}

