#include "monty.h"

/**
 * top_str - prints a string of characters from the top of a stack
 * followed by a new line
 *
 * @head: stack head
 * @counter: line_number
 *
 * Return: nothing
 */

void top_str(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
