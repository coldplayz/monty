#include "stack.h"

int main(void)
{
	char infix[25] = "1*(2+3)", postfix[25];
	int stack[25];

	convert(stack, infix, postfix);
	printf("Infix expression: %s\n", infix);
	printf("Postfix expression: %s\n", postfix);
	printf("Evaluated result: %d\n", evaluate(stack, postfix));
	return (0);
}

