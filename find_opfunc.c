#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * find_opfunc - returns the function of the opcode represented by opstr.
 * @opstr: string representing a potentially available opcode.
 *
 * Return: pointer to the function corresponding to opstr, or NULL if no match.
 */
opfunc find_opfunc(char *opstr)
{
	oplist_t *oplist_cpy;

	oplist_cpy = oplist; /* make copy as oplist is global, and thus modifiable */
	while (oplist_cpy)
	{
		if (strcmp(oplist_cpy->opstruct->opcode, opstr) == 0)
		{
			/* opcode struct found */
			return (oplist_cpy->opstruct->f);
		}

		oplist_cpy = oplist_cpy->next;
	}

	/* opstr does not represent any available opcode */
	return (NULL);
}
