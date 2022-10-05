#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - frees a stack_t linked list
 * @stk_top: pointer to the first node of the list
 */
void free_stack(stack_t *stk_top)
{
	stack_t *temp2, *temp = stk_top;

	for (; temp; temp = temp2)
	{
		temp2 = temp->next;
		free(temp);
	}
}
