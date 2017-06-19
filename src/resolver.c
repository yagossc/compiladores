#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../util/defines.h"

//Typedef for token struct
typedef struct Token
{
	int set;
	char token_name[MAX_ID];
	char lexem[MAX_ID];
	char attribute[MAX_ID];
}t_token;

//Typedef for Hashmap (t_tokens array)
typedef struct Hashmap
{
	t_token hmap[SIZE];
}t_hashmap;


//Halfass solution to sintatic analyzer's buffer
typedef struct Buffer
{
	t_token buffer[SIZE];
}s_buffer;

//Calculates table's index over lexem
unsigned long hashFunction(char *id)
{
	unsigned long h = 0;
	for(int i = 0; i < strlen(id); i++)
	{
		h +=(int)id[i];
	}

	return h;
}

//Print token elements
void print_token(t_token token)
{
	char *s;
	if(token.set)
		printf("------------------------------\n[TOKEN]: %s\n[Lexem]: %s\n[Atribute]: %s\n",
		token.token_name,
		token.lexem,
		token.attribute);
}

//Insert t_token into t_hashmap
void insert_token(t_hashmap *hm, char *lexem, char *token_name)
{	
	//Calculates index
	unsigned long h = hashFunction(lexem);
	t_token token;

	//Clear buffers
	memset(token.token_name, '\0', MAX_ID);
	memset(token.lexem, '\0', MAX_ID);

	//Safely copy content to buffers
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.lexem, lexem, strlen(lexem));
	strncpy(token.attribute,"\0", 1);

	//Set and atribute table's element
	token.set = 1;
	hm->hmap[h] = token;
}

//Get hashmap's (t_hashmap) element
t_token get_element(t_hashmap *hm, char *lexem, t_token token)
{
	unsigned long h = hashFunction(lexem);

	if(hm->hmap[h].set)
	{
		token = hm->hmap[h];
		//print_token(token);
	}

	return token;
}

//Check for existent entry at hashmap
int check_table(t_hashmap *hm, char *lexem)
{
	unsigned long h = hashFunction(lexem);
	if(!hm->hmap[h].set)
		return 0;
	return 1;
}

//Initialize hashtable(t_hashmap) with command words
void initialize_table(t_hashmap *hm)
{
	//Populate array with 'empty' tokens
	for(int i = 0; i < SIZE; i++)
	{
		t_token token = {.set = 0, .token_name="", .lexem="", .attribute="\0"};
		hm->hmap[i] = token;
	}

	//Command words array
	char *init[] = 
	{"inicio","varinicio",
	 "varfim","escreva",
	"leia", "se", "entao",
	"fimse", "fim"};

	//Insert command words in t_hashmap
	for(int i = 0; i < 9; i++)
		insert_token(hm, init[i], "PALAVRA DE COMANDO");
}

void initialize_buffer(s_buffer *buffer)
{
	for(int i = 0; i < SIZE; i++)
	{
		t_token token = {.set = 0, .token_name="", .lexem="", .attribute="\0"};
		buffer->buffer[i] = token;
	}
}
//Populate and Set t_token
t_token set_token(t_token token, char *token_name, char *lexem, char *attribute)
{
	token.set = 1;
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.lexem, lexem, strlen(lexem));
	if(strlen(attribute) > 0)
		strncpy(token.attribute, attribute, strlen(attribute));
	else
		strncpy(token.attribute, "\0", 1);
	return token;
}

//Resolve table's column
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
	else if(c == '*' || c == '/') return 15;
	else if(c == '(') return 16;
	else if(c == ')') return 17;
	else if(c == ';') return 18;
	else if(c == '+') return 20;
	else return 21;
}



//Resolve state on table given curr. state and character read from lexem
t_token state_resolver(int state, char *lexem, t_hashmap *table, s_buffer *buffer)
{
	t_token token = {.set = 0, .token_name="", .lexem="", .attribute=""};
	if(state == ID)
	{
		if(!check_table(table, lexem))
			insert_token(table, lexem,"ID");
			
		token = get_element(table, lexem, token);
//		return token;
	}
	else if(state == INT)
		token = set_token(token, "NUM", lexem, "INT");
	
	else if(state == REAL)
		token = set_token(token, "NUM", lexem, "REAL");
	
	else if(state == STR)
		token =	set_token(token, "STR", lexem, "\0");
	
	
	else if(state == _ATRIB_ || state == OPER || state == _OPER_)
		token = set_token(token, "OPR", lexem, "\0");

	else if(state == ATRIB)
		token = set_token(token, "ATRIB", lexem, "\0");

	
	else if(state == ARITM)
		token = set_token(token, "OPM", lexem, "\0");

	
	else if(state == COMMENT){token.set=0;}
	else if(state == ERROR){} //token = set_token(token, "ERRO", lexem, "\0");

	else if(state == _eof_)
		token =	set_token(token, "Eof", "End of file", "\0");

	else if(state == AB_P)
		token =	set_token(token, "AB_P", lexem, "\0");
	
	else if(state == FC_P)
		token =	set_token(token, "FC_P", lexem, "\0");
	
	else if(state == PT_V)
		token = set_token(token, "PT_V", lexem, "\0");
	
	else if(state == EXP)
		token = set_token(token, "NUM", lexem, "EXP");

	else{token.set=0;}
	
	//At this stage of the assignment we must only print the t_token on screen
	//print_token(token);
	//insert_word(buffer, token);
	return token;
}

