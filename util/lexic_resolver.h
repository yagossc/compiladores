#include <stdio.h>
#include <stdlib.h>

typedef struct Token
{
	int set;
	char token_name[MAX_ID];
	int token_type;
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

typedef struct SElement
{
	int value;
	struct SElement *prev;
}t_element;

typedef struct LElement
{
	t_token *token;
	struct LElement *prev;
}l_element;

typedef struct List
{
	t_element *tail;
	t_element *head;
}t_list;

typedef struct Stack
{
	t_element *bot;
	t_element *top;
}t_stack;

int production_length(int r_item);

int get_production(int r_item);

void list_insert(t_list *list, t_token *token);

int list_get(t_list *list);

void stack_up(t_stack *stack, int value);

void stack_down(t_stack *stack, int times);

void stack_down_once(t_stack *stack);

void free_stack(t_stack *stack);

unsigned int hashFunction(char *id);

void print_token(t_token token);

void insert_token(t_hashmap *hm, char *lexem, char *token_name, int token_type);

t_token get_element(t_hashmap *hm, char *lexem, t_token token);

void initialize_table(t_hashmap *hm);

void initialize_buffer(s_buffer *buff);

int check_table(t_hashmap *hm, char *lexem);

int column_resolver(char c);

t_token set_token(t_token token, char *token_name, char *lexem, int token_type);

t_token state_resolver(int state, char *lexem, t_hashmap *table);

