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
	int read;
	size_t buff_size = 0;

	init_globals(); /* initializes variables in the globals_t struct, globals */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globals.fp = fopen(argv[1], "r"); /* returns a FILE ptr or NULL on failure */
	if (!globals.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* process monty file, line by line */
	read = getline(&globals.linebuff, &buff_size, globals.fp);
	while (read != -1)
	{
		globals.linenum++;
		/* compose array of instruction tokens */
		globals.instruct_arr = str_arr(globals.linebuff, "\a\r \t\n");
		if (!(globals.instruct_arr)[0] || (globals.instruct_arr)[0][0] == '#')
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
		read = getline(&globals.linebuff, &buff_size, globals.fp);
	}
	free(globals.linebuff);
	if (globals.stack_top)
		free_stack(globals.stack_top);
	fclose(globals.fp);
	return (0);
}
