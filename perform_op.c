#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * perform_op - executes monty file instructions.
 * @instruct_arr: a NULL-terminated array of strings
 * representing a single instruction opcode [and arguments].
 */
void perform_op(char *instruct_arr[])
{
	int oparg = 0;
	/* opfunc is a typedef for a pointer to the opcode function type */
	opfunc ofunc;

	ofunc = find_opfunc(instruct_arr[0]); /* instruct_arr[0] == opcode string */
	if (!ofunc)
	{
		/* invalid instruction */
		fprintf(
				stderr,
				RED "L%d: unknown instruction %s\n" RESET,
				linenum, instruct_arr[0]);
		free(linebuff);
		free(instruct_arr);
		free_stack(stack_top);
		free_oplist(oplist);
		exit(EXIT_FAILURE);
	}

	if (instruct_arr[1])
	{
		/* there is an int argument for the opcode instruction */
		oparg = atoi(instruct_arr[1]);
	}

	ofunc(&stack_top, oparg);
}
