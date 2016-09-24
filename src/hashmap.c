#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include "../util/defines.h"


typedef struct Token
{
	int set;
	char token_name[MAX_ID];
	char lexem[MAX_ID];
	char atribute[MAX_ID];
}t_token;

typedef struct Hashmap
{
	t_token hmap[SIZE];
}t_hashmap;
unsigned int hashFunction(char *id)
{
	unsigned int h = 0;
	for(int i = 0; i < strlen(id) || i < 10; i++)
	{
		h += pow(13, i)*id[i];
	}
	h = h%251;
	return h;
}

void print_token(t_token token)
{
	printf("Token_name: %s; Lexem: %s; Atribute: \n", token.token_name, token.lexem);
}
void insert_token(t_hashmap * hm, char *lexem, char *token_name)
{	
//	printf("INSERT TOKEN!\n");
	unsigned int h = hashFunction(lexem);
	t_token token;
	memset(token.token_name, '\0', MAX_ID);
	memset(token.lexem, '\0', MAX_ID);
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.lexem, lexem, strlen(lexem));
	token.set = 1;
	printf("***********NAME: %s   LEX: %s \n   SET: %d\n*********", token.token_name, token.lexem, token.set);
	hm->hmap[h] = token;
//	printf("END INSERT TOKEN\n");
}

t_token get_element(t_hashmap *hm, char *lexem)
{
//	printf("GET ELEMENT!\n");
//	printf("LEXEMA: %s\n", lexem);
	unsigned int h = hashFunction(lexem);
	printf("Indice H: %d\n", h);
	
	//if(hm->hmap[h].set)
	//{
		t_token token = hm->hmap[h];
		printf("=============>TESTANDO<============\n");
		print_token(hm->hmap[h]);
		printf("====>LEXXXXEMA: %s<=====\n", hm->hmap[h].lexem);
		return token;
	//}
}

int check_table(t_hashmap *hm, char *lexem)
{
	printf("CHECK TABLE!\n");
	unsigned int h = hashFunction(lexem);
	if(hm->hmap[h].set)
		return 1;
	return 0;
}
void initialize_table(t_hashmap *hm)
{
	for(int i = 0; i < SIZE; i++)
	{
		t_token token = {.set = 0, .token_name="", .lexem="", .atribute=""};
		hm->hmap[i] = token;
//		printf("DID I GET HERE?\n");
	}
	char *init[] = 
	{"inicio","varinicio",
	 "varfim","escreva",
	"leia", "se", "entao",
	"fimse", "fim"};
	for(int i = 0; i < 9; i++)
		printf("%s\n", init[i]);
	char *token_name = "PALAVRA DE COMANDO";
	for(int i = 0; i < 9; i++)
		insert_token(hm, init[i], token_name);

	
}

void set_token(t_token token, char *token_name, char *lexem)
{
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.token_name, token_name, strlen(token_name));
}


/*
int main(int argc, char *argv[])
{

	t_hashmap *table = malloc(sizeof(t_hashmap));
	
	initialize_table(table);
	t_token token = get_element(table, "inicio");
	if(token.set)
		printf("Token: %s\nLexem: %s\n", token.token_name, token.lexem);

	insert_token(table, "teste", "ID");
	token = get_element(table, "teste");
	print_token(token);

	return 0;
	}*/
