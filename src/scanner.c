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


int main(int argc, char *argv[])
{
	if(argc < 2)
		die("USAGE: scanner <filename>");

	printf("Testando %d\n", END);

	FILE *file = fopen(argv[1], "r");
	return 0;
}


























