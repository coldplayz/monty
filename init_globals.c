#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * init_globals - gives definitions to variables in the globals_t struct.
 */
void init_globals(void)
{
	globals.linenum = 0; /* for storing file line number count */
	globals.stack_top = NULL; /* head of program stack */
	globals.instruct_arr = NULL; /* for containing the list of instruction tokens*/
	globals.linebuff = NULL; /* stores lines of instructions from the monty file */
	globals.fp = NULL; /* FILE pointer to the monty file */
}
