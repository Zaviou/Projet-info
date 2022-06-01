all: exe

exe: run_id.o run_book.o connect.o iu.o display_list_books.o translate.o scan_all_types.o get_give_book.o
	gcc run_id.o run_book.o connect.o iu.o display_list_books.o translate.o scan_all_types.o get_give_book.o -o exe

exec: scan_all_types.o run_id.o run_book.o
	gcc scan_all_types.o run_id.o run_book.o -o exec

main.o: main.c
	gcc -c main.c main.o

scan_all_types.o: scan_all_types.c headers.h
	gcc -c scan_all_types.c -o scan_all_types.o

iu.o: iu.c headers.h
	gcc -c iu.c -o iu.o

connect.o: connect.c headers.h
	gcc -c connect.c -o connect.o

translate.o: translate.c headers.h
	gcc -c translate.c -o translate.o	

get_give_book.o: get_give_book.c headers.h
	gcc -c get_give_book.c -o get_give_book.o

display_list_books.o: display_list_books.c headers.h
	gcc -c  display_list_books.c -o display_list_books.o

run_book.o: run_book.c headers.h
	gcc -c run_book.c -o run_book.o

run_id.o: run_id.c headers.h
	gcc -c run_id.c -o run_id.o
