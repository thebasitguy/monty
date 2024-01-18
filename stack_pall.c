#include "monty.h"

/**
 * stack_pall - prints all the elements of the stack
 *
 * @head: stack head
 * @counter: no used
 *
 * Return: nothing
 */

void stack_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
