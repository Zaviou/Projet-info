#include "headers.h"



#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main () {
	printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
	return 0;
}
