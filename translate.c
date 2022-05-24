#include "headers.h"

long int char_to_long(char* str){
	//

	//Statement & Initialization :
	char *ptr;
	long int res =1000000000;

	res = strtol(str, NULL, 10);
	printf("The number(unsigned long integer) is %ld\n", res);

	return res;
}

/*
int main(){
	//

	//Statement & Initialization :
	int id_nb =0;
	Id* list_id =NULL;
	long int test =1000000000;

	test =char_to_long("12345");

	return 0;
}
*/
