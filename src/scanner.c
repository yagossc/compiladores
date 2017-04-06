#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "../util/defines.h"
#include "../util/table.h"
#include "../util/resolver.h"

unsigned int row = 0;
unsigned int col = 0;
unsigned int aux_col = 0;

void die(char* message)
{
        if(errno) {
                perror(message);
        } else {
                printf("ERROR: %s\n", message);
        }
        exit(1);
}

void die_f(char* message, FILE *file, int row, int col)
{
        if(errno) {
                perror(message);
        } else {
                printf("ERROR: %s at line[%d] col[%d]\n", message, row, col);
        }
	fclose(file);
        exit(1);
}


int lexic(FILE *file, char *lexem)
{
	int state = _init_;
	char c = fgetc(file);
	char *lex = malloc(sizeof(char)*BUFFER);
	int i = 0;
	memset(lexem, '\0', BUFFER);

	while(trans_table[state][column_resolver(c)] != END)
	{
		aux_col = col;
		if(c == '\n')
		{
			row++;
			if(c != EOF) col = 0;
		}
		if(c != '\n'){
			col++;
			lexem[i] = c;
			i++;
			if(i == 1 && c == ' ') i--;
		}
		state = trans_table[state][column_resolver(c)];
		c = fgetc(file);
	
	}
	if(state != _init_ && c != '"' && c != '}') ungetc(c, file);
	else if (c == '"') lexem[i] = c;
	if(c == EOF) col = aux_col-1;
	return state;

}

int main(int argc, char *argv[])
{
	int state;
	if(argc != 2)
		die("USAGE: scanner <filename>");
	char *lexem= malloc(sizeof(char)*BUFFER);
	FILE *file = fopen(argv[1], "r");
	if(!file) die("Could not open file.");

	t_hashmap *table = malloc(sizeof(t_hashmap));
	initialize_table(table);

	while(state != ERROR && state != _eof_)
	{
		state = lexic(file, lexem);
		state_resolver(state, lexem, table);
	}
	if(state == ERROR) die_f("Token not indentified.", file, row, col+1);
	fclose(file);
	free(lexem);
	free(table);

	return 0;
}
