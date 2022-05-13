#include "headers.h"

typedef struct{
	char* title[50];
	char* author[50];
	char* genre[50];
	int release;
} books;

void create_book(){
	FILE* file;
	books bookt;
	file=NULL;
	file=fopen("book.txt","a+");
	if(file==NULL){
		printf("Can't open the file book.txt\n");
		exit(0);
	}		

	printf("Title of the book\n");
	scanf("%s", &bookt.title);
	

	printf("Name of the author\n");
	scanf("%s", &bookt.author);
	

	printf("Genre of the book\n");
	scanf("%s", &bookt.genre);
	

	printf("Release date of the book\n");
	scanf("%d", &bookt.release);
	


/*	fprintf(file,"%s","[\n");
	fprintf(file,"%s","]\n");
*/

	rewind(file);
	if(fgetc(file)!='['){
		fprintf(file,"%s","[\n");
		//printf("passage du test\n");
	}

	fprintf(file,"%s","	{\n");
	fprintf(file,"%s","		\"Title\"  : ");
	fprintf(file,"\"%s\";\n",bookt.title);
	fprintf(file,"%s","		\"Author\" : ");
	fprintf(file,"\"%s\";\n",bookt.author);
	fprintf(file,"%s","		\"Genre\"  : ");
	fprintf(file,"%s;\n",bookt.genre);
	fprintf(file,"%s","		\"Release\": ");
	fprintf(file,"%d;\n  ",bookt.release);
	fprintf(file,"%s","\n");
	fprintf(file,"%s","	},");		
	fprintf(file,"%s","\n");

}











int main(){
	create_book();
	create_book();
	return 0;
}
