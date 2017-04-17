#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "../util/defines.h" //Custom MACRO defines
#include "../util/table.h"
#include "../util/resolver.h"

//Global variable for error's row
unsigned int row = 0;
//Global variable for error's column
unsigned int col = 0;
//Auxiliary global var. for counting columns
unsigned int aux_col = 0;

//End program on error
void die(char* message)
{
        if(errno) {
                perror(message);
        } else {
                printf("ERROR: %s\n", message);
        }
        exit(1);
}

//End program and close source file stream on error
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

//Determines state according to table automata
//View: ~/util/table.h
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

	//Check correct usage
	if(argc != 2)
		die("USAGE: scanner <filename>");

	char *lexem= malloc(sizeof(char)*BUFFER);

	//Open source file and check for error
	FILE *file = fopen(argv[1], "r");
	if(!file) die("Could not open file.");

	//Allocate hashmap
	t_hashmap *table = malloc(sizeof(t_hashmap));
	//Initialize table with command words
	//View: resolver.c
	initialize_table(table);

	//Loop until error or end of file
	while(state != ERROR && state != _eof_)
	{
		//Current state
		state = lexic(file, lexem);
		//Resolve next state according to current state
		//View: resolver.c
		state_resolver(state, lexem, table);
	}

	//Check for error state
	if(state == ERROR) die_f("Token not indentified.", file, row, col+1);

	//Close stream and free heap
	fclose(file);
	free(lexem);
	free(table);

	return 0;
}
