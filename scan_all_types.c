#include "headers.h"

char* scan_text(char* ask, char* error, int taille_max){
	//Statement :
	char text[taille_max];
	char text2[taille_max];
	int okay;
	char i;

	//Initialization :
	okay =0;
	i =0;

	do{
		memset(text2, '\0', sizeof(text));
		printf("%s\n", ask);
		strcpy(text, fgets(text, taille_max, stdin));
		//fgets(text, taille_max, stdin);

		printf("Voici le texte : %s\n", text);
		printf("Voici le text2 : %s\n", text2);
		//printf("strlen(text) :%d\n", strlen(text2));

		strncpy(text2, text, strlen(text2));

		printf("Voici le texte modifié : %s\n", text2);
		/*for(i =0; i <strlen(text); i++){
			if(text[i] <65 || (text[i] >90 && text[i] <96) || text[i] >122){
				//printf("Voici le texte : %s\n", text);
				okay =1;
				printf("not oki\n");
			}
		}

		if (okay !=0){
			printf("%s\n", error);
		}*/
	} while(okay !=0);
	return text;
}

int main(){
	char* text;
	text =scan_text("Saisir nom auteur", "ous ne pouvez pas saisir des charactères différents des lettres", 50);
	//printf("Voici le texte : %s\n", text);
	return 0;
}
