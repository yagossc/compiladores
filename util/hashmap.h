#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 

struct Token
{
	char *token_name;
	char *lexem;
	char *atribute;
}

struct Hashmap
{
	struct Token hmap[SIZE];
}

