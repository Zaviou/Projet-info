all: exe

exe: run_id.o display_list_books.o
	gcc run_id.o display_list_books.o -o exe

main.o: main.c
	gcc -c main.c main.o

display_list_books.o: display_list_books.c
	gcc -c  display_list_books.c -o display_list_books.o

run_book.o: run_book.c headers.h
	gcc -c run_book.c run_book.o

run_id.o: run_id.c headers.h
	gcc -c run_id.c run_id.o
