#include <headers.h>

int date_comparison(long borrow_date, int type_user, int* comparison){

	//Statement & Initialization :
	time_t seconds;
	seconds = time(NULL);

	//Calculate how many second the user have left to return a book
	(*comparison)=seconds-borrow_date;

	//For a student
	if(type_user==1){
		if(*comparison<=120 && *comparison>0){
			return 1;
		}
		else{
			return 0;
		} 
	}

	//For a teacher
	else{
		if(*comparison<=180 && *comparison>0){
			return 1;
		}
		else{
			return 0;
		}
	}
}

/*
int main(){
	//Exemples of how to use all functions in this file.

	//Statement & Initialization :
	long int borrow_date;
	int comparison;

	//date_comparison(borrow_date, 1, &comparison);
	//printf("comparison :%ld!\n", comparison);
}
/*
