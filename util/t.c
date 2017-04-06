#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[])
{
	char *str = "string";
	printf("%s\n", str);
	printf("%d\n", strlen(str));
	char *str2 = "";
	printf("%s\n", str2);
	printf("%d\n", strlen(str2));
}
