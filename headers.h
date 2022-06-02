#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRESENTATION system("clear");printf("______________________________________________________________________________\n\n");printf("                          Application CY-BiblioTECH                             ");printf("______________________________________________________________________________\n\n");

#define SIZE_MAX 50
//Colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct{
	long int id;
	int taken;
	char title[SIZE_MAX];
	char author[SIZE_MAX];
	char genre[SIZE_MAX];
	char release[13];
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
int date_comparison(long borrow_date, int type_user, int* comparison);
	/*
	This function calculates if the user is late or not to return the books he borrowed. The time allowed to keep the book is 120 seconds for a student and 180 seconds for a teacher. It returns 1 if the user is not late and 0 if he is.
	*/
Books get_book_from_id (Books* list_book, char* id_book, int book_nb);
	/*
	This function uses an ID of a book and returns the book's informations after recognizing the ID.
	*/
void display_book(Id* list_id ,char* login ,Books* list_book ,int id_nb, int book_nb, int* cursor_id);
	/*
	This function prints the list of the books borrowed with the name and the author. It also prints the time remaining to return it, if the time has passed the name and author of the book are written in red.
	
	list_id: list of ids contained in the ID's file (id.txt).
	login: login of the user ~~~~~
	id_nb: 
	book_nb:
	*/
void all_books(Books* list_book, int book_nb);

//translate.c
long int char_to_long(char* str);

//connect.c
int connect(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id, int id_cursor, char* title);

//iu.o
void start(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id,  int id_cursor, char* title);
void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id, int id_cursor, char* title);

//scan_all_types.c
void scan_text(char* ask, char* text, int taille_max);
void scan_word(char* ask, char* word, int taille_max);
long int scan_long(char* ask, int taille_max);
int scan_int(char* ask, int min, int max);
