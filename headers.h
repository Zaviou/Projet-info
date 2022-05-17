#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_MAX 50

typedef struct{
	char title[SIZE_MAX];
	char author[SIZE_MAX];
	char genre[SIZE_MAX];
	int release;
	int taken;
	int id;
} Books;

typedef struct {
	char login[SIZE_MAX];
	char password[SIZE_MAX];
	char*** books;
	int role;
} Id;

//run_book.o
void create_book();
int read_book(Books* list);

//run_id.o
void create_id();
void read_id(Id* list);

//iu.o
void start();
void book_management ();
