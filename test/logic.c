#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int main()
{
	int logic = 17;
	int ilogic = 0;

	if(logic)
		printf("Not logic.\n");
	if(!ilogic)
		printf("Not Ilogic.\n");
	switch(logic)
	{
		case 17:
			printf("WORKS!.\n");
			break;
		default:
			break;
	}

	char *str = "zzzzzzzzzzz";

	int k = 0;
	for(int i = 0; i < strlen(str); i++)
		k += (int)str[i];
	printf("10*z = (int)%d\n", k);

	unsigned long h = 0;
	char *i1 = "inicio";
	char *i2 = "varinicio";
	char *i3 = "varfim";
	char *i4 = "escreva";
	char *i5 = "leia";
	char *i6 = "se";
	char *i7 = "entao";
	char *i8 = "fimse";
	char *i9 = "fim";

	for(int i = 0; i < strlen(i1); i++)
	{
		h += pow(127, i)*i1[i];
	}
	printf("HUGE H = %ld\n", h);

	unsigned long hash = h%ULONG_MAX;
	printf("HUGE_H mod ULONG_MAX(hashmap size) = %ld\n", hash);
	printf("ULONG_MAX = %lld\n", LONG_MAX);
/*	for(int i = 0; i < strlen(i2); i++)
	{
		h = (13*h + (int(i2[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	for(int i = 0; i < strlen(i1); i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);*/
	return 0;
}
