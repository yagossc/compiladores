#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

unsigned long hashFunction(char *id)
{
	unsigned long h = 0;
	for(int i = 0; i < strlen(id); i++)
	{
		h +=(int)id[i];
	}
	
	return h;
}

void print_token(t_token token)
{
	if(token.set)
	printf("TOKEN: %s | Lexem: %s | Atribute: |\n", token.token_name, token.lexem);
}


void insert_token(t_hashmap * hm, char *lexem, char *token_name)
{	
	unsigned long h = hashFunction(lexem);
	t_token token;
	memset(token.token_name, '\0', MAX_ID);
	memset(token.lexem, '\0', MAX_ID);
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.lexem, lexem, strlen(lexem));
	token.set = 1;
	hm->hmap[h] = token;
}

void get_element(t_hashmap *hm, char *lexem, t_token token)
{
	unsigned long h = hashFunction(lexem);

	if(hm->hmap[h].set)
	{
		token = hm->hmap[h];
		print_token(token);
	}
}

int check_table(t_hashmap *hm, char *lexem)
{
	unsigned long h = hashFunction(lexem);
	if(!hm->hmap[h].set)
		return 0;
	return 1;
}

void initialize_table(t_hashmap *hm)
{
	for(int i = 0; i < SIZE; i++)
	{
		t_token token = {.set = 0, .token_name="", .lexem="", .atribute=""};
		hm->hmap[i] = token;
	}
	char *init[] = 
	{"inicio","varinicio",
	 "varfim","escreva",
	"leia", "se", "entao",
	"fimse", "fim"};
	char *token_name = "PALAVRA DE COMANDO";
	for(int i = 0; i < 9; i++)
		insert_token(hm, init[i], token_name);
}

t_token set_token(t_token token, char *token_name, char *lexem)
{
	token.set = 1;
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.lexem, lexem, strlen(lexem));
	return token;
}


int column_resolver(char c)
{
	if(c == 'E') return 19;
	else if(isalpha(c)) return 0;
	else if(isdigit(c)) return 1;
	else if(c == '.') return 2;
	else if(c == ' ') return 3;
	else if(c == '	') return 4;
	else if(c == '\n') return 5;
	else if(c == '"') return 6;
	else if(c == '_') return 7;
	else if(c == EOF) return 8;
	else if(c == '{') return 9;
	else if(c == '}') return 10;
	else if(c == '<') return 11;
	else if(c == '-') return 12;
	else if(c == '>') return 13;
	else if(c == '=') return 14;
	else if(c == '+' || c == '*' || c == '/') return 15;
	else if(c == '(') return 16;
	else if(c == ')') return 17;
	else if(c == ';') return 18;
	else return 20;
}


void state_resolver(int state, char *lexem, t_hashmap *table)
{
	t_token token = {.set = 0, .token_name="", .lexem=""};
	if(state == ID)
	{
		if(!check_table(table, lexem))
			insert_token(table, lexem,"ID");
			
		get_element(table, lexem, token);
		return;
	}
	else if(state == INT)
		token = set_token(token, "INT", lexem);
	
	else if(state == REAL)
		token = set_token(token, "REAL", lexem);
	
	else if(state == STR)
		token =	set_token(token, "STR", lexem);
	
	
	else if(state == _ATRIB_ || state == OPER || state == _OPER_)
		token = set_token(token, "OPR", lexem);

	else if(state == ATRIB)
		token = set_token(token, "ATRIB", lexem);

	
	else if(state == ARITM)
		token = set_token(token, "OPM", lexem);

	
	else if(state == COMMENT){}
	else if(state == ERROR)
		token =	set_token(token, "ERRO", lexem);

	else if(state == _eof_)
		token =	set_token(token, "Eof", "End of file");

	else if(state == AB_P)
		token =	set_token(token, "AB_P", lexem);
	
	else if(state == FC_P)
		token =	set_token(token, "FC_P", lexem);
	
	else if(state == PT_V)
		token = set_token(token, "PT_V", lexem);
	
	else if(state == EXP)
		token = set_token(token, "EXP", lexem);

	else{token.set=0;}

	print_token(token);
}
