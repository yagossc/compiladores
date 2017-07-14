#include <stdio.h>
#include <stdlib.h>

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
void list_insert(t_list *list, t_token *token);

int list_get(t_list *list);

void stack_up(t_stack *stack, int value);

void stack_down(t_stack *stack, int times);

void stack_down_once(t_stack *stack);

void free_stack(t_stack *stack);