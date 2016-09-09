#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../util/defines.h"
#include <string.h>
#include <errno.h>


int trans_table[11][19] = 
{//	L |  D | . | ESPAÇO | TAB | \n | " | _ | EOF | { | } | < | - | OP_R | 	OP_A | ( | ) | ; | OUTRO |
/*init*/ ID, INT, ERROR, END, END, END, STR, ERROR, END, COMMENT, ERROR, _ATRIB_, ARITM, OPER, ARITM, END, END, END, ERROR,
/*ID*/	ID, ID, ERROR, END, END, END, ERROR, ID, END, COMMENT, ERROR, END, END, END, END, END, END, END, ERROR,
/*INT*/ ERROR, INT, REAL, END, END, END, ERROR, ERROR, END, COMMENT, ERROR, END, END, END, END, 
/*REAL*/ ERROR, REAL, ERROR, END, END, END, ERROR, ERROR, END, COMMENT, 
}











void die(char* message)
{
        if(errno) {
                perror(message);
        } else {
                printf("ERROR: %s\n", message);
        }
        exit(1);
}


int main(int argc, char *argv[])
{
	if(argc < 2)
		die("USAGE: scanner <filename>");

	printf("Testando %d\n", ATRIB);

	FILE *file = fopen(argv[1], "r");
	return 0;
}


























