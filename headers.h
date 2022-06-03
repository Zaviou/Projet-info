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
/*This function put characters of a string into another tring.
receive: is the tring that take the characters.
give: is the tring that give the characters.
size_max: is the maximal numbers of characters.
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
void create_id(Id* list_id, int id_nb);
/*This function ask the user all infomartion needed to create an id, add it the list_id and write it in the id.txt.
list_id: list of ids contained in the id's file (id.txt).
id_nb: is the number of ids saved.
*/
void line_to_id_date(char* line, char* id, char* date);
/*This function get from a string, an id and a date.
line: is the string.
id: is an identification number of a borrowed book.
date: is the number of second elapsed between the 1st of january in 1970 and the date of borrowing.
*/
Id* read_id(int id_nb[1]);
/*This function explore the id.txt file and return a list of Id containing all the informations read.
id_nb: is the number of ids saved.
*/

	//get_give_book.c
int right_to_borrow(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
/*Ths function checks if the users can or not borrow a book. It returns 0 if he can or 1 if he can't.
list_id: list of ids contained in the id's file (id.txt).
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
id_nb: is the number of ids saved.
id_cursor: is the place of the user in list_id.
title: is the title of the book wished to borrow.
*/
int right_to_give_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
/*This function checks if the users can or not return a book. It returns 0 if he can or 1 if he can't.
list_id: list of ids contained in the id's file (id.txt).
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
id_nb: is the number of ids saved.
id_cursor: is the place of the user in list_id.
title: is the title of the book wished to return.
*/
void book_is_taken(int book_cursor, char* title, char taken);
/*This function change the value of list_book[book_cursor].taken in the file book.txt.
book_cursor: is the place of the book in list_book.
title: is the title of the book wished to return.
taken: is character by what is change the initial list_book[book_cursor].taken ('0' if he is available or '1' if he's taken).
*/
void rewrite_borrowed_book(Id* list_id, int id_cursor);
/*This function rewrite all the borrowed book in the id.txt.
list_id: list of ids contained in the id's file (id.txt).
id_cursor: is the place of the user in list_id.
*/
void get_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
/*This function reallocate the memorie for the list of borrowed book of a user (list_id[id_cursor].books) and add the values of the borrowed book.
list_id: list of ids contained in the id's file (id.txt).
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
id_nb: is the number of ids saved.
id_cursor: is the place of the user in list_id.
title: is the title of the book wished to borrow.
*/
void give_book(Id* list_id, Books* list_book, int book_nb, int id_nb, int id_cursor, char* title);
/*This function reallocate the memorie for the list of borrowed book of a user (list_id[id_cursor].books) and delete the values of the returned book.
list_id: list of ids contained in the id's file (id.txt).
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
id_nb: is the number of ids saved.
id_cursor: is the place of the user in list_id.
title: is the title of the book wished to return.
*/

	//display_list_book.c
int date_comparison(long borrow_date, int type_user, int* comparison);
/*This function calculates if the user is late or not to return the books he borrowed. The time allowed to keep the book is 120 seconds for a student and 180 seconds for a teacher. It returns 1 if the user is not late and 0 if he is.
borrow_date: is the number of second elapsed between the 1st of january in 1970 and the date of borrowing.
type_user: equals 1 if the user is a student, or 2 if the user is a teacher.
comparison: is the number of seconds left to return the book (if the user insn't late).
*/
void triSelection_all_title(Books* list_book, int book_nb, int TAILLE);
/*This function create a list of book, use the "copy_string" function to copy the titles in "list_book", then sort it, lorking the titles, in the ASCII (not alphabetical) order. At the end, it use the "all_books_title" function to displays them.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
TAILLE: is the maximum lenght (number of character) of the titles.
*/
void triSelection_all_author(Books* list_book, int book_nb, int TAILLE);
/*This function create a list of book use the "copy_string" function to copy the authors in "list_book", then sort it, lorking the auhtor, in the ASCII (not alphabetical) order. At the end, it use the "all_books_author" function to displays them.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
TAILLE: is the maximum lenght (number of character) of the authors.
*/
void triSelection_your_title(Books* list_book, Id* list_id, int book_nb, int id_cursor, int TAILLE);
/*This function create a list of book and sort it, lorking the titles, use the "copy_string" function to copy the titles of the borrowed books, then sort it, lorking the titles, in the ASCII (not alphabetical) order. At the end, it use the "all_books_title" function to displays them.
list_book: list of books contained in the book's file (book.txt).
list_id: list of ids contained in the id's file (id.txt).
book_nb: is the number of book saved.
id_cursor: is the place of the user in list_id.
TAILLE: is the maximum lenght (number of character) of the titles.
*/
void all_books_title(Books* list_book, int book_nb, char** title);
/*This function display the titles in "title", find their author thanks to the "get_book_from_title" function and indicate if there are available or not.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
title: is a list of titles.
*/
void all_books_author(Books* list_book, int book_nb, char** author);
/*This function display the authors in "author", find their title thanks to the "get_book_from_author" function and indicate if there are available or not.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
author: is a list of authors.
*/
void your_books_title(Id* list_id, Books* list_book, int id_cursor, int book_nb, char** title);
/*This function display the titles in "title", find their author thanks to the "get_book_from_title" function and indicate if the user is late to returns them or not (if not : it indicate how many time left he have to return it).
list_id: list of ids contained in the id's file (id.txt).
list_book: list of books contained in the book's file (book.txt).
id_cursor: is the place of the user in list_id.
book_nb: is the number of book saved.
title: is a list of titles.
*/
void look_for_by_title(Books* list_book, int book_nb);
/*This function ask the user a title. If this title is in list_book then it display it with the author's name. If not, then it explain the user that the book doesn't exist in the library.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
*/
void look_for_by_author(Books* list_book, int book_nb);
/*This function ask the user an author. If this author is in list_book then it display the titles of the list of book written by him. If not, then it explain the user that there isn't books from him in the library.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
*/
void look_for_by_genre(Books* list_book, int book_nb);
/*This function ask the user a genre. If this genre is in list_book then it display the titles and the authors of the list of book of this genre. If not, then it explain the user that there isn't books of the find of genre in the library.
list_book: list of books contained in the book's file (book.txt).
book_nb: is the number of book saved.
*/

	//translate.c
long int char_to_long(char* str);
/*This function convert a string into a long. It returns the long. 
str: is a string.
*/
Books get_book_from_id (Books* list_book, char* id_book, int book_nb);
/*This function uses an ID of a book and returns the book's informations after recognizing the ID.
list_book: list of books contained in the book's file (book.txt).
id_book: is an identification number of a borrowed book.
book_nb: is the number of book saved.
*/
int get_book_from_title (Books* list_book, char* title, int book_nb);
/*This function look for a book in "list_book" from his title and return his place in list_book. If the book doesn't exist ir returns -1.
list_book: list of books contained in the book's file (book.txt).
title: title of a book.
book_nb: is the number of book saved.
*/
int get_book_from_author (Books* list_book, char* author, int book_nb);
/*This function look for the first book in "list_book" from his author and return his place in list_book. If the book doesn't exist ir returns -1.
list_book: list of books contained in the book's file (book.txt).
author: author of a book.
book_nb: is the number of book saved.
*/

	//connect.c
int connect(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id);
/*
*/

	//iu.o
void start(Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id);
void book_management (Books* list_book, Id* list_id, int id_nb, int book_nb, int* cursor_id);

	//scan_all_types.c
void scan_text(char* ask, char* text, int taille_max);
/*This function ask the user to enter text, then take it. If the user took to many characters then the function displays an error and ask again until having a text with the right amont of characters.
ask: is the text that the function displays in order to ask the user to enter text.
text: is the final text entered by the user.
taille_max: is the maximum number of characters allowed to take.
*/
void scan_word(char* ask, char* word, int taille_max);
/*This function ask the user to enter a word, then take it. If the user took to many characters, or a space character (' ') then the function displays the error and ask again until having a word without problem.
ask: is the text that the function displays in order to ask the user to enter text.
word: is the final word entered by the user.
taille_max: is the maximum number of characters allowed to take.
*/
long int scan_long(char* ask, int taille_max);
/*This function ask the user to enter a value, then take it. If the user took to many characters, or a text characters (not numbers characters) then the function displays the error and ask again until having a value without problem. The function returns
ask: is the text that the function displays in order to ask the user to enter text.
taille_max: is the maximum number of characters allowed to take.
*/
int scan_int(char* ask, int min, int max);
/*This function ask the user to enter a value, then take it. If the user took to many characters, or a text characters (not numbers characters), or value between min and max then the function displays the error and ask again until having a value without problem. The function returns
ask: is the text that the function displays in order to ask the user to enter text.
min: is the minimum value.
max: is the maximum value.
*/
