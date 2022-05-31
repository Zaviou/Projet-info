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

void book_is_taken(int book_cursor, char* title, char taken){
	//

	//Statement & Initialization :
	FILE* file;
	char tmp ='0';
	char tmp2[12];
	char tempo_title[SIZE_MAX +3];
	int i =0, change =0;

	//Open the file "book.txt"
	file=fopen("book.txt","r+");
	if(file ==NULL){
		printf("Can't open the file book.txt\n");
		exit(1);
	}

		//Find the place where to change the value of "list_book[book_cursor].taken" in "book.txt"
	//Find title
	rewind(file);
	do{
		tmp =fgetc(file);
		if(tmp =='"'){
			tempo_title[0] ='\0';
			fgets(tmp2, 12, file);
			if(strcmp(tmp2, "Title\"  : \"") ==0){
				fgets(tempo_title, SIZE_MAX +3, file);

				//Delete the '";\n' character from the tempo_title
				i =0;
				while(tempo_title[i] !='"' && i <=SIZE_MAX +2){
					i ++;
				}
				tempo_title[i] ='\0';
			}
		}
	}while(tmp !=EOF && (strcmp(tempo_title, title) !=0));

	//Find taken
	do{
		tmp =fgetc(file);
		if(tmp =='"'){
			tempo_title[0] ='\0';
			fgets(tmp2, 12, file);
			 if(strcmp(tmp2, "taken\"  : \"") ==0){
				fprintf(file, "%c", taken);
				change =1;
			}
		}
	}while(tmp !=EOF && change ==0);

	fclose(file);
}

void rewrite_borrowed_book(Id* list_id, int id_cursor){
	//

	//Statement & Initialization :
	FILE* file;
	char tmp ='0';
	char tmp2[15];
	char tempo_login[SIZE_MAX +3];
	int i =0, nb_allowed_books =-1, change =0;

	//Open the file "id.txt"
	file =fopen("id.txt","r+");
	if(file ==NULL){
		printf("Can't open the file id.txt\n");
		exit(1);
	}

		//Find the place where to add the book in "id.txt"
	//Find login
	rewind(file);
	do{
		tmp =fgetc(file);
		if(tmp =='"'){
			tempo_login[0] ='0';
			fgets(tmp2, 14, file);
			if(strcmp(tmp2, "Login\"    : \"") ==0){
				fgets(tempo_login, SIZE_MAX +3, file);

				//Delete the '";\n' character from the tempo_login
				i =0;
				while(tempo_login[i] !='"' && i <=SIZE_MAX +2){
					i ++;
				}
				tempo_login[i] ='\0';
			}
		}
	}while(tmp !=EOF && (strcmp(tempo_login, list_id[id_cursor].login) !=0));

	//Find books
	if(list_id[id_cursor].role ==1){
		nb_allowed_books =3;
	} else{
		nb_allowed_books =5;
	}
	do{
		tmp =fgetc(file);
		if(tmp =='"'){
			tempo_login[0] ='\0';
			fgets(tmp2, 14, file);
			 if(strcmp(tmp2, "Books\"    : [") ==0){
				fseek(file, 4, SEEK_CUR);
				for(i =0; (i <list_id[id_cursor].nb_borrowed_books && i <nb_allowed_books); i++){
					fprintf(file, "%s : ", list_id[id_cursor].books[i][0]);
					fprintf(file, "%s;\n			", list_id[id_cursor].books[i][1]);
				}
				for(i =list_id[id_cursor].nb_borrowed_books; i <nb_allowed_books; i++){
					fprintf(file, "                 \n");
					if(i ==nb_allowed_books){
						fprintf(file, "			");
					}
				}
				change =1;
			}
		}
	}while(tmp !=EOF && change ==0);

	fclose(file);
}

