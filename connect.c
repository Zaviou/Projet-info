#include "headers.h"





int connect(Books* list_book, Id* list_id, int id_nb, int book_nb){
	int i =0, cursor_id =-1;
	char entered_login[SIZE_MAX];
	char entered_password[SIZE_MAX];
	printf("Entrez votre identifiant ou appuyez sur 0 pour quitter\n");
	scanf("%s", entered_login);
	if(strcmp(entered_login, "0") ==0){
		start(list_book, list_id, id_nb, book_nb, cursor_id);
	}
	for(i=0;i<id_nb; i++){
		if(strcmp(entered_login, list_id[i].login) ==0){
			cursor_id =i;
		}
	}
	if(cursor_id ==-1){
		printf(ANSI_COLOR_RED "Votre identifiant est invalide.\n\n" ANSI_COLOR_RESET);
		connect(list_book, list_id, id_nb, book_nb);
	}
	printf("Entrez votre mot de passe ou appuyez sur 0 pour quitter\n");
	scanf("%s", entered_password);
	if(strcmp(entered_password, "0") ==0){
		start(list_book, list_id, id_nb, book_nb, cursor_id);
	}
	if(strcmp(list_id[cursor_id].password, entered_password) ==0){
		printf("Vous êtes connecté.\n");
	}
	else{
		printf(ANSI_COLOR_RED "Votre mot de passe est invalide\n" ANSI_COLOR_RESET); 
		connect(list_book, list_id, id_nb, book_nb);
	}
}













/*int main(){
	//Statement & Initialization :
	int id_nb =0;
	int book_nb =0;
	Books* list_book =NULL;
	Id* list_id =NULL;

	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);

	connect(list_book, list_id, id_nb, book_nb);
	return 0;
}*/
