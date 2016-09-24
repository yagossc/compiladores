#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../util/defines.h"
int column_resolver(char c)
{
	if(c == 'E') return 18;
	else if(isalpha(c)) return 0;
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
	else return 19;
}

void print_token(char *state)
{
	printf("TOKEN: %s.\n", state);
}

void state_resolver(int state)
{
	if(state == ID)
		print_token("ID");
	if(state == INT)
		print_token("INT");
	else if(state == REAL)
		print_token("REAL");
	else if(state == STR)
		print_token("STR");
	else if(state == _ATRIB_ || state == OPER)
		print_token("OPR");
	else if(state == ATRIB)
		print_token("RCB");
	else if(state == ARITM)
		print_token("OPM");
	else if(state == COMMENT)
		return;//print_token("Comentario");
	else if(state == ERROR)
		print_token("ERRO");
	else if(state == _eof_)
		print_token("End of file");
	else if(state == AB_P)
		print_token("AB_P");
	else if(state == FC_P)
		print_token("FC_P");
	else if(state == PT_V)
		print_token("PT_V");
	else if(state == EXP)
		print_token("EXP");
}

char *token_resolver(int state)
{

	char *token_name;

	if(state == ID)
		token_name = "ID";
	if(state == INT)
		token_name = "INT";
	else if(state == REAL)
		token_name = "REAL";
	else if(state == STR)
		token_name = "STR";
	else if(state == _ATRIB_ || state == OPER)
		token_name = "OPR";
	else if(state == ATRIB)
		token_name = "RCB";
	else if(state == ARITM)
		token_name = "OPM";
	else if(state == COMMENT)
		return;//print_token("Comentario");
	else if(state == ERROR)
		print_token("ERRO");
	else if(state == _eof_)
		print_token("End of file");
	else if(state == AB_P)
		print_token("AB_P");
	else if(state == FC_P)
		print_token("FC_P");
	else if(state == PT_V)
		print_token("PT_V");
	else if(state == EXP)
		print_token("EXP");

	return token_name;
}








