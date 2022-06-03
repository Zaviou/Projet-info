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
			printf("in start cursor_id=%d!\n", *cursor_id);
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
/*
void triSelection_all_title(Books* list_book, int book_nb, int TAILLE);
void triSelection_all_author(Books* list_book, int book_nb, int TAILLE);
void triSelection_your_title(Books* list_book, Id* list_id, int book_nb, int id_cursor, int TAILLE);
void look_for_by_title(Books* list_book, int book_nb);
void look_for_by_author(Books* list_book, int book_nb);
void look_for_by_genre(Books* list_book, int book_nb);
*/
void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id){
	//*cursor_id =id_nb -1;
	int answer=0, come_back=0;
	char title[SIZE_MAX] ={0};
	PRESENTATION

//	triSelection_your_title(Books* list_book, Id* list_id, int book_nb, int id_cursor, int TAILLE);
	if(list_id[*cursor_id].role==1){
		do{
			printf("Quelle action souhaitez-vous réaliser ?\n");
			printf("1. Emprunter un nouveau livre\n"); 
			printf("2. Rendre un livre\n");
			printf("3. Se déconnecter.\n\n\n");
			answer=scan_int("", 1, 3);
			if(answer==1){
				PRESENTATION

	//			all_books_title(list_book, book_nb, list_book[*cursor_id].title);

				printf("cursor_id=%d!\n", *cursor_id);

				scan_text("Quel livre souhaitez-vous emprunter ? Appuyez sur 0 pour quitter", title, SIZE_MAX);
				if(title[0]==0){
					book_management (list_book, list_id, id_nb, book_nb, cursor_id);
				}
				else{
					PRESENTATION	
					printf("1. Trier par ordre alphabétique des titres.\n"); 
					printf("2. Trier par ordre alphabétique des auteurs.\n");
					printf("2. Trier par genre.\n");
					answer=scan_int("", 1, 2);

					if(answer==1){
				
	//void all_books_title(Books* list_book, int book_nb, char** title);
	//				all_books_title(list_book, book_nb);
					get_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
	//				book_management (list_book, list_id, id_nb, book_nb, cursor_id);
					}
					else{
	//				all_books_author( list_book, book_nb, list_book[*cursor_id].author);
					get_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
	//				book_management (list_book, list_id, id_nb, book_nb, cursor_id);
					}				
				
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

					void your_books_title(Id* list_id, Books* list_book, int id_cursor, int book_nb, char** title);
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
/*	else{
		do{
			printf("Quelle action souhaitez-vous réaliser ?\n");
			printf("1. Emprunter un nouveau livre\n"); 
			printf("2. Rendre un livre\n");
			printf("3. Ajouter un livre à la bibliothèque\n");
			printf("4. Se déconnecter.\n\n\n");
			answer=scan_int("", 1, 4);
			if(answer==1){
				PRESENTATION

				all_books_title(list_book, book_nb, list_book[*cursor_id].title);

				printf("cursor_id=%d!\n");

				scan_text("Quel livre souhaitez-vous emprunter ? Appuyez sur 0 pour quitter", title, SIZE_MAX);
				if(title[0]==0){
					book_management (list_book, list_id, id_nb, book_nb, cursor_id);
				}
				else{
					PRESENTATION	
					printf("1. Trier par ordre alphabétique des titres.\n"); 
					printf("2. Trier par ordre alphabétique des auteurs.\n");
					answer=scan_int("", 1, 2);

					if(answer==1){
				
	//void all_books_title(Books* list_book, int book_nb, char** title);
					all_books_title(list_book, book_nb);
					get_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
	//				book_management (list_book, list_id, id_nb, book_nb, cursor_id);
					}
					else{
					all_books_author( list_book, book_nb, list_book[*cursor_id].author);
					get_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
	//				book_management (list_book, list_id, id_nb, book_nb, cursor_id);
					}				
				
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

					void your_books_title(Id* list_id, Books* list_book, int id_cursor, int book_nb, char** title);
					scan_text("Quel livre souhaitez-vous rendre ?", title, SIZE_MAX);
					give_book(list_id, list_book, book_nb, id_nb, *cursor_id, title);
					book_management (list_book, list_id, id_nb, book_nb, cursor_id);
				}
			}
			else if(answer==3){
				 create_book(list_book, book_nb);
//				book_management (list_book, list_id, id_nb, book_nb, cursor_id);
			}			
			else if(answer==4){
				start(list_book, list_id, id_nb, book_nb, cursor_id);
			}
		}while(answer!=1 && answer !=2 && answer!=3 && answer !=4);
	}
}*/

}












int main(){
	int id_nb =0;
	int book_nb =0;
	Books* list_book =NULL;
	Id* list_id =NULL;
	int cursor_id=0;
	int id_cursor=0;

	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);

	start(list_book, list_id, id_nb, book_nb, &cursor_id);
	return 0;
}

