#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE_MAX 50

typedef struct{
	char title[SIZE_MAX];
	char author[SIZE_MAX];
	char genre[SIZE_MAX];
	char release[9];
	long id;
	int taken;
} Books;

typedef struct {
	int nb_borrowed_books;
	int role;
	char login[SIZE_MAX];
	char password[SIZE_MAX];
	char*** books;
} Id;

//run_book.o
void create_book(Books* list_book, int book_nb);
Books* read_book(int book_nb[1]);

//run_id.o
void create_id(Id* list_id, int id_nb);
void line_to_id_date(char* line, char* id, char* date);
Id* read_id();

//get_give_book.c
char* get_date();
void book_is_taken(int book_cursor, char* title);
void get_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
//void give_book();

//translate.c
long int char_to_long(char* str);

//iu.o
void start();
void book_management ();
