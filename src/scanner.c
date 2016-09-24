#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../util/defines.h"
#include "../util/table.h"
#include "../util/resolver.h"
#include <string.h>
#include <errno.h>
#define BUFFER 256

void die(char* message)
{
        if(errno) {
                perror(message);
        } else {
                printf("ERROR: %s\n", message);
        }
        exit(1);
}

void die_f(char* message, FILE *file)
{
        if(errno) {
                perror(message);
        } else {
                printf("ERROR: %s\n", message);
        }
	fclose(file);
        exit(1);
}


int lexic(FILE *file)
{
	int state = _init_;
	char c = fgetc(file);
	char *lex = malloc(sizeof(char)*BUFFER);
	int i = 0;
	memset(lex, '\0', BUFFER);

	while(trans_table[state][column_resolver(c)] != END)
	{
		if(c != '\n' && c != ' '){
			lex[i] = c;
			i++;
		}
		state = trans_table[state][column_resolver(c)];
		c = fgetc(file);
	
	}
	printf("==>%s<==\n", lex);
	if(state != _init_ && c != '"' && c != '}') ungetc(c, file);
	
	return state;

}

int main(int argc, char *argv[])
{
	int token;
	if(argc != 2)
		die("USAGE: scanner <filename>");

	FILE *file = fopen(argv[1], "r");
	if(!file)
		die("Could not open file.");
	
	while(token != ERROR && token != _eof_)
	{
		token = lexic(file);
		//if(token == _init_) fgetc(file);
		//printf("GOT HERE");
		state_resolver(token);
	}
	if(token == ERROR) die_f("Token not indentified.", file);



	return 0;
}


























