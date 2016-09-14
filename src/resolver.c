#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../util/defines.h"
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

void print_token(char *state)
{
	printf("TOKEN: %s.\n", state);
}

void state_resolver(int state)
{
	if(state == ID)
		print_token("Identificador");
	if(state == INT)
		print_token("Inteiro");
	else if(state == REAL)
		print_token("Real");
	else if(state == STR)
		print_token("String");
	else if(state == _ATRIB_ || state == OPER)
		print_token("Operador Relacional");
	else if(state == ATRIB)
		print_token("Atribuicao");
	else if(state == ARITM)
		print_token("Operador aritmetico");
	else if(state == COMMENT)
		print_token("Comentario");
	else if(state == ERROR)
		print_token("Error");
	else if(state == _eof_)
		print_token("End of file");
	else if(state == PT_V)
		print_token("PT_V");
}

int peculiar(char c, int state)
{
	 
	if(c == '"' || c == '}')
		return state;
	else if(c == ';')
		return 17;
	else
		return 0;
}
	







