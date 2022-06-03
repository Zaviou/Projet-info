#include "headers.h"

void scan_text(char* ask, char* text, int taille_max){
	//

	//Statement & Initialization :
	int check_len;
	int i;
	char* error_len ="Vous ne pouvez pas saisir autant de caractères\n";
	char test_len[taille_max];

	do{
		i =-1;
		text[0] ='\0';
		check_len =0;
		test_len[0] ='\0';

		//Enter text
		printf("\n%s\n", ask);
		do{
			fgets(text, taille_max, stdin);
			//Delete the '\n' character from text
			i =0;
			while(text[i] !='\n' && i <taille_max){
				i ++;
			}
			if(text[i] =='\n'){
				text[i] ='\0';
			}
		} while(strlen(text) ==0);

		//Fill the test_len value if needed
		if(strlen(text) ==taille_max -1){
			do{
				fgets(test_len, taille_max +1, stdin);
				test_len[0] ='a';
			}while(strlen(test_len) ==taille_max);
		}

		//Delete the '\n' character from test_len
		i =0;
		while(test_len[i] !='\n' && i <taille_max){
			i ++;
		}
		if(test_len[i] =='\n'){
			test_len[i] ='\0';
		}

		//Check the lenght of what's given
		if (test_len[0] !='\0'){
			check_len =1;
		}

		//Explain the problem if there is one
		if (check_len ==1){
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_len);
		}
	} while(check_len !=0);

	//Delete spaces if there are
	while(text[strlen(text) -1] ==' '){
		text[strlen(text) -1] ='\0';
	}
}

void scan_word(char* ask, char* word, int taille_max){
	//

	//Statement & Initialization :
	int check_len, check_space;
	int i;
	char* error_space ="Vous ne pouvez pas saisir d'espaces\n";
	char* error_len ="Vous ne pouvez pas saisir autant de caractères\n";
	char test_len[taille_max];


	do{
		i =-1;
		word[0] ='\0';
		check_len =0;
		check_space =0;
		test_len[0] ='\0';

		//Enter word
		printf("\n%s\n", ask);
		do{
			fgets(word, taille_max, stdin);

			//Delete the '\n' character from word
			i =0;
			while(word[i] !='\n' && i <taille_max){
				i ++;
			}
			if(word[i] =='\n'){
				word[i] ='\0';
			}
		} while(strlen(word) ==0);

		//Fill the test_len value if needed
		if(strlen(word) ==taille_max -1){
			do{
				fgets(test_len, taille_max, stdin);
				test_len[0] ='a';
			}while(strlen(test_len) ==taille_max);
		}

		//Delete the '\n' character from test_len
		i =0;
		while(test_len[i] !='\n' && i <taille_max){
			i ++;
		}
		if(test_len[i] =='\n'){
			test_len[i] ='\0';
		}

		//Check if space (' ') has been given
		for(i =0; i <strlen(word); i++){
			if(word[i] ==' '){
				check_space =1;
			}
		}

		//Check the lenght of what's given
		if (test_len[0] !='\0'){
			check_len =1;
		}

		//Explain the problem if there is one
		if (check_len ==1){
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_len);
		} if (check_space ==1){
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_space);
		}
	} while(check_len !=0 || check_space !=0);

	//Delete spaces if there are
	while(word[strlen(word) -1] ==' '){
		word[strlen(word) -1] ='\0';
	}
}

