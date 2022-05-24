
long int char_to_long(char* str){
	//

	//Statement & Initialization :
	char *ptr;
	long int res =1000000000;

	res = strtol(str, NULL, 10);
	printf("The number(unsigned long integer) is %ld\n", res);

	return res;
}

int main(){
	//

	//Statement & Initialization :
	int id_nb =0;
	Id* list_id =NULL;
	long int test =1000000000;

	printf("oki doki !\n");
	test =char_to_long("12345");
	printf("long :%lg!\n", test);
/*
	date_comparison(borrow_date, type_user);
	list_id =read_id(&id_nb);
//	display(list_id, id_nb, "zaviou");
//	create_id(list_id, id_nb);
//	date_comparison(1, "Thu May 19 15:52:30 2022");*/
	return 0;
}
