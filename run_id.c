#include "headers.h"

typedef struct {
	char login[50];
	char password[50];
	int** books;
	int role;
} Id;

void create_id(){
	//This function has to ask the user his login, password and role, then put thoses informations in the file "id.tkt".

	//Statement & Initialization :
	char login[50] ={0};
	char pw[50] ={0};
	int role;
	FILE* file =NULL;

	system("clear");

	printf("Veuillez entrer un login.\n");
	scanf("%s", login);
	//fgets(login, 50, stdin);

	printf("Veuillez entrer un mot de passe.\n");
	scanf("%s", pw);

	printf("Veuillez spécifier si vous êtes :\n1. un étudiant ?\n2. un professeur ?\n");
	scanf("%d", &role);

		//Write the informations in the file "id.txt"
	//Open the file "id.txt"
	file =fopen("id.txt","a+");
	if(file ==NULL){
		printf("Can't open the file id.txt\n");
		exit(1);
	}

	//Check if there is already a id in the file
	rewind(file);
	if(fgetc(file)!='['){
		fprintf(file,"%s","[\n");
	}

	//Write
	fprintf(file, "%s", "	{\n");
	fprintf(file, "%s", "		\"Login\"    : ");
	fprintf(file, "\"%s\";\n", login);
	fprintf(file, "%s", "		\"Password\" : ");
	fprintf(file, "\"%s\";\n", pw);
	fprintf(file, "%s", "		\"Role\"     : ");
	fprintf(file, "%d;\n", role);
	fprintf(file, "%s", "		\"Books\"    : [");
	fprintf(file, "%s", "\n			]");
	fprintf(file, "%s", "\n	},");
	fprintf(file, "%s", "\n");
}

void read_id(Id* list){
	//

	//Statement & Initialization :
	FILE* file =NULL;
	list =NULL;
	int id_nb =0;
	char tmp =' ';

	//Open the file "id.txt"
	file =fopen("id.txt","r");
	if(file ==NULL){
		printf("Can't open the file id.txt\n");
		exit(1);
	}
	rewind(file);

	//Get the number of id
	do{
		tmp =fgetc(file);
		if(tmp =='{'){
			id_nb ++;
			printf("oki\n");
		}
	}while(tmp !=EOF);
	printf("id_nb : %d\n", id_nb);

	free(list);
}

int main(){
	Id* list =NULL;
	//create_id();
	read_id(list);

	free(list);
	return 0;
}
