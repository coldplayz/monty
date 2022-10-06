#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * handle_realloc - handles reallocation of memory to str_ar.
 * @i: the value of the index tracking the number of elements in str_ar.
 * @str_ar: address of a double pointer previously allocated memory.
 * @bsize: the unit memory size for str_ar.
 * @old_bsize: address of variable storing the buffer's prev size.
 * @bsize_total: address of the variable
 * representing the total size of the str_ar buffer.
 */
void handle_realloc(char ***str_ar, int i, int bsize, int *old_bsize,
	int *bsize_total)
{
	char **tmp, **tmp2;

	(void)tmp2;
	tmp2 = *str_ar; /* store the address of the string array to reallocate */
	if (i >= (*bsize_total / bsize))
	{
		*old_bsize = *bsize_total;
		*bsize_total += bsize;
		/* tmp = realloc(*str_ar, *bsize_total); */
		tmp = realloc3(*str_ar, *old_bsize, *bsize_total);
		if (!tmp)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(globals.linebuff);
			free(globals.instruct_arr);
			if (globals.stack_top)
				free_stack(globals.stack_top); /* stack is not empty */
			fclose(globals.fp);
			exit(EXIT_FAILURE);
		}

		*str_ar = tmp;
	}
}
