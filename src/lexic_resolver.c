#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../util/defines.h"

//Typedef for token struct
typedef struct Token
{
	int set;
	char token_name[MAX_ID];
	int token_type;
	char lexem[MAX_ID];
	char attribute[MAX_ID];
}t_token;

//Typedef for Hashmap (t_tokens array)
typedef struct Hashmap
{
	t_token hmap[SIZE];
}t_hashmap;


//Halfass solution to sintatic analyzer's buffer
typedef struct Buffer
{
	t_token buffer[SIZE];
}s_buffer;

//Typedef stack elements
typedef struct SElement
{
	int value;
	struct SElement *prev;
}s_element;

//Typedef list elements
typedef struct LElement
{
	t_token *token;
	struct LElement *prev;
}l_element;

//Typedef List
typedef struct List
{
	l_element *tail;
	l_element *head;
}t_list;

//Typedef stack
typedef struct Stack
{
	s_element *bot;
	s_element *top;
}t_stack;

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

//Print token elements
void print_token(t_token token)
{
	char *s;
	if(token.set)
		printf("------------------------------\n[TOKEN]: %s\n[Lexem]: %s\n[Atribute]: %s\n",
		token.token_name,
		token.lexem,
		token.attribute);
}

//Insert element into List and move tail
void list_insert(t_list *list, t_token *token)
{
	l_element *new = malloc(sizeof(l_element));
	new->token = token;
	if(!list->head && !list->tail)
	{
//		printf("[DEBBUG]: NO ELEMENTS\n\n");
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail->prev = new;
		list->tail = new;
	}
}

//Get element from list
//For this assignment we'll get an element and already remove it from the list
int list_get(t_list *list)
{
	l_element *aux;
	int symbol;
	if(!list->head && !list->tail)
	{
		//printf("[DEBBUG]: List is empty\n\n");
		return -1;
	}
	else if(list->head == list->tail)
	{
		//printf("[DEBBUG]: End of list\n\n");
		//print_token(*list->head->token);
		symbol = list->head->token->token_type;
		free(list->head);
		free(list);
		return symbol;
	}
	else
	{
		//print_token(*list->head->token);
		symbol = list->head->token->token_type;
		aux = list->head->prev;
		free(list->head);
		list->head = aux;
		return symbol;
	}
}

//Put on top of the stack, 
//a.k.a. PUSH
void stack_up(t_stack *stack, int value)
{
	s_element *new = malloc(sizeof(s_element));
	new->value = value;
	if(!stack->top && !stack->bot)
	{
//		printf("[DEBBUG]: NO ELEMENTS\n\n");
		stack->bot = new;
		stack->top = new;
	}
	else
	{
		new->prev = stack->top;
		stack->top = new;
	}
}

//Remove from the top of the stack, 
//a.k.a. POP
void stack_down(t_stack *stack, int times)
{
//	printf("[DEBBUG]: Freeing stack\n\n");
	int i = 0;
	s_element *aux;
	for(i = 0; i < times; i++)
	{
		if(!stack->top && !stack->bot)
			printf("[DEBBUG]: Stack is empty!\n\n");
		
		else if(stack->top == stack->bot)
		{
			//printf("[DEBBUG]: Emptying stack!\n\n");
			free(stack);
		}
		else
		{
			//printf("[DEBBUG]: Freeing stack %d of %d!\n", i, times);
			aux = stack->top;
			stack->top = stack->top->prev;
			free(aux);
		}
	}
}

//Remove from the top of the stack, 
//a.k.a. POP
void stack_down_once(t_stack *stack)
{
//	printf("[DEBBUG]: Freeing stack\n\n");
	s_element *aux;

	if(!stack->top && !stack->bot)
		printf("[DEBBUG]: Stack is empty!\n\n");
	
	else if(stack->top == stack->bot)
	{
		printf("[DEBBUG]: Emptying stack!\n\n");
		free(stack);
	}
	else
	{
		aux = stack->top;
		stack->top = stack->top->prev;
		free(aux);
	}
}

//Free entire data structure
void free_stack(t_stack *stack)
{
	while(stack->top != stack->bot)
		stack_down_once(stack);
//	print_token(*(stack->top->token));
	free(stack->top);
	free(stack);
}

//Calculates table's index over lexem
unsigned long hashFunction(char *id)
{
	unsigned long h = 0;
	for(int i = 0; i < strlen(id); i++)
	{
		h +=(int)id[i];
	}

	return h;
}

//Insert t_token into t_hashmap
void insert_token(t_hashmap *hm, char *lexem, char *token_name, int token_type)
{	
	//Calculates index
	unsigned long h = hashFunction(lexem);
	t_token token;

	//Clear buffers
	memset(token.token_name, '\0', MAX_ID);
	memset(token.lexem, '\0', MAX_ID);

	//Safely copy content to buffers
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.lexem, lexem, strlen(lexem));
	strncpy(token.attribute,"\0", 1);

	//Set token type
	token.token_type = token_type;

	//Set and atribute table's element
	token.set = 1;
	hm->hmap[h] = token;
}

//Get hashmap's (t_hashmap) element
t_token get_element(t_hashmap *hm, char *lexem, t_token token)
{
	unsigned long h = hashFunction(lexem);

	if(hm->hmap[h].set)
	{
		token = hm->hmap[h];
		//print_token(token);
	}

	return token;
}

