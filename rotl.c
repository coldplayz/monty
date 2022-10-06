#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * Description: i.e. the top element of the stack becomes the last one
 * and the second top element becomes the first one (the stk_top)
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void rotl(stack_t **stk_top, unsigned int n)
{
	stack_t *temp, *last = *stk_top;
	(void)n;

	/*need at least two elements to swap, else stack remains unchanged*/
	if (*stk_top != NULL && (*stk_top)->next)
	{
		temp = (*stk_top)->next;
		/*get the last element*/
		while (last->next != NULL)
			last = last->next;
		/* do the updates */
		last->next = *stk_top;
		(*stk_top)->prev = last;
		(*stk_top)->next = NULL;
		temp->prev = NULL;
		*stk_top = temp;
	}
}
