#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * sub - subtracts the two element at the top of the stack
 * Description: i.e. the stk_top from stk_top->next
 * and stores the result in stk_top->next, popping stk_top
 * @stk_top: double pointer to stk_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void sub(stack_t **stk_top, unsigned int n)
{
	stack_t *temp;
	(void)n;

	if (*stk_top != NULL)
	{
		temp = *stk_top;
		if (temp->next)/*then we have at least two elements*/
		{
			*stk_top = temp->next;/*i.e the 2nd element*/
			(*stk_top)->n = (*stk_top)->n - temp->n;
			(*stk_top)->prev = NULL;
			free(temp);
		}
		else
		{
			/* only one node */
			fprintf(stderr, "L%u: can't sub, stack too short\n", n);
			garbage_collector();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* zero nodes */
		fprintf(stderr, "L%u: can't sub, stack too short\n", n);
		garbage_collector();
		exit(EXIT_FAILURE);
	}
}
