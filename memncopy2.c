#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "monty.h"


/**
 * _memncpy - copies n bytes from memory area src to memory area dest
 * @dest: memory area to be filled
 * @src: src from which to copy bytes
 * @n: integer determining number of bytes (characters) to be copied
 */
void _memncpy(void *dest, void *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*((char *)dest + i) = *((char *)src + i);
	}
}
