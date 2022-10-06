#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * Description: i.e. the last element of the stack becomes the top one
 * and the stk_top (top element) becomes the second one
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void rotr(stack_t **stk_top, unsigned int n)
{
	stack_t *last = *stk_top;
	(void)n;

	/*need at least two elements to swap, else stack remains unchanged*/
	if (*stk_top != NULL && (*stk_top)->next)
	{
		/*get the last element*/
		while (last->next != NULL)
			last = last->next;
		/* do the updates */
		last->next = *stk_top;
		(last->prev)->next = NULL;
		last->prev = NULL;
		(*stk_top)->prev = last;
		*stk_top = last;
	}
}
