#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "../util/defines.h"
#define SIZE UINT_MAX

struct Token
{
	int set;
	char *token_name;
	char *lexem;
	char *atribute;
};

struct Hashmap
{
	struct Token hmap[SIZE];
};

unsigned long hashFunction(char *id)
{
	unsigned long h = 0;
	for(int i = 0; i < strlen(id) || i < 10; i++)
	{
		h += pow(13, i)*id[i];
	}
	h = h%251;
	return h;
}

void insert_token(struct Hashmap * hm, char *lexem, char *token_name)
{	
	printf("GOT HERE TOO!\n");
	unsigned int h = hashFunction(lexem);
	printf("%u\n", h);
	int size = sizeof(token_name)/sizeof(char);
	printf("%d\n", size);
	struct Token *token = &hm->hmap[h];
	strncpy(token->token_name, token_name, size);
}

void get_element(struct Hashmap *hm, char *lexem)
{
	unsigned long h = hashFunction(lexem);
	//char *s = hm->hmap[h]->token_name;
	//printf("LEXEMA: %s\n", s);
}

void initialize(struct Hashmap *hm)
{
	printf("GOT HERE!\n");
	char *init[] = 
	{"inicio","varinicio",
	 "varfim","escreva",
	"leia", "se", "entao",
	"fimse", "fim"};
	int s = sizeof(init)/sizeof(char);
	printf("tamanho = %d\n", s);
	for(int i = 0; i < 9; i++)
		printf("%s\n", init[i]);

	for(int i = 0; i < 9; i++)
		insert_token(hm, init[i], "PALAVRA DE COMANDO");

}
int main(int argc, char *argv[])
{

	struct Hashmap *table = malloc(sizeof(struct Hashmap));
	struct Token *token = malloc(sizeof(struct Token));

	token->token_name = "teste";
	printf("%s\n", token->token_name);

	for(int i = 0; i < UINT_MAX; i++)
	{
		table->hmap[i] = {.set = 0, .token_name = "", .lexem = "", .atribute = ""};
	}
	return 0;
}
