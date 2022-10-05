#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * bld_oplist - builds a doubly-linked list of oplist_t structs.
 * @oplist: addres of head of the oplist
 */
void bld_oplist(oplist_t **oplist)
{
	oplist_t *new;
	instruction_t *opstruct[] = {&push_st, &pall_st};
	int i;
	
	for (i = 0; i < 2; i++)
	{
		new = malloc(sizeof(oplist_t));
		if (new == NULL)
		{
			fprintf(stderr, RED "Error: malloc failed\n" RESET);
			exit(EXIT_FAILURE);
		}

		new->opstruct = opstruct[i];
		new->next = *oplist;		/*new node is now pointing to what head is pointing to*/
		new->prev = NULL;

		if (*oplist)
		{
			(*oplist)->prev = new;
		}
		*oplist = new;			/*new node is now the head node*/
	}
}
