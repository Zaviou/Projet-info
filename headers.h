#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_MAX 50

typedef struct{
	char title[SIZE_MAX];
	char author[SIZE_MAX];
	char genre[SIZE_MAX];
	char release[9];
	char id[3];
	int taken;
} Books;

typedef struct {
	char login[SIZE_MAX];
	char password[SIZE_MAX];
	char*** books;
	int role;
} Id;

//run_book.o
void create_book(Books* list_book, int book_nb);
Books* read_book(int book_nb[1]);

//run_id.o
void create_id(Id* list_id, int id_nb);
void line_to_id_date(char* line, char* id, char* date);
Id* read_id();

//iu.o
void start();
void book_management ();
