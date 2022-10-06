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
	/*oplist_t *oplist_cpy;*/
	int i = 0;
	instruction_t opslist[] = {
		{"push", push}, {"pall", pall}, {"swap", swap}, {"pop", pop},
		{"add", add}, {"pint", pint},
		{NULL, NULL},
	};

	/*oplist_cpy = globals.oplist; make copy as oplist is global */
	/*while (oplist_cpy)*/
	while (opslist[i].opcode != NULL)
	{
		/*if (strcmp(oplist_cpy->opstruct->opcode, opstr) == 0)*/
		if (strcmp(opslist[i].opcode, opstr) == 0)
		{
			/* opcode struct found */
			return (opslist[i].f);
			/*return (oplist_cpy->opstruct->f);*/
		}
		i++;
		/*oplist_cpy = oplist_cpy->next;*/
	}

	/* opstr does not represent any available opcode */
	return (NULL);
}
