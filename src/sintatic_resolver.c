#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../util/defines.h"
//#include "../util/lexic_resolver.h"

//Calculate production length to determine how many items to pop from stack
int production_length(int r_item)
{
	int length = 0;
	if(r_item == R7 || r_item == R8 || r_item == R9 || r_item == R13 || r_item == R14 || r_item == R15 || r_item == R19 || r_item == R20 || r_item == R21 || r_item == R30) length = 2;
	else if(r_item == R5 || r_item == R3 || r_item == R4 || r_item == R10 || r_item == R16 || r_item == R22 || r_item == R23 || r_item == R26 || r_item == R27 || r_item == R28 || r_item == R29) length = 4;
	else if(r_item == R2 || r_item == R6 ||  r_item == R11 || r_item == R12 || r_item == R18 || r_item == R25) length = 6;
	else if(r_item == R17) length = 8;
	else if(r_item == R24) length = 10;

//	printf("THE LENGTH I FOUND IS: %d\n", length);
	return length;
}

//Get non-terminal from reduction and print production on screen
int get_production(int r_item)
{
	printf("[REDUCTION]: ");
	if(r_item == R2)
	{
		printf("P -> inicio V A\n");
		return P;
	}
	if(r_item == R3)
	{
		printf("V -> varinicio LV\n");
		return V;
	}
	if(r_item == R4)
	{
		printf("LV -> D LV\n");
		return LV;
	}
	if(r_item == R5)
	{
		printf("LV -> varfim;\n");
		return LV;
	}
	if(r_item == R6)
	{
		printf("D -> id TIPO;\n");
		return D;
	}
	if(r_item == R7)
	{
		printf("TIPO -> int\n");
		return TIPO;
	}
	if(r_item == R8)
	{
		printf("TIPO -> real\n");
		return TIPO;
	}
	if(r_item == R9)
	{
		printf("TIPO -> lit\n");
		return TIPO;
	}
	if(r_item == R10)
	{
		printf("A -> ES A\n");
		return A;
	}
	if(r_item == R11)
	{
		printf("ES -> leia id;\n");
		return ES;
	}
	if(r_item == R12)
	{
		printf("ES -> escreva ARG;\n");
		return ES;
	}
	if(r_item == R13)
	{
		printf("ARG -> literal\n");
		return ARG;
	}
	if(r_item == R14)
	{
		printf("ARG -> num\n");
		return ARG;
	}
	if(r_item == R15)
	{
		printf("ARG -> id\n");
		return ARG;
	}
	if(r_item == R16)
	{
		printf("A -> CMD A\n");
		return A;
	}
	if(r_item == R17)
	{
		printf("CMD -> id rcb LD;\n");
		return CMD;
	}
	if(r_item == R18)
	{
		printf("LD -> OPRD opm OPRD\n");
		return LD;
	}
	if(r_item == R19)
	{
		printf("LD -> OPRD\n");
		return LD;
	}
	if(r_item == R20)
	{
		printf("OPRD -> id\n");
		return OPRD;
	}
	if(r_item == R21)
	{
		printf("OPRD -> num\n");
		return OPRD;
	}
	if(r_item == R22)
	{
		printf("A -> COND A\n");
		return A;
	}
	if(r_item == R23)
	{
		printf("COND -> CABECALHO CORPO\n");
		return COND;
	}
	if(r_item == R24)
	{
		printf("CABECALHO -> se (EXP_R) entao\n");
		return CABECALHO;
	}
	if(r_item == R25)
	{
		printf("EXP_R -> OPRD opr OPRD\n");
		return EXP_R;
	}
	if(r_item == R26)
	{
		printf("CORPO -> ES CORPO\n");
		return CORPO;
	}
	if(r_item == R27)
	{
		printf("CORPO -> CMD CORPO\n");
		return CORPO;
	}
	if(r_item == R28)
	{
		printf("CORPO -> COND CORPO\n");
		return CORPO;
	}
	if(r_item == R29)
	{
		printf("CORPO -> fimse\n");
		return CORPO;
	}
	if(r_item == R30)
	{
		printf("A -> fim\n");
		return A;
	}
}

