#include "stack.h"

/**
 * Infix notation is the most human readable while
 * Postfix notation is the best form of expression for
 * machines & computers to parse
 * Postfix - the operators come after(to the right) of operands
 */

/**
 * is_operator - checks whether a symbol is an operator
 * @symbol: the symbol to check
 * Return: 1 if true and 0 otherwise
 */
int is_operator(char symbol)
{
	switch (symbol)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')':
			return (1);
		default:
			return (0);
	}
}

/**
 * precedence - returns the precedence of an operator
 * @op: the operator symbol
 * Return: operator precedence
 */
int precedence(char op)
{
	switch (op)
	{
		case '+':
		case '-':
			return (2);
		case '*':
		case '/':
			return (3);
		case '^':
			return (4);
		case '(':
		case ')':
		case '#':
			return (1);
		default:
			return (0);
	}
}

/**
 * convert - converts infix to postfix notation
 * @stack: the stack
 * @infix: a string of chars in an infix expression
 * @postfix: an array to hold the postfix result
 * Return: Nothing
 */
void convert(int stack[], char infix[], char postfix[])
{
	int i, symbol, j = 0;

	stack[++top] = '#'; /*stack[0]*/
	for (i = 0; i < (int)strlen(infix); i++)
	{
		symbol = infix[i];
		/* append postfix with operands */
		if (is_operator(symbol) == 0)
		{
			postfix[j] = symbol;
			j++;
		}
		else /* symbol is an operator */
		{
			if (symbol == '(')
				push(stack, symbol);
			else

			{
				if (symbol == ')')
				{
					while (stack[top] != '(')
					{
						postfix[j] = pop(stack);
						j++;
					}
					/* pop the '(' operator */
					pop(stack);
				}
				else /* the symbol (operator) is not parenthesis */
				{
					if (precedence(symbol) > precedence(stack[top]))
						push(stack, symbol);
					else
					{/* append all higher precedence operators into postfix */
						while (precedence(symbol) <= precedence(stack[top]))
						{
							postfix[j] = pop(stack);
							j++;
						}
						/*they'll be evaluated before this symbol (push it onto stack)*/
						push(stack, symbol);
					}
				}
			}
		}
	}
	/* at this point, we are done with infix array */
	while (stack[top] != '#')
	{
		/* pop off any operators still in stack & append postfix */
		postfix[j] = pop(stack);
		j++;
	}
	postfix[j] = '\0'; /* terminate array/string */
}

