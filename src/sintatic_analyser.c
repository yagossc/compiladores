#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "../util/defines.h" //Custom MACRO defines
#include "../util/table.h"
#include "../util/sintatic_table.h"
#include "../util/lexic_resolver.h"
#include "../util/data_structures.h"
#include "../util/sintatic_resolver.h"



//Global variable for error's row
unsigned int row = 1;
//Global variable for error's column
unsigned int col = 0;
//Auxiliary global var. for counting columns
unsigned int aux_col = 0;

//Terminate execution on error
void die(char* message, FILE *file, int row, int col)
{
	if(errno){
		perror(message);
	}
	else if(row == 0 && col == 0){
		printf("ERRO: %s.\n", message);
	}
	else{
		printf("ERRO: %s linha[%d] coluna[%d]\n", message, row, col);
	}
	if(file != NULL)
		fclose(file);
	exit(1);
}


//Determines state according to table automata
//View: ~/util/table.h
int lexic(FILE *file, char *lexem)
{
	int state = _init_;
	char c = fgetc(file);
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

	if(state != _init_ && c != '"' && c != '}')
		ungetc(c, file);
	else if (c == '"')
		lexem[i] = c;
	if(c == EOF)
		col = aux_col-1;

	return state;
}

//Determines status of sintatic analysis according to sintatic table
//View: ~/util/sintatic_table.h
int sintatic(int state, int symbol, t_stack *stack)
{
	//If it's an acceptance item
	if(sintable[state][symbol] == ACC)
		return ACC;

	//Check for error
	else if(sintable[state][symbol] == ERR)
		return ERR;

	//If it's a push item in the table
	else if(sintable[state][symbol] < REDUCE &&  sintable[state][symbol] > STACK)
	{
		stack_up(stack, symbol);
		stack_up(stack, sintable[state][symbol]%100);
		return OK;
	}
	
	//If it's a reduction item in the table
	else if(sintable[state][symbol] > REDUCE)
	{
		//Pop 2*|B| from stack
		stack_down(stack,production_length(sintable[state][symbol]));

		//Store state on top of the stack
		int aux_state = stack->top->value;

		//Get the left side of the production subjected to reduction
		int production = get_production(sintable[state][symbol]);

		//Push to stack the non-terminal of the reduction
		stack_up(stack, production);

		//Push to stack the state determined by the non-terminal and the current top of the stack state
		stack_up(stack, sintable[aux_state][production]);
		
		return OK;
	}
}

int main(int argc, char *argv[])
{
	int state = _init_;
	int i = 0;

	//Check correct usage
	if(argc != 2)
		die("USAGE: scanner <filename>", NULL, 0, 0);

	//Open source file and check for error
	FILE *file = fopen(argv[1], "r");
	if(!file) die("Could not open file.", NULL, 0, 0);

	char *lexem= malloc(sizeof(char)*BUFFER);
	t_token token;

	//Initialize table with command words
	//View: resolver.c
	t_hashmap *table = malloc(sizeof(t_hashmap));
	initialize_table(table);
	
	//Allocate S.A. input buffer(list)
	//Actually, the pointer *list is the ip pointer mentioned in the
	//assignment's manual of implementation
	t_list *list = malloc(sizeof(t_list));

	//Allocate S.A. input buffer
	s_buffer *input_buffer = malloc(sizeof(s_buffer));

	//Initialize buffer
	//I still don't know why, but i could correctly fetch the tokens
	//directly into the list, so I'm using this buffer
	initialize_buffer(input_buffer);

	//Create stack for stack_automata
	t_stack *stack = malloc(sizeof(t_stack));

	//Loop until error or end of file
	while(state != ERROR && state != _eof_)
	{
		//Current state
		state = lexic(file, lexem);

		//Resolve next state according to current state
		//View: resolver.c
		input_buffer->buffer[i] = state_resolver(state, lexem, table);
		if(input_buffer->buffer[i].set)
		{
			//print_token(token);
			list_insert(list, &input_buffer->buffer[i]);
			i++;
		}
	}
	
	//Check for lexic error
	if(state == ERROR) die("Token not indentified.", file, row+1, col+1);


	//Sintatic Analyser portion
	
	//Push initial state into Stack automata
	stack_up(stack, 0);

	//Status flag
	int status = OK;

	//Input symbol
	int a = list_get(list);

	state = lexic(file, lexem);
	token = state_resolver(state, lexem, table);
	int symbol = token.token_type;

	while(state != ERROR && status != ERR && status != ACC){
		if(stack->top != stack->bot){
			if(stack->top->prev->value < NTerm){

				a = list_get(list);
			}
		}
		status = sintatic(stack->top->value, a, stack);
	}

	if(status == ERR) die("[SYSTEM]: Sintatic Error Found. Aborting.", file, row+1, col+1);

	else if(status == ACC)
		printf("[INFO]: Sintatic analysis concluded with no errors.\n");

	//Close stream and free heap
	fclose(file);
	free(lexem);
	free(table);
	free_stack(stack);
	
	return 0;
}
