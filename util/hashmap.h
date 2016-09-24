#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include "defines.h"

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



unsigned long hashFunction(char *id);

void insert_token(t_hashmap *hm, char *lexem, char *token_name);

t_token get_element(t_hashmap *hm, char *lexem);

int check_table(t_hashmap *hm, char *lexem);

void initialize_table(t_hashmap *hm);

void set_token(t_token, char *token_name, char *lexem);

void print_token(t_token token);
#endif
