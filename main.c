#include "headers.h"

int main(){
	Books* list_book =NULL;
	Id* list_id =NULL;
	int id_nb =0;
	int book_nb =0;
	int cursor_id=0;
	int id_cursor=0;

	list_id =read_id(&id_nb);
	list_book =read_book(&book_nb);

	start(list_book, list_id, id_nb, book_nb, &cursor_id);
	return 0;
}
