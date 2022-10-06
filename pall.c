#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pall - prints all elements of the structure stack_s
 * @stk_top: the head of a structure of type 'struct stack_s'
 * @n: file current line number.
 */
void pall(stack_t **stk_top, unsigned int n __attribute__((unused)))
{
	stack_t *stk_top_cpy = *stk_top;

	for (; stk_top_cpy; stk_top_cpy = (stk_top_cpy)->next)
	{
		printf("%d\n", (stk_top_cpy)->n);
	}
}
