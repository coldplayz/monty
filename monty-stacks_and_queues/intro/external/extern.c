#include "extern.h"

/* define the (header) declared variable here */
int global_var = 37;

/* use the extern global var */
int increment(void)
{
	return (global_var++);
}

