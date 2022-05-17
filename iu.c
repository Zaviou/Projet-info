#include "headers.h"

void start(){
	system("clear");
	int answer;
	printf("______________________________________________________________________________\n\n");
	printf("                          Application CY-BiblioTECH                             ");
	printf("______________________________________________________________________________\n\n");
	printf("Bienvenue dans la bibliothèque de CY-TECH!\n\n");
	do{
		printf("Que souhaitez-vous faire ?\n");
		printf("1. Se connecter \n"); 
		printf("2. S'identifier\n\n\n\n");
		scanf("%d",&answer);
		if(answer==1){
			printf("ui\n\n\n");
		}
		else if(answer==2){
			printf("nion è_é\n\n\n");
		}
	}while(answer!=1 && answer !=2);
}



void book_management (){
	int answer;
	system("clear");
	printf("______________________________________________________________________________\n\n");
	printf("                          Application CY-BiblioTECH                             ");
	printf("______________________________________________________________________________\n\n");
	do{
		printf("Quelle action souhaitez-vous réaliser ?\n");
		printf("1. Emprunter un nouveau livre\n"); 
		printf("2. Rendre un livre\n");
		printf("3. Se déconnecter.\n\n\n");
		scanf("%d",&answer);
		if(answer==1){
			printf("ui\n\n\n");
		}
		else if(answer==2){
			printf("nion è_é\n\n\n");
		}
		else if(answer==3){
			start();
		}
	}while(answer!=1 && answer !=2 && answer!=3);
}














int main(){
//	start();
	book_management ();
	return 0;
}
