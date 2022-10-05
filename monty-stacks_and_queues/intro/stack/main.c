#include "stack.h"

int main(void)
{
	int i, stack[8];

	for (i = 0; i <= MAXSIZE; i++)
	       push(stack, i);
	while (top > -1)/*alt: while (!is_empty())*/
		printf("data: %d\n", pop(stack));
	printf("stack is empty: %s\n", is_empty() ? "true" : "false");
	return (0);
}	

