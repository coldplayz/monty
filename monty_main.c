#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

globals_t globals; /* definition of the globals struct. To be initialized */


/**
 * main - driver for the Monty ByteCode interpreter.
 * @argc: number of args passed to the interpreter.
 * @argv: array of command-line args.
 *
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	int read;
	size_t buff_size = 0;

	init_globals(); /* initializes variables in the globals_t struct, globals */
	init_opstruct(); /* define extern-declared instances of opcode structs */
	bld_oplist(&globals.oplist); /* create an oplist_t linked list based on available opstructs*/

	if (argc != 2)
	{
		fprintf(stderr, RED "USAGE: monty file\n" RESET);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r"); /* fopen() returns a FILE ptr or NULL on failure */
	if (!fp)
	{
		fprintf(stderr, RED "Error: Can't open file %s\n" RESET, argv[1]);
		exit(EXIT_FAILURE);
	}

	/* process monty file, line by line */
	read = getline(&globals.linebuff, &buff_size, fp);
	while (read != -1)
	{
		globals.linenum++;
		/* compose array of instruction tokens */
		globals.instruct_arr = str_arr(globals.linebuff, " \n"); /* to L0 free instruct_arr*/
		if (!(globals.instruct_arr)[0])
		{
			/* only space(s) and/or newline xters on line */
			goto nextline; /* skip instruction execution and get next line */
		}

		perform_op(globals.instruct_arr); /* carry out instruction */

nextline:
		free(globals.linebuff);
		globals.linebuff = NULL;
		free(globals.instruct_arr);

		/* get next line from the fp file */
		read = getline(&globals.linebuff, &buff_size, fp); /* to L0 free linebuff */
	}

	free(globals.linebuff);
	free_stack(globals.stack_top);
	free_oplist(globals.oplist);
	fclose(fp);

	return (0);
}
