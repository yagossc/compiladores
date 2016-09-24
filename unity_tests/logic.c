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

	char *tes = "zzxx1234zzzss";
	for(int i = 0; i < strlen(str); i++)
	{
		h += pow(13, i)*str[i];
		printf("%d: h = %ld\n", i, h);
	}
	 long teste = ULONG_MAX - h;
	printf("TESTE: %lu\n", teste);
	unsigned long hash = h%251;
	printf("==>HUGE_H mod ULONG_MAX(hashmap size) = %ld\n", hash);
	h=0;
	for(int i = 0; i < strlen(i1); i++)
	{
		h += pow(43, i)*i1[i];
		printf("%d: h = %ld\n", i, h);
	}hash = h%251;printf("HUGE_H mod ULONG_MAX(hashmap size) = %ld\n", hash);h=0;
	for(int i = 0; i < strlen(i2); i++)
	{
		h += pow(43, i)*i2[i];
		printf("%d: h = %ld\n", i, h);
	}hash = h%251;printf("HUGE_H mod ULONG_MAX(hashmap size) = %ld\n", hash);h=0;
	for(int i = 0; i < strlen(i3); i++)
	{
		h += pow(43, i)*i3[i];
		printf("%d: h = %ld\n", i, h);
	}hash = h%251;printf("HUGE_H mod ULONG_MAX(hashmap size) = %ld\n", hash);h=0;
	for(int i = 0; i < strlen(i4); i++)
	{
		h += pow(43, i)*i4[i];
		printf("%d: h = %ld\n", i, h);
	}hash = h%251;printf("HUGE_H mod ULONG_MAX(hashmap size) = %ld\n", hash);h=0;
	/*for(int i = 0; i < strlen(str); i++)
	{
		h += pow(43, i)*str[i];
		printf("%d: h = %ld\n", i, h);
	}
	for(int i = 0; i < strlen(str); i++)
	{
		h += pow(43, i)*str[i];
		printf("%d: h = %ld\n", i, h);
	}
	for(int i = 0; i < strlen(str); i++)
	{
		h += pow(43, i)*str[i];
		printf("%d: h = %ld\n", i, h);
	}*/
	printf("ULONG_MAX = %lu\n", ULONG_MAX);
	

	char c = 'a';

	char d[128];
	memset(d, '\0', 128);
	d[0] = 'c';
	d[1] = 'a';
	d[2] = 's';
	d[3] = 'a';
	char *end = "\0";
	strcat(d, end);
//	char e = 'b';
//	char *f = '\0';
//	strcat(d, &e);
//	strcat(d, f);
	printf("%s\n", d);

	char *strr = malloc(sizeof(char)*128);
	for(int i = 0; i < 128; i++)
		strr[i] = '\0';
	strr[0] = 'f';
	strr[1] = 'o';
	strr[2] = 'i';

	printf("%s\n", strr);
	return 0;
}
