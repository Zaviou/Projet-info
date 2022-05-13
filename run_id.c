
typedef struct {
	char login[50];
	char password[50];
	int** books;
	int role;
} Id;

void create_id(){
	//This function has to ask the user his login, password and role, then put thoses informations in the file "id.tkt".

	//Statement :
	char login[50] ={0};
	//Initialization :

	do{
		printf("Veuillez sélectionner un login.\n");
		//scanf("%s", login);
		fgets(login, 50, stdin);
		printf("Voici le login choisi : %s.\n",  login);
	} while (login[0] =='\n');
}

int main(){
	create_id();
	return 0;
}
