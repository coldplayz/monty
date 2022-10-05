#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_oplist - frees a oplist_t linked list
 * @oplist: pointer to the first node of the list
 */
void free_oplist(oplist_t *oplist)
{
	oplist_t *temp2, *temp = oplist;

	for (; temp; temp = temp2)
	{
		temp2 = temp->next;
		free(temp);
	}
}
