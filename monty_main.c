#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int linenum = 0; /* for storing file line number count */
oplist_t *oplist = NULL; /* head of opcode instructions list */
stack_t *stack_top = NULL; /* head of program stack */
char **instruct_arr = NULL; /* for containing the list of instruction tokens*/
char *linebuff = NULL; /* stores lines of instructions from the monty file */
instruction_t push_st, pall_st; /* instances of instruction_t opstructs */


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

	init_opstruct(); /* define extern-declared instances of opcode structs */
	bld_oplist(&oplist); /* create an oplist_t linked list based on available opstructs*/

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
	read = getline(&linebuff, &buff_size, fp);
	while (read != -1)
	{
		linenum++;
		/* compose array of instruction tokens */
		instruct_arr = str_arr(linebuff, " \n"); /* to L0 free instruct_arr*/
		if (!instruct_arr[0])
		{
			/* only space(s) and/or newline xters on line */
			goto nextline; /* skip instruction execution and get next line */
		}

		perform_op(instruct_arr); /* carry out instruction */

nextline:
		free(linebuff);
		linebuff = NULL;
		free(instruct_arr);

		/* get next line from the fp file */
		read = getline(&linebuff, &buff_size, fp); /* to L0 free linebuff */
	}

	free(linebuff);
	free_stack(stack_top);
	free_oplist(oplist);
	fclose(fp);

	return (0);
}
