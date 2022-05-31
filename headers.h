#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRESENTATION system("clear");printf("______________________________________________________________________________\n\n");printf("                          Application CY-BiblioTECH                             ");printf("______________________________________________________________________________\n\n");

#define SIZE_MAX 50
//Colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct{
	long id;
	int taken;
	char title[SIZE_MAX];
	char author[SIZE_MAX];
	char genre[SIZE_MAX];
	char release[9];
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
void book_is_taken(int book_cursor, char* title, char taken);
void rewrite_borrowed_book(Id* list_id, int id_cursor);
void get_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
void give_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);

//display_list_book.c
void display_book(Id* list_id ,char* login ,Books* list_book ,int id_nb, int book_nb);

//translate.c
long int char_to_long(char* str);

//connect.c
int connect(Books* list_book, Id* list_id, int id_nb, int book_nb);

//iu.o
void start(Books* list_book, Id* list_id, int id_nb, int book_nb, int cursor_id);
void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int cursor_id);
