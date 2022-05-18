#include "headers.h"

void create_book(){
	//

	//Statement & Initialization :
	FILE* file;
	Books bookt;
	file=NULL;

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

	printf("\n");
	printf("bookt.release :%s\n", bookt.release);
	printf("bookt.id :%s\n", bookt.id);

	bookt.taken=0;

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

Books* read_book(){
	//

	//Statement & Initialization :
	int i =0, j =0, book_nb=0;
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

	//Get the number of book (book_nb)
	do{
		tmp=fgetc(file);
		if(tmp=='{'){
			book_nb++;
		}
	} while(tmp!=EOF);

	//Allocate the memory for the list of books (list)
	list=malloc((book_nb) * sizeof(Books));
	if (list == NULL) {
		printf("Erreur allocation memoire.");
		exit(1);
	}

	//Get the informations for all launchers
	rewind(file);
	for(i =0; i <book_nb; i ++){
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
					fgets(list[i].release, 8, file);

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
	printf("list[0].title :%s\n", list[0].title);
	printf("list[0].author :%s\n", list[0].author);
	printf("list[0].genre :%s\n", list[0].genre);
	printf("list[0].release :%s\n", list[0].release);
	printf("list[0].id :%s\n", list[0].id);
	printf("list[0].taken :%d\n", list[0].taken);

	fclose(file);
}

int main(){
	Books* list_books=NULL;
	//list_books =read_book();
	create_book();

	free(list_books);
	return 0;
}
