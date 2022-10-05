#include "stack.h"

/* define the extern global variables defined in stack.h */
int top = -1;
int MAXSIZE = 8;

/**
 * peek - returns the value at stack top
 * @stack: the stack
 * Return: the item at the top of the stack
 */
int peek(int stack[])
{
	return (stack[top]);
}

/**
 * is_full - checks if the stack is full
 * Return: 1 if full and 0 otherwise
 */
int is_full(void)
{
	if (top == MAXSIZE)
		return (1);
	return (0); /*otherwise*/
}

/**
 * is_empty - checks if a stack is empty
 * Return: 1 if true and 0 otherwise
 */
int is_empty(void)
{
	if (top < 0)
		return (1);
	return (0);
}

/**
 * push - adds an item to the top of the stack
 * @stack: the stack
 * @data: the item to push onto stack
 * Return: 1 if successful and 0 otherwise
 */
int push(int stack[], int data)
{
	if (is_full())
	{
		printf("stack full!\n");
		return (0);
	}
	top++;
	stack[top] = data;
	return (1);
}

/**
 * pop - removes an item from the top of the stack
 * @stack: the stack
 * Return: the removed (popped) item
 */
int pop(int stack[])
{
	int data;

	if (is_empty())
	{
		printf("empty stack!\n");
		return (0);
	}
	data = stack[top];
	top--;
	return (data);
}


