#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - prints the element at the top of the stack
 * Description: i.e. the stk_top (topmost)
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pint(stack_t **stk_top, unsigned int n)
{
	(void)n;
	if (*stk_top != NULL)
		printf("%d\n", (*stk_top)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", globals.linenum);
		free(globals.linebuff);
		free(globals.instruct_arr);
		if (globals.stack_top)
			free_stack(globals.stack_top); /* stack is not empty */
		fclose(globals.fp);
		exit(EXIT_FAILURE);
	}
}
