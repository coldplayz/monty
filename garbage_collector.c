#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * garbage_collector - performs the full suite of
 * cleanups needed to be done just before the interpreter exits.
 */
void garbage_collector(void)
{
	free(globals.linebuff);
	free(globals.instruct_arr);
	if (globals.stack_top)
		free_stack(globals.stack_top); /* stack is not empty */
	fclose(globals.fp);
}
