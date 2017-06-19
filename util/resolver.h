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


typedef struct Buffer
{
	t_token buffer[SIZE];
}s_buffer;

typedef struct Element
{
	t_token *token;
	t_token *prev;
}t_element;

typedef struct Stack
{
	t_element * bot;
	t_element * top;
}t_stack;

void stack_up(t_stack *stack, t_token *token);

void stack_down(t_stack *stack);

unsigned int hashFunction(char *id);

void insert_word(s_buffer *buffer, t_token token);

void print_token(t_token token);

void insert_token(t_hashmap *hm, char *lexem, char *token_name);

t_token get_element(t_hashmap *hm, char *lexem, t_token token);

void initialize_table(t_hashmap *hm);

void initialize_buffer(s_buffer *buff);

int check_table(t_hashmap *hm, char *lexem);

int column_resolver(char c);

t_token set_token(t_token token, char *token_name, char *lexem);

t_token state_resolver(int state, char *lexem, t_hashmap *table, s_buffer *buffer);

