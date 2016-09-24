#include <stdio.h>
#include <stdlib.h>

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

unsigned int hashFunction(char *id);

void print_token(t_token token);

void insert_token(t_hashmap * hm, char *lexem, char *token_name);

void get_element(t_hashmap *hm, char *lexem, t_token token);

int check_table(t_hashmap *hm, char *lexem);

void initialize_table(t_hashmap *hm);

void set_token(t_token token, char *token_name, char *lexem);

int column_resolver(char c);

void state_resolver(int state, char *lexem, t_hashmap *table);

