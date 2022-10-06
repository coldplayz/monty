#include <stdio.h>
#include <stdlib.h>
#include "monty.h"



/**
 * pop - deletes the head node of a stack_t linked list.
 * @stk_top: a pointer storing the address of the pointer to the list head
 * @n: unsigned int.
 */
void pop(stack_t **stk_top, unsigned int n __attribute__((unused)))
{
	stack_t *head_cpy;

	if (!(*stk_top))
	{
		/* empty stack */
		fprintf(
				stderr,
				RED "L%d: can't pop an empty stack\n" RESET,
				globals.linenum);
		free(globals.linebuff);
		free(globals.instruct_arr);
		if (globals.stack_top)
			free_stack(globals.stack_top); /* stack is not empty */
		fclose(globals.fp);
		exit(EXIT_FAILURE);
	}

	if (stack_len(*stk_top) != 0)
	{
		head_cpy = *stk_top; /* collect the address to free */

		/* change the head */
		*stk_top = (*stk_top)->next;
		if (*stk_top)
		{
			(*stk_top)->prev = NULL;
		}

		/* free previous head */
		free(head_cpy);
	}
}
