#include "headers.h"

void create_book(Books* list_book, int book_nb){
	//

	//Statement & Initialization :
	FILE* file;
	Books bookt;
	file=NULL;
	Books* list_book_tmp =NULL;
	int i;

	system("clear");

		//Ask the user the informations about the book
	//Title
	printf("Title of the book\n");
	scanf("%s", bookt.title);
	//Author
	printf("Name of the author\n");
	scanf("%s", bookt.author);
	//Genre
	printf("Genre of the book\n");
	scanf("%s", bookt.genre);
	//Date of release (release)
	printf("Release date of the book\n");
	scanf("%s", bookt.release);
	printf("bookt.release :%s\n", bookt.release);
	//Id
	printf("ID of the book\n");
	scanf("%s", bookt.id);

	bookt.taken=0;

		//Put the informations in the list of ID (list_book)
	//Increase the lenght of the ID list (list_book)
	list_book_tmp =realloc(list_book, (book_nb +1) *sizeof(Books));
	if(list_book_tmp ==NULL){
		printf("Impossible d'augmenter la taille de la list de livres.\n");
		exit(1);
	}
	list_book =list_book_tmp;

	//Add the informations
	for(i =0; i <SIZE_MAX; i++){
		list_book[book_nb].title[i] =bookt.title[i];
		list_book[book_nb].author[i] =bookt.author[i];
		list_book[book_nb].genre[i] =bookt.genre[i];
	}
	for(i =0; i <9; i++){
		list_book[book_nb].release[i] =bookt.release[i];
	}
	for(i =0; i <4; i++){
		list_book[book_nb].id[i] =bookt.id[i];
	}
	list_book[book_nb].taken =bookt.taken;

		//Write the informations in the file "book.txt"
	//Open the file "book.txt"
	file=fopen("book.txt","a+");
	if(file==NULL){
		printf("Can't open the file book.txt\n");
		exit(1);
	}

	rewind(file);

	//Check if there is already a book in the file
	if(fgetc(file)!='['){
		fprintf(file,"%s","[\n");
	}

	//Write
	fprintf(file, "%s","	{\n");
	fprintf(file, "%s","		\"Title\"  : ");
	fprintf(file, "\"%s\";\n",bookt.title);
	fprintf(file, "%s","		\"Author\" : ");
	fprintf(file, "\"%s\";\n",bookt.author);
	fprintf(file, "%s","		\"Genre\"  : ");
	fprintf(file, "\"%s\";\n",bookt.genre); 
	fprintf(file, "%s","		\"Release\": ");
	fprintf(file, "\"%s\";\n  ",bookt.release);
	fprintf(file, "%s","		\"ID\"     : ");
	fprintf(file, "\"%s\";\n  ",bookt.id);
	fprintf(file, "%s","		\"taken\"  : ");
	fprintf(file, "\"%d\";\n",bookt.taken);
	fprintf(file, "%s","\n");
	fprintf(file, "%s","	},");
	fprintf(file, "%s","\n");

	/*fseek(file, -0, SEEK_END);
	if(fgetc(file)!=']'){
		fprintf(file,"%s","]\n");
	}*/

	fclose(file);
}

Books* read_book(int book_nb[1]){
	//

	//Statement & Initialization :
	int i =0, j =0;
	(*book_nb)=0;
	Books* list=NULL;
	FILE* file=NULL;
	char tmp =' ';
	char tmp2[SIZE_MAX];

	//Open the file "book.txt"
	file=fopen("book.txt","r");
	if(file ==NULL){
		printf("Can't open the file book.txt\n");
		exit(1);
	}

	//Get the number of book (*book_nb)
	do{
		tmp=fgetc(file);
		if(tmp=='{'){
			(*book_nb)++;
		}
	} while(tmp!=EOF);

	//Allocate the memory for the list of books (list)
	list=malloc((*book_nb) * sizeof(Books));
	if (list == NULL) {
		printf("Erreur allocation memoire.");
		exit(1);
	}

	//Get the informations for all launchers
	rewind(file);
	for(i =0; i <(*book_nb); i ++){
		do{
		tmp =fgetc(file);
			if(tmp =='"'){
				fgets(tmp2, 12, file);

				//Get title
				if(strcmp(tmp2, "Title\"  : \"") ==0){
					fgets(list[i].title, SIZE_MAX +3, file);

				//Get author
				}else if(strcmp(tmp2, "Author\" : \"") ==0){
					fgets(list[i].author, SIZE_MAX +3, file);

				//Get genre
				}else if(strcmp(tmp2, "Genre\"  : \"") ==0){
					fgets(list[i].genre, SIZE_MAX +3, file);
				

				//Get release date
				}else if(strcmp(tmp2, "Release\": \"") ==0){
					fgets(list[i].release, 9, file);

				//Get id
				}else if(strcmp(tmp2, "ID\"     : \"") ==0){
					fgets(list[i].id, 3, file);

				//Get taken
				}else if(strcmp(tmp2, "taken\"  : \"") ==0){
					list[i].taken =fgetc(file) -48;
				}
			}
		}while(tmp !='}');

		//Delete the '";\n' character from the title
		j =0;
		while(list[i].title[j] !='"' && j <=SIZE_MAX +2){
			j ++;
		}
		list[i].title[j] ='\0';

		//Delete the '";\n' character from the author
		j =0;
		while(list[i].author[j] !='"' && j <=SIZE_MAX +2){
			j ++;
		}
		list[i].author[j] ='\0';

		//Delete the '";\n' character from the genre
		j =0;
		while(list[i].genre[j] !='"' && j <=SIZE_MAX +2){
			j ++;
		}
		list[i].genre[j] ='\0';
	}

	fclose(file);

	return list;
}
/*
int main(){
	//

	//Statement & Initialization :
	Books* list_books=NULL;
	int book_nb =0;

	list_books =read_book(&book_nb);
	create_book(list_books, book_nb);

	return 0;
}*/
