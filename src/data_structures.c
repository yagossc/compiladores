#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../util/defines.h"
#include "../util/lexic_resolver.h"

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