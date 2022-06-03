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
void copy_string(char* receive, char* give, int size_max);
/*This function put caracters of a string into another tring.
receive: is the tring that take the caracters.
give: is the tring that give the caracters.
size_max: is the maximal numbers of caracters.
*/
void create_book(Books* list_book, int book_nb);
/*This function ask the user all infomartion needed to create a book, add it the list_book and write it in the book.txt.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
*/
Books* read_book(int book_nb[1]);
/*This function explore the book.txt file and return a list of Books containing all the informations read.
book_nb: is the number of book saved.
*/

	//run_id.o
void create_id(Id* list_id, int id_nb[1]);
/*This function ask the user all infomartion needed to create an id, add it the list_id and write it in the id.txt.
list_id: list of ids contained in the id's file (id.txt).
id_nb: is the number of ids saved.
*/
void line_to_id_date(char* line, char* id, char* date);
/*This function get from a string, an id and a date.
line: is the string.
id: is an identification number of a book.
date: is the number of second elapsed between the 1st of january in 1970 and the date of borrowing.
*/
Id* read_id(int id_nb[1]);
/*This function explore the id.txt file and return a list of Id containing all the informations read.
id_nb: is the number of ids saved.
*/

	//get_give_book.c
int right_to_borrow(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
/*Ths function checks if the users can or not borrow a book. It returns 0 if he can or 1 if he can't.
*/
int right_to_give_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
void book_is_taken(int book_cursor, char* title, char taken);
void rewrite_borrowed_book(Id* list_id, int id_cursor);
void get_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
void give_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);

//display_list_book.c
int date_comparison(long borrow_date, int type_user, int* comparison);
/*This function calculates if the user is late or not to return the books he borrowed. The time allowed to keep the book is 120 seconds for a student and 180 seconds for a teacher. It returns 1 if the user is not late and 0 if he is.*/
void triSelection_all_title(Books* list_book, int book_nb, int TAILLE);
void triSelection_all_author(Books* list_book, int book_nb, int TAILLE);
void triSelection_your_title(Books* list_book, Id* list_id, int book_nb, int cursor_id, int TAILLE);
void look_for_by_title(Books* list_book, int book_nb);
void look_for_by_author(Books* list_book, int book_nb);
void look_for_by_genre(Books* list_book, int book_nb);
void all_books_title(Books* list_book, int book_nb, char** title);
void all_books_author(Books* list_book, int book_nb, char** author);
void your_books_title(Id* list_id, Books* list_book, int id_cursor, int book_nb, char** title);

//translate.c
long int char_to_long(char* str);
Books get_book_from_id (Books* list_book, char* id_book, int book_nb);
/*This function uses an ID of a book and returns the book's informations after recognizing the ID.*/
int get_book_from_title (Books* list_book, char* title, int book_nb);
int get_book_from_author (Books* list_book, char* author, int book_nb);

//connect.c
void connect(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id);
/*This function asks your log informations, verifies them to permit you to get you to the book management page or ask you to try again if they are false.*/

//iu.o
void start(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id);
/*This function displays the user interface of the starting page. It offers to the user the possibility to connect if they have already registered or to identify for new users. If you connect successfuly you get to the book management page.*/
void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id);
/*This function displays the list of the books you borrowed then give the choice to choose between:
borrow a book:
return a borrowed book:
add a book to the library:
deconnect(only for teachers):

*/
//scan_all_types.c
void scan_text(char* ask, char* text, int taille_max);
void scan_word(char* ask, char* word, int taille_max);
long int scan_long(char* ask, int taille_max);
int scan_int(char* ask, int min, int max);
