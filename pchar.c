#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pchar - prints the character stored at the top of the stack
 * Description: i.e. treats the integer as an ascii value
 * if the integer is not in the ascii table - exits with an error
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pchar(stack_t **stk_top, unsigned int n)
{
	(void)n;

	if (*stk_top != NULL)
	{
		if ((*stk_top)->n < 0 || (*stk_top)->n > 127)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", (*stk_top)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
}
