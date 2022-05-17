#include "headers.h"

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
	fprintf(file, "%s", "		\"Role\"     : \"");
	fprintf(file, "%d\";\n", role);
	fprintf(file, "%s", "		\"Books\"    : [");
	fprintf(file, "%s", "\n			]");
	fprintf(file, "%s", "\n	},");
	fprintf(file, "%s", "\n");

	fclose(file);
}

void line_to_id_date(char* line, char* id, char* date){
	//

	//Statement & Initialization :
	char tmp ='0';
	int i =0, mark_id =0, mark_date =0;

	//
	for(i =0; i <strlen(line); i++){
		tmp =line[i];
		//Get id
		if(i >2 && i <6){
			id[mark_id] =tmp;
			mark_id ++;
		//Get date
		}else if(i >8 & i <17){
			date[mark_date] =tmp;
			mark_date ++;
		}
	}
}

void read_id(Id* list){
	//

	//Statement & Initialization :
	FILE* file =NULL;
	list =NULL;
	int id_nb =0, i =0, j =0, nb_borrowed_books =0;
	char tmp =' ';
	char tmp2[SIZE_MAX];

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
		}
	}while(tmp !=EOF);

	//Allocate the memory for the list of ids
	list =malloc(id_nb *sizeof(Id));
	if(list ==NULL){
		printf("Erreur d'allocation de mémoire. Impossible de créer une liste d'identifiants.\n");
		exit(1);
	}

	//Get the informations for all launchers
	rewind(file);
	for(i =0; i <id_nb; i ++){
		do{
		tmp =fgetc(file);
			if(tmp =='"'){
				fgets(tmp2, 14, file);

				//Get login
				if(strcmp(tmp2, "Login\"    : \"") ==0){
					fgets(list[i].login, SIZE_MAX +3, file);

				//Get password
				}else if(strcmp(tmp2, "Password\" : \"") ==0){
					fgets(list[i].password, SIZE_MAX +3, file);

				//Get role
				}else if(strcmp(tmp2, "Role\"     : \"") ==0){
					list[i].role =fgetc(file) -48;

				//Get the borrowed books
				}else if(strcmp(tmp2, "Books\"    : [") ==0){

					//Get the number of borrowed books
					nb_borrowed_books =0;
					do{
						tmp =fgetc(file);
						if(tmp ==';'){
							nb_borrowed_books ++;
						}
					}while(tmp !=']');

						//Get each book (book's id and date)
					//Allocate memory for the list of books (list[i].books)
					list[i].books =malloc (nb_borrowed_books * sizeof(char*));
					if(list[i].books ==NULL){
						printf("Erreur d'allocation de mémoire. Impossible de créer une liste list[i].books.\n");
						exit(1);
					}

					//Allocate memory and fill the list of book's id and their date of borrowing (list[i].books)
					fseek(file, -4 -(nb_borrowed_books *19), SEEK_CUR);
					for(j =0; j <nb_borrowed_books; j++){
						list[i].books[j] =malloc (2 * sizeof(char));
						if(list[i].books[j] ==NULL){
							printf("Erreur d'allocation de mémoire. Impossible de créer une liste list[i].books[j].\n");
							exit(1);
						}

						//Allocate memory the list of book's id(list[i].books[j][0])
						list[i].books[j][0] =malloc (2 * sizeof(char));
						if(list[i].books[j] ==NULL){
							printf("Erreur d'allocation de mémoire. Impossible de créer une liste list[i].books[j][0].\n");
							exit(1);
						}

						//Allocate memory the list of book's id and their date of borrowing (list[i].books[j][1])
						list[i].books[j][1] =malloc (2 * sizeof(char));
						if(list[i].books[j] ==NULL){
							printf("Erreur d'allocation de mémoire. Impossible de créer une liste list[i].books[j][1].\n");
							exit(1);
						}

						//Fill the lists (list[i].books[j][0] et list[i].books[j][1])
						fgets(tmp2, 20, file);
						line_to_id_date(tmp2, list[i].books[j][0], list[i].books[j][1]);
					}
				}
			}
		}while(tmp !='}');

		//Delete the '";\n' character from the login
		j =0;
		while(list[i].login[j] !='"' && j <=SIZE_MAX +2){
			j ++;
		}
		list[i].login[j] ='\0';

		//Delete the '";\n' character from the password
		j =0;
		while(list[i].password[j] !='"' && j <=SIZE_MAX +2){
			j ++;
		}
		list[i].password[j] ='\0';
	}

	free(list);
	fclose(file);
}

int main(){
	Id* list =NULL;
	//create_id();
	read_id(list);
	printf("list[0].login :%s\n", list[0].login);

	free(list);
	return 0;
}
