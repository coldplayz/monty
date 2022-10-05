#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * stack_len - determines the number of elements of the structure stack_s
 * @stk_top: the head of a structure of type 'struct stack_s'
 *
 * Return: the number of nodes in the list
 */
size_t stack_len(const stack_t *stk_top)
{
	size_t n = 0;
	stack_t *temp;

	temp = (stack_t *)stk_top;
	for (; temp; temp = temp->next)
	{
		n++;
	}

	return (n);
}
