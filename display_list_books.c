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
	for(i=0;i<id_nb; i++){
		printf("%s\n",list_id[cursor].books[i][0]);
		printf("%s\n",list_id[cursor].books[i][1]);
	}
}































int main(){
	//

	//Statement & Initialization :
	int id_nb =0;
	Id* list_id =NULL;

	list_id =read_id(&id_nb);
	display(list_id, id_nb, "zaviou");
//	create_id(list_id, id_nb);

	return 0;
}
