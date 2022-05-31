#include "headers.h"

void scan_text(char* ask, char* text, int taille_max){
	//

	//Statement & Initialization :
	int check;
	int i;
	char* error_char ="Vous ne pouvez pas saisir des charactères différents des lettres\n";


	do{
		text[0] ='\0';
		check =0;
		i =0;

		//Enter text
		printf("%s\n", ask);
		fgets(text, taille_max, stdin);

		//Delete the '\n' character
		do{
			i ++;
		} while(text[i] !='\n');
		text[i] ='\0';

		//Check if only letters have been given
		for(i =0; i <strlen(text); i++){
			if((text[i] <65 && text[i] !=32) || (text[i] >90 && text[i] <96) || text[i] >122){
				check =1;
			}
		}

		//Explain the problem if there is one
		if (check !=0){
			printf(ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, error_char);
		}

	} while(check !=0);
}

void scan_word(char* ask, char* word, int taille_max){
	//

	//Statement & Initialization :
	int check;
	int i;
	char* error_space ="Vous ne pouvez pas saisir d'espaces\n";


	do{
		word[0] ='\0';
		check =0;
		i =0;

		//Enter text
		printf("%s\n", ask);
		fgets(word, taille_max, stdin);

		//Delete the '\n' character
		do{
			i ++;
		} while(word[i] !='\n');
		word[i] ='\0';

		//Check if space (' ') has been given
		for(i =0; i <strlen(word); i++){
			if(word[i] ==' '){
				check =1;
			}
		}

		//Explain the problem if there is one
		if (check !=0){
			printf(ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, error_space);
		}

	} while(check !=0);
}

long int scan_long(char* ask, char* lg, int taille_max){
	//

	//Statement & Initialization :
	int check;
	int i;
	char* error_char ="Vous ne pouvez pas saisir des charactères différents des chiffres\n";


	do{
		lg[0] ='\0';
		check =0;
		i =0;

		//Enter text
		printf("%s\n", ask);
		fgets(lg, taille_max, stdin);

		//Delete the '\n' character
		do{
			i ++;
		} while(lg[i] !='\n');
		lg[i] ='\0';

		//Check if only numbers have been given
		for(i =0; i <strlen(lg); i++){
			if(lg[i] >'9' || lg[i] <'0'){
				check =1;
			}
		}

		//Explain the problem if there is one
		if (check !=0){
			printf(ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, error_char);
		}

	} while(check !=0);

	return strtol(lg, NULL, 10);
}

/*
int main(){
	//Exemples of how to use all functions in this file.

	//Statement & Initialization :
	char text[SIZE_MAX];
	long res =0;

	//scan_text("Saisir nom auteur", text, SIZE_MAX);
	//scan_word("Saisir un login", text, SIZE_MAX);
	//res =scan_long("Saisir id book", text, SIZE_MAX);

	return 0;
}
*/
