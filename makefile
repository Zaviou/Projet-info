all: exe

exe: run_id.o display_list_books.o run_book.o
	gcc run_id.o display_list_books.o -o exe

exec: run_book.o run_id.o translate.o
	gcc translate.o run_book.o run_id.o -o exec

main.o: main.c
	gcc -c main.c main.o

translate.o: translate.c headers.h
	gcc -c translate.c -o translate.o	

get_give_book.o: get_give_book.c
	gcc -c get_give_book.c -o get_give_book.o

display_list_books.o: display_list_books.c headers.h
	gcc -c  display_list_books.c -o display_list_books.o

run_book.o: run_book.c headers.h
	gcc -c run_book.c -o run_book.o

run_id.o: run_id.c headers.h
	gcc -c run_id.c -o run_id.o