//Check for existent entry at hashmap
int check_table(t_hashmap *hm, char *lexem)
{
	unsigned long h = hashFunction(lexem);
	if(!hm->hmap[h].set)
		return 0;
	return 1;
}

//Initialize hashtable(t_hashmap) with command words
void initialize_table(t_hashmap *hm)
{
	//Populate array with 'empty' tokens
	for(int i = 0; i < SIZE; i++)
	{
		t_token token = {.set = 0, .token_name="", .token_type = -2, .lexem="", .attribute="\0"};
		hm->hmap[i] = token;
	}

	//Insert reserved words into hash table
	//I'm doing it one by one because of the strategy adopted using the int value: token_type in the struct Token
	insert_token(hm, "inicio", "PALAVRA RESERVADA", inicio);
	insert_token(hm, "varinicio", "PALAVRA RESERVADA", varinicio);
	insert_token(hm, "varfim", "PALAVRA RESERVADA", varfim);
	insert_token(hm, "escreva", "PALAVRA RESERVADA", escreva);
	insert_token(hm, "leia", "PALAVRA RESERVADA", leia);
	insert_token(hm, "se", "PALAVRA RESERVADA", se);
	insert_token(hm, "entao", "PALAVRA RESERVADA", entao);
	insert_token(hm, "fimse", "PALAVRA RESERVADA", fimse);
	insert_token(hm, "fim", "PALAVRA RESERVADA", fim);
	insert_token(hm, "literal", "PALAVRA RESERVADA", _lit_);
	insert_token(hm, "inteiro", "PALAVRA RESERVADA", _int_);
	insert_token(hm, "real", "PALAVRA RESERVADA", _real_);

	//Command words array
	/*char *init[] = 
	{"inicio",
	"varinicio",
	"varfim",
	"escreva",
	"leia",
	"se",
	"entao",
	"fimse",
	"fim",
	"literal",
	"inteiro",
	"real"};

	//Insert command words in t_hashmap
	for(int i = 0; i < 12; i++)
		insert_token(hm, init[i], "PALAVRA RESERVADA", ID);*/
}


//Initialize sintatic buffer
//Gonna change this to a linked list (please)
void initialize_buffer(s_buffer *buffer)
{
	for(int i = 0; i < SIZE; i++)
	{
		t_token token = {.set = 0, .token_name="", .token_type=-2, .lexem="", .attribute="\0"};
		buffer->buffer[i] = token;
	}
}

//Populate and Set t_token
t_token set_token(t_token token, char *token_name, char *lexem, char *attribute, int token_type)
{
	token.set = 1;
	strncpy(token.token_name, token_name, strlen(token_name));
	strncpy(token.lexem, lexem, strlen(lexem));
	if(strlen(attribute) > 0)
		strncpy(token.attribute, attribute, strlen(attribute));
	else
		strncpy(token.attribute, "\0", 1);
	token.token_type = token_type;
	return token;
}

//Resolve table's column
int column_resolver(char c)
{
	if(c == 'E') return 19;
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
	else if(c == '>') return 13;
	else if(c == '=') return 14;
	else if(c == '*' || c == '/') return 15;
	else if(c == '(') return 16;
	else if(c == ')') return 17;
	else if(c == ';') return 18;
	else if(c == '+') return 20;
	else return 21;
}



//Resolve state on table given curr. state and character read from lexem
t_token state_resolver(int state, char *lexem, t_hashmap *table)
{
	t_token token = {.set = 0, .token_name="", .lexem="", .attribute=""};
	if(state == ID)
	{
		if(!check_table(table, lexem))
			insert_token(table, lexem,"ID", _id_);
			
		token = get_element(table, lexem, token);
	}
	else if(state == INT)
		token = set_token(token, "NUM", lexem, "INT", num);
	
	else if(state == REAL)
		token = set_token(token, "NUM", lexem, "REAL", num);
	
	else if(state == STR)
		token =	set_token(token, "STR", lexem, "\0", literal);
	
	
	else if(state == _ATRIB_ || state == OPER || state == _OPER_)
		token = set_token(token, "OPR", lexem, "\0", opr);

	else if(state == ATRIB)
		token = set_token(token, "ATRIB", lexem, "\0", rcb);

	
	else if(state == ARITM)
		token = set_token(token, "OPM", lexem, "\0", opm);

	
	else if(state == COMMENT){token.set=0;}
	else if(state == ERROR){} //token = set_token(token, "ERRO", lexem, "\0\n");

	else if(state == _eof_)
		token =	set_token(token, "Eof", "End of file", "\0", $);

	else if(state == AB_P)
		token =	set_token(token, "AB_P", lexem, "\0", ab_p);
	
	else if(state == FC_P)
		token =	set_token(token, "FC_P", lexem, "\0", fc_p);
	
	else if(state == PT_V)
		token = set_token(token, "PT_V", lexem, "\0", pt_v);
	
	else if(state == EXP)
		token = set_token(token, "NUM", lexem, "EXP", num);

	else{token.set=0;}
	
	//At this stage of the assignment we must only print the t_token on screen
	//print_token(token);
	return token;
}

