#include <stdlib.h>
#include <stdio.h>

#define STR(x) #x

int main(void)
{
	printf("%s\n", STR('It's a long string'));	
	return 0;
}
