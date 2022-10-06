#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue - does nothing to the top of the stack
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void queue(stack_t **stk_top, unsigned int n)
{
	(void)n;
	(void)stk_top;
}

/**
 * stack_ - does nothing to the top of the stack
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void stack_(stack_t **stk_top, unsigned int n)
{
	(void)n;
	(void)stk_top;
}

/**
 * queue_push - (an opcode) pushes an element to the stack's rear(tail)
 * @stk_top: double pointer to stk_top of stack
 * @n: integer argument
 * Description: adds new element to the stk_top of list
 * Return: Nothing
 */
void queue_push(stack_t **stk_top, unsigned int n)
{
	stack_t *new, *tail = *stk_top;

	/*checking if n - done outside this fn */
	/*printf("in push\n");*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		garbage_collector();
		exit(EXIT_FAILURE);
	}
	new->n = (int)n;
	new->next = NULL;
	/* navigate to the tail of the stack */
	if (tail != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		new->prev = tail;
		tail->next = new;
	}
	else
	{
		new->prev = NULL;
		*stk_top = new;
	}
}
