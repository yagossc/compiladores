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

//Halfass solution to sintatic analyzer's buffer
typedef struct Buffer
{
	t_token buffer[SIZE];
}s_buffer;

void print_token(t_token token);

unsigned int hashFunction(char *id);

void insert_token(t_hashmap *hm, char *lexem, char *token_name, int token_type);

t_token get_element(t_hashmap *hm, char *lexem, t_token token);

int check_table(t_hashmap *hm, char *lexem);

void initialize_table(t_hashmap *hm);

void initialize_buffer(s_buffer *buff);

t_token set_token(t_token token, char *token_name, char *lexem, int token_type);

int column_resolver(char c);

t_token state_resolver(int state, char *lexem, t_hashmap *table);






