#include "headers.h"

typedef struct{
	char title[SIZE_MAX];
	char author[SIZE_MAX];
	char genre[SIZE_MAX];
	int release;
	int taken;
	int id;
} Books;

void create_book(){
	FILE* file;
	Books bookt;
	file=NULL;
	file=fopen("book.txt","a+");
	if(file==NULL){
		printf("Can't open the file book.txt\n");
		exit(1);
	}		

	printf("Title of the book\n");
	scanf("%s", &bookt.title);
	

	printf("Name of the author\n");
	scanf("%s", &bookt.author);
	

	printf("Genre of the book\n");
	scanf("%s", &bookt.genre);
	

	printf("Release date of the book\n");
	scanf("%d", &bookt.release);

	printf("ID of the book\n");
	scanf("%d", &bookt.id);	

	bookt.taken=0;
	
/*	fprintf(file,"%s","[\n");
	fprintf(file,"%s","]\n");
*/

	rewind(file);
	if(fgetc(file)!='['){
		fprintf(file,"%s","[\n");
		//printf("passage du test\n");
	}

	fprintf(file, "%s","	{\n");
	fprintf(file, "%s","		\"Title\"  : ");
	fprintf(file, "\"%s\";\n",bookt.title);
	fprintf(file, "%s","		\"Author\" : ");
	fprintf(file, "\"%s\";\n",bookt.author);
	fprintf(file, "%s","		\"Genre\"  : ");
	fprintf(file, "%s;\n",bookt.genre);
	fprintf(file, "%s","		\"Release\": ");
	fprintf(file, "%d;\n  ",bookt.release);
	fprintf(file, "%s","		\"ID\"     : ");
	fprintf(file, "%d;\n  ",bookt.id);
	fprintf(file, "%s","		\"taken\"  : ");
	fprintf(file, "%d;\n",bookt.taken);
	fprintf(file, "%s","\n");
	fprintf(file, "%s","	},");
	fprintf(file, "%s","\n");

	fseek(file, -0, SEEK_END);
	if(fgetc(file)!=']'){
		fprintf(file,"%s","]\n");
	}
	fclose(file);
}

int read_book(Books* list){
	int i, book_nb=0;
	char tmp;
	list=NULL;
	FILE* file;
	file=NULL;
	file=fopen("book.txt","r");
	do{
		tmp=fgetc(file);
		if(tmp=='{'){
			book_nb++;
		}
	} while(tmp!=EOF);
	list=malloc((book_nb) * sizeof(Books));
	if (list == NULL) {
		printf("Erreur allocation memoire.");
		exit(1);
	}
	rewind(file);
	for(i=0;i<book_nb;i++){
		while(fgets(list[i].title,SIZE_MAX,file)!=NULL){
			printf("%s\n",list[i].title);
		}
		//printf("oki\n");
	}
	free(list);
	fclose(file);
	return 0;
}











int main(){
	Books* list=NULL;
	//create_book();
	read_book(list);
	free(list);
	return 0;
}
