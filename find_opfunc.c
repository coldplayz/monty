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
	static int queue_on;
	instruction_t opslist[] = {
		{"push", push}, {"pall", pall}, {"swap", swap}, {"pop", pop},
		{"sub", sub}, {"div", div_}, {"mul", mul}, {"mod", mod}, {"add", add},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", stack_}, {"queue", queue}, {NULL, NULL},
	};

	/* check and update mode flag */
	if (strcmp(opstr, "queue") == 0)
		queue_on = 1;/*once enabled, only disabled by an explicit stack mode*/
	else if (strcmp(opstr, "stack") == 0)
		queue_on = 0;
	/*printf("queue mode %s\n", queue_on ? "on" : "off");*/
	/*oplist_cpy = globals.oplist; make copy as oplist is global */
	/*while (oplist_cpy)*/
	while (opslist[i].opcode != NULL)
	{
		/*if (strcmp(oplist_cpy->opstruct->opcode, opstr) == 0)*/
		if (strcmp(opslist[i].opcode, opstr) == 0)
		{
			/* opcode struct found */
			if (strcmp(opstr, "push")== 0 && queue_on)
				return (queue_push);
			else
				return (opslist[i].f);
			/*return (oplist_cpy->opstruct->f);*/
		}
		i++;
		/*oplist_cpy = oplist_cpy->next;*/
	}

	/* opstr does not represent any available opcode */
	return (NULL);
}
