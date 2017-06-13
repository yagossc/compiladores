#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "../util/defines.h"	//Custom MACRO defines
#include "../util/table.h"	//Lexic Table
#include "../util/resolver.h"	//Lexix Analiser handler
#include "../util/lexic.h"	//Lexic Analiser

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

int main(int argc, char *argv[])
{

	//Check correct usage
	if(argc != 2)
		die("USAGE: scanner <filename>");
	return 0;
}