long int scan_long(char* ask, int taille_max){
	//

	//Statement & Initialization :
	int check_len =-1, check_char =-1;
	int i;
	char lg[taille_max];
	char test_len[taille_max];
	char* error_char ="Vous ne pouvez pas saisir des caractères différents des chiffres\n";
	char* error_len ="Vous ne pouvez pas saisir autant de caractères\n";


	do{
		i =-1;
		lg[0] ='\0';
		check_len =0;
		check_char =0;
		test_len[0] ='\0';

		//Enter long
		printf("\n%s\n", ask);
		do{
			fgets(lg, taille_max, stdin);

			//Delete the '\n' character from lg
			i =0;
			while(lg[i] !='\n' && i <taille_max){
				i ++;
			}
			if(lg[i] =='\n'){
				lg[i] ='\0';
			}
		} while(strlen(lg) ==0);

		//Fill the test_len value if needed
		if(strlen(lg) ==taille_max -1){
			fgets(test_len, taille_max +1, stdin);
			while(strlen(test_len) ==taille_max){
				fgets(test_len, taille_max +1, stdin);
				test_len[0] ='a';
			}
		}

		//Delete the '\n' character from test_len
		i =0;
		while(test_len[i] !='\n' && i <taille_max){
			i ++;
		}
		if(test_len[i] =='\n'){
			test_len[i] ='\0';
		}

		//Check if only numbers have been given
		for(i =0; i <strlen(lg); i++){
			if(lg[i] >'9' || lg[i] <'0'){
				check_char =1;
			}
		}

		//Check the lenght of what's given
		if (test_len[0] !='\0' && test_len[0] !='\n'){
			check_len =1;
		}

		//Explain the problem if there is one
		if (check_len ==1){
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_len);
		} if (check_char ==1){
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_char);
		}
	} while(check_len !=0 || check_char !=0);

	return strtol(lg, NULL, 10);
}

int scan_int(char* ask, int min, int max){
	//

	//Statement & Initialization :
	int check_len, check_char, check_gap;
	int i, res;
	char value[2];
	char* error_char ="Vous ne pouvez pas saisir des caractères différents des chiffres\n";
	char* error_len ="Vous ne pouvez pas saisir autant de caractères\n";
	char* error_gap ="La valeur saisie n'est pas dans l'intervalle souhaitée\n";
	char test_len[10];


	do{
		i =-1;
		value[0] ='\0';
		check_len =0;
		check_char =0;
		check_gap =0;
		test_len[0] ='\0';

		//Enter long
		printf("\n%s\n", ask);
		do{
			fgets(value, 2, stdin);

			//Delete the '\n' character from value
			do{
				i ++;
			} while(value[i] !='\n' && i <2);
			value[i] ='\0';
		} while(strlen(value) ==0);

		//Fill the test_len value if needed
		do{
			fgets(test_len, 10, stdin);
		}while(strlen(test_len) ==10);

		//Delete the '\n' character from test_len
		i =0;
		while(test_len[i] !='\n' && i <10){
			i ++;
		}
		if(test_len[i] =='\n'){
			test_len[i] ='\0';
		}

		//Check if only numbers have been given
		if(value[0] >'9' || value[i] <'0'){
			check_char =1;
		}
		for(i =0; i <strlen(test_len); i++){
			if(test_len[i] >'9' || test_len[i] <'0'){
				check_char =1;
			}
		}

		//Check the lenght of what's given
		if (test_len[0] !='\0'){
			check_len =1;
		}

		res =*value -48;
		//Explain the problem if there is one
		if (check_len ==1){
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_len);
		} if (check_char ==1){
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_char);
		} if (check_len ==0 && check_char ==0 && (res <min || res >max)){
			check_gap =1;
			printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, error_gap);
		}
	} while(check_len !=0 || check_char !=0 || check_gap !=0);

	return res;
}
/*
int main(){
	//Exemples of how to use all functions in this file.

	//Statement & Initialization :
	char text[SIZE_MAX];
	long res =0;
	int a;

	//scan_text("Saisir nom auteur", text, SIZE_MAX);
	//scan_word("Saisir un login", text, SIZE_MAX);
	//res =scan_long("Saisir id book", text, SIZE_MAX);
	//a =scan_int("Saisir 1, 2 ou 3", 1, 3);

	//printf("text :%s!\n", text);
	//printf("res :%ld!\n", res);
	//printf("a :%d!\n", a);

	return 0;
}
*/
