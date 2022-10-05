#include "stack.h"

int top_int = -1;

/**
 * push_int - push an integer onto stack
 * @n: the integer to push
 * @stack: a stack of ints
 * Return: (1 if successful and 0 otherwise) Nothing
 */
void push_int(int stack[], int n)
{
	/* this' stack_int */
	stack[++top_int] = n;
}

/**
 * pop_int - pops an int from a stack
 * @stack: the stack
 * Return: the popped value
 */
int pop_int(int stack[])
{
	return (stack[top_int--]);
}

/**
 * evaluate - evaluates a postfix expression
 * @stack: the integers stack
 * @postfix: array/string - the postfix expression
 * Return: the result (on evaluation)
 */
int evaluate(int stack[], char postfix[])
{
	char c;
	int i = 0, op1, op2;

	while ((c = postfix[i++]) != '\0')
	{
		if (isdigit(c))
			push_int(stack, (c - '0'));
		else
		{
			/*it's an operator, pop the two immediate operands*/
			op1 = pop_int(stack);
			op2 = pop_int(stack);
			switch (c)
			{
				case '+':
					push_int(stack, (op1 + op2));
					break;
				case '-':
					push_int(stack, (op1 - op2));
					break;
				case '*':
					push_int(stack, (op1 * op2));
					break;
				case '/':
					push_int(stack, (op1 / op2));
					break;
			}
		}
	}
	return (stack[top_int]);/*the result*/
}

