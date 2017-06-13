#include <stdio.h>
#include <stdlib.h>

typedef struct Token
{
	int set;
	char token_name[MAX_ID];
	char lexem[MAX_ID];
	char attribute[MAX_ID];
}t_token;

typedef struct Hashmap
{
	t_token hmap[SIZE];
}t_hashmap;

typedef struct G_symbol
{
	t_token *token;
	struct G_symbol *next;
}g_symbol;

typedef struct SintaticBuffer
{
	g_symbol *head;
	g_symbol *tail;
}s_buffer;

unsigned int hashFunction(char *id);

void insert_word(s_buffer *buffer, t_token token);

void free_buffer(s_buffer *buffer);

void print_buffer(s_buffer *buffer);

void print_token(t_token token);

void insert_token(t_hashmap *hm, char *lexem, char *token_name);

t_token get_element(t_hashmap *hm, char *lexem, t_token token);

void initialize_table(t_hashmap *hm);

int check_table(t_hashmap *hm, char *lexem);

int column_resolver(char c);

t_token set_token(t_token token, char *token_name, char *lexem);

t_token state_resolver(int state, char *lexem, t_hashmap *table, s_buffer *buffer);

