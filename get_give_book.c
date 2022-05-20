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

void book_is_taken(int book_cursor, char* title){
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
			}

			//Delete the '";\n' character from the tempo_title
			i =0;
			while(tempo_title[i] !='"' && i <=SIZE_MAX +2){
				i ++;
			}
			tempo_title[i] ='\0';
		}
	}while(tmp !=EOF && (strcmp(tempo_title, title) !=0));

	//Find taken
	do{
		tmp =fgetc(file);
		if(tmp =='"'){
			tempo_title[0] ='\0';
			fgets(tmp2, 12, file);
				 if(strcmp(tmp2, "taken\"  : \"") ==0){
					fprintf(file, "1");
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
	char* date =NULL;
	char** tmp =NULL;

	//Find the id's book in book's list (list_book)
	for(i =0; i <book_nb; i++){
		if(strcmp(title, list_book[i].title) ==0){
			book_cursor =i;
		}
	}

	//Get the date
	date =get_date();
	date[24] ='\0';

		//Add the book in the id's list (list_id[id_cursor].books)
	//Increase the lenght of the book list (list_id[id_cursor].books) of 1
	tmp =realloc(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books -1], (list_id[id_cursor].nb_borrowed_books) *sizeof(char**));
	if(tmp ==NULL){
		printf("Impossible d'augmenter la taille de la list (list_id[%d].books).\n", id_cursor);
		exit(1);
	}
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books] =tmp;

	//Add the values
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][0] =list_book[book_cursor].id;
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books][1] =date;

	//Change the book's status in the book list (list_book[book_cursor].taken)
	list_book[book_cursor].taken =0;

	//Write in the files (book.txt and id.txt)
	book_is_taken(book_cursor, title);

	free(tmp);
}

void give_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title){
	//

	//Statement & Initialization :
	int i =0, book_cursor_book =0, book_cursor_id =0;
	char** tmp =NULL;

	//Find the id's book in book's list (list_book)
	for(i =0; i <book_nb; i++){
		if(strcmp(title, list_book[i].title) ==0){
			book_cursor_book =i;
		}
	}

	//Find the book in the borrowed books (list_id[id_cursor].books[i])
	for(i =0; i <list_id[id_cursor].nb_borrowed_books; i++){
		if(strcmp(list_book[book_cursor_book].id, list_id[id_cursor].books[i][0]) ==0){
			book_cursor_id =i;
		}
	}
	printf("book_cursor_id:%d!\n", book_cursor_id);

		//Delete the book in the id's list (list_id[id_cursor].books)
	//Shift the book in the id's list (list_id[id_cursor].books) from the book_cursor
	for(i =book_cursor_id +1; i <list_id[id_cursor].nb_borrowed_books; i++){
		list_id[id_cursor].books[i -1] =list_id[id_cursor].books[i];
	}

	//Decrease the lenght of the book list (list_id[id_cursor].books) of 1
	tmp =realloc(list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books -2], (list_id[id_cursor].nb_borrowed_books) *sizeof(char**));
	if(tmp ==NULL){
		printf("Impossible d'augmenter la taille de la list (list_id[%d].books).\n", id_cursor);
		exit(1);
	}
	list_id[id_cursor].books[list_id[id_cursor].nb_borrowed_books] =tmp;
	list_id[id_cursor].nb_borrowed_books --;

	//Write in the file id.txt the decrease

	free(tmp);
}

int main(){
	//

	//Statement & Initialization :
	Books* list_book=NULL;
	Id* list_id =NULL;
	int id_nb =0, book_nb =1, i =0;

	list_book =read_book(&book_nb);
	list_id =read_id(&id_nb);

	give_book(list_id, list_book, book_nb, id_nb, 0, "aze");
	//get_book(list_id, list_book, book_nb, id_nb, 0, "aze");

	return 0;
}
/*
[
	{
		"Login"    : "aze";
		"Password" : "qsd";
		"Role"     : "1";
		"Books"    : [
			123 : Thu May 19 15:52:30 2022;
			213 : Thu May 20 15:51:30 2023;
			321 : Thu May 21 15:51:30 2024;
			]
	},
*/
