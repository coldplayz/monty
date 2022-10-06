#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * isint - checks if str contains only characters 0 through 9.
 * @str: string to check.
 *
 * Return: 1 of str is numeric, 0 otherwise.
 */
int isint(char *str)
{
	int i = 0, entry_flag = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		i = 1;
	}

	for (; str[i]; i++)
	{
		entry_flag = 1;
		if (isdigit(str[i]) == 0)
		{
			/* str[i] not a digit char */
			return (0);
		}
	}

	if (!entry_flag)
	{
		/* loop was not entered */
		return (0);
	}

	return (1);
}
