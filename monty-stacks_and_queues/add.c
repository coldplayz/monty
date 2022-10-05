#include "monty.h"

/**
 * add - adds the two element at the top of the stack
 * Description: i.e. the head (topmost) and head->next
 * and stores the result in head->next, popping head
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void add(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void)n;

	if (*head != NULL)
		temp = *head;
	if (temp->next)/*then we have at least two elements*/
	{
		*head = temp->next;/*i.e the 2nd element*/
		(*head)->n = temp->n + (*head)->n;
        free(temp);
	}
	else
	{
		dprintf(2, "L%u: can't add, stack too short", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - does nothing to the top of the stack
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void nop(stack_t **head, unsigned int n)
{
	(void)n;
}