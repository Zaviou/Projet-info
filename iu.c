#include "headers.h"

void start(Books* list_book, Id* list_id, int id_nb, int book_nb, int cursor_id){
	int answer;
	PRESENTATION
	printf("Bienvenue dans la bibliothèque de CY-TECH!\n\n");
	do{
		printf("Que souhaitez-vous faire ?\n");
		printf("1. Se connecter \n"); 
		printf("2. S'identifier\n\n\n\n");
		scanf("%d",&answer);
		if(answer==1){
			PRESENTATION
			connect(list_book, list_id, id_nb, book_nb);
			book_management (list_book, list_id,  id_nb, book_nb, cursor_id);
		}
		else if(answer==2){
			PRESENTATION
			create_id(list_id, id_nb);
		}
	}while(answer!=1 && answer !=2);
}



void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int cursor_id){
	int answer;
	PRESENTATION
	//display_book(list_id ,list_id[cursor_id].login ,list_book ,id_nb, book_nb);
	do{
		printf("Quelle action souhaitez-vous réaliser ?\n");
		printf("1. Emprunter un nouveau livre\n"); 
		printf("2. Rendre un livre\n");
		printf("3. Se déconnecter.\n\n\n");
		scanf("%d",&answer);
		if(answer==1){

			printf("ui\n\n\n");
		}
		else if(answer==2){
			printf("nion è_é\n\n\n");
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
	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);

	start(list_book, list_id, id_nb, book_nb, cursor_id);
//	book_management ();
	return 0;
}

