all: exe

exe: run_id.o run_book.o display_list_books.o get_give_book.o translate.o iu.o connect.o scan_all_types.o main.o
	gcc run_id.o run_book.o display_list_books.o get_give_book.o translate.o iu.o connect.o scan_all_types.o main.o -o exe

main.o: main.c run_book.o
	gcc -c main.c -o main.o

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

date.o: date.c headers.h
	gcc -c date.c -o date.o

display_list_books.o: display_list_books.c headers.h
	gcc -c  display_list_books.c -o display_list_books.o

run_book.o: run_book.c headers.h
	gcc -c run_book.c -o run_book.o

run_id.o: run_id.c headers.h
	gcc -c run_id.c -o run_id.o
