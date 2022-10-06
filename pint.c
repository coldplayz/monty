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
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
}