void get_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title){
	//

	//Statement & Initialization :
	int i =0, book_cursor =0;
	char** tmp =NULL;
	time_t date;
	date = time(NULL);

	//Find the id's book in book's list (list_book)
	for(i =0; i <book_nb; i++){
		if(strcmp(title, list_book[i].title) ==0){
			book_cursor =i;
		}
	}

		//Add the book in the id's list (list_id[id_cursor].books)
	//Increase the lenght of the book list (list_id[id_cursor].books) of 1
	tmp =realloc(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books], (list_id[id_cursor].nb_borrowed_books) *sizeof(char**));
	if(tmp ==NULL){
		printf("Impossible d'augmenter la taille de la list (list_id[%d].books).\n", id_cursor);
		exit(1);
	}
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books] =tmp;

	//Allocate memory for the list of borrowed books (list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][0])
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][0] =malloc(3 *sizeof(char));
	if(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][0] ==NULL){
		printf("Impossible d'allouer de l'espace pour l'id du livre emprunté (list_id[%d].books[%d][0]).\n", id_cursor, list_id[id_cursor].nb_borrowed_books);
		exit(1);
	}

	//Allocate memory for the list of borrowed books (list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][1])
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][1] =malloc(10 *sizeof(char));
	if(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][1] ==NULL){
		printf("Impossible d'allouer de l'espace pour la date d'emprunt (list_id[%d].books[%d][1]).\n", id_cursor, list_id[id_cursor].nb_borrowed_books);
		exit(1);
	}

	//Add the values
	list_id[id_cursor].nb_borrowed_books ++;
	snprintf(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books -1][1], 11 *sizeof(char), "%ld", date);
	snprintf(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books -1][0], 4 *sizeof(char), "%ld", list_book[book_cursor].id);
	list_book[book_cursor].taken =1;

	//Write in the files (book.txt and id.txt)
	book_is_taken(book_cursor, title, '1');
	rewrite_borrowed_book(list_id, id_cursor);

	free(tmp);
}

void give_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title){
	//

	//Statement & Initialization :
	int i =0, book_cursor_book =-1, book_cursor_id =-1;
	char** tmp =NULL;
	char id[3];

	//Find the id's book in book's list (list_book)
	for(i =0; i <book_nb; i++){
		if(strcmp(title, list_book[i].title) ==0){
			book_cursor_book =i;
		}
	}
	list_book[book_cursor_book].taken =0;

	//Find the book in the borrowed books (list_id[id_cursor].books[i])
	sprintf(id, "%ld", list_book[book_cursor_book].id);
	for(i =0; i <list_id[id_cursor].nb_borrowed_books; i++){
		if(strcmp(id, list_id[id_cursor].books[i][0]) ==0){
			book_cursor_id =i;
		}
	}

		//Delete the book in the id's list (list_id[id_cursor].books)
	//Shift the book in the id's list (list_id[id_cursor].books) from the book_cursor
	for(i =book_cursor_id +1; i <list_id[id_cursor].nb_borrowed_books; i++){
		list_id[id_cursor].books[i -1] =list_id[id_cursor].books[i];
	}

	//Decrease the lenght of the book list (list_id[id_cursor].books) of 1
	tmp =realloc(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books -1], (list_id[id_cursor].nb_borrowed_books) *sizeof(char**));
	if(tmp ==NULL){
		printf("Impossible d'augmenter la taille de la list (list_id[%d].books).\n", id_cursor);
		exit(1);
	}
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books] =tmp;
	list_id[id_cursor].nb_borrowed_books --;

	//Write in the files (book.txt and id.txt)
	book_is_taken(book_cursor_book, title, '0');
	rewrite_borrowed_book(list_id, id_cursor);

	free(tmp);
}

int main(){
	//

	//Statement & Initialization :
	Books* list_book=NULL;
	Id* list_id =NULL;
	int id_nb =0, book_nb =1, i =0, id_cursor =0;

	list_book =read_book(&book_nb);
	list_id =read_id(&id_nb);

	get_book(list_id, list_book, book_nb, id_nb, 0, "ert");
	//give_book(list_id, list_book, book_nb, id_nb, 0, "ert");

	return 0;
}
