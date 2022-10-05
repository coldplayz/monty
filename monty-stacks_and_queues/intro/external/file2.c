#include "extern.h"

void use_it(void)
{
	int var = increment();
	printf("global_var on increment: %d\n", var);
	printf("global_var on increment: %d\n", increment());
	/* use the global variable from another file */
	printf("Global variable, explicitly incremented: %d\n", ++global_var);
}

