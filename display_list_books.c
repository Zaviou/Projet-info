#include "headers.h"

char* get_date(){
	//

	//Statement & Initialization :
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo =localtime(&rawtime);

	return asctime(timeinfo);
}

/* retourner int
argument date en char format Thu May 19 15:52:30 2022
comparer avec date actuelle avec get_date
si temps entre les 2 dates < time_limit return 0:
si temps >= return 1
argument : si user élève/professeur type user
type user : 1 student/ 2 porofessor
*/

/*
int date_comparison (int type_user, char* date){
	int time_limit;
	if(type_user==1){
		time_limit=120;
	}
	else{
		time_limit=180;
	} 	
	
	return 0;
}
*/


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




//attoi
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

























int main(){
	//
	int type_user=2;
	long borrow_date=1653063512;
	//Statement & Initialization :
	int id_nb =0;
	Id* list_id =NULL;
	date_comparison(borrow_date, type_user);
	list_id =read_id(&id_nb);
//	display(list_id, id_nb, "zaviou");
//	create_id(list_id, id_nb);
//	date_comparison(1, "Thu May 19 15:52:30 2022");
	return 0;
}
