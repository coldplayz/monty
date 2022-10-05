#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap - swaps the two element at the top of the stack
 * Description: i.e. the stk_top (topmost) and stk_top->next
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void swap(stack_t **stk_top, unsigned int n)
{
	stack_t *temp, *third;
	(void)n;

	if (*stk_top != NULL)
		temp = *stk_top;
	if (temp->next)/*then we have at least two elements*/
	{
		*stk_top = temp->next;/*i.e the 2nd element*/
		if (temp->next->next)
		{
			third = temp->next->next;
			third->prev = temp;
			temp->next = third;
		}
		else
			temp->next = NULL;
		(*stk_top)->prev = NULL;
		(*stk_top)->next = temp;
		temp->prev = *stk_top;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short", n);
		exit(EXIT_FAILURE);
	}
}