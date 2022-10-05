#include "monty.h"

/**
 * push - (an opcode) pushes an element to the stack
 * @head: double pointer to head of stack
 * @n: integer argument
 * Description: adds new element to the head of list
 * Return: Nothing
 */
void push(stack_t **head, unsigned int n)
{
	stack_t *new;

	/*checking if n - done outside this fn */
	/*printf("in push\n");*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*printf("new assigned\n");*/
	new->n = (int)n;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	new->prev = NULL;
	*head = new;
}

/**
 * pall - prints all the elements on the stack
 * Description: starting from the head (topmost)
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pall(stack_t **head, unsigned int n)
{
	stack_t *curr;
	(void)n;

	for (curr = *head; curr != NULL; curr = curr->next)
		printf("%d\n", curr->n);
}

/**
 * pint - prints the element at the top of the stack
 * Description: i.e. the head (topmost)
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pint(stack_t **head, unsigned int n)
{
	(void)n;
	if (*head != NULL)
		printf("%d\n", (*head)->n);
	else
	{
		dprintf(2, "L%u: can't pint, stack empty", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - removes the element at the top of the stack
 * Description: i.e. the head (topmost)
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pop(stack_t **head, unsigned int n)
{
	stack_t *to_pop;
	(void)n;

	if (*head != NULL)
	{
		to_pop = *head;
		*head = to_pop->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(to_pop);
	}
	else
	{
		dprintf(2, "L%u: can't pop an empty stack", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swaps the two element at the top of the stack
 * Description: i.e. the head (topmost) and head->next
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int n)
{
	stack_t *temp, *third;
	(void)n;

	if (*head != NULL)
		temp = *head;
	if (temp->next)/*then we have at least two elements*/
	{
		*head = temp->next;/*i.e the 2nd element*/
		if (temp->next->next)
		{
			third = temp->next->next;
			third->prev = temp;
			temp->next = third;
		}
		else
			temp->next = NULL;
		(*head)->prev = NULL;
		(*head)->next = temp;
		temp->prev = *head;
	}
	else
	{
		dprintf(2, "L%u: can't swap, stack too short", n);
		exit(EXIT_FAILURE);
	}
}


