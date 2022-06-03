#include "headers.h"

int connect(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id){

	//Statement & Initialization :
	int i =0;
	*cursor_id =-1;
	char entered_login[SIZE_MAX];
	char entered_password[SIZE_MAX];

	scan_word("Entrez votre identifiant ou appuyez sur 0 pour quitter", entered_login, SIZE_MAX);

	//Return to "start" functinon if asked
	if(strcmp(entered_login, "0") ==0){
		start(list_book, list_id, id_nb, book_nb, cursor_id);
	}

	//Find cursor_id from login
	for(i=0;i<id_nb; i++){
		if(strcmp(entered_login, list_id[i].login) ==0){
			*cursor_id =i;
		}
	}

	//Explain the user if the login is not right
	if(*cursor_id ==-1){
		printf(ANSI_COLOR_RED "Votre identifiant est invalide.\n\n" ANSI_COLOR_RESET);
		connect(list_book, list_id, id_nb, book_nb, cursor_id);
	}

	scan_word("Entrez votre mot de passe ou appuyez sur 0 pour quitter", entered_password, SIZE_MAX);

	//Return to "start" functinon if asked
	if(strcmp(entered_password, "0") ==0){
		start(list_book, list_id, id_nb, book_nb, cursor_id);
	}

	//Tell the user if he's connected
	else if(strcmp(list_id[*cursor_id].password, entered_password) ==0){
		printf("Vous êtes connecté.\n");
	}

	//Explain the user if the password is not right
	else{
		printf(ANSI_COLOR_RED "Votre mot de passe est invalide\n\n" ANSI_COLOR_RESET); 
		connect(list_book, list_id, id_nb, book_nb, cursor_id);
	}
}

/*int main(){
	//Exemples of how to use all functions in this file.

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
