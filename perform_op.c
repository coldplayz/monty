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
	/* opfunc is a typedef for a pointer to the opcode function type */
	opfunc ofunc;

	ofunc = find_opfunc(instruct_arr[0]); /* instruct_arr[0] == opcode string */
	if (!ofunc)
	{/* invalid instruction */
		fprintf(
				stderr,
				RED "L%d: unknown instruction %s\n" RESET,
				globals.linenum, instruct_arr[0]);
		free(globals.linebuff);
		free(globals.instruct_arr);
		if (globals.stack_top)
			free_stack(globals.stack_top); /* stack is not empty */
		fclose(globals.fp), exit(EXIT_FAILURE);
	}
	if (instruct_arr[1])
	{
		if (!isint(instruct_arr[1]) && strcmp(instruct_arr[0], "push") == 0)
		{/* argument not int */
			fprintf(stderr, RED "L%d: usage: push integer\n" RESET, globals.linenum);
			free(globals.linebuff);
			free(globals.instruct_arr);
			if (globals.stack_top)
				free_stack(globals.stack_top); /* stack is not empty */
			fclose(globals.fp), exit(EXIT_FAILURE);
		} /* there is an int argument for the opcode instruction */
		globals.oparg = atoi(instruct_arr[1]);
	}
	else if ((strcmp(instruct_arr[0], "push") == 0) && (!instruct_arr[1]))
	{/* no argument for push */
		fprintf(stderr, RED "L%d: usage: push integer\n" RESET, globals.linenum);
		free(globals.linebuff);
		free(globals.instruct_arr);
		if (globals.stack_top)
			free_stack(globals.stack_top); /* stack is not empty */
		fclose(globals.fp), exit(EXIT_FAILURE);
	}
	ofunc(&globals.stack_top, 0);
}
