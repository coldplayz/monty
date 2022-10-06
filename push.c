#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push -  adds a new node at the beginning of a stack_t list.
 * @stk_top: a double pointer representing the address of the head of the list
 * @n: integer to initialize the new node with
 */
void push(stack_t **stk_top, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, RED "Error: malloc failed\n" RESET);
		free(globals.linebuff);
		free(globals.instruct_arr);
		if (globals.stack_top)
			free_stack(globals.stack_top); /* stack is not empty */
		fclose(globals.fp);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = *stk_top;		/*new node is now pointing to what head is pointing to*/
	new->prev = NULL;

	/* link new to stack */
	if (*stk_top)
	{
		/* stack top not NULL */
		(*stk_top)->prev = new;
	}
	*stk_top = new;			/*new node is now the head node*/
}
