#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../util/defines.h"
#include "../util/table.h"
#include <string.h>
#include <errno.h>


void die(char* message)
{
        if(errno) {
                perror(message);
        } else {
                printf("ERROR: %s\n", message);
        }
        exit(1);
}


int column_resolver(char c)
{
	if(isalpha(c)) return 0;
	else if(isdigit(c)) return 1;
	else if(c == '.') return 2;
	else if(c == ' ') return 3;
	else if(c == '	') return 4;
	else if(c == '\n') return 5;
	else if(c == '"') return 6;
	else if(c == '_') return 7;
	else if(c == EOF) return 8;
	else if(c == '{') return 9;
	else if(c == '}') return 10;
	else if(c == '<') return 11;
	else if(c == '-') return 12;
	else if(c == '>' || c == '=') return 13;
	else if(c == '+' || c == '*' || c == '/') return 14;
	else if(c == '(') return 15;
	else if(c == ')') return 16;
	else if(c == ';') return 17;
	else return 18;
}


int state_resolver(int state)
{}
int lexic(FILE *file)
{
	int state = _init_;
	char c = fgetc(file);

	while(trans_table[state][column_resolver(c)] != END)
	{
		state = trans_table[state][column_resolver(c)];
		c = fgetc(file);
	}
	ungetc(c, file);
	return state;
}

int main(int argc, char *argv[])
{
	int signal;
	if(argc != 2)
		die("USAGE: scanner <filename>");

	FILE *file = fopen(argv[1], "r");
	if(!file)
		die("Could not open file.");
	
	while(token != -1))
	{
		token = lexic(file);
	}


	return 0;
}


























