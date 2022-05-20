all: exe

exe: run_id.o display_list_books.o
	gcc run_id.o display_list_books.o -o exe

exec: get_give_book.o run_book.o
	gcc get_give_book.o run_book.o -o exec

main.o: main.c
	gcc -c main.c main.o

get_give_book.o: get_give_book.c
	gcc -c get_give_book.c -o get_give_book.o

display_list_books.o: display_list_books.c headers.h
	gcc -c  display_list_books.c -o display_list_books.o

run_book.o: run_book.c headers.h
	gcc -c run_book.c -o run_book.o

run_id.o: run_id.c headers.h
	gcc -c run_id.c -o run_id.o
